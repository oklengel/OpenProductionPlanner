#ifndef MaschineManager_H
#define MaschineManager_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Maschine.h"

class MaschinenManager: public DatabaseManager {
public:
    MaschinenManager();
    ~MaschinenManager();

    void addMaschine(std::string name,std::string& maschineData);
    void changeMaschine(int id,  std::string &name, std::string &machineData);
    void deleteMaschine(int id);
    nlohmann::json getAllMaschinesJson(); 

private:
    DatabaseManager dbManager_;
    //std::vector<Maschine> Maschinee;
    std::vector<nlohmann::json> Maschines;
    int nextId;
    //DatabaseManager databaseManager;
    //HttpManager& m_httpManager;

    nlohmann::json createMaschineJson(int id, const std::string& name, const std::string& dauer, const std::string& daten);
    int findMaschineIndexById(int id);
};

#endif // MaschineManager_H