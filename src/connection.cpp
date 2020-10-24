#include "connection.h"

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardPaths>

Connection::Connection()
{   
    const QString DB_PATH = QDir::currentPath() + "/presets.db";

    if(!QFile::exists(DB_PATH))
    {
        qDebug() << "File does not exist:" << DB_PATH;
    }

    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName(DB_PATH);

    if (!m_db.open())
    {
        qDebug() << "Could not establish connection to the database";
        return;
    }

    QString query = "CREATE TABLE IF NOT EXISTS `presets` ("
                        "`id`	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                        "`title`	TEXT,"
                        "`search_str`	TEXT,"
                        "`replace_str`	TEXT"
                    ");";

    QSqlQuery q(query);

    if (!q.exec()) {
        qDebug() << "Could not execute test SQL query. Database connection was unsuccessfull";
        return;
    }
}

Connection& Connection::getInstance()
{
    static Connection instance;
    return instance;
}

QSqlDatabase& Connection::getDB()
{
    return m_db;
}
