#ifndef GLSCENE_H
#define GLSCENE_H

#include "QOpenGLWidget"
#include "cube.h"

class GLScene : public QOpenGLWidget {

private:
    Cube cube;
    float angleOX;
    float angleOY;

public:
    GLScene(QWidget *parent) : QOpenGLWidget(parent) {}
    GLScene();
    void setAngleOX(float);
    void setAngleOY(float);

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

};

#endif // GLSCENE_H
