#include "HttpManager.h"
/*

Global REST Endpoint for the entire BACKEND

*/
HttpManager::HttpManager(const std::string &host, const std::string &port)
    : listener_("http://" + host + ":" + port + "/"),
      rezeptManager(new RezeptManager()),
      productionManager(new ProductionManager()),
      resourcenManager(new ResourcenManager()),
      personalManager(new PersonalManager()),
      maschinenManager(new MaschinenManager()),
      szenarioManager(new SzenarioManager()) {}

HttpManager::~HttpManager() {
  std::cout << "HttpManager DOWN" << std::endl;
  delete rezeptManager;
  delete productionManager;
  delete resourcenManager;
  delete personalManager;
  delete maschinenManager;
  delete szenarioManager;
  listener_.close().wait();
  std::cout << "HttpListener: Server stopped" << std::endl;
}

void HttpManager::start() {
  listener_.support(methods::GET, std::bind(&HttpManager::handle_request, this,
                                            std::placeholders::_1));
  listener_.support(methods::POST, std::bind(&HttpManager::handle_request, this,
                                             std::placeholders::_1));
  listener_.support(methods::PUT, std::bind(&HttpManager::handle_request, this,
                                            std::placeholders::_1));
  listener_.support(methods::DEL, std::bind(&HttpManager::handle_request, this,
                                            std::placeholders::_1));

  try {
    listener_.open().wait();
    std::cout << "HttpListener: Server started" << std::endl;
  } catch (const std::exception &e) {
    std::cout << "HttpListener: Error: " << e.what() << std::endl;
  }
}

void HttpManager::handle_request(http_request req) {
  auto method = req.method();
  auto path = req.request_uri().path();
  /*REZEPTE*/
  if (method == methods::GET && path == "/rezepte") {
    handle_get_rezepte(req);
  } else if (method == methods::POST && path == "/rezepte") {
    handle_post_rezepte(req);
  } else if (method == methods::PUT &&
             path.find("/rezepte/") != std::string::npos) {
    std::cout << "put called...." << std::endl;
    handle_put_rezepte(req);
  } else if (method == methods::DEL &&
             path.find("/rezepte/") != std::string::npos) {
    std::cout << "delete called...." << std::endl;
    handle_delete_rezepte(req);
    /*PRODUKTIONEN*/
  } else if (method == methods::GET && path == "/production") {
    handle_get_production(req);
  } else if (method == methods::POST && path == "/production") {
    handle_post_production(req);
  } else if (method == methods::PUT &&
             path.find("/production/") != std::string::npos) {
    std::cout << "put called...." << std::endl;
    handle_put_production(req);
  } else if (method == methods::DEL &&
             path.find("/production/") != std::string::npos) {
    std::cout << "delete called...." << std::endl;
    handle_delete_production(req);

  } else {
    nlohmann::json response = create_response("Ungültiger Endpunkt");
    send_response(req, response, status_codes::NotFound);
  }
}
// Rezept
//  ✅
void HttpManager::handle_get_rezepte(http_request req) {
  // nlohmann::json response = rezeptManager->getAllRezepteJson();
   nlohmann::json response = create_response("Implementiere die Logik, um Rezepte abzurufen");
  send_response(req, response);
}
// ✅
void HttpManager::handle_post_rezepte(http_request req) {
   // Lese den Inhalt der Anfrage
   req.extract_json().then([=](pplx::task<json::value> task) {
     try {
       // Erhalte den JSON-Inhalt der Anfrage
       const json::value &requestJson = task.get();

       // Überprüfe, ob die erforderlichen Felder im JSON vorhanden sind
       if (requestJson.has_field("name") && requestJson.has_field("duration") &&
           requestJson.has_field("data")) {
         // Extrahiere die Werte aus dem JSON
         std::string name = requestJson.at("name").as_string();
         std::string duration = requestJson.at("duration").as_string();
         std::string data = requestJson.at("data").as_string();

         // rezeptManager->addRezept(name, duration, data);
         http_response response(status_codes::OK);
         req.reply(response);
       }
     } catch (const std::exception &e) {
       std::cout << "Fehler beim Anlegen von Rezept" << e.what() << std::endl;
       http_response response(status_codes::InternalError);
       response.set_body("Fehler beim Anlegen des Rezepts.");
       req.reply(response);
     }
   });
}

void HttpManager::handle_put_rezepte(http_request req) {
   // Lese den Inhalt der Anfrage
   req.extract_json().then([=](pplx::task<json::value> task) {
     try {
       // Erhalte den JSON-Inhalt der Anfrage
       const json::value &requestJson = task.get();

       // Überprüfe, ob die erforderlichen Felder im JSON vorhanden sind
       if (requestJson.has_field("id") && requestJson.has_field("name") &&
           requestJson.has_field("duration") && requestJson.has_field("data")) {
         // Extrahiere die Werte aus dem JSON
         std::string id_str = requestJson.at("id").as_string();
         std::string name = requestJson.at("name").as_string();
         std::string duration = requestJson.at("duration").as_string();
         std::string data = requestJson.at("data").as_string();

         int id = std::stoi(id_str);
         // rezeptManager->addRezept(name, duration, data);
         // rezeptManager->changeRezept(id, name, duration, data);
         http_response response(status_codes::OK);
         req.reply(response);
       }
     } catch (const std::exception &e) {
       std::cout << "Fehler beim Anlegen von Rezept" << e.what() << std::endl;
       http_response response(status_codes::InternalError);
       response.set_body("Fehler beim Anlegen des Rezepts.");
       req.reply(response);
     }
   });
}

// ✅
void HttpManager::handle_delete_rezepte(http_request req) {
   try {
     // Extrahiere die ID aus der Anfrage-URL
     std::string idStr = uri::decode(req.relative_uri().path());
     // Entferne den führenden Schrägstrich "/"

     // Konvertiere die ID in einen Integer
     std::cout << "id: " << idStr << std::endl;
     int id = extractLastPositiveInteger(idStr);

     std::cout << "to be deleted: " << id << std::endl;
     // Lösche das Rezept mit der angegebenen ID
     // rezeptManager->deleteRezept(id);
     std::cout << "should be deleted...." << std::endl;

     // Setze den HTTP-Statuscode entsprechend
     req.reply(status_codes::OK, "Rezept erfolgreich gelöscht.");
   } catch (const std::exception &e) {
     std::cout << "Fehler beim Löschen des Rezepts: " << e.what() << std::endl;
     req.reply(status_codes::InternalError, "Fehler beim Löschen des Rezepts.");
   }
}

// Produktion
//  ✅
void HttpManager::handle_get_production(http_request req) {
   // nlohmann::json response = productionManager->getAllProductionsJson();
     nlohmann::json response = create_response("Implementiere die Logik, um Rezepte abzurufen");
   send_response(req, response);
}
// ✅
/*
name
rezept
amount
*/
void HttpManager::handle_post_production(http_request req) {
   // Lese den Inhalt der Anfrage
   req.extract_json().then([=](pplx::task<json::value> task) {
     try {
       // Erhalte den JSON-Inhalt der Anfrage
       const json::value &requestJson = task.get();

       // Überprüfe, ob die erforderlichen Felder im JSON vorhanden sind
       if (requestJson.has_field("name") && requestJson.has_field("rezept") &&
           requestJson.has_field("amount")) {
         // Extrahiere die Werte aus dem JSON
         std::string name = requestJson.at("name").as_string();
         std::string rezept = requestJson.at("rezept").as_string();
         std::string amount = requestJson.at("amount").as_string();

         // productionManager -> addProduction(name, rezept, amount);
         http_response response(status_codes::OK);
         req.reply(response);
       }
     } catch (const std::exception &e) {
       std::cout << "Fehler beim Anlegen von Produktion" << e.what()
                 << std::endl;
       http_response response(status_codes::InternalError);
       response.set_body("Fehler beim Anlegen des Produktion.");
       req.reply(response);
     }
   });
}

void HttpManager::handle_put_production(http_request req) {
   // Lese den Inhalt der Anfrage
   req.extract_json().then([=](pplx::task<json::value> task) {
     try {
       // Erhalte den JSON-Inhalt der Anfrage
       const json::value &requestJson = task.get();

       // Überprüfe, ob die erforderlichen Felder im JSON vorhanden sind
       if (requestJson.has_field("id") && requestJson.has_field("name") &&
           requestJson.has_field("rezept") && requestJson.has_field("amount")) {
         // Extrahiere die Werte aus dem JSON
         std::string id_str = requestJson.at("id").as_string();
         std::string name = requestJson.at("name").as_string();
         std::string rezept = requestJson.at("rezept").as_string();
         std::string amount = requestJson.at("amount").as_string();

         int id = std::stoi(id_str);
         // rezeptManager->addRezept(name, duration, data);
         // productionManager->changeProduction(id, name, rezept, amount);
         http_response response(status_codes::OK);
         req.reply(response);
       }
     } catch (const std::exception &e) {
       std::cout << "Fehler beim ändern von Produktion" << e.what()
                 << std::endl;
       http_response response(status_codes::InternalError);
       response.set_body("Fehler beim ändern von Produktion.");
       req.reply(response);
     }
   });
}

// ✅
void HttpManager::handle_delete_production(http_request req) {
   try {
     // Extrahiere die ID aus der Anfrage-URL
     std::string idStr = uri::decode(req.relative_uri().path());
     // Entferne den führenden Schrägstrich "/"

     // Konvertiere die ID in einen Integer
     std::cout << "id: " << idStr << std::endl;
     int id = extractLastPositiveInteger(idStr);

     std::cout << "to be deleted: " << id << std::endl;
     // Lösche das Rezept mit der angegebenen ID
     //productionManager->deleteProduction(id);
     std::cout << "should be deleted...." << std::endl;

     // Setze den HTTP-Statuscode entsprechend
     req.reply(status_codes::OK, "Rezept erfolgreich gelöscht.");
   } catch (const std::exception &e) {
     std::cout << "Fehler beim Löschen des Rezepts: " << e.what() << std::endl;
     req.reply(status_codes::InternalError, "Fehler beim Löschen des Rezepts.");
   }
}

// Hilfsfunktionen:
nlohmann::json HttpManager::create_response(const std::string &message,
                                            const std::string &content_type,
                                            status_code status) {
   nlohmann::json response;
   response["message"] = message;

   http_response http_response(status);
   http_response.headers().add("Content-Type", content_type);
   http_response.set_body(response.dump());

   return response;
}

void HttpManager::send_response(http_request req,
                                const nlohmann::json &response,
                                status_code status) {
   http_response http_response(status);
   http_response.headers().add("Content-Type", "application/json");
   http_response.set_body(response.dump());

   req.reply(http_response);
}

int HttpManager::extractLastPositiveInteger(const std::string &str) {
   int number = 0;
   int startIndex = -1;
   int endIndex = -1;
   bool foundDigits = false;

   // Durchlaufe den String von rechts nach links
   for (int i = str.length() - 1; i >= 0; i--) {
     // Überprüfe, ob das aktuelle Zeichen eine Ziffer ist
     if (std::isdigit(str[i])) {
       // Setze den Endindex, wenn noch kein Endindex gefunden wurde
       if (endIndex == -1) {
         endIndex = i;
       }
       // Setze den Startindex, wenn kein Startindex gefunden wurde und das
       // Zeichen nicht '0' ist
       if (startIndex == -1 && str[i] != '0') {
         startIndex = i;
         foundDigits = true;
       }
     } else {
       // Wenn ein Startindex gefunden wurde, beende die Schleife
       if (startIndex != -1) {
         break;
       }
     }
   }

   // Extrahiere die Zahl aus dem String
   if (foundDigits && startIndex != -1 && endIndex != -1) {
     std::string numberStr = str.substr(startIndex, endIndex - startIndex + 1);
     try {
       number = std::stoi(numberStr);
     } catch (const std::exception &e) {
       // Fehler beim Konvertieren der Zahl
       std::cerr << "Fehler beim Konvertieren der Zahl: " << e.what()
                 << std::endl;
     }
   }

   return number;
}
