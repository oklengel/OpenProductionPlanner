#include "ProductionManager.h"


ProductionManager::ProductionManager()
    : DatabaseManager("ProductionManager") {
    //std::cout<<"should be connected"<<std::endl;
    // Weitere Initialisierungen für ProductionManager
}

ProductionManager::~ProductionManager() {
    std::cout<<"ProductionManager gestorben"<<std::endl;
}


