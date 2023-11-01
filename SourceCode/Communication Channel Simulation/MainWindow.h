#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <random>
#include <time.h>
#include <stdlib.h>
#include "QString"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonAddNormalNoise_clicked();

    void on_pushButtonDetection_clicked();

    void on_pushButtonErrorRate_clicked();

private:
    Ui::MainWindow *ui;

    std::vector<double> m_bineryVector;
    std::vector<double> m_detectedBitList;


    void makeRandomBit(int bitNumber);
    void addNormalNoise(std::vector<double> randomBitList);
    void detectBits(std::vector<double> randomBitList);

    void showVector(std::vector<double>myVector);
    void showVectorFloat(std::vector<float>myVector);
};
#endif // MAINWINDOW_H
