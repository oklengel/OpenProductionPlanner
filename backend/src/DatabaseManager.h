#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <libpq-fe.h>
#include <pqxx/pqxx>
#include <sstream>
#include <string>

#include "../extern/LibEnv/Env.h"
#include "supportFunctions/stringTools.h"

class DatabaseManager {
public:
  DatabaseManager(const std::string name); // Hier sollte der Klassenname "DatabaseManager"
                               // angegeben werden.
  ~DatabaseManager();


private:

const char *postgresDB;
const char *postgresHOST;
const char *postgresPWD;
const char *postgresUSR;
const char *postgresPORT;

int logLevel;
std::string connectionStr;


};

#endif // DATABASEMANAGER_H
