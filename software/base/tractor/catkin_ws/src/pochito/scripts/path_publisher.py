#! /usr/bin/python

import rospy
from nav_msgs.msg import Path
from geometry_msgs.msg import  PoseStamped
from tf.transformations import quaternion_from_euler
from std_msgs.msg import Float64

got_path = False

def path_callback(msg):
    global got_path
    if msg.data == -1.0:
        got_path = True

def path_publisher():
    rospy.init_node('path_publisher')
    rospy.Subscriber('got_path', Float64, path_callback)
    path_pub = rospy.Publisher('/drive_path', Path, queue_size=10)

    path = Path()
    
    path.header.frame_id = "map"
    path.header.seq = 0
    path.header.stamp = rospy.Time.now()
    
    seq = 0

    for line in content:
        #print(line)
        pose = PoseStamped()
        
        points = line.split()
        #print(points)
        x = float(points[0])
        y = float(points[1])
        yaw = float(points[2])

        quat = quaternion_from_euler(0, 0, yaw)

        pose.header.frame_id = "map"
        pose.header.seq = seq
        pose.pose.position.x = x
        pose.pose.position.y = y
        pose.pose.position.z = 0
        pose.pose.orientation.x = quat[0]
        pose.pose.orientation.y = quat[1]
        pose.pose.orientation.z = quat[2]
        pose.pose.orientation.w = quat[3]
        pose.header.stamp = path.header.stamp
        
        path.poses.append(pose)

        seq += 1


    while not rospy.is_shutdown():
        if (got_path is False):
            print("Sending Path")  
            path_pub.publish(path)
        else:
            break

        rospy.sleep(5)


content = {}
def load_file():
    # TODO: Get filename from rosparam
    global content
    try:
        with open('generated_points.txt', 'r') as file:
            content = file.readlines()
            content = [x.strip() for x in content]
    except:
        rospy.loginfo("File failed to load")


if __name__ == '__main__':
    try:
        load_file()
        path_publisher()
    except rospy.ROSInterruptException:
        pass