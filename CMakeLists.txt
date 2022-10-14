cmake_minimum_required(VERSION 2.19)
project(KarintEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DKARINT_DEBUG")






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
        src/karint/util/FileException.h
        src/karint/graphic/Camera3D.cpp
        src/karint/graphic/Camera3D.h
        src/karint/input/input.cpp
        src/karint/input/input.h
        src/karint/graphic/Renderable.h
        src/karint/graphic/Renderer.cpp
        src/karint/graphic/Renderer.h
        src/karint/math/kmath.cpp
        src/karint/math/kmath.h
        src/karint/input/CameraController.cpp
        src/karint/input/CameraController.h
        src/karint/graphic/Camera2D.cpp
        src/karint/graphic/Camera2D.h
        src/karint/graphic/Camera.cpp
        src/karint/graphic/Camera.h
        src/karint/graphic/g3d/Environment.cpp
        src/karint/graphic/g3d/Environment.h
        src/karint/util/File.cpp
        src/karint/util/File.h
        src/karint/graphic/g3d/Vertex.cpp
        src/karint/graphic/g3d/Vertex.h
        src/karint/util/logger.cpp
        src/karint/util/logger.h
        src/karint/graphic/g3d/Material.cpp
        src/karint/graphic/g3d/Material.h
        src/karint/graphic/gl/UniformBlockBuffer.cpp
        src/karint/graphic/gl/UniformBlockBuffer.h
        vertices.h
        src/karint/ecs/Entity.cpp
        src/karint/ecs/Entity.h
        src/karint/ecs/Component.cpp
        src/karint/ecs/Component.h
        src/karint/ecs/EcsHandler.cpp
        src/karint/ecs/EcsHandler.h
        src/karint/graphic/pipeline/RenderPipeline.cpp
        src/karint/graphic/pipeline/RenderPipeline.h
        src/karint/graphic/pipeline/RenderUnit.cpp
        src/karint/graphic/pipeline/RenderUnit.h
        src/karint/graphic/pipeline/units/ColorUnit.cpp
        src/karint/graphic/pipeline/units/ColorUnit.h src/karint/graphic/pipeline/units/CameraUnit.cpp src/karint/graphic/pipeline/units/CameraUnit.h src/karint/graphic/pipeline/units/AmbientUnit.cpp src/karint/graphic/pipeline/units/AmbientUnit.h src/karint/graphic/pipeline/units/DiffuseLightUnit.cpp src/karint/graphic/pipeline/units/DiffuseLightUnit.h)



add_executable(KarintEngine main.cpp ${ENGINE_SOURCE})

if (UNIX)
    #gtk
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
    # Setup CMake to use GTK+, tell the compiler where to look for headers
    # and to the linker where to look for libraries
    include_directories(${GTK3_INCLUDE_DIRS})
    link_directories(${GTK3_LIBRARY_DIRS})
    # Add other flags to the compiler
    add_definitions(${GTK3_CFLAGS_OTHER})
    # Add an executable compiled from KarintEngine.c

    # Link the target to the GTK+ libraries
    target_link_libraries(KarintEngine ${GTK3_LIBRARIES})
endif ()


# glm
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
