#ifndef ENV_H
#define ENV_H

#include <map>
#include <string>

class Env {
private:
  std::map<std::string, std::string> envMap;

public:
  Env(std::string path);
  std::map<std::string, std::string> getEnvMap();
  std::string getVal(std::string key);

  ~Env();
};

#endif
