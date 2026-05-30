cmake_minimum_required(VERSION 3.22.0)
project(MyProject)

# Создаём динамическую библиотеку (SHARED)
set(HEADERS_FILES Functions.h)
set(SOURCES_FILES Functions.cpp)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Functions STATIC ${HEADERS_FILES} ${SOURCES_FILES})

# Создаём исполняемый файл приложения
add_executable(MyProject Source.cpp)

# Линкуем динамическую библиотеку к приложению
target_link_libraries(MyProject PRIVATE Functions)