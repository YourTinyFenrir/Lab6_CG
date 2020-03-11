#include "cube.h"

Cube::Cube() {

}

Cube::Cube(float a) {

    // Задаем значения, начиная с ближней верхней левой вершины, сначала по часовой верхнюю грань
    // Затем в том же порядке нижнюю грань
    vertex.push_back(QVector4D(0, 0, 0, 1));
    vertex.push_back(QVector4D(0, 0, a, 1));
    vertex.push_back(QVector4D(a, 0, a, 1));
    vertex.push_back(QVector4D(a, 0, 0, 1));
    vertex.push_back(QVector4D(0, a, 0, 1));
    vertex.push_back(QVector4D(0, a, a, 1));
    vertex.push_back(QVector4D(a, a, a, 1));
    vertex.push_back(QVector4D(a, a, 0, 1));

}

Cube::Cube(QVector<QVector4D> pts) {

    vertex = pts;

}

void Cube::draw() {

   QVector<QVector4D> temp;

   temp.push_back(vertex[0]);
   temp.push_back(vertex[3]);
   temp.push_back(vertex[7]);
   temp.push_back(vertex[4]);

   Square front(temp);

   temp.clear();
   temp.push_back(vertex[1]);
   temp.push_back(vertex[2]);
   temp.push_back(vertex[6]);
   temp.push_back(vertex[5]);

   Square back(temp);

   temp.clear();
   temp.push_back(vertex[1]);
   temp.push_back(vertex[2]);
   temp.push_back(vertex[3]);
   temp.push_back(vertex[0]);

   Square top(temp);

   temp.clear();
   temp.push_back(vertex[5]);
   temp.push_back(vertex[6]);
   temp.push_back(vertex[7]);
   temp.push_back(vertex[4]);

   Square bottom(temp);

   temp.clear();
   temp.push_back(vertex[0]);
   temp.push_back(vertex[1]);
   temp.push_back(vertex[5]);
   temp.push_back(vertex[4]);

   Square left(temp);

   temp.clear();
   temp.push_back(vertex[3]);
   temp.push_back(vertex[2]);
   temp.push_back(vertex[6]);
   temp.push_back(vertex[7]);

   Square right(temp);

   QVector<QPair<int,float>> centerZ;

   centerZ.push_back(QPair<int, float>(0, front.getCenterZ()));
   centerZ.push_back(QPair<int, float>(1, back.getCenterZ()));
   centerZ.push_back(QPair<int, float>(2, top.getCenterZ()));
   centerZ.push_back(QPair<int, float>(3, bottom.getCenterZ()));
   centerZ.push_back(QPair<int, float>(4, left.getCenterZ()));
   centerZ.push_back(QPair<int, float>(5, right.getCenterZ()));

   for (int i = 0; i < centerZ.size() - 1; ++i) {
       for (int j = i + 1; j < centerZ.size(); ++j) {
           if (centerZ[i].second < centerZ[j].second) {

               QPair<int, float> temp = centerZ[i];
               centerZ[i] = centerZ[j];
               centerZ[j] = temp;

           }
       }
   }

   for (int i = 0; i < centerZ.size(); ++i) {

       switch(centerZ[i].first) {

       case 0:
           front.draw(1, 0, 0); // Красный
           break;
       case 1:
           back.draw(0.5, 0, 0); // Темнокрасный
           break;
       case 2:
           top.draw(0, 0, 1); // Синий
           break;
       case 3:
           bottom.draw(0, 0, 0.5); // Темносиний
           break;
       case 4:
           left.draw(0, 1, 0); // Зеленый
           break;
       case 5:
           right.draw(0, 0.5, 0); // Темнозеленый
           break;

       }

   }

}

QVector<QVector4D> Cube::multiplyMatrix(QVector<QVector4D> mR) {

    QVector<QVector4D> res;

    QVector4D temp(0, 0, 0, 0);

    for(int i = 0; i < vertex.size(); ++i)
        res.push_back(temp);

    for(int i = 0; i < vertex.size(); ++i) {

        res[i].setX(vertex[i].x() * mR[0].x() + vertex[i].y() * mR[1].x() + vertex[i].z() * mR[2].x() + vertex[i].w() * mR[3].x());
        res[i].setY(vertex[i].x() * mR[0].y() + vertex[i].y() * mR[1].y() + vertex[i].z() * mR[2].y() + vertex[i].w() * mR[3].y());
        res[i].setZ(vertex[i].x() * mR[0].z() + vertex[i].y() * mR[1].z() + vertex[i].z() * mR[2].z() + vertex[i].w() * mR[3].z());
        res[i].setW(vertex[i].x() * mR[0].w() + vertex[i].y() * mR[1].w() + vertex[i].z() * mR[2].w() + vertex[i].w() * mR[3].w());

    }

    return res;

}

Cube Cube::rotateOX(float angle) {

    QVector<QVector4D> tempMatrix;
    QVector<QVector4D> matrixRotation;

    float radAngle = qDegreesToRadians(angle);

    matrixRotation.push_back(QVector4D(1, 0, 0, 0));
    matrixRotation.push_back(QVector4D(0, cos(radAngle), sin(radAngle), 0));
    matrixRotation.push_back(QVector4D(0, -sin(radAngle), cos(radAngle), 0));
    matrixRotation.push_back(QVector4D(0, 0, 0, 1));

    tempMatrix = multiplyMatrix(matrixRotation);
    Cube res(tempMatrix);

    return res;

}

Cube Cube::rotateOY(float angle) {

    QVector<QVector4D> tempMatrix;
    QVector<QVector4D> matrixRotation;

    float radAngle = qDegreesToRadians(angle);

    matrixRotation.push_back(QVector4D(cos(radAngle), 0, -sin(radAngle), 0));
    matrixRotation.push_back(QVector4D(0, 1, 0, 0));
    matrixRotation.push_back(QVector4D(sin(radAngle), 0, cos(radAngle), 0));
    matrixRotation.push_back(QVector4D(0, 0, 0, 1));

    tempMatrix = multiplyMatrix(matrixRotation);
    Cube res(tempMatrix);

    return res;

}



