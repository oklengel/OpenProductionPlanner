cmake_minimum_required(VERSION 3.14)
project(RecipeServer)

set(CMAKE_CXX_STANDARD 14)

# Fügen Sie hier die erforderlichen Bibliotheken hinzu, wenn Sie sie benötigen.
# Zum Beispiel, wenn Sie PostgreSQL verwenden möchten:
find_package(PostgreSQL REQUIRED)
find_package(cpprestsdk REQUIRED)

add_executable(RecipeServer ./src/main.cpp)

# Fügen Sie hier Ihre Quelldateien hinzu.
target_sources(RecipeServer PRIVATE
    ./src/main.cpp
    ./src/DatabaseManager.cpp
    ./src/HttpManager.cpp
    ./src/RezeptManager.cpp
    ./src/ProductionManager.cpp
)

target_include_directories(RecipeServer PRIVATE ${PostgreSQL_INCLUDE_DIRS})

target_link_libraries(RecipeServer PRIVATE ${PostgreSQL_LIBRARIES} cpprestsdk::cpprest)
