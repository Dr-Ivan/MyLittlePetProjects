cmake_minimum_required(VERSION 3.10.0)
project(15 VERSION 0.1.0 LANGUAGES C CXX)

# Настройки стандарта C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# Поиск FLTK с явным указанием на статическую линковку
find_package(FLTK REQUIRED NO_MODULE)
include_directories(${FLTK_INCLUDE_DIRS}) 
link_directories(${FLTK_LIBRARY_DIRS}) 
add_definitions(${FLTK_DEFINITIONS})

# Настройки для Windows
if(WIN32)
    # Статическая линковка всех библиотек (включая C++ runtime)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++ -mwindows")
    
    # Дополнительные системные библиотеки, необходимые для FLTK
    set(EXTRA_LIBS ole32 uuid comctl32)
endif()

# # Исходники (закомментированный вариант)
# file(GLOB_RECURSE GAME_SOURCES
#     "ControllerFiles/*.cpp"
#     "ModelFiles/*.cpp"
#     "UtilityFiles/*.cpp"
#     "ViewFiles/*.cpp"
#     "main.cpp"
# )

# # Заголовочные файлы (закомментированный вариант)
# file(GLOB_RECURSE GAME_HEADERS
#     "ControllerFiles/*.hpp"
#     "ModelFiles/*.hpp"
#     "UtilityFiles/*.hpp"
#     "ViewFiles/*.hpp"
# )

# # Исполняемый файл 
# add_executable(game15 ${GAME_SOURCES} ${GAME_HEADERS})

# Исходники
add_executable(game15 
    main.cpp 
    GameView.hpp GameView.cpp 
    MatrixModel.hpp MatrixModel.cpp 
    Controller.hpp Controller.cpp 
    EndGameMessage.hpp EndGameMessage.cpp)

# Линковка с FLTK и дополнительными библиотеками
target_link_libraries(game15 
    fltk 
    fltk_images 
    ${EXTRA_LIBS})

# Настройки тестирования
include(CTest)
enable_testing()