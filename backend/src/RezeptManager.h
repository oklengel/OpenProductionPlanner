#ifndef REZEPTMANAGER_H
#define REZEPTMANAGER_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Rezept.h"

class RezeptManager: public DatabaseManager {
public:
    RezeptManager();
    ~RezeptManager();


private:
    //std::vector<Rezept> rezepte;
    std::vector<nlohmann::json> rezepte;
    int nextId;
    //DatabaseManager databaseManager;
    //HttpManager& m_httpManager;

    nlohmann::json createRezeptJson(int id, const std::string& name, const std::string& dauer, const std::string& daten);
    int findRezeptIndexById(int id);
};

#endif // REZEPTMANAGER_H
