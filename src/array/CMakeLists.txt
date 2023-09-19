cmake_minimum_required(VERSION 3.18.0)
project(CMakeSeqList VERSION 0.0.1 LANGUAGES C CXX)

aux_source_directory(. ARRAY_SRC)
message("ARRAY_SRC: ${ARRAY_SRC}")

add_library(ararray STATIC ${ARRAY_SRC})