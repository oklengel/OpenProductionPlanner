#ifndef ResourceManager_H
#define ResourceManager_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Resource.h"

class ResourcenManager: public DatabaseManager {
public:
    ResourcenManager();
    ~ResourcenManager();

    //void addResource(std::string name,std::string rezept,std::string amount);
    //void changeResource(int id, const std::string& name, const std::string& rezept, const std::string& amount);
    //void deleteResource(int id);
    nlohmann::json getAllResourcesJson(); 

private:
    //std::vector<Resource> Resourcee;
    std::vector<nlohmann::json> Resources;
    int nextId;
    //DatabaseManager databaseManager;
    //HttpManager& m_httpManager;

    nlohmann::json createResourceJson(int id, const std::string& name, const std::string& dauer, const std::string& daten);
    int findResourceIndexById(int id);
};

#endif // ResourceManager_H