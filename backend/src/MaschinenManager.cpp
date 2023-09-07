#include "MaschinenManager.h"

MaschinenManager::MaschinenManager()
    : dbManager_(/*"db", "5432", "OOP", "postgres", "example"*/) {}

void MaschinenManager::addMaschine(std::string name, std::string &maschineData) {
    if (dbManager_.connect()) {
        bool s = dbManager_.executeQuery("SELECT * FROM some_table");
        dbManager_.disconnect();
    } else {
        // Fehlerbehandlung für die Verbindung
    }
}

void MaschinenManager::deleteMaschine(int id) {
    if (dbManager_.connect()) {
        bool s = dbManager_.executeQuery("DELETE FROM some_table WHERE id = " + std::to_string(id));
        dbManager_.disconnect();
    } else {
        // Fehlerbehandlung für die Verbindung
    }
}

void MaschinenManager::changeMaschine(int id,  std::string &name,
                                       std::string &machineData) {
    // Ihre Implementierung hier
}


/* nlohmann::getAllMaschinesJson(){
if(DatabaseManager.executeQuery("")){
         //log ok
     }else
     {
         //log error
     }
 }*/
