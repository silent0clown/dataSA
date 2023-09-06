# CMake generated Testfile for 
# Source directory: /mnt/hgfs/Vscode/Ctest/dataSA
# Build directory: /mnt/hgfs/Vscode/Ctest/dataSA/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_SeqList "/mnt/hgfs/Vscode/Ctest/dataSA/build/test_SeqList")
set_tests_properties(test_SeqList PROPERTIES  _BACKTRACE_TRIPLES "/mnt/hgfs/Vscode/Ctest/dataSA/CMakeLists.txt;92;add_test;/mnt/hgfs/Vscode/Ctest/dataSA/CMakeLists.txt;0;")
subdirs("src/SeqList")
subdirs("third_party/googletest-main")
