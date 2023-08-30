#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <iostream>
#include <string>
#include <cpprest/http_listener.h>
#include <nlohmann/json.hpp>
#include "RezeptManager.h"
#include "ProductionManager.h"
#include "ResourcenManager.h" 
#include "PersonalManager.h"
#include "PlanerManager.h"
#include "MaschinenManager.h" 
#include "SzenarioManager.h"

//using json = nlohmann::json; frisst Compiler nicht
using namespace web;
using namespace http;
using namespace http::experimental::listener;


class HttpManager {
public:
    HttpManager(const std::string& host, const std::string& port);
    ~HttpManager();

    void start();
    void stop();

private:
    http_listener listener_;
    RezeptManager *rezeptManager;
    ResourcenManager *resourcenManager;
    PersonalManager *personalManager;
    ProductionManager *productionManager;
    PlannerManager *plannerManager;
    MaschinenManager *maschinenManager;
    SzenarioManager *szenarioManager;
    //root
    void handle_request(http_request req);
    //Rezepte
    void handle_get_rezepte(http_request req);
    void handle_post_rezepte(http_request req);
    void handle_put_rezepte(http_request req);
    void handle_delete_rezepte(http_request req);
    //Resourcen
    void handle_get_ressource(http_request req);
    void handle_post_ressource(http_request req);
    void handle_put_ressource(http_request req);
    void handle_delete_ressource(http_request req);
    //Personal
    void handle_get_personal(http_request req);
    void handle_post_personal(http_request req);
    void handle_put_personal(http_request req);
    void handle_delete_personal(http_request req);
    //Produktion
    void handle_get_production(http_request req);
    void handle_post_production(http_request req);
    void handle_put_production(http_request req);
    void handle_delete_production(http_request req);
    //Planner
    void handle_get_plan(http_request req);
    //Maschienenlog
    void handle_post_masch_log(http_request req);
    //Szenario
    void handle_get_szenario(http_request req);
    void handle_post_szenario(http_request req);

    //Hilfsfunktionen
    nlohmann::json create_response(const std::string& message, const std::string& content_type = "text/plain", status_code status = status_codes::OK);
    void send_response(http_request req, const nlohmann::json& response, status_code status = status_codes::OK);
    int extractLastPositiveInteger(const std::string& str);
};

#endif  // HTTPMANAGER_H
