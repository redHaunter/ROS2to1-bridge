cmake_minimum_required(VERSION 3.5)
project(foxy_publisher)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
# Find ROS 2 packages and libraries
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)

# Add your package dependencies here
# find_package(<dependency> REQUIRED)

# Create an executable for your node
add_executable(publisher_node src/publisher.cpp)

# Include directories for the executable
target_include_directories(publisher_node
  PRIVATE
  ${OpenCV_INCLUDE_DIRS}
)

# Link your executable with ROS 2 libraries
ament_target_dependencies(publisher_node
  rclcpp
  sensor_msgs
  # Add your dependencies here
  # <dependency>
)

# Install the executable
install(TARGETS
  publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

install(FILES
  my_bridge_mapping.yaml
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
