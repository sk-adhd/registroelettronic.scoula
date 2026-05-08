#include <iostream>
#include "database.h"
#include "admin.h"
#include "professore.h"
#include "studente.h"

int main() {
    Database db;
    db.connect("registro.db");
    db.init();

    int scelta;

    while (true) {
        std::cout << "\n=== REGISTRO ===\n";
        std::cout << "1. Studente\n2. Docente\n3. Admin\n0. Esci\nScelta: ";
        std::cin >> scelta;

        if (scelta == 0) break;

        if (scelta == 1) {
           std::string user;
           std::cout << "Username studente: ";
           std::cin >> user;
           Studente s(&db, user);
            int c;
            std::cout << "1 Voti 2 Presenze: ";
            std::cin >> c;
            if (c==1) s.vediVoti();
            else s.vediPresenze();
        }
        else if (scelta == 2) {
            Professore p(&db);
            int c;
            std::cout << "1 Voto 2 Presenza: ";
            std::cin >> c;
            if (c==1) p.inserisciVoto();
            else p.segnaPresenza();
        }
        else if (scelta == 3) {
            Admin a(&db);
            a.creaUtente();
        }
    }

    return 0;
}