#include <iostream>
#include <thread>
#include <chrono>
#include "HttpManager.h"
#include "RezeptManager.h"
#include "DatabaseManager.h"


int main(int argc, char* argv[]) {
    // DatabaseManager initialisieren
    //DatabaseManager dbManager("db:5432");

    DatabaseManager dbManager("db","5432","OOP","postgres","example");
    std::cout << "Main: init DB Manager" << std::endl;

    // HttpManager initialisieren
    HttpManager httpManager("0.0.0.0", "8083");
    std::cout << "Main: init http Manager" << std::endl;

    // RezeptManager initialisieren
    //RezeptManager rezeptManager(dbManager);
    //std::cout << "Main: init Recipe Manager" << std::endl;

    // Server starten
    httpManager.start();
    std::cout << "Main: Server started" << std::endl;

    while (true) {
        // Hier können weitere Aufgaben oder Überprüfungen ausgeführt werden

        // Eine kleine Verzögerung, um die CPU-Auslastung zu reduzieren
        // und den Server nicht zu überlasten
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // disassemble...

    std::cout << "Backend stopped" << std::endl;
    return 0;
}

