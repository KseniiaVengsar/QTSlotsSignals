#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Stopwatch.h"

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
    void onStartStopClicked();
    void onResetClicked();
    void onLapClicked();
    void updateDisplay(int ms);

private:
    Ui::MainWindow *ui;
    Stopwatch *m_stopwatch;
};

#endif // MAINWINDOW_H

