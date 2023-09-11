
#include "DashboardManager.h"

#include <iostream>
#include <map>
#include <string>

DashboardManager::DashboardManager() : DatabaseManager("DashboardManager") {}
DashboardManager::~DashboardManager() {}
/*

Widgets for Home tab

*/
nlohmann::json DashboardManager::getDashboardJson() {
  std::map<std::string, std::string> sql;
  nlohmann::json jsonData;
  try {
    sql["AllMachines"] = "select count id from Machines";
    sql["BusyMachines"] = "select count id from Machines where status='busy'";
    // attention! designd for single value results!!!
    for (const auto &pair : sql) {
      const std::string &key = pair.first;

      // get db data
      pqxx::work txn(Connection);
      pqxx::result result = txn.exec("SELECT COUNT(*) FROM A");
      int val = result[0][0].as<int>();
      // push to json
      jsonData[key] = val;
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    std::cout << "FATAL ERROR inside DashboardManager::getDashboardJson"
              << std::endl;
  }
  return jsonData;
}