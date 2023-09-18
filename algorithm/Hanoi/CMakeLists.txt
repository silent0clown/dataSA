# # 包含公共库
# include_directories(${CMAKE_SOURCE_DIR}/include)

# # 生成可执行文件
# add_executable(Maze maze_stack.h maze_stack.c maze.h maze.c main_maze.c)
# # 链接公共库
# # target_link_libraries(Maze Scanf_lib)


cmake_minimum_required(VERSION 3.14)
project(CMakeSeqList VERSION 0.0.1 LANGUAGES C CXX)

aux_source_directory(. HANOI_SRC)
message("HANOI_SRC: ${HANOI_SRC}")

add_library(arhanoi STATIC ${HANOI_SRC})