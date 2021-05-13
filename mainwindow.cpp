#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib> // для функций rand() и srand()
#include <iostream>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
