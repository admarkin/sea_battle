cmake_minimum_required(VERSION 3.27)
project(seabattle)

set(CMAKE_CXX_STANDARD 17)

add_executable(seabattle main.cpp
        iship.h
        ship_one_cell.h
        ship_two_cells.h
        ship_three_cells.h
        ship_four_cells.h
        person.h
        battle.h
        src/battle.cpp
        factory.h
        src/factory.cpp
        fleet.h
)
