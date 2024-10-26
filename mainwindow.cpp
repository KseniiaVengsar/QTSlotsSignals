#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Stopwatch.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_stopwatch(new Stopwatch(this))
{
    ui->setupUi(this);

    connect(ui->startStopButton, &QPushButton::clicked, this, &MainWindow::onStartStopClicked);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    connect(ui->lapButton, &QPushButton::clicked, this, &MainWindow::onLapClicked);

    connect(m_stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateDisplay);

    ui->lapButton->setEnabled(false); 
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartStopClicked()
{
    if (m_stopwatch->isRunning()) {
        m_stopwatch->stop();
        ui->startStopButton->setText("Старт");
        ui->lapButton->setEnabled(false);
    } else {
        m_stopwatch->start();
        ui->startStopButton->setText("Стоп");
        ui->lapButton->setEnabled(true);
    }
}

void MainWindow::onResetClicked()
{
    m_stopwatch->reset();
    ui->lapBrowser->clear();
    ui->startStopButton->setText("Старт");
    ui->lapButton->setEnabled(false);
}

void MainWindow::onLapClicked()
{
    int lapTime = m_stopwatch->lastLapTime(); 
    int lapNumber = m_stopwatch->lapCount() + 1; 
    ui->lapBrowser->append(QString("Круг %1, время: %2 сек").arg(lapNumber).arg(lapTime / 1000.0, 0, 'f', 1));
    m_stopwatch->lap(); 
}

void MainWindow::updateDisplay(int ms)
{
    int seconds = (ms / 1000) % 60;
    int minutes = (ms / 60000);
    int tenths = (ms % 1000) / 100;
    ui->timeLabel->setText(QString("%1:%2.%3")
                           .arg(minutes, 2, 10, QLatin1Char('0'))
                           .arg(seconds, 2, 10, QLatin1Char('0'))
                           .arg(tenths));
}
