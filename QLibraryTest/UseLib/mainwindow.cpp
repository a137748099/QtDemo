#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLibrary>
#include <QDebug>
#include "cpplib.h"

using addFunc = int (*)(int, int);
using cppFunc = void *(*)();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QLibrary lib("CppLib");
    if(!lib.load()) {
        qDebug() << __FUNCTION__ << "song" << "load err";
        return;
    }

    auto func = (addFunc)lib.resolve("MyAdd");
    auto val = func(1, 2);
    qDebug() << __FUNCTION__ << "song" << val;
}


void MainWindow::on_pushButton_2_clicked()
{
    QLibrary lib("CppLib");
    if(!lib.load()) {
        qDebug() << __FUNCTION__ << "song" << "load err";
        return;
    }

    auto func = (cppFunc)lib.resolve("createCppLib");
    TestLib *cppLibObj = static_cast<TestLib *>(func());
    if(cppLibObj) {
        qDebug() << __FUNCTION__ << "song" << cppLibObj->add(2,3);
    }
}

