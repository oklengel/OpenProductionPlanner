#include "DatabaseManager.h"
/*
DatabaseManager::DatabaseManager(const std::string &host,
                                 const std::string &port,
                                 const std::string &dbname,
                                 const std::string &user,
                                 const std::string &password)
    : connection_(nullptr), host_(host), port_(port), dbname_(dbname),
      user_(user), password_(password) {
  connect();
}*/
DatabaseManager::DatabaseManager()
    : connection_(nullptr), host_(""), port_(""), dbname_(""),
      user_(""), password_("") {
  loadConfigFromFile("config.txt");
  connect();
}
/* 
POSTGRESintPort=3306
POSTGRES_DATABASE="mydb"
POSTGRES_USER="myuser"
POSTGRES_PASSWORD="mypassword"
*/
void DatabaseManager::loadConfigFromFile(const std::string &filename) {
  std::ifstream configFile(filename);
  if (configFile.is_open()) {
    std::string line;
    while (std::getline(configFile, line)) {
      std::istringstream iss(line);
      std::string key, value;
      if (std::getline(iss, key, '=') && std::getline(iss, value)) {
        if (key == "DB_HOST") {
          host_ = value;
        } else if (key == "POSTGRESintPort") {
          port_ = value;
        } else if (key == "POSTGRES_DATABASE") {
          dbname_ = value;
        } else if (key == "POSTGRES_USER") {
          user_ = value;
        } else if (key == "POSTGRES_PASSWORD") {
          password_ = value;
        }
      }
      host_="db";//never change things since is part of a docker compose stack
    }
    configFile.close();
  } else {
    std::cerr << "Unable to open config file: " << filename << std::endl;
    // Hier können Sie eine geeignete Fehlerbehandlung hinzufügen.
  }
}

DatabaseManager::~DatabaseManager() { disconnect(); }

bool DatabaseManager::connect() {
  std::string connectionString = "host=" + host_ + " port=" + port_ +
                                 " dbname=" + dbname_ + " user=" + user_ +
                                 " password=" + password_;
  connection_ = PQconnectdb(connectionString.c_str());

  if (PQstatus(connection_) != CONNECTION_OK) {
    std::cout << "Failed to connect to database." << std::endl;
    std::cout << "Host:\t"<<host_<<"\n"<<
                "Port:\t"<<port_<<"\n"<<
                "USR:\t"<<user_<<"\n"<<
                "PWD:\t"<<password_<<"\n"<<std::endl;
    return false;
  }
  std::cout << "DB connected" << std::endl;
  return true;
}

void DatabaseManager::disconnect() {
  std::cout << "DB disconnect" << std::endl;
  if (connection_) {
    PQfinish(connection_);
    connection_ = nullptr;
  }
}

bool DatabaseManager::isConnected() const {
  return (connection_ != nullptr && PQstatus(connection_) == CONNECTION_OK);
}

bool DatabaseManager::executeQuery(const std::string &query) {
  if (!isConnected()) {
    std::cout << "Not connected to database." << std::endl;
    return false;
  }

  PGresult *result = PQexec(connection_, query.c_str());
  ExecStatusType status = PQresultStatus(result);
  PQclear(result);

  if (status != PGRES_COMMAND_OK && status != PGRES_TUPLES_OK) {
    std::cout << "Query execution failed." << std::endl;
    return false;
  }

  return true;
}

PGresult *DatabaseManager::executeQueryWithResult(const std::string &query) {
  if (!isConnected()) {
    std::cout << "Not connected to database." << std::endl;
    return nullptr;
  }

  PGresult *result = PQexec(connection_, query.c_str());
  ExecStatusType status = PQresultStatus(result);

  if (status != PGRES_COMMAND_OK && status != PGRES_TUPLES_OK) {
    std::cout << "Query execution failed." << std::endl;
    PQclear(result);
    return nullptr;
  }

  return result;
}
