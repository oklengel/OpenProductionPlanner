#ifndef PERSON_H
#define PERSON_H

#include <string>

class PERSON {
private:
    int id;
    std::string name;
    std::string Job;
    std::string Zeitmodell;
    std::short wochenarbeitszeit;

public:
    PERSON(int id, const std::string& name, const std::string& duration, const std::string& data);

    // Getter- und Setter-Methoden

    // Weitere Funktionen

};

#endif  // PERSON_H