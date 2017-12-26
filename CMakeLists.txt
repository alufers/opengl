# CMake entry point
cmake_minimum_required (VERSION 3.1)
project (opengl)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()


# Compile external dependencies 
add_subdirectory (external)
set(CMAKE_BUILD_TYPE Debug)

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED network audio graphics window system)

find_package( Boost 1.40 COMPONENTS filesystem REQUIRED )

include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/GLFW/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/
	.
	${SFML_INCLUDE_DIR}
	${Boost_INCLUDE_DIR}
)

add_subdirectory(external/variant)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
	${SFML_LIBRARIES} 
	${SFML_DEPENDENCIES}
	mpark_variant
	${Boost_LIBRARIES}
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
	-DSTB_IMAGE_IMPLEMENTATION
)


# User playground
add_executable(app 
	src/main.cpp
	src/Display.cpp
	src/Geometry.cpp
	src/Material.cpp
	src/AssetManager.cpp
	src/ShaderProgram.cpp
)
target_link_libraries(app
	${ALL_LIBS}
)
# Xcode and Visual working directories


