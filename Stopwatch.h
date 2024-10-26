#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    void lap();

    bool isRunning() const;

    int elapsedTime() const; // Время с начала работы секундомера в миллисекундах
    int lastLapTime() const; // Время последнего круга
    int lapCount() const;     // Количество кругов

signals:
    void timeUpdated(int ms); // Сигнал для обновления времени

private slots:
    void update(); // Обновление времени

private:
    QTimer *m_timer;
    int m_elapsedTime;
    int m_lastLapTime;
    int m_lapCount;
    bool m_running;
};

#endif // STOPWATCH_H
