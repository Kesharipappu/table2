#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "sqlitehelper.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    SQLiteHelper dbHelper;
    dbHelper.openDatabase("path_to_your_database.db");

    engine.rootContext()->setContextProperty("dbHelper", &dbHelper);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
