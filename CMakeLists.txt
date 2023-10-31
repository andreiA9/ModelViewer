cmake_minimum_required(VERSION 3.1)

# numele PROIECTULUI
set(PROJECT_NAME ModelViewer)
project(${PROJECT_NAME})

# INSTRUCT CMake to call COMPILER=MOC automatically
set(CMAKE_AUTOMOC ON)
# NU SE stie de ce ai adaugat o
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(Application)
add_subdirectory(MainWindow)
add_subdirectory(GlModule)

