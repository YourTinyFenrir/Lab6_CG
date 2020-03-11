#include "glscene.h"

GLScene::GLScene() {

    Cube newCube(0.5);
    cube = newCube;
    angleOX = 0;
    angleOY = 0;

}

void GLScene::setAngleOX(float angle) {

    angleOX = angle;

}

void GLScene::setAngleOY(float angle) {

    angleOY = angle;

}

void GLScene::initializeGL() {

    glClearColor(1, 1, 1, 0); // задаем фон окна
    glEnable(GL_DEPTH_TEST); // задаем глубину проверки пикселей
    glEnable(GL_LIGHTING); // расчет освещения
    //glEnable(GL_NORMALIZE);
    glShadeModel(GL_FLAT);
    glDepthFunc(GL_LEQUAL);

}

void GLScene::resizeGL(int w, int h) {

    glViewport(0, 0, h, h); // установка точки обзора
    glMatrixMode(GL_PROJECTION); // установка режима матрицы
    glLoadIdentity(); // загрузка матрицы

}

void GLScene::paintGL() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очистка экрана
    glMatrixMode(GL_MODELVIEW); // задаем модельно-видовую матрицу
    glLoadIdentity();           // загрузка единичную матрицу

    // точечный источник света
    // убывание интенсивности с расстоянием
    // задано функцией f(d) = 1.0 / (0.4 * d * d + 0.2 * d)
    GLfloat light_position[] = {0, 0, -1, 1};

    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.4);

    glColor3f(1, 0, 0);
    glBegin(GL_LINES);

        glVertex3f(0, -1, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(-1, 0, 0);
        glVertex3f(1, 0, 0);

    glEnd();

    if (angleOX == 0 && angleOY == 0) {

        Cube defCube(0.5);
        cube = defCube;
        cube.draw();

    }
    else {

        cube = cube.rotateOX(angleOX);
        cube = cube.rotateOY(angleOY);
        cube.draw();

    }

}


