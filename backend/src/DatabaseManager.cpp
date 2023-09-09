#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(std::string name) {
    std::cout<<"Constructor called from "<<name<<std::endl;
    Env env("config.txt");
    std::string c = "dbname = " + env.getVal("Postgres_DB") + " user = " + env.getVal("Postgres_USER") + " password = " + env.getVal("Postgres_PASSWORD") + " hostaddr = db port = " + env.getVal("Postgres_Port");
    std::cout << c << std::endl;
    try {
      pqxx::connection C(c);
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
