cmake_minimum_required(VERSION 3.8)
project(Group21RPS)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        Makefile
        paper.cpp
        paper.hpp
        rock.cpp
        rock.hpp
        RPSGame.cpp
        RPSGame.hpp
        scissors.cpp
        scissors.hpp
        tool.cpp
        tool.hpp Rock.cpp Rock.hpp
        validChar.cpp
        utilities.cpp
        )

add_executable(Group21RPS ${SOURCE_FILES})