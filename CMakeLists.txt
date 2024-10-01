cmake_minimum_required(VERSION 3.10)
project(c)

# Setze den C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Füge Include-Verzeichnisse hinzu
include_directories(include)

# Erstelle die Shared Library
add_library(c SHARED src/cpp.cpp src/Downloader.cpp src/sqlite3.c)

# Verlinke die dl-Bibliothek auf Linux
if (UNIX)
    target_link_libraries(c PRIVATE dl)
endif()