
#ifndef DashboardManager_H
#define DashboardManager_H

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <libpq-fe.h>

//#include "HttpManager.h"
#include "DatabaseManager.h"
//#include "pods/Maschine.h"

class DashboardManager: public DatabaseManager {
public:
    DashboardManager();
    ~DashboardManager();

    nlohmann::json getDashboardJson(); 

private:
    
};

#endif