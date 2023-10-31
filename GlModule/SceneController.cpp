#include "SceneController.h"

//#include <GL/glut.h>
#include <GL/gl.h>

// GCC COMMAND in Linux
// gcc glut1.cpp -o glut1 -L/usr/X11R6/lib -lglut -lGLU -lGL -lX11 -lXmu -lXi

SceneController::SceneController()
{

}

void SceneController::drawRectangle(Rect spotRectangle)
{
    glBegin(GL_QUADS);
    glVertex2f(spotRectangle.right, spotRectangle.top);
    glVertex2f(spotRectangle.right, spotRectangle.bottom);
    glVertex2f(spotRectangle.left, spotRectangle.bottom);
    glVertex2f(spotRectangle.left, spotRectangle.top);
    glEnd();
}

void SceneController::drawEmptyRectangle(Rect spotRectangle)
{
    // 0.0001 ensures that just 1pixel will be added in all directions
    glBegin(GL_LINE_LOOP);
    glVertex2f(spotRectangle.right + 0.0001, spotRectangle.top + 0.0001);
    glVertex2f(spotRectangle.right + 0.0001, spotRectangle.bottom - 0.0001);
    glVertex2f(spotRectangle.left - 0.0001, spotRectangle.bottom - 0.0001);
    glVertex2f(spotRectangle.left - 0.0001, spotRectangle.top + 0.0001);
    glEnd();
}

void SceneController::drawLine(Rect spotRectangle)
{
    glBegin(GL_LINE_LOOP);
    glVertex2f(spotRectangle.left, spotRectangle.top);
    glVertex2f(spotRectangle.right, spotRectangle.bottom);
    glEnd();
}

void SceneController::drawTriangle(Triangle triangle, bool translate, bool scale, bool rotate,
                                   QPointF rotateCoordinates)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (translate)
    {
        // here the coordinates for the rotation have to be
        // reversed, because it is a rotation overt that axis
        glTranslatef(-0.001f, -0.001f, 0.0f); // x is at right / y is above / z is in the back
    }
    else if (rotate)
    {
        // here the coordinates for the rotation have to be
        // reversed, because it is a rotation overt that axis
        glRotatef(-0.5f, rotateCoordinates.y(), rotateCoordinates.x(), 0.0f);
    }

    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(triangle.topX, triangle.topY);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(triangle.bottomLeftX, triangle.bottomLeftY);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(triangle.bottomRightX, triangle.bottomRightY);
    glEnd();
    glFlush();
}
