cmake_minimum_required(VERSION 3.26)
project(calculator)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Find packages
find_package(Qt6 COMPONENTS Widgets Multimedia REQUIRED)

# Read paths from environment variables
set(MONGOCXX_INCLUDE_DIR $ENV{MONGOCXX_INCLUDE_DIR})
set(BSONCXX_INCLUDE_DIR $ENV{BSONCXX_INCLUDE_DIR})
set(MONGOCXX_LIBRARY $ENV{MONGOCXX_LIBRARY})
set(BSONCXX_LIBRARY $ENV{BSONCXX_LIBRARY})

include_directories(${MONGOCXX_INCLUDE_DIR})
include_directories(${BSONCXX_INCLUDE_DIR})

add_executable(
        calculator
        main.cpp
        Calculator.cpp
        Calculator.h
        Animal.cpp
        Animal.h
        Housecat.cpp
        Housecat.cpp
        Housecat.h
        ClickableLabel.cpp
        ClickableLabel.h
        GameBoard.cpp
        GameBoard.h
        Blueberry.cpp
        Blueberry.h
        BearWidget.cpp
        BearWidget.h
)

# link the Qt6 libraries and MongoDB driver libraries
target_link_libraries(calculator Qt6::Widgets Qt6::Multimedia ${MONGOCXX_LIBRARY} ${BSONCXX_LIBRARY})
