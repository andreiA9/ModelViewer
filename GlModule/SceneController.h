#ifndef SCENE_CONTROLLER_H
#define SCENE_CONTROLLER_H

#include <QPointF>

struct Rect
{
    float   left;
    float   top;
    float   right;
    float   bottom;
};

struct Triangle
{
    float   topX;
    float   topY;
    float   bottomLeftX;
    float   bottomLeftY;
    float   bottomRightX;
    float   bottomRightY;
};

class SceneController
{
public:
    SceneController();

    static void drawRectangle(Rect spotRectangle);

    static void drawTriangle(Triangle triangle, bool translate, bool scale, bool rotate,
                             QPointF rotateCoordinates);

    static void drawEmptyRectangle(Rect spotRectangle);

    static void drawLine(Rect spotRectangle);
};

#endif // SCENE_CONTROLLER_H
