#include "RezeptManager.h"

/*

Controller for recipes, "Building instuction for something"

*/
RezeptManager::RezeptManager() : DatabaseManager("RezeptManager") {

  // Weitere Initialisierungen für RezeptManager
}

RezeptManager::~RezeptManager() {
  std::cout << "RezeptManager gestorben" << std::endl;
}

nlohmann::json RezeptManager::getAllRezepte() {}
void RezeptManager::createRezeptJson(const std::string &name,
                                     const std::string &dauer,
                                     const std::string &daten) {}
void RezeptManager::createRezeptJson(int id, const std::string &name,
                                     const std::string &dauer,
                                     const std::string &daten) {}
