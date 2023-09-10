#include "Env.h"
#include <fstream>
#include <iostream>

Env::Env(std::string path) {
  std::string line, currentVar, currentVal;
  std::ifstream envfile(path);
  if (envfile.is_open()) {
    while (getline(envfile, line)) {
      if (!(line.length() < 2 || line[0] == '#')) {
        size_t found = line.find('=');
        if (found != std::string::npos) {
          currentVar = line.substr(0, found);
          currentVal = line.substr(found + 1, line.length());
          std::cout << "ck: " << currentVar << "; cv: " << currentVal << std::endl;
          envMap.insert(std::pair<std::string, std::string>(currentVar, currentVal));
        }
      }
    }
    envfile.close();
  } else {
    std::cout << "Unable to open env file " + path + " ";
  }
}

Env::~Env() {}

std::map<std::string, std::string> Env::getEnvMap() {
  return envMap;
}

std::string Env::getVal(std::string key) {
  try {
    const std::string &value = envMap.at(key);
    return value;
  } catch (const std::exception &e) {
    std::cerr << "LibEnvCPP: Key " << key << " not found" << std::endl;
    return ""; // Sie sollten eine sinnvolle Rückgabe hinzufügen oder eine Exception werfen.
  }
}
