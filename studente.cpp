#include "studente.h"
#include <iostream>

Studente::Studente(Database* database, std::string user)
    : db(database), username(user) {}

void Studente::vediVoti() {
    db->execute("SELECT * FROM voti WHERE studente='" + username + "';");
}

void Studente::vediPresenze() {
    db->execute("SELECT * FROM presenze WHERE studente='" + username + "';");
}