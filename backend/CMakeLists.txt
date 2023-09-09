cmake_minimum_required(VERSION 3.14)
project(OOPbackend)

set(CMAKE_CXX_STANDARD 17)

# Fügen Sie hier die erforderlichen Bibliotheken hinzu, wenn Sie sie benötigen.
# Zum Beispiel, wenn Sie PostgreSQL verwenden möchten:
find_package(PostgreSQL REQUIRED)
find_package(cpprestsdk REQUIRED)

# Fügen Sie die Pfade zu den Dateien der Env-Klasse hinzu
set(ENV_CLASS_DIR extern/LibEnv)
include_directories(${ENV_CLASS_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include/pqxx)

find_library(PQXX_LIB pqxx)
find_library(PQ_LIB pq)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

# Fügen Sie die Quelldateien der Env-Klasse hinzu
list(APPEND SOURCE_FILES ${ENV_CLASS_DIR}/Env.cpp)

add_executable(OOPbackend ${SOURCE_FILES})

target_include_directories(OOPbackend PRIVATE ${ENV_CLASS_DIR})

target_link_libraries(OOPbackend PRIVATE ${PQXX_LIB} ${PQ_LIB} cpprestsdk::cpprest)
