#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <iostream>
#include <libpq-fe.h>

class DatabaseManager {
public:
    DatabaseManager(const std::string& host, const std::string& port, const std::string& dbname, const std::string& user, const std::string& password);
    ~DatabaseManager();

    bool connect();
    void disconnect();
    bool isConnected() const;

    bool executeQuery(const std::string& query);
    PGresult* executeQueryWithResult(const std::string& query);

private:
    PGconn* connection_;
    std::string host_;
    std::string port_;
    std::string dbname_;
    std::string user_;
    std::string password_;
};

#endif  // DATABASEMANAGER_H
