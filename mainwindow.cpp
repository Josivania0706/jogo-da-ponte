#include "mainwindow.h"
#include "ui_mainwindow.h"

int tempo = 60;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, ui->openGLWidget, &canvas::rotacao);

    connect(timer, &QTimer::timeout, ui->openGLWidget, &canvas::direcionamento);
    timer->start(70);
}

MainWindow::~MainWindow()
{
    delete ui;
}



