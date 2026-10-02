cmake_minimum_required(VERSION 3.20)
get_filename_component(_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${_name} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# -DSANITIZE=address | thread | undefined
set(SANITIZE "" CACHE STRING "Sanitizer")

# общие флаги для C и C++ целей
add_compile_options(-Wall -Wextra -Wpedantic)
if(SANITIZE)
  add_compile_options(-fsanitize=${SANITIZE} -fno-omit-frame-pointer -g)
  add_link_options(-fsanitize=${SANITIZE})
endif()

find_package(Threads REQUIRED)
find_package(OpenMP REQUIRED COMPONENTS C CXX)
find_package(TBB QUIET)
find_package(MPI QUIET COMPONENTS CXX)

# C-часть: src/c/*.c -> статическая библиотека clib, интерфейс в include/clib.h
file(GLOB_RECURSE C_SRC CONFIGURE_DEPENDS src/c/*.c)
if(C_SRC)
  add_library(clib STATIC ${C_SRC})
  target_include_directories(clib PUBLIC include)
  target_link_libraries(clib PUBLIC OpenMP::OpenMP_C)
endif()

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS src/*.cpp)
add_executable(app ${SRC})
target_include_directories(app PRIVATE include)
target_link_libraries(app PRIVATE Threads::Threads OpenMP::OpenMP_CXX)

if(TARGET clib)
  target_link_libraries(app PRIVATE clib)
endif()
if(TBB_FOUND)
  target_link_libraries(app PRIVATE TBB::tbb)
endif()
if(MPI_CXX_FOUND)
  target_link_libraries(app PRIVATE MPI::MPI_CXX)
endif()
