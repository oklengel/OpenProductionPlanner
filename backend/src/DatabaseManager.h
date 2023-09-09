#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <iostream>
#include <libpq-fe.h> 
#include <pqxx/pqxx> 
#include <fstream>    
#include <sstream>    
#include <string>

#include "supportFunctions/stringTools.h"
#include "../extern/LibEnv/Env.h"

class DatabaseManager {
public:
  DatabaseManager(); // Hier sollte der Klassenname "DatabaseManager" angegeben werden.
  ~DatabaseManager();
};

#endif // DATABASEMANAGER_H
