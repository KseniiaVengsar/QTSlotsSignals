#include "Stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject(parent),
    m_timer(new QTimer(this)), m_elapsedTime(0), m_lastLapTime(0),
    m_lapCount(0), m_running(false)
{
    connect(m_timer, &QTimer::timeout, this, &Stopwatch::update);
    m_timer->setInterval(100); 
}

void Stopwatch::start()
{
    if (!m_running) {
        m_timer->start();
        m_running = true;
    }
}

void Stopwatch::stop()
{
    if (m_running) {
        m_timer->stop();
        m_running = false;
    }
}

void Stopwatch::reset()
{
    m_elapsedTime = 0;
    m_lastLapTime = 0;
    m_lapCount = 0;
    emit timeUpdated(m_elapsedTime);
}

bool Stopwatch::isRunning() const
{
    return m_running;
}

void Stopwatch::lap()
{
    if (m_running) {
        int currentLapTime = m_elapsedTime - m_lastLapTime;
        m_lastLapTime = m_elapsedTime;
        m_lapCount++;
    }
}

int Stopwatch::elapsedTime() const
{
    return m_elapsedTime;
}

int Stopwatch::lastLapTime() const
{
    return m_elapsedTime - m_lastLapTime;
}

int Stopwatch::lapCount() const
{
    return m_lapCount;
}

void Stopwatch::update()
{
    m_elapsedTime += 100; 
    emit timeUpdated(m_elapsedTime);
}
