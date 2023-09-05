# CMake generated Testfile for 
# Source directory: G:/ProjectCode/dataSA
# Build directory: G:/ProjectCode/dataSA/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_demo "test_SeqList")
set_tests_properties(test_demo PROPERTIES  _BACKTRACE_TRIPLES "G:/ProjectCode/dataSA/CMakeLists.txt;93;add_test;G:/ProjectCode/dataSA/CMakeLists.txt;0;")
subdirs("src/SeqList")
subdirs("third_party/googletest-main")
