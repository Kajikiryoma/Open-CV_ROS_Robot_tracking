#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(){
    cv::VideoCapture cap(0);

    int key = 0;
    while (key != 27){
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

        ave_x = temp_x/count;
        ave_y = temp_y/count;

        if(frame.cols/3 > ave_x) {
            printf("左\n");
        }
        else if(frame.cols/2 > ave_x){
            printf("中\n");
        }else{
            printf("右\n");
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