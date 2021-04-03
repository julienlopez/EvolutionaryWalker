set(LIBRARY_TARGET_NAME LibPhysics)

set(LIB_ROOT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/")
file(GLOB_RECURSE LIB_UTILS_ALL_SRC "${LIB_ROOT_DIRECTORY}/*.cpp")
file(GLOB_RECURSE LIB_UTILS_ALL_HDR "${LIB_ROOT_DIRECTORY}/*.hpp")

include_directories(${LIB_ROOT_DIRECTORY})

add_library(${LIBRARY_TARGET_NAME} ${LIB_UTILS_ALL_SRC} ${LIB_UTILS_ALL_HDR})
add_library(${PROJECT_NAME}::${LIBRARY_TARGET_NAME} ALIAS ${LIBRARY_TARGET_NAME})

set_target_properties(
  ${LIBRARY_TARGET_NAME}
  PROPERTIES
  PUBLIC_HEADER
  "${LIB_UTILS_ALL_HDR}"
)

target_include_directories(
  ${LIBRARY_TARGET_NAME}
  INTERFACE
  "$<BUILD_INTERFACE:${LIB_ROOT_DIRECTORY}>"
  "$<BUILD_INTERFACE:${}>"
  "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)

target_link_libraries(
  ${LIBRARY_TARGET_NAME}
  PRIVATE project_options
          project_warnings
  PUBLIC
          EvolutionaryWalker::LibUtils
          Boost::headers
)

message(STATUS "Created target ${LIBRARY_TARGET_NAME} for export ${PROJECT_NAME}.")
