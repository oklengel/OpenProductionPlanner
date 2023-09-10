# Basisimage für das Backend
FROM fedora:latest

# Aktualisieren des Paketmanagers und Installation der Abhängigkeiten
RUN dnf -y update && dnf -y install \
    gcc \
    gcc-c++ \
    cmake \
    make \
    git \
    postgresql-devel \
    libpqxx\
    libpqxx-devel \
    cpprest-devel \
    zlib \
    zlib-devel \
    openssl-devel \
    json-devel

# Arbeitsverzeichnis im Container erstellen
WORKDIR /app

# Kopieren des Quellcodes & ENV Config in das Arbeitsverzeichnis im Container
COPY . /app

# Kompilieren des Backend-Codes
RUN mkdir build && cd build && cmake -DPOSTGRES=ON .. && \
    make

RUN pwd
RUN ls
RUN ls ./build

# Port für den Backend-Server freigeben
EXPOSE 8083

# Umgebungsvariablen für die Datenbankverbindung setzen
#ENV DB_HOST=localhost
#ENV DB_USER=myuser
#ENV DB_PASSWORD=mypassword
#ENV DB_NAME=recipes

# Skript zum Starten des Backend-Servers im Container
#CMD ./build/OOPbackend

#Sleep for 60secs since depends on db is.... sometimes not working
#RUN sleep 1m 
ENTRYPOINT ["bash", "-c", "./build/OOPbackend 8083"]