#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(const std::string &host,
                                 const std::string &port,
                                 const std::string &dbname,
                                 const std::string &user,
                                 const std::string &password)
    : connection_(nullptr), host_(host), port_(port), dbname_(dbname),
      user_(user), password_(password) {
  connect();
}

DatabaseManager::~DatabaseManager() { disconnect(); }

bool DatabaseManager::connect() {
  std::string connectionString = "host=" + host_ + " port=" + port_ +
                                 " dbname=" + dbname_ + " user=" + user_ +
                                 " password=" + password_;
  connection_ = PQconnectdb(connectionString.c_str());

  if (PQstatus(connection_) != CONNECTION_OK) {
    std::cout << "Failed to connect to database." << std::endl;
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
