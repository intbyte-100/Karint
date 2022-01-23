cmake_minimum_required(VERSION 2.19)
project(LiteEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



set(ENGINE_SOURCE
        src/lite/desktop/Window.cpp
        src/lite/util/LiteException.h
        src/lite/graphic/gl/gl.cpp
        src/lite/desktop/DesktopApplication.cpp
        src/lite/desktop/lite.cpp src/lite/Application.h
        src/lite/desktop/DesktopApplication.h
        src/lite/desktop/lite.h src/lite/desktop/Window.h
        src/lite/graphic/gl/gl.h
        src/lite/graphic/gl/VertexBufferObject.cpp
        src/lite/graphic/gl/VertexBufferObject.h
        src/lite/graphic/gl/ShaderProgram.cpp
        src/lite/graphic/gl/ShaderProgram.h
        src/lite/graphic/gl/VertexAttributeObject.cpp
        src/lite/graphic/gl/VertexAttributeObject.h
        src/lite/graphic/gl/ElementBufferObject.h
        src/lite/graphic/gl/ElementBufferObject.cpp
        src/lite/graphic/gl/Uniform.h
        src/lite/graphic/gl/Uniform.cpp
        src/lite/graphic/gl/Texture.h
        src/lite/graphic/gl/Texture.cpp
        src/lite/util/FileNotFoundException.h
        src/lite/graphic/PerspectiveCamera.cpp
        src/lite/graphic/PerspectiveCamera.h src/lite/input/input.cpp src/lite/input/input.h)

add_executable(LiteEngine main.cpp ${ENGINE_SOURCE})

find_package(glm REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})
link_directories(${GLM_LIBRARY_DIRS})
add_definitions(${GLM_DEFINITIONS})

# GLFW
find_package(glfw3 3.3 REQUIRED)

# glad
set(GLAD_DIR "include/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
include_directories("src")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(${PROJECT_NAME} PRIVATE "${GLAD_DIR}/include")

target_link_libraries(${PROJECT_NAME} "glad" "${CMAKE_DL_LIBS}" glfw)

add_library("stb" "include/stb_image/stb_implementation.cpp")
target_include_directories("stb" PRIVATE "include/stb_image")
target_include_directories(${PROJECT_NAME} PRIVATE "include/stb_image")

target_link_libraries(${PROJECT_NAME} "stb")
