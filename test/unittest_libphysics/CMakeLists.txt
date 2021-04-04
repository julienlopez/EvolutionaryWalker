set(EXE_TARGET_NAME Unittest_LibPhysics)

add_executable(${EXE_TARGET_NAME} catch_main.cpp)

target_link_libraries(${EXE_TARGET_NAME} PRIVATE project_warnings project_options CONAN_PKG::catch2 EvolutionaryWalker::LibPhysics)

include(CTest)
include(Catch)
catch_discover_tests(${EXE_TARGET_NAME})
