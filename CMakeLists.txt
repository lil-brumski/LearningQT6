cmake_minimum_required(VERSION 3.30)
project(LearningQT6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    src/main.cpp
    src/ChapterOne.cpp
    src/ChapterTwo.cpp
)

set(HEADER_FILES
    include/ChapterOne.hpp
    include/ChapterTwo.hpp
)

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
)
