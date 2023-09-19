cmake_minimum_required(VERSION 3.14)
project(CMakeSeqList VERSION 0.0.1 LANGUAGES C CXX)

aux_source_directory(. STRING_SRC)
message("STRING_SRC: ${STRING_SRC}")

add_library(arstr STATIC ${STRING_SRC})