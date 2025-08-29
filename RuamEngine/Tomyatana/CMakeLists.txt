set(TOMY_EXE_NAME "Tomy-Audio")
set(CMAKE_CXX_STANDARD 17)

file(GLOB TOMY_SRC "${CMAKE_SOURCE_DIR}/Tomyatana/src/*.cpp")

add_executable(${TOMY_EXE_NAME} ${TOMY_SRC})

target_link_libraries(${TOMY_EXE_NAME} PRIVATE RuamCore)
