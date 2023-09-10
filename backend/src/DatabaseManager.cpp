#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(std::string name) {
  std::cout << "Constructor called from " << name << std::endl;
  // Env env("config.txt");
  // std::string c = "dbname = " + env.getVal("POSTGRES_DB") + " user = " +
  // env.getVal("POSTGRES_USER") + " password = " +
  // env.getVal("POSTGRES_PASSWORD") + " hostaddr = db port = " +
  // env.getVal("POSTGRES_Port"); std::string c = std::string("dbname = ") +
  // std::getenv("POSTGRES_DB") + " user = " + std::getenv("POSTGRES_USER") + "
  // password = " + std::getenv("POSTGRES_PASSWORD") + " hostaddr = " +
  // std::getenv("POSTGRES_Port");
  // check env vars

  const char *debugEnv = std::getenv("LOG_LEVEL");
  if (debugEnv != nullptr) {
    logLevel = std::atoi(debugEnv);
  } else {
    logLevel = 0;
  }

  postgresDB = std::getenv("POSTGRES_DB");
  if (postgresDB != nullptr) {
    if (logLevel >= 1) {
      std::cout << "POSTGRES_DB: " << postgresDB << std::endl;
    }
  }

  else {
    std::cerr << "Umgebungsvariable POSTGRES_DB nicht gefunden." << std::endl;
  }
  postgresHOST = std::getenv("POSTGRES_HOST");
  if (postgresHOST != nullptr) {
    if (logLevel >= 1) {
      std::cout << "POSTGRES_HOST: " << postgresHOST << std::endl;
    }
  } else {
    std::cerr << "Umgebungsvariable postgres_HOST nicht gefunden." << std::endl;
  }
  postgresPWD = std::getenv("POSTGRES_PASSWORD");
  if (postgresPWD != nullptr) {
    if (logLevel >= 1) {
      std::cout << "POSTGRES_PASSWORD: " << postgresPWD << std::endl;
    }
  } else {
    std::cerr << "Umgebungsvariable POSTGRES_PASSWORD nicht gefunden."
              << std::endl;
  }
  postgresUSR = std::getenv("POSTGRES_USER");
  if (postgresUSR != nullptr) {
    if (logLevel >= 1) {
      std::cout << "POSTGRES_USER: " << postgresUSR << std::endl;
    }
  } else {
    std::cerr << "Umgebungsvariable POSTGRES_USER nicht gefunden." << std::endl;
  }
  postgresPORT = std::getenv("POSTGRES_PORT");
  if (postgresPORT != nullptr) {
    if (logLevel >= 1) {
      std::cout << "POSTGRES_PORT: " << postgresPORT << std::endl;
    }
  } else {
    std::cerr << "Umgebungsvariable POSTGRES_PORT nicht gefunden." << std::endl;
  }

  try {
    connectionStr = "";
    connectionStr += "host=" + std::string(postgresHOST) + " ";
    connectionStr += "port=" + std::string(postgresPORT) + " ";
    connectionStr += "dbname=" + std::string(postgresDB) + " ";
    connectionStr += "user=" + std::string(postgresUSR) + " ";
    connectionStr += "password=" + std::string(postgresPWD) + " ";

    pqxx::connection C(connectionStr);
    if (C.is_open()) {
      std::cout << "Opened database successfully: " << C.dbname() << std::endl;
    } else {
      std::cout << "Can't open database" << std::endl;
      // Hier kannst du eine geeignete Fehlerbehandlung hinzufügen.
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    // Hier kannst du eine Fehlerbehandlung für Ausnahmen hinzufügen.
  }
}

DatabaseManager::~DatabaseManager() {}
