#include "professore.h"
#include <iostream>

Professore::Professore(Database* database) : db(database) {}

void Professore::inserisciVoto() {
    std::string s,m;
    float v;
    std::cout << "Studente: "; std::cin >> s;
    std::cout << "Materia: "; std::cin >> m;
    std::cout << "Voto: "; std::cin >> v;

    db->insertVoto(s,m,v);
}

void Professore::segnaPresenza() {
    std::string s,d;
    int p;
    std::cout << "Studente: "; std::cin >> s;
    std::cout << "Data: "; std::cin >> d;
    std::cout << "Presente (1/0): "; std::cin >> p;

    db->insertPresenza(s,d,p);
}