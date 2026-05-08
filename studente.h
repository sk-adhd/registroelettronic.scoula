#ifndef STUDENTE_H
#define STUDENTE_H

#include "database.h"
#include <string>

class Studente {
private:
    Database* db;
    std::string username;

public:
    Studente(Database* database, std::string user);
    void vediVoti();
    void vediPresenze();
};

#endif