#ifndef PersonalManager_H
#define PersonalManager_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Personal.h"

class PersonalManager: public DatabaseManager {
public:
    PersonalManager();
    ~PersonalManager();

    //void addPersonal(std::string name,std::string rezept,std::string amount);
    //void changePersonal(int id, const std::string& name, const std::string& rezept, const std::string& amount);
    //void deletePersonal(int id);
    nlohmann::json getAllPersonalsJson(); 

private:
    //std::vector<Personal> Personale;
    std::vector<nlohmann::json> Personals;
    int nextId;
    //DatabaseManager databaseManager;
    //HttpManager& m_httpManager;

    nlohmann::json createPersonalJson(int id, const std::string& name, const std::string& dauer, const std::string& daten);
    int findPersonalIndexById(int id);
};

#endif // PersonalManager_H