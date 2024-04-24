cmake_minimum_required(VERSION 3.2)
project(bitarr)
set(SOURCE_LIB bitarr.cpp)
# Создание статической библиотеки
add_library(bitarr STATIC ${SOURCE_LIB})
# если написать SHARED, то будет динамическая