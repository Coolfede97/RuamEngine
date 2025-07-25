
project("CoolFede97")
set(CMAKE_CXX_STANDARD 17)

add_executable(CoolFede97 src/Application.cpp)

# Tests
file (GLOB TESTS_SRC "${CMAKE_SOURCE_DIR}/CoolFede97/src/tests/tests/*.cpp")
add_library(Tests STATIC ${TESTS_SRC})
target_link_libraries(Tests PUBLIC RuamCore)
target_include_directories(CoolFede97 PRIVATE
    ${CMAKE_SOURCE_DIR}/CoolFede97/src/tests
)

# This RuamCore that is being added is redundant. 
target_link_libraries(CoolFede97 PRIVATE RuamCore Tests)



