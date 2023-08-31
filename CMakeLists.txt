#1.cmake verson，指定cmake版本
cmake_minimum_required(VERSION 3.2)

#2.project name，指定项目的名称，一般和项目的文件夹名称对应
PROJECT(date_struct)

#3.head file path，头文件目录
INCLUDE_DIRECTORIES(
include
)

#4.source directory，源文件目录
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#5.set environment variable，设置环境变量，编译用到的源文件全部都要放到这里，否则编译能够通过，但是执行的时候会出现各种问题，比如"symbol lookup error xxxxx , undefined symbol"
SET(TEST_MATH
${DIR_SRCS}
)

#6.add executable file，添加要编译的可执行文件
ADD_EXECUTABLE(${PROJECT_NAME} ${TEST_MATH})

#7.add link library，添加可执行文件所需要的库，比如我们用到了libm.so（命名规则：lib+name+.so），就添加该库的名称
TARGET_LINK_LIBRARIES(${PROJECT_NAME} m)

# # 一、设置项目版本和生成version.h
# cmake_minimum_required(VERSION 3.10)   # version

# # Version字段来自project配置 major.minor.patch.tweak
# project(DataAlgorithms VERSION 1.0.0 LANGUAGES C CXX DESCRIPTION "Data_Algorithms")

# # 配置自动生成版本头文件，将头文件版本号定义成对应的宏，或者定义成接口，方便在代码运行的时候了解当前的版本号
# configure_file(include/cmake_dsa_version.h.in "${PROJECT_SOURCE_DIR}/include/cmake_dsa_version.h")

# # CMAKE_、_CMAKE或者以下划线开头后面加上任意CMake命令的变量名都是CMake保留的


# # 二、指定编译语言C/C++ 版本
# set(CMAKE_C_STANDARD 99)
# set(CMAKE_CXX_STANDARD 11)


# ##--------------------- Compile Options ------------------------------------##
# # 三、配置编译选项
# # Configure compile options
# add_compile_options(-Wall -Wextra -pedantic -Werror)
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11")

# # Set build type
# # set(CMAKE_BUILD_TYPE Debug)  # Use `cmake -DCMAKE_BUILD_TYPE=Debug` more better

# # 四、配置编译类型
# set(CMAKE_BUILD_TYPE Debug)
# message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# # Compile options for Debug variant
# set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# # Compile options for Release variant
# set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
# set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# message(STATUS "Compile options for c: ${CMAKE_C_FLAGS}")
# message(STATUS "Compile options for c++: ${CMAKE_CXX_FLAGS}")

# # 五、添加全局宏定义
# ##--------------------- Global Macros --------------------------------------##
# add_definitions(-DDEBUG -DREAL_COOL_ENGINEER)

# # 六、设置头文件搜索目录
# ##--------------------- Include directories --------------------------------##
# include_directories(include)


# # 获取编译静态库需要的文件列表
# ##--------------------- Source files ---------------------------------------##
# file(GLOB_RECURSE DSA_LIB_SRC
#     src/*.c
# )
# add_library(DataAlgorithms STATIC ${DSA_LIB_SRC})

# ##--------------------- Build target ---------------------------------------##
# # option(USE_IMPORTED_LIB "Use pre compiled lib" OFF)
# # if (USE_IMPORTED_LIB)
# #     # add_library(math STATIC IMPORTED)
# #     # set_property(TARGET math PROPERTY IMPORTED_LOCATION "./lib/libmath.a")
# #     find_library(LIB_MATH_DEBUG mathd HINTS "./lib")
# #     find_library(LIB_MATH_RELEASE math HINTS "./lib")
# #     add_library(math STATIC IMPORTED GLOBAL)
# #     set_target_properties(math PROPERTIES
# #         IMPORTED_LOCATION "${LIB_MATH_RELEASE}"
# #         IMPORTED_LOCATION_DEBUG "${LIB_MATH_DEBUG}"
# #         IMPORTED_CONFIGURATIONS "RELEASE;DEBUG"
# #     )

# #     add_subdirectory(src/c/nn)
# # else()
# #     # Build math lib
# #     add_subdirectory(src/c/math)
# #     add_subdirectory(src/c/nn)
# # endif()

# # Merge library
# # if (APPLE)
# #     set(MERGE_CMD libtool -static -o)
# #     add_custom_command(OUTPUT libmerge.a
# #     COMMAND libtool -static -o libmerge.a $<TARGET_FILE:math> $<TARGET_FILE:nn>
# #     DEPENDS math nn)
# # else()
# #     add_custom_command(OUTPUT libmerge.a
# #     COMMAND ar crsT libmerge.a $<TARGET_FILE:math> $<TARGET_FILE:nn>
# #     DEPENDS math nn)
# # endif()

# # add_custom_target(_merge ALL DEPENDS libmerge.a)
# # add_library(merge STATIC IMPORTED GLOBAL)
# # set_target_properties(merge PROPERTIES
# #     IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/libmerge.a
# # )

# # Build demo executable
# add_executable(demo src/main.c)
# target_link_libraries(demo PRIVATE merge)


# ## 构建C测试
# ##--------------------- Build unit tests -----------------------------------##
# # option(CMAKE_TEMPLATE_ENABLE_TEST "Whether to enable unit tests" ON)
# # if (CMAKE_TEMPLATE_ENABLE_TEST)
# #     message(STATUS "Unit tests enabled")
# #     enable_testing()
# #     add_subdirectory(third_party/googletest-release-1.10.0 EXCLUDE_FROM_ALL)
# #     include_directories(third_party/googletest-release-1.10.0/googletest/include)

# #     add_executable(test_add test/c/test_add.cc)
# #     add_executable(test_minus test/c/test_minus.cc)
# #     add_executable(test_gtest_demo test/c/test_gtest_demo.cc)
# #     target_link_libraries(test_add math gtest gtest_main)
# #     target_link_libraries(test_minus math gtest gtest_main)
# #     target_link_libraries(test_gtest_demo math gtest gtest_main)

# #     add_test(NAME test_add COMMAND test_add)
# #     add_test(NAME test_minus COMMAND test_minus)
# #     add_test(NAME test_gtest_demo COMMAND test_gtest_demo)
# # endif()

# ##--------------------- Install and Package target -------------------------##
# # Install

# ## 指定当前项目在执行安装时，需要安装什么内容
# # if (NOT USE_IMPORTED_LIB)
# #     install(TARGETS math nn demo
# #             RUNTIME DESTINATION bin
# #             LIBRARY DESTINATION lib
# #             ARCHIVE DESTINATION lib
# #             PUBLIC_HEADER DESTINATION include)
# #     file(GLOB_RECURSE MATH_LIB_HEADERS src/c/math/*.h)
# #     install(FILES ${MATH_LIB_HEADERS} DESTINATION include/math)
# # endif()

# # Package, These variables should set before including CPack module
# # set(CPACK_GENERATOR "ZIP")
# # set(CPACK_SET_DESTDIR ON)  # 支持指定安装目录
# # set(CPACK_INSTALL_PREFIX "RealCoolEngineer")
# # include(CPack)