

add_executable(tests catch_main.cpp tests.cpp test_strings.cpp )
target_link_libraries(tests PRIVATE project_warnings project_options CONAN_PKG::catch2 EvolutionaryWalker::LibUtils)