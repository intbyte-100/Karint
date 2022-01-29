cmake_minimum_required(VERSION 2.19)
project(KarintEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(ENGINE_SOURCE
        src/karint/desktop/Window.cpp
        src/karint/util/KarintException.h
        src/karint/graphic/gl/gl.cpp
        src/karint/desktop/DesktopApplication.cpp
        src/karint/desktop/karint.cpp
        src/karint/Application.h
        src/karint/desktop/DesktopApplication.h
        src/karint/desktop/karint.h
        src/karint/desktop/Window.h
        src/karint/graphic/gl/gl.h
        src/karint/graphic/gl/VertexBufferObject.cpp
        src/karint/graphic/gl/VertexBufferObject.h
        src/karint/graphic/gl/ShaderProgram.cpp
        src/karint/graphic/gl/ShaderProgram.h
        src/karint/graphic/gl/VertexAttributeObject.cpp
        src/karint/graphic/gl/VertexAttributeObject.h
        src/karint/graphic/gl/ElementBufferObject.h
        src/karint/graphic/gl/ElementBufferObject.cpp
        src/karint/graphic/gl/Uniform.h
        src/karint/graphic/gl/Uniform.cpp
        src/karint/graphic/gl/Texture.h
        src/karint/graphic/gl/Texture.cpp
        src/karint/util/FileNotFoundException.h
        src/karint/graphic/PerspectiveCamera.cpp
        src/karint/graphic/PerspectiveCamera.h
        src/karint/input/input.cpp
        src/karint/input/input.h
        src/karint/graphic/Renderable.h
        src/karint/graphic/Renderer.cpp
        src/karint/graphic/Renderer.h
        src/karint/math/math.cpp
        src/karint/math/math.h
        src/karint/input/CameraController.cpp
        src/karint/input/CameraController.h src/karint/graphic/OrthographicCamera.cpp src/karint/graphic/OrthographicCamera.h src/karint/graphic/Camera.cpp src/karint/graphic/Camera.h)

add_executable(KarintEngine main.cpp ${ENGINE_SOURCE})

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
