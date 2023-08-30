#ifndef SzenarioManager_H
#define SzenarioManager_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Szenario.h"

class SzenarioManager: public DatabaseManager {
public:
    SzenarioManager();
    ~SzenarioManager();

    void postSzenario(std::string name,std::string rezept,std::string amount);
    nlohmann::json getSzenario(); 

private:
    //std::vector<Szenario> Szenarioe;
    std::vector<nlohmann::json> Szenarios;
    int nextId;
    //DatabaseManager databaseManager;
    //HttpManager& m_httpManager;

    nlohmann::json createSzenarioJson(int id, const std::string& name, const std::string& dauer, const std::string& daten);
    int findSzenarioIndexById(int id);
};

#endif // SzenarioManager_H