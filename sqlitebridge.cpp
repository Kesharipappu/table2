// sqlitehelper.cpp
#include <sqlitehelper.h>
#include <QObject>
#include <Sqlitehelper.h>

SQLiteHelper::SQLiteHelper(QObject *parent) : QObject(parent)
{
}

bool SQLiteHelper::openDatabase(const QString &databasePath)
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(databasePath);
    return m_database.open();
}

QList<QObject *> SQLiteHelper::getPeople()
{
    QList<QObject *> people;

    QSqlQuery query("SELECT name, age FROM my_table", m_database);
    while (query.next()) {
        QObject *person = new QObject();
        person->setProperty("name", query.value("name").toString());
        person->setProperty("age", query.value("age").toInt());
        people.append(person);
    }

    return people;
}
