#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<ros/ros.h>
#include<geometry_msgs/Twist.h>

int main(int argc, char **argv){
    cv::VideoCapture cap(2);
    ros::init(argc, argv, "pub_cmd_vel");
        ros::NodeHandle n;
        ros::Publisher wheel_pub
            = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

        ros::Rate loop_rate(10);

    int key = 0;
    while (ros::ok()){
        cv::Mat frame;
        cap.read(frame);

        int temp_x = 0;
        int temp_y = 0;
        int count = 0;
        int ave_x = 0;
        int ave_y = 0;

        for(int y = 0; y < frame.rows; ++y) {
            for(int x = 0; x < frame.cols; ++x) {
                cv::Vec3b pixel1 = frame.at<cv::Vec3b>(y, x);
                if(pixel1[2] > 100 && pixel1[1] < 75 && pixel1[0] < 75) {
                temp_x += x;
                temp_y += y;
                count++;
                }
            }
        }

        if(count == 0){
            continue;
        }

        ave_x = temp_x/count;
        ave_y = temp_y/count;
        geometry_msgs::Twist  wheel_data;
        if(frame.cols/3 > ave_x) {
            printf("左\n");
            wheel_data.linear.x = 1.00;
            wheel_data.angular.z = 1.50;

            wheel_pub.publish(wheel_data);
            ros::spinOnce();
            loop_rate.sleep();
        }
        else if(frame.cols/2 > ave_x){
            printf("中\n");
            wheel_data.linear.x = 1.00;
            wheel_data.angular.z = 0.00;

            wheel_pub.publish(wheel_data);
            ros::spinOnce();
            loop_rate.sleep();
        }else{
            printf("右\n");
            wheel_data.linear.x = 1.00;
            wheel_data.angular.z = -1.50;

            wheel_pub.publish(wheel_data);
            ros::spinOnce();
            loop_rate.sleep();
        }

        cv::imshow("image_test", frame);
        key = cv::waitKey(30);
        cv::Point center(ave_x,ave_y);
        int radius = 5;
        cv::circle(frame, center, radius, cv::Scalar(255,0,0), -1);
        cv::imshow("image_test", frame);
        cv::waitKey(1);
    }
    cv::destroyAllWindows();
    return 0;
}