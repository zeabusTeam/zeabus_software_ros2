#!/usr/bin/python3
"""
    File name: gate
    Author: Shayennn
    Date created: 2019/04/20
    Python Version: 3.6
"""

import numpy as np
import cv2 as cv

import rclpy
from sensor_msgs.msg import CompressedImage
from zeabus.srv import VisionGate
from gate.gate import Gate


g_node = None
SUB_SAMPLING = 0.3
PUBLIC_TOPIC = '/vision/mission/gate'
CAMERA_TOPIC = '/vision/front/image_rect_color/compressed'
DEBUG = {
    'console': True,
    'imageSource': True
}

process_obj = Gate()
image = None
last_found = [0.0, 0.0, 0.0, 0.0, 0.0]


def imageCallback(msg):
    global image, SUB_SAMPLING
    arr = np.fromstring(msg.data, np.uint8)
    image = cv.resize(cv.imdecode(arr, 1), (0, 0),
                      fx=SUB_SAMPLING, fy=SUB_SAMPLING)


def find_gate():
    global image, last_found
    output = None
    if image is not None:
        output = process_obj.doProcess(image)
        output = [float(i) for i in output]
    else:
        print('No input image')
    if output is not None:
        last_found = output
        return [1]+last_found
    else:
        return [0]+last_found


def gate_callback(msg, res):
    global g_node
    task = str(msg.task.data)
    req = str(msg.req.data)
    if DEBUG['console'] or task == '':
        print('Service called', msg, req)
    if task in ['gate', '']:
        find_result = find_gate()
        res.found = find_result[0]
        res.cx1 = find_result[1]
        res.cy1 = find_result[2]
        res.x_left = find_result[3]
        res.x_right = find_result[4]
        res.area = find_result[5]
    else:
        if DEBUG['console'] or task == '':
            print('Not OK')
        res.found = 2
        res.cx1 = 0.0
        res.cy1 = 0.0
        res.x_left = 0.0
        res.x_right = 0.0
        res.area = 0.0
    return res


def main(args=None):
    global g_node
    rclpy.init(args=args)

    g_node = rclpy.create_node('vision_gate')

    sub = g_node.create_subscription(
        CompressedImage, CAMERA_TOPIC, imageCallback)

    srv = g_node.create_service(VisionGate, 'gate_service', gate_callback)
    while rclpy.ok():
        rclpy.spin_once(g_node)

    g_node.destroy_service(srv)
    g_node.destroy_subscription(sub)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
