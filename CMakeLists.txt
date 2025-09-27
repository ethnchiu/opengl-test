cmake_minimum_required(VERSION 3.15)

project(OpenGLTest CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(fmt REQUIRED)

add_executable(opengl_test src/main.cpp)

# Add GLAD sources and includes
target_sources(opengl_test PRIVATE "vendor/glad/src/glad.c")
target_include_directories(opengl_test PRIVATE "vendor/glad/include")

# Link GLFW, fmt
target_link_libraries(opengl_test PRIVATE glfw fmt::fmt)

# Link OpenGL
if(APPLE)
    # On macOS, find and link the OpenGL framework
    find_library(OPENGL_LIBRARY OpenGL REQUIRED)
    target_link_libraries(opengl_test PRIVATE ${OPENGL_LIBRARY})
else()
    # On other systems (like Linux), link the standard OpenGL::GL target
    target_link_libraries(opengl_test PRIVATE OpenGL::GL)
endif()


