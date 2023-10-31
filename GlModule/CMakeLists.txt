set(Qt5_Application_Components Core Widgets REQUIRED)
find_package(Qt5 COMPONENTS ${Qt5_Application_Components})

set(GlModule_SRC
    GlWidget.cpp
    GlWidget.h
    SceneController.cpp
    SceneController.h
    Events.cpp
    Events.h
    GlModule.cpp
    GlModule.h
)

add_library(GlModule_static
    ${GlModule_SRC}
)

target_include_directories(GlModule_static
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    )

# NEEDED for OpenGl
find_package(OpenGL REQUIRED)
#find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
#include_directories( ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} )

#target_link_libraries(ModelViewer ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
target_link_libraries(GlModule_static PRIVATE
    Qt5::Widgets        # -> Widgets
    Qt5::Core           # -> Core
    ${OPENGL_LIBRARIES}
    )
