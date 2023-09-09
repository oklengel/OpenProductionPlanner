#include "RezeptManager.h"


RezeptManager::RezeptManager()
    : DatabaseManager(/*"db","5432","OOP","postgres","example"*/) {
   
    // Weitere Initialisierungen für RezeptManager
}

RezeptManager::~RezeptManager() {
    std::cout<<"RezeptManager gestorben"<<std::endl;
}


