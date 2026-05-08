#include "utente.h"

Utente::Utente() {}

Utente::Utente(int id, std::string u, std::string p, std::string r)
    : id(id), username(u), password(p), ruolo(r) {}

std::string Utente::getRuolo() {
    return ruolo;
}