#include "square.h"

Square::Square() {

}

Square::Square(QVector<QVector4D> pts) {

    vertex = pts;

    if (vertex[2].z() != vertex[0].z())
        centerZ = ((vertex[2].z() - vertex[0].z()) / 2) + vertex[0].z();
    else
        centerZ = vertex[0].z();

}

const Square Square::operator=(const Square &temp) {

    this->vertex = temp.vertex;
    this->centerZ = temp.centerZ;

    return *this;

}

void Square::draw(float r, float g, float b) {

    GLfloat color[] = {r, g, b, 1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);

    glBegin(GL_POLYGON);

    /*QVector4D normal = vertex[vertex.size() - 1];
    glNormal3f(normal.x(), normal.y(), normal.z());*/

    for (int i = 0; i < vertex.size(); ++i)
        glVertex3f(vertex[i].x(), vertex[i].y(), vertex[i].z());

    glEnd();

}

float Square::getCenterZ() {

    return centerZ;

}

