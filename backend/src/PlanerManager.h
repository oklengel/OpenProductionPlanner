#ifndef PlannerManager_H
#define PlannerManager_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Planner.h"

class PlannerManager: public DatabaseManager {
public:
    PlannerManager();
    ~PlannerManager();

    //void addPlanner(std::string name,std::string rezept,std::string amount);
    //void changePlanner(int id, const std::string& name, const std::string& rezept, const std::string& amount);
    //void deletePlanner(int id);
    nlohmann::json getAllPlannersJson(); 

private:
    //std::vector<Planner> Plannere;
    std::vector<nlohmann::json> Planners;
    int nextId;
    //DatabaseManager databaseManager;
    //HttpManager& m_httpManager;

    nlohmann::json createPlannerJson(int id, const std::string& name, const std::string& dauer, const std::string& daten);
    int findPlannerIndexById(int id);
};

#endif // PlannerManager_H