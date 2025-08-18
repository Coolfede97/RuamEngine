# CMakeList.txt : CMake project for RuamEngine, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8...4.1.0)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Requerido por Tomy para poder usar lsp
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project ("RuamEngine")
# Add source to this project's executable.
add_executable (RuamEngine "RuamEngine.cpp" "RuamEngine.h")

add_subdirectory(CoolFede97)
add_subdirectory(Santinorua)
add_subdirectory(Skuerjuan)

# -----------------------------------------------------------------------------------------------------
#######################################################################################################
#######################################################################################################
# -----------------------------------------------------------------------------------------------------


# Libraries paths depending on the configuration (x86 or x64 Debug)

set(VENDOR_PATH "${CMAKE_SOURCE_DIR}/vendor")
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(GLFW_SRC_PATH "${VENDOR_PATH}/GLFW/lib-vc2022/x64")
    set(GLFW_INCLUDE_PATH "${VENDOR_PATH}/GLFW/include/x64")
    set(GLEW_SRC_PATH "${VENDOR_PATH}/GLEW/lib/x64")
    set(GLEW_INCLUDE_PATH "${VENDOR_PATH}/GLEW/include/x64")

else()
    set(GLFW_SRC_PATH "${VENDOR_PATH}/GLFW/lib-vc2022/x86")
    set(GLFW_INCLUDE_PATH "${VENDOR_PATH}/GLFW/include/x86")
    set(GLEW_SRC_PATH "${VENDOR_PATH}/GLEW/lib/x86")
    set(GLEW_INCLUDE_PATH "${VENDOR_PATH}/GLEW/include/x86")
endif()


# -----------------------------------------------------------------------------------------------------
#######################################################################################################
#######################################################################################################
# -----------------------------------------------------------------------------------------------------

# Vendor

add_library(Vendor INTERFACE)


target_link_directories(Vendor INTERFACE
	${GLEW_SRC_PATH}
)

target_include_directories(Vendor INTERFACE 
	${GLEW_INCLUDE_PATH}
	${CMAKE_SOURCE_DIR}/vendor/GLM
	${CMAKE_SOURCE_DIR}/vendor/stb_image
	${CMAKE_SOURCE_DIR}/vendor/IMGUI
)

target_compile_definitions(Vendor INTERFACE STB_IMAGE_IMPLEMENTATION)
target_compile_definitions(Vendor INTERFACE GLEW_STATIC)


# ///////////////////////////////////////////////////////////////////////////////////////////////

# IMGUI

# In order to use a library which has cpp and h files, you need to create a library (add_library) and
# give it a source path (with the cpp files). 
file (GLOB IMGUI_SRC "${VENDOR_PATH}/IMGUI/*.cpp")
add_library(ImGui STATIC ${IMGUI_SRC})
# In this case, the library has #include <AnotherLibrary> in its cpp files, like GLFW or GLEW, so 
# we need to indicate where those glfw.h and glew.h files are.
target_include_directories(ImGui PRIVATE
    ${GLEW_INCLUDE_PATH}
    ${GLFW_INCLUDE_PATH}
)
# Lastly, add this new library to the function target_link_directories and also provice the path to 
# the h files to the target_include_directories function

# ///////////////////////////////////////////////////////////////////////////////////////////////

# GLFW

add_library(GLFW INTERFACE)
target_link_directories(GLFW INTERFACE ${GLFW_SRC_PATH})
target_include_directories(GLFW INTERFACE ${GLFW_INCLUDE_PATH})

target_link_directories(Vendor INTERFACE
    ${GLEW_SRC_PATH}
)
# ///////////////////////////////////////////////////////////////////////////////////////////////

# Linking
if (UNIX)
    target_link_libraries(Vendor INTERFACE
        glfw GLEW ImGui GL
    )
endif()
if (WIN32)
target_link_libraries(GLFW INTERFACE ${GLFW_SRC_PATH}/glfw3.lib)
    target_link_libraries(Vendor INTERFACE
        GLFW opengl32 ${GLEW_SRC_PATH}/glew32s.lib ImGui
    )
endif()
target_include_directories(Vendor INTERFACE 
    ${GLEW_INCLUDE_PATH}
    ${VENDOR_PATH}/GLM
    ${VENDOR_PATH}/stb_image
    ${VENDOR_PATH}/IMGUI
)

target_compile_definitions(Vendor INTERFACE STB_IMAGE_IMPLEMENTATION)
target_compile_definitions(Vendor INTERFACE GLEW_STATIC)

# -----------------------------------------------------------------------------------------------------
#######################################################################################################
#######################################################################################################
# -----------------------------------------------------------------------------------------------------


add_library(RuamCore INTERFACE)


# -----------------------------------------------------------------------------------------------------

# Rendering

file (GLOB RENDERING_SRC "${CMAKE_SOURCE_DIR}/RuamCore/Rendering/*.cpp")
add_library(Rendering STATIC ${RENDERING_SRC})
target_link_libraries(Rendering PUBLIC Vendor Files Maths)
target_include_directories(Rendering INTERFACE ${CMAKE_SOURCE_DIR}/RuamCore/Rendering)

# ///////////////////////////////////////////////////////////////////////////////////////////////

# Maths

# -----------------------------------------------------------------------------------------------------

# Vec

file (GLOB VEC_SRC "${CMAKE_SOURCE_DIR}/RuamCore/Maths/Vec/*.cpp")
add_library(Vec STATIC ${VEC_SRC})
target_include_directories(Vec PUBLIC ${CMAKE_SOURCE_DIR}/RuamCore/Maths/Vec)

# -----------------------------------------------------------------------------------------------------

add_library(Maths INTERFACE)
target_link_libraries(Maths INTERFACE Vec)

# ///////////////////////////////////////////////////////////////////////////////////////////////

# Time

file (GLOB TIME_SRC "${CMAKE_SOURCE_DIR}/RuamCore/Time/*.cpp")
add_library(Time STATIC ${TIME_SRC})
target_link_libraries(Time PUBLIC GLFW)
target_include_directories(Time INTERFACE ${CMAKE_SOURCE_DIR}/RuamCore/Time)

# ///////////////////////////////////////////////////////////////////////////////////////////////

# Objects

file (GLOB OBJECTS_SRC "${CMAKE_SOURCE_DIR}/RuamCore/Objects/*.cpp")
add_library(Objects STATIC ${OBJECTS_SRC})
target_include_directories(Objects INTERFACE ${CMAKE_SOURCE_DIR}/RuamCore/Objects)

# ///////////////////////////////////////////////////////////////////////////////////////////////

# Files

file (GLOB FILES_SRC "${CMAKE_SOURCE_DIR}/RuamCore/Files/*.cpp")
add_library(Files STATIC ${FILES_SRC})
target_compile_definitions(Files PUBLIC PROJECT_ROOT_DIR="${CMAKE_SOURCE_DIR}")
target_include_directories(Files INTERFACE ${CMAKE_SOURCE_DIR}/RuamCore/Files)


# ///////////////////////////////////////////////////////////////////////////////////////////////

# Input

file (GLOB INPUT_SRC "${CMAKE_SOURCE_DIR}/RuamCore/Input/*.cpp")
add_library(Input STATIC ${INPUT_SRC})
target_link_libraries(Input PUBLIC Rendering Maths)
target_include_directories(Input INTERFACE ${CMAKE_SOURCE_DIR}/RuamCore/Input)


# /////////////////////////////////////////////////////////////////////////////////////////////// 

# Linking

target_link_libraries(RuamCore INTERFACE 
	Rendering Maths Time Files Input Objects
)


# -----------------------------------------------------------------------------------------------------
#######################################################################################################
#######################################################################################################
# -----------------------------------------------------------------------------------------------------




# -----------------------------------------------------------------------------------------------------
#######################################################################################################
#######################################################################################################
# -----------------------------------------------------------------------------------------------------


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET RuamEngine PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(RuamEngine PUBLIC RuamCore)

# TODO: Add tests and install targets if needed.
