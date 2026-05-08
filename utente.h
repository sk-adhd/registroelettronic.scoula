#ifndef UTENTE_H
#define UTENTE_H

#include <string>

class Utente {
protected:
    int id;
    std::string username;
    std::string password;
    std::string ruolo;

public:
    Utente();
    Utente(int id, std::string u, std::string p, std::string r);

    virtual void mostraMenu() = 0;

    std::string getRuolo();
};

#endif