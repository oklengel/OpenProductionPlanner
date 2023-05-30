#ifndef PRODUKTION_H
#define PRODUKTION_H

#include <string>

class PRODUKTION {
private:
    int id;
    std::string name;
    std::string rezept;
    std::long amount;

public:
    PRODUKTION(int id,
    const std::string& name,
    const std::string& rezept,
    const std::long& amount
    );

    // Getter- und Setter-Methoden

    // Weitere Funktionen

};

#endif  // PRODUKTION_H