cmake_minimum_required(VERSION 3.14)
project(CMakeSeqList VERSION 0.0.1 LANGUAGES C CXX)

aux_source_directory(. LINELINKLIST_SRC)
message("LINELINKLIST_SRC: ${LINELINKLIST_SRC}")

add_library(arlinelinklist STATIC ${LINELINKLIST_SRC})