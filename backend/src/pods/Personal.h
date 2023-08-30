#ifndef PERSON_H
#define PERSON_H

#include <string>

class PERSON {
private:
    int id;
    std::string name;
    std::string job;
    std::string zeitmodell;
    std::short wochenarbeitszeit;

public:
    PERSON(int id,
    const std::string& name,
    const std::string& job,
    const std::string& zeitmodell
    );

    // Getter- und Setter-Methoden

    // Weitere Funktionen

};

#endif  // PERSON_H