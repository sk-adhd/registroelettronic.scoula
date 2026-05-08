#include "admin.h"
#include <iostream>

Admin::Admin(Database* database) : db(database) {}

void Admin::creaUtente() {
    std::string u,p,r;
    std::cout << "Username: "; std::cin >> u;
    std::cout << "Password: "; std::cin >> p;
    std::cout << "Ruolo: "; std::cin >> r;

    db->createUser(u,p,r);
}