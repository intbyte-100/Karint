cmake_minimum_required(VERSION 2.19)
project(LiteEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON )


set(ENGINE_SOURCE
    src/lite/desktop/Window.cpp
    src/lite/util/LiteException.h
    src/lite/graphic/gl.cpp
    src/lite/desktop/DesktopApplication.cpp
    src/lite/desktop/lite.cpp src/lite/Application.h
    src/lite/desktop/DesktopApplication.h
    src/lite/desktop/lite.h src/lite/desktop/Window.h
    src/lite/graphic/gl.h
    src/lite/graphic/VertexBufferObject.cpp
    src/lite/graphic/VertexBufferObject.h
    src/lite/graphic/ShaderProgram.cpp
    src/lite/graphic/ShaderProgram.h
    src/lite/graphic/VertexAttributeObject.cpp
    src/lite/graphic/VertexAttributeObject.h
    src/lite/graphic/ElementBufferObject.h
    src/lite/graphic/ElementBufferObject.cpp
    src/lite/graphic/Uniform.h
    src/lite/graphic/Uniform.cpp
    src/lite/graphic/Texture.h
    src/lite/graphic/Texture.cpp
    src/lite/util/FileNotFoundException.h
    src/lite/graphic/attribute/PositionAttribute.h
    src/lite/graphic/attribute/AttributeArray.h
    src/lite/graphic/attribute/AttributeArray.cpp
    src/lite/graphic/attribute/ColorAttribute.h
)

add_executable(LiteEngine main.cpp ${ENGINE_SOURCE})

find_package(glm REQUIRED)
target_link_libraries("${PROJECT_NAME}" glm)

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
