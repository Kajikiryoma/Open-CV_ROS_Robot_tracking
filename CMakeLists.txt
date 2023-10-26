cmake_minimum_required(VERSION 3.0.2)
project(robot_pkg)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  geometry_msgs
)

catkin_package(
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
)

find_package (OpenCV REQUIRED)

add_executable(image_file_viewer src/image_file_viewer.cpp)
target_link_libraries(image_file_viewer ${OpenCV_LIBRARIES})

add_executable(search_red_area src/search_red_area.cpp)
target_link_libraries(search_red_area ${OpenCV_LIBRARIES})

add_executable(get_webcamera_image src/get_webcamera_image.cpp)
target_link_libraries(get_webcamera_image ${OpenCV_LIBRARIES})

add_executable(draw_blue_cirle src/draw_blue_cirle.cpp)
target_link_libraries(draw_blue_cirle ${OpenCV_LIBRARIES})

add_executable(calc_red_center src/calc_red_center.cpp)
target_link_libraries(calc_red_center ${OpenCV_LIBRARIES})

add_executable(calc_red_center2 src/calc_red_center2.cpp)
target_link_libraries(calc_red_center2 ${OpenCV_LIBRARIES})

add_executable(pub_cmd_vel src/pub_cmd_vel.cpp)
target_link_libraries(
pub_cmd_vel ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})

add_executable(pub_cmd_vel2 src/pub_cmd_vel2.cpp)
target_link_libraries(
pub_cmd_vel2 ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})