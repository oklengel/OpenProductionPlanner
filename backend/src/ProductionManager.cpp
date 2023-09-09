#include "ProductionManager.h"


ProductionManager::ProductionManager()
    : DatabaseManager(/*"db","5432","OOP","postgres","example"*/) {
    std::cout<<"should be connected"<<std::endl;
    // Weitere Initialisierungen für ProductionManager
}

ProductionManager::~ProductionManager() {
    std::cout<<"ProductionManager gestorben"<<std::endl;
}


