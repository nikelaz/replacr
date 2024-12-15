#include "connection.h"

#include <QFile>
#include <QDir>
#include <QDebug>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>

Connection::Connection()
{
    QString appDataLocation = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QString expectedDbLocation = appDataLocation + "/presets.db";
    const QString DB_PATH = appDataLocation + "/presets.db";

    if(!QFile::exists(DB_PATH))
    {
        if (!QDir(appDataLocation).exists()) {
            QDir().mkdir(appDataLocation);
        }
        QFile::copy(QDir::currentPath() + "/presets-template.db", expectedDbLocation);
        qDebug() << "Database file does not exist. Creating from template." << DB_PATH;
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
