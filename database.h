#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "sqlite3.h"

class Database {
private:
    sqlite3* db;

public:
    Database();
    ~Database();

    bool connect(const std::string& filename);
    void init();
    bool execute(const std::string& query);

    static int callback(void* NotUsed, int argc, char** argv, char** azColName);

    bool createUser(const std::string& username, const std::string& password, const std::string& ruolo);
    bool insertVoto(const std::string& studente, const std::string& materia, float voto);
    bool insertPresenza(const std::string& studente, const std::string& data, int presente);
};

#endif