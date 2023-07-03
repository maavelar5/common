cmake_minimum_required (VERSION 3.6.0)
project (common)

find_package(SDL2 REQUIRED)
find_package(GLEW REQUIRED)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

message(STATUS "opengl: ${OPENGL_LIBRARIES}")

set(LIBS ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${SDL2_LIBRARIES})
message(STATUS "wtf: ${LIBS}")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

# add_executable(${PROJECT_NAME} main.cc)
file(GLOB SOURCES "src/*.cpp" "sdl/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBS})
