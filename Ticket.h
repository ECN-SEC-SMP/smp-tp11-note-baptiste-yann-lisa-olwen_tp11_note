#pragma once
#include "Ville.h"
#include <string>

class Ticket {
private:
    int id;
    Ville villeA;
    Ville villeB;
    bool valide;
public:
    Ticket(int id, const Ville& vA, const Ville& vB);
    int getId() const;
    const Ville& getVilleA() const;
    const Ville& getVilleB() const;
    bool estValide() const;
    bool operator==(const Ticket& other) const;
};

