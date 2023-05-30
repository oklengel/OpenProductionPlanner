#include "ProductionManager.h"


ProductionManager::ProductionManager()
    : DatabaseManager("db","5432","OOP","postgres","example") {
    std::cout<<"should be connected"<<std::endl;
    // Weitere Initialisierungen für ProductionManager
}

ProductionManager::~ProductionManager() {
    std::cout<<"ProductionManager gestorben"<<std::endl;
}


// Funktion zum Ändern der Productiondaten
void ProductionManager::changeProduction(int id, const std::string& name, const std::string& rezept, const std::string& amount)
{
    // Erstelle die SQL-Abfrage, um die Daten zu aktualisieren
    std::string query = "UPDATE production SET ";
    query += "name = '" + name + "', ";
    query += "recipe = '" + rezept + "', ";
    query += "amount = '" + amount + "' ";
    query += "WHERE id = " + std::to_string(id);

    std::cout<<"Put: Query: "<< query<<std::endl;
    // Führe die Datenbankabfrage aus
    bool success = executeQuery(query);

    // Überprüfe das Ergebnis der Datenbankabfrage
    if (success)
    {
        // Die Daten wurden erfolgreich aktualisiert
        // Füge hier ggf. weitere Logik hinzu, falls benötigt
        std::cout<<"Put: ok"<<std::endl;
    }
    else
    {
        // Fehler bei der Datenbankabfrage
        // Füge hier ggf. Fehlerbehandlungslogik hinzu
        std::cout<<"Put: Fehler"<<std::endl;
    }
}

nlohmann::json ProductionManager::getAllProductionsJson() {
    // SQL-Abfrage, um alle Productione abzurufen
    std::string query = "SELECT * FROM production;";
    
    // Führe die Abfrage aus und erhalte das Ergebnis als PGresult*
    PGresult* _result = executeQueryWithResult(query);
    
    nlohmann::json ProductioneArray; // JSON-Array für Productione
    
    // Überprüfe, ob die Abfrage erfolgreich war und das Ergebnis vorhanden ist
    if (_result && PQresultStatus(_result) == PGRES_TUPLES_OK) {
        int rowCount = PQntuples(_result); // Anzahl der Reihen im Ergebnis
        std::cout<<"rowcount: "<<rowCount<<std::endl;
        // Überprüfe, ob das Ergebnis leer ist
        if (rowCount == 0) {
            // Erstelle eine Meldung für den leeren Zustand
            nlohmann::json emptyMessage;
            emptyMessage["message"] = "Keine Production gefunden.";
            
            // Gib die leere Meldung als JSON zurück
            return emptyMessage;
        }
        
        // Iteriere über die Reihen des Ergebnisses
        for (int i = 0; i < rowCount; ++i) {
            nlohmann::json Production; // JSON-Objekt für jedes Production
            
            // Hole die Spaltenwerte für das aktuelle Production
            int id = std::stoi(PQgetvalue(_result, i, 0));
            std::string name = PQgetvalue(_result, i, 1);
            std::string rezept = PQgetvalue(_result, i, 2);
            std::string amount = PQgetvalue(_result, i, 3);
            
            // Setze die Werte im JSON-Objekt
            Production["id"] = id;
            Production["name"] = name;
            Production["rezept"] = rezept;
            Production["amount"] = amount;
            
            // Füge das Production dem JSON-Array hinzu
            ProductioneArray.push_back(Production);
        }
    }
    
    // Gib das JSON-Array der Productione zurück
    return ProductioneArray;
}

void ProductionManager::addProduction(std::string name, std::string rezept, std::string amount) {
    std::string query = "INSERT INTO production (name, duration, data) VALUES ('" + name + "', '" + rezept + "', '" + amount + "');";
     std::cout << "DB add query: "<<query<< std::endl;
    if (/*databaseManager_.*/executeQuery(query)) {
        std::cout << "Added new Recipe" << std::endl;
    } else {
        std::cout << "DB error: Failed to add new Recipe" << std::endl;
    }
}


void ProductionManager::deleteProduction(int id) {
    // Erstelle die SQL-Abfrage, um den Datensatz mit der angegebenen ID zu löschen
    std::string query = "DELETE FROM production WHERE id = " + std::to_string(id) + ";";
    std::cout << "deletequery:  " << query <<  std::endl;
    // Führe die Abfrage aus
    if (executeQuery(query)) {
        std::cout << "Production mit ID " << id << " erfolgreich gelöscht." << std::endl;
    } else {
        std::cout << "Fehler beim Löschen des Productions mit ID " << id << "." << std::endl;
    }
}

/*
int ProductionManager::findProductionIndexById(int id) {
    for (size_t i = 0; i < Productione.size(); i++) {
        if (Productione[i]["id"] == id) {
            return i;
        }
    }
    return -1;
}*/
