#include "database.h"
#include <iostream>

Database::Database() : db(nullptr) {}

Database::~Database() {
    if (db) sqlite3_close(db);
}

bool Database::connect(const std::string& filename) {
    return sqlite3_open(filename.c_str(), &db) == SQLITE_OK;
}

void Database::init() {
    execute("CREATE TABLE IF NOT EXISTS utenti (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT, ruolo TEXT);");
    execute("CREATE TABLE IF NOT EXISTS voti (id INTEGER PRIMARY KEY AUTOINCREMENT, studente TEXT, materia TEXT, voto REAL);");
    execute("CREATE TABLE IF NOT EXISTS presenze (id INTEGER PRIMARY KEY AUTOINCREMENT, studente TEXT, data TEXT, presente INTEGER);");
}

bool Database::execute(const std::string& query) {
    char* errMsg = nullptr;
    int res = sqlite3_exec(db, query.c_str(), callback, nullptr, &errMsg);

    if (res != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool Database::createUser(const std::string& username, const std::string& password, const std::string& ruolo) {
    std::string sql = "INSERT INTO utenti (username,password,ruolo) VALUES ('" + username + "','" + password + "','" + ruolo + "');";
    return execute(sql);
}

bool Database::insertVoto(const std::string& studente, const std::string& materia, float voto) {
    std::string sql = "INSERT INTO voti (studente,materia,voto) VALUES ('" + studente + "','" + materia + "'," + std::to_string(voto) + ");";
    return execute(sql);
}

bool Database::insertPresenza(const std::string& studente, const std::string& data, int presente) {
    std::string sql = "INSERT INTO presenze (studente,data,presente) VALUES ('" + studente + "','" + data + "'," + std::to_string(presente) + ");";
    return execute(sql);
}

int Database::callback(void*, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << "-------------------\n";
    return 0;
}