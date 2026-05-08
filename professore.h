#ifndef PROFESSORE_H
#define PROFESSORE_H

#include "database.h"

class Professore {
private:
    Database* db;

public:
    Professore(Database* database);
    void inserisciVoto();
    void segnaPresenza();
};

#endif