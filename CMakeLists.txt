# Specify the minimum version of CMake required
cmake_minimum_required(VERSION 3.0)

# Set the project name and version
project(task1_c VERSION 1.0)
project(task1_cpp VERSION 1.0)
project(merge_sort_c VERSION 1.0)
# Add the executable target
add_executable(task1_c "FreeCodeCamp course/Algorithms/Find the Symmetric Difference/main.c")
add_executable(task1_cpp  "FreeCodeCamp course/Algorithms/Find the Symmetric Difference/main.cpp")
add_executable(merge_sort_c "FreeCodeCamp course/Algorithms/Merge Sort/main.c")