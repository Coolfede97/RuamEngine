# CMakeList.txt : CMake project for RuamEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("RuamEngine")

# Add source to this project's executable.
add_executable (RuamEngine "RuamEngine.cpp" "RuamEngine.h")

add_subdirectory(CoolFede97)

add_library(RuamCore INTERFACE)

target_link_directories(RuamCore INTERFACE
	${CMAKE_SOURCE_DIR}/libs/GLFW/lib-vc2022
	${CMAKE_SOURCE_DIR}/libs/GLEW/lib
)

target_link_libraries(RuamCore INTERFACE
	glfw3 opengl32 glew32s 
)

target_include_directories(RuamCore INTERFACE 
	${CMAKE_SOURCE_DIR}/libs/GLFW/include
	${CMAKE_SOURCE_DIR}/libs/GLEW/include
	${CMAKE_SOURCE_DIR}/libs/GLM
)

target_compile_definitions(RuamCore INTERFACE GLEW_STATIC)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RuamEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
