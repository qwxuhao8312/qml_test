#ifndef GEMINI_H
#define GEMINI_H
// Gemini.h
#include <QObject>
#include <QDebug>
class Gemini : public QObject
{
    Q_OBJECT
    Q_ENUMS(BALL_COLOR)
    Q_PROPERTY(unsigned int ballNumber READ ballNumber WRITE setBallNumber NOTIFY ballNumberChanged)
public:
    Gemini() : m_ballColor(BALL_COLOR_YELLOW), m_ballNumber(0) {
        qDebug() << "Gemini::Gemini() called";
    }
    enum BALL_COLOR {
        BALL_COLOR_YELLOW,
        BALL_COLOR_RED,
        BALL_COLOR_BLUE,
        BALL_COLOR_ALL
    };
    unsigned int ballNumber() const {
        return m_ballNumber;
    }
    void setBallNumber(const unsigned int &ballNumber) {
        if(ballNumber != m_ballNumber) {
            m_ballNumber = ballNumber;
            emit ballNumberChanged();
        }
    }
    Q_INVOKABLE void stop() {
        qDebug() << "Gemini::stop() called";
    }
signals:
    void begin();
    void ballNumberChanged();
public slots:
    void doSomething(BALL_COLOR ballColor) {
        qDebug() << "Gemini::doSomething() called with" << ballColor;
        if(ballColor != m_ballColor) {
            m_ballColor = ballColor;
            qDebug() << "ball color changed";
        }
    }
private:
    BALL_COLOR m_ballColor;
    unsigned int m_ballNumber;
};
#endif // GEMINI_H
