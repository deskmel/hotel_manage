cmake_minimum_required(VERSION 3.10)
project(hotel_1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(hotel_1
    hotel-db.c
    hotel-db.h
    hotel-ll.c
    hotel-ll.h
    hotel-main.c
    hotel-mt.c
    hotel-mt.h
    hotel.h)
