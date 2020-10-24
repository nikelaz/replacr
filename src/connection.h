#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
private:
    Connection();
    QSqlDatabase m_db;

public:
    static Connection& getInstance();
    QSqlDatabase& getDB();
};

#endif // CONNECTION_H
