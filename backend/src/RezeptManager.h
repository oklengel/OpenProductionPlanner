#ifndef REZEPTMANAGER_H
#define REZEPTMANAGER_H

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

#include <libpq-fe.h>

// #include "HttpManager.h"
#include "DatabaseManager.h"
// #include "pods/Rezept.h"

class RezeptManager : public DatabaseManager {
public:
  RezeptManager();
  ~RezeptManager();

  nlohmann::json getAllRezepte();
  void createRezeptJson(const std::string &name, const std::string &dauer,
                        const std::string &daten);
  void createRezeptJson(int id, const std::string &name,
                        const std::string &dauer, const std::string &daten);

private:

};

#endif // REZEPTMANAGER_H
