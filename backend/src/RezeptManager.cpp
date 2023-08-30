#include "RezeptManager.h"


RezeptManager::RezeptManager()
    : DatabaseManager("db","5432","OOP","postgres","example") {
   
    // Weitere Initialisierungen für RezeptManager
}

RezeptManager::~RezeptManager() {
    std::cout<<"RezeptManager gestorben"<<std::endl;
}



// Funktion zum Ändern der Rezeptdaten
void RezeptManager::changeRezept(int id, const std::string& name, const std::string& dauer, const std::string& daten)
{
    // Erstelle die SQL-Abfrage, um die Daten zu aktualisieren
    std::string query = "UPDATE recipes SET ";
    query += "name = '" + name + "', ";
    query += "dauer = '" + dauer + "', ";
    query += "daten = '" + daten + "' ";
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

nlohmann::json RezeptManager::getAllRezepteJson() {
    // SQL-Abfrage, um alle Rezepte abzurufen
    std::string query = "SELECT * FROM recipes;";
    
    // Führe die Abfrage aus und erhalte das Ergebnis als PGresult*
    PGresult* _result = executeQueryWithResult(query);
    
    nlohmann::json rezepteArray; // JSON-Array für Rezepte
    
    // Überprüfe, ob die Abfrage erfolgreich war und das Ergebnis vorhanden ist
    if (_result && PQresultStatus(_result) == PGRES_TUPLES_OK) {
        int rowCount = PQntuples(_result); // Anzahl der Reihen im Ergebnis
        std::cout<<"rowcount: "<<rowCount<<std::endl;
        // Überprüfe, ob das Ergebnis leer ist
        if (rowCount == 0) {
            // Erstelle eine Meldung für den leeren Zustand
            nlohmann::json emptyMessage;
            emptyMessage["message"] = "Keine Rezepte gefunden.";
            
            // Gib die leere Meldung als JSON zurück
            return emptyMessage;
        }
        
        // Iteriere über die Reihen des Ergebnisses
        for (int i = 0; i < rowCount; ++i) {
            nlohmann::json rezept; // JSON-Objekt für jedes Rezept
            
            // Hole die Spaltenwerte für das aktuelle Rezept
            int id = std::stoi(PQgetvalue(_result, i, 0));
            std::string name = PQgetvalue(_result, i, 1);
            std::string duration = PQgetvalue(_result, i, 2);
            std::string data = PQgetvalue(_result, i, 3);
            
            // Setze die Werte im JSON-Objekt
            rezept["id"] = id;
            rezept["name"] = name;
            rezept["duration"] = duration;
            rezept["data"] = data;
            
            // Füge das Rezept dem JSON-Array hinzu
            rezepteArray.push_back(rezept);
        }
    }
    
    // Gib das JSON-Array der Rezepte zurück
    return rezepteArray;
}

void RezeptManager::addRezept(std::string name, std::string dauer, std::string daten) {
    std::string query = "INSERT INTO recipes (name, duration, data) VALUES ('" + name + "', '" + dauer + "', '" + daten + "');";
     std::cout << "DB add query: "<<query<< std::endl;
    if (/*databaseManager_.*/executeQuery(query)) {
        std::cout << "Added new Recipe" << std::endl;
    } else {
        std::cout << "DB error: Failed to add new Recipe" << std::endl;
    }
}


void RezeptManager::deleteRezept(int id) {
    // Erstelle die SQL-Abfrage, um den Datensatz mit der angegebenen ID zu löschen
    std::string query = "DELETE FROM recipes WHERE id = " + std::to_string(id) + ";";
    std::cout << "deletequery:  " << query <<  std::endl;
    // Führe die Abfrage aus
    if (executeQuery(query)) {
        std::cout << "Rezept mit ID " << id << " erfolgreich gelöscht." << std::endl;
    } else {
        std::cout << "Fehler beim Löschen des Rezepts mit ID " << id << "." << std::endl;
    }
}

/*
int RezeptManager::findRezeptIndexById(int id) {
    for (size_t i = 0; i < rezepte.size(); i++) {
        if (rezepte[i]["id"] == id) {
            return i;
        }
    }
    return -1;
}*/
