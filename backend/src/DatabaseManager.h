#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <libpq-fe.h>
#include <pqxx/pqxx>
#include <sstream>
#include <string>



class DatabaseManager {
public:
  DatabaseManager(const std::string name); // Hier sollte der Klassenname "DatabaseManager"
                               // angegeben werden.
  ~DatabaseManager();

  bool transactionWithOutResult(std::string sql);



private:

const char *postgresDB;
const char *postgresHOST;
const char *postgresPWD;
const char *postgresUSR;
const char *postgresPORT;

int logLevel;
std::string connectionStr;

protected:
 pqxx::connection Connection;

};

#endif // DATABASEMANAGER_H
