cmake_minimum_required(VERSION 3.2)

project(ExampleProg LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20) 
set(SOURCE_EXE main.cpp)

include_directories(./bitarr_dir)
# Расположение заголовочных файлов
# (будет доступно всем target'ам проекта)
# Альтернатива: target_include_directories

add_executable(Example ${SOURCE_EXE})

add_subdirectory(./bitarr_dir)
# Добавление подпроекта, указывается имя дирректории
# в этой директории должен быть свой небольшой CMakeLists.txt

# Линковка программы с библиотеками
target_link_libraries(Example bitarr)
# после названия цели (Example) идёт перечисление библиотек