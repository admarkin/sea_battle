cmake_minimum_required(VERSION 3.27)
project(seabattle)

set(CMAKE_CXX_STANDARD 17)

add_executable(seabattle main.cpp
        iship.h
        ship_1.h
        ship_2.h
        ship_3.h
        ship_4.h
        person.h
        battle.h
        src/battle.cpp
        flot.h
        factory.h
        src/factory.cpp
)
