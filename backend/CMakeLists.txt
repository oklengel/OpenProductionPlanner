cmake_minimum_required(VERSION 3.14)
project(OOPbackend)

set(CMAKE_CXX_STANDARD 14)

# Fügen Sie hier die erforderlichen Bibliotheken hinzu, wenn Sie sie benötigen.
# Zum Beispiel, wenn Sie PostgreSQL verwenden möchten:
find_package(PostgreSQL REQUIRED)
find_package(cpprestsdk REQUIRED)

add_executable(OOPbackend ./src/main.cpp)

# Fügen Sie hier Ihre Quelldateien hinzu.
target_sources(OOPbackend PRIVATE
    ./src/main.cpp
    ./src/DatabaseManager.cpp
    ./src/HttpManager.cpp
    ./src/RezeptManager.cpp
    ./src/ProductionManager.cpp
    ./src/PersonalManager.cpp
    ./src/MaschinenManager.cpp
    ./src/ResourcenManager.cpp
    ./src/SzenarioManager.cpp
)

target_include_directories(OOPbackend PRIVATE ${PostgreSQL_INCLUDE_DIRS})

target_link_libraries(OOPbackend PRIVATE ${PostgreSQL_LIBRARIES} cpprestsdk::cpprest)
