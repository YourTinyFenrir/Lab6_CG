#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {

    ui->setupUi(this);
    scene.show();

}

MainWindow::~MainWindow() {

    delete ui;

}

void MainWindow::on_createCube_clicked() {

    scene.setAngleOX(-1);
    scene.setAngleOY(-1);
    scene.repaint();

}

void MainWindow::on_rotateCube_clicked() {

    scene.setAngleOX(ui->angleOX->value());
    scene.setAngleOY(ui->angleOY->value());
    scene.repaint();

}
