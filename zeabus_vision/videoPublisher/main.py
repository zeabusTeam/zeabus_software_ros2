#!/usr/bin/python3
"""
    File name: gate
    Author: Shayennn
    Date created: 2019/04/20
    Python Version: 3.6
"""

# import tkinter as tk
# from tkinter import filedialog

import cv2 as cv
from cv_bridge import CvBridge

import rclpy
from rclpy.qos import qos_profile_default
from sensor_msgs.msg import CompressedImage

g_node = None
CAMERA_TOPIC = '/vision/front/image_rect_color'


def main(args=None):
    global g_node
    # root = tk.Tk()
    # root.withdraw()

    # file_path = filedialog.askopenfilename()
    # file_path = '/home/shayennn/Desktop/zb/01_bag_of_vision/Casino gate(3_)/2018-06-17-14-50-55_stereo.right.image.rect.color.compressed.avi'

    bridge = CvBridge()
    dev = cv.VideoCapture(0)

    rclpy.init(args=args)

    g_node = rclpy.create_node('vision_videoPublisher')
    pub = g_node.create_publisher(
        CompressedImage, CAMERA_TOPIC, qos_profile=qos_profile_default)

    def timerCallback():
        if dev.isOpened():
            ret, img = dev.read()
            if ret:
                print('Pub!')
                pub.publish(bridge.cv2_to_compressed_imgmsg(img))

    tm = g_node.create_timer(1/10, timerCallback)

    rclpy.spin(g_node)

    g_node.destroy_timer(tm)

    g_node.destroy_node()

    rclpy.shutdown()


if __name__ == "__main__":
    main()
