#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <Gemini.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<Gemini>("Union.Lotto.Gemini", 1, 0, "Gemini");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
