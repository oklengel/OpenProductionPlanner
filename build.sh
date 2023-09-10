#!/bin/bash

# Pfad zur .env-Datei
ENV_FILE_PATH=.env

# Verzeichnis, in das die .env-Datei kopiert werden soll
BACKEND_DIR=backend/build



# Kopiere die .env-Datei in das backend-Verzeichnis
#cp "$ENV_FILE_PATH" "$BACKEND_DIR"



#cd $BACKEND_DIR
#mv .env config.txt
#cd ../..

# Führen Sie Docker Compose aus, um die Container zu erstellen und auszuführen
docker-compose -f "docker-compose.yml" down
docker-compose build
docker-compose -f "docker-compose.yml" up -d

