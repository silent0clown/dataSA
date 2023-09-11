#1.cmake verson，指定cmake版本
cmake_minimum_required(VERSION 3.14)
# Version字段来自project配置 major.minor.patch.tweak
project(data_algorithms VERSION 1.0.0 LANGUAGES C CXX DESCRIPTION "Data_Algorithms")

# 配置自动生成版本头文件，将头文件版本号定义成对应的宏，或者定义成接口，方便在代码运行的时候了解当前的版本号
# CMAKE_、_CMAKE或者以下划线开头后面加上任意CMake命令的变量名都是CMake保留的
configure_file(include/cmake_dsa_version.h.in "${PROJECT_SOURCE_DIR}/include/cmake_dsa_version.h")

# 指定编译语言C/C++ 版本
set(CMAKE_C_STANDARD 99)
#为了使用gtest，指定c++语言，为c++11版本
set(CMAKE_CXX_STANDARD 11)

##--------------------- Compile Options ------------------------------------##
# Configure compile options
add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pipe -std=c99 -Wno-error=unused-value -Wno-error=unused-but-set-parameter")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pipe -std=c++11")

# 四、配置编译类型
# set(CMAKE_BUILD_TYPE Debug)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Compile options for Debug variant
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# Compile options for Release variant
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

message(STATUS "Compile options for c: ${CMAKE_C_FLAGS}")
message(STATUS "Compile options for c++: ${CMAKE_CXX_FLAGS}")

add_definitions(-DDEBUG -DREAL_COOL_ENGINEER)

#3.include directories
include_directories(include)
include_directories(src)


# source files
file(GLOB_RECURSE DATAALGOR_LIB_SRC
        src/*.c
        )

##--------------------- Build target ---------------------------------------##
option(USE_IMPORTED_LIB "Use pre compiled lib" OFF)
if (USE_IMPORTED_LIB)
    find_library(LIB_DATAALGOR_DEBUG data_algorithms HINTS "./lib")
    find_library(LIB_DATAALGOR_RELEASE data_algorithms HINTS "./lib")
    add_library(data_algorithms STATIC IMPORTED GLOBAL)
    set_target_properties(data_algorithms PROPERTIES
        IMPORTED_LOCATION "${LIB_DATAALGOR_RELEASE}"
        IMPORTED_LOCATION_DEBUG "${LIB_DATAALGOR_DEBUG}"
        IMPORTED_CONFIGURATIONS "RELEASE;DEBUG"
    )
    add_subdirectory(src/sequencelist)
    add_subdirectory(src/linerlinklist)
else()
    # Build  lib
    # 加入子模块
    add_subdirectory(src/sequencelist)
    add_subdirectory(src/linerlinklist)
#     add_subdirectory(src/c/nn)
endif()

# merge library
add_custom_command(OUTPUT libmerge.a
COMMAND ar crsT libmerge.a $<TARGET_FILE:arseqlist> $<TARGET_FILE:arlinelinklist>
DEPENDS arseqlist arlinelinklist)

add_custom_target(_merge ALL DEPENDS libmerge.a)
add_library(merge STATIC IMPORTED GLOBAL)
set_target_properties(merge PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/libmerge.a
)

# Build demo executable
add_executable(proc src/main.c)
target_link_libraries(proc PRIVATE merge)

##--------------------- Build unit tests -----------------------------------##
option(CMAKE_TEMPLATE_ENABLE_TEST "Whether to enable unit tests" ON)
if (CMAKE_TEMPLATE_ENABLE_TEST)
    message(STATUS "Unit tests enabled")
    enable_testing()
    add_subdirectory(third_party/googletest-main EXCLUDE_FROM_ALL)
    include_directories(third_party/googletest-main/googletest/include)

    add_executable(test_LineList test/test_SeqList.cpp test/test_LinkList.cpp)
    target_link_libraries(test_LineList arseqlist arlinelinklist gtest gtest_main)
    add_test(NAME test_LineList COMMAND test_LineList)


endif()

##--------------------- Install and Package target -------------------------##
# Install
if (NOT USE_IMPORTED_LIB)
    install(TARGETS arseqlist proc
            RUNTIME DESTINATION bin
            LIBRARY DESTINATION lib
            ARCHIVE DESTINATION lib
            PUBLIC_HEADER DESTINATION include)
    file(GLOB_RECURSE DATASTRUCT_LIB_HEADERS src/sequencelist/*.h)
    install(FILES ${DATASTRUCT_LIB_HEADERS} DESTINATION include/SeqList)
endif()

# Package, These variables should set before including CPack module
set(CPACK_GENERATOR "ZIP")
set(CPACK_SET_DESTDIR ON)  # 支持指定安装目录
set(CPACK_INSTALL_PREFIX "RealCoolEngineer")
include(CPack)