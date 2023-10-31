cmake_minimum_required(VERSION 2.8)

# headers included in both[Qt Widgests/Qt QML]
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})

add_executable(${PROJECT_NAME}
    main.cpp
    )

find_package(Qt5 COMPONENTS Core)


target_link_libraries(${PROJECT_NAME} PRIVATE
    MainWindow_static
    )

