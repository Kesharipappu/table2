// sqlitehelper.h
#ifndef SQLITEHELPER_H
#define SQLITEHELPER_H

#include <QObject>
#include <QtSql>

class SQLiteHelper : public QObject
{
    Q_OBJECT

public:
    explicit SQLiteHelper(QObject *parent = nullptr);

    bool openDatabase(const QString &databasePath);
    QList<QObject *> getPeople();

private:
    QSqlDatabase m_database;
};

#endif // SQLITEHELPER_H
