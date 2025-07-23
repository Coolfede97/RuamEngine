
project("CoolFede97")
set(CMAKE_CXX_STANDARD 17)

add_executable(CoolFede97 src/Application.cpp)

target_link_libraries(CoolFede97 PRIVATE RuamCore)

