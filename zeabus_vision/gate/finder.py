#!/usr/bin/python3
"""
    File name: gate
    Author: Shayennn
    Date created: 2019/04/20
    Python Version: 3.6
"""

import rclpy
from sensor_msgs.msg import CompressedImage
from zeabus.srv import VisionGate
from gate.gate import Gate
from gate.image import Image

g_node = None
PUBLIC_TOPIC = '/vision/mission/gate'
DEBUG = {
    'console': True,
    'imageSource': True
}

process_obj = Gate()
image = Image(DEBUG['imageSource'])
last_found = [0, 0, 0, 0, 0]


def find_gate():
    global image, last_found
    output = process_obj.doProcess(image.get())
    if output is not None:
        last_found = output
        return [1]+last_found
    else:
        return [0]+last_found


def gate_callback(msg, res):
    global g_node
    task = str(msg.task.data)
    req = str(msg.req.data)
    if DEBUG['console']:
        print(task, req)
    if task in ['gate']:
        find_result = find_gate()
        res.found = find_result[0]
        res.cx1 = find_result[1]
        res.cy1 = find_result[2]
        res.x_left = find_result[3]
        res.x_right = find_result[4]
        res.area = find_result[5]
    else:
        res.found = -1
        res.cx1 = 0
        res.cy1 = 0
        res.x_left = 0
        res.x_right = 0
        res.area = 0
    return res


def main(args=None):
    global g_node
    rclpy.init(args=args)

    g_node = rclpy.create_node('vision/gate')

    sub = g_node.create_subscription(
        CompressedImage, image.topic('front'), image.callback)

    srv = g_node.create_service(VisionGate, 'gate_service', gate_callback)
    while rclpy.ok():
        rclpy.spin_once(g_node)

    g_node.destroy_service(srv)
    g_node.destroy_subscription(sub)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
