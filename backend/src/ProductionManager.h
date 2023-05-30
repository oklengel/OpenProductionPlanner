#ifndef ProductionManager_H
#define ProductionManager_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Production.h"

class ProductionManager: public DatabaseManager {
public:
    ProductionManager();
    ~ProductionManager();

    void addProduction(std::string name,std::string rezept,std::string amount);
    void changeProduction(int id, const std::string& name, const std::string& rezept, const std::string& amount);
    void deleteProduction(int id);
    nlohmann::json getAllProductionsJson(); 

private:
    //std::vector<Production> Productione;
    std::vector<nlohmann::json> Productions;
    int nextId;
    //DatabaseManager databaseManager;
    //HttpManager& m_httpManager;

    nlohmann::json createProductionJson(int id, const std::string& name, const std::string& dauer, const std::string& daten);
    int findProductionIndexById(int id);
};

#endif // ProductionManager_H