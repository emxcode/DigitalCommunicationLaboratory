#include "MainWindow.h"
#include "ui_MainWindow.h"

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

void MainWindow::makeRandomBit(int bitNumber)
{
    srand(time(NULL));

    for (int i = 0; i < bitNumber; i++)
    {
        int generatedBit = ((int)rand() % 2);
        m_bineryVector.push_back(generatedBit);
    }
    showVector(m_bineryVector);
}

void MainWindow::addNormalNoise(std::vector<double> randomBitList)
{
    std::default_random_engine de(time(NULL)); //seed
    std::normal_distribution<double> nd(0.0,1.0); //mean followed by stdiv

    for(int i = 0; i < int(randomBitList.size()); i++)
    {
        randomBitList[i] += nd(de);
    }
    showVector(randomBitList);
}

void MainWindow::detectBits(std::vector<double> randomBitList)
{

    for (int i = 0; i < int(randomBitList.size()) ; i++)
    {
        if(randomBitList[i] > 0.5)
        {
            m_detectedBitList.push_back(1);
        }
        else if(randomBitList[i] < 0.5)
        {
            m_detectedBitList.push_back(0);
        }
    }
    showVector(m_detectedBitList);
}

void MainWindow::showVector(std::vector<double> myVector)
{
    for (int i = 0; i < int(myVector.size()); i++)
    {
        std::cerr << "/" <<myVector[i];
    }
}

void MainWindow::showVectorFloat(std::vector<float> myVector)
{
    for (int i = 0; i < int(myVector.size()); i++)
    {
        std::cerr << "/" << myVector[i];
    }
}


void MainWindow::on_pushButton_clicked()
{
    makeRandomBit(10);
}

void MainWindow::on_pushButtonAddNormalNoise_clicked()
{
    addNormalNoise(m_bineryVector);
}

void MainWindow::on_pushButtonDetection_clicked()
{
    detectBits(m_bineryVector);
}

void MainWindow::on_pushButtonErrorRate_clicked()
{
    int errorNumber = 0;
    float res = 0.0;
    for (int i = 0; i < int(m_bineryVector.size()); i++)
    {
        if(m_bineryVector[i] != m_detectedBitList[i])
        {
            errorNumber++;
        }
    }
    res = errorNumber/m_bineryVector.size();
    ui->labelErrorRate->setText(QString::number(errorNumber));

}
