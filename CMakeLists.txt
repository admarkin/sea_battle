cmake_minimum_required(VERSION 3.27)
project(seabattle)

set(CMAKE_CXX_STANDARD 17)

add_executable(seabattle main.cpp
        include/iship.h
        include/boat.h
        include/catamaran.h
        include/barge.h
        include/cruiser.h
        include/person.h
        include/battle.h
        src/battle.cpp
        include/factory.h
        src/factory.cpp
        include/fleet.h
        src/barge.cpp
        src/boat.cpp
        src/cruiser.cpp
        src/catamaran.cpp
        src/fleet.cpp
)
