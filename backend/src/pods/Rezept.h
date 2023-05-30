#ifndef REZEPT_H
#define REZEPT_H

#include <string>

class Rezept {
private:
    int id;
    std::string name;
    std::string duration;
    std::string data;

public:
    Rezept(int id, const std::string& name, const std::string& duration, const std::string& data);

    // Getter- und Setter-Methoden

    // Weitere Funktionen

};

#endif  // REZEPT_H
