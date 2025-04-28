cmake_minimum_required(VERSION 3.10.0)
project(15 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIRS}) 
link_directories(${FLTK_LIBRARY_DIRS}) 
add_definitions(${FLTK_DEFINITIONS})

# # Исходники
# file(GLOB_RECURSE GAME_SOURCES
#     "ControllerFiles/*.cpp"
#     "ModelFiles/*.cpp"
#     "UtilityFiles/*.cpp"
#     "ViewFiles/*.cpp"
#     "main.cpp"
# )

# # Заголовочные файлы
# file(GLOB_RECURSE GAME_HEADERS
#     "ControllerFiles/*.hpp"
#     "ModelFiles/*.hpp"
#     "UtilityFiles/*.hpp"
#     "ViewFiles/*.hpp"
# )

# add_executable(game15 ${GAME_SOURCES} ${GAME_HEADERS})

add_executable(game15 main.cpp GameView.hpp GameView.cpp)

target_link_libraries(game15 fltk fltk_images)


include(CTest)
enable_testing()
