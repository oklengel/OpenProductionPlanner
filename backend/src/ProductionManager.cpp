#include "ProductionManager.h"
/*

Controller to handle productions; production=recipe*amount

*/

ProductionManager::ProductionManager()
    : DatabaseManager("ProductionManager") {}

ProductionManager::~ProductionManager() {
    std::cout<<"ProductionManager gestorben"<<std::endl;
}


/*
CREATE TABLE IF NOT EXISTS production (
    id SERIAL PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    recipe VARCHAR(20) NOT NULL,
    amount VARCHAR(20) NOT NULL,
);
*/

void ProductionManager::addProduction(std::string name,std::string rezept,std::string amount){

}
void ProductionManager::changeProduction(int id, const std::string& name, const std::string& rezept, const std::string& amount){

}
void ProductionManager::deleteProduction(int id){

}
nlohmann::json  ProductionManager::getAllProductionsJson(){

} 