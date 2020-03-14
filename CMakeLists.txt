CMAKE_MINIMUM_REQUIRED(VERSION 3.14)
project(rhoshell)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(rhoshell
    src/main.cpp
    src/Parser.cpp
    src/Semicolon.cpp
    src/Command.cpp
    src/Or.cpp
    src/And.cpp
    src/TestCommand.cpp
)

ADD_EXECUTABLE(test
    unit_tests/unit_test.cpp
    src/Parser.cpp
    src/Semicolon.cpp
    src/Command.cpp
    src/Or.cpp
    src/And.cpp
    src/TestCommand.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
