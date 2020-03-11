#ifndef CUBE_H
#define CUBE_H

#include "square.h"

class Cube {

private:
    QVector<QVector4D> vertex;
public:
    Cube();
    Cube(float);
    Cube(QVector<QVector4D>);
    void draw();
    QVector<QVector4D> multiplyMatrix(QVector<QVector4D>);
    Cube rotateOX(float);
    Cube rotateOY(float);

};

#endif // CUBE_H
