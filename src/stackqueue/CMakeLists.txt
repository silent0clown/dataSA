cmake_minimum_required(VERSION 3.14)
project(CMakeSeqList VERSION 0.0.1 LANGUAGES C CXX)

aux_source_directory(. STACKQUEUE_SRC)
message("STACKQUEUE_SRC: ${STACKQUEUE_SRC}")

add_library(arstackqueue STATIC ${STACKQUEUE_SRC})