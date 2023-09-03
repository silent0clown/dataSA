cmake_minimum_required(VERSION 3.14)

aux_source_directory(. SEQLIST_SRC)
message("SEQLIST_SRC: ${SEQLIST_SRC}")

add_library(arseqlist STATIC ${SEQLIST_SRC})