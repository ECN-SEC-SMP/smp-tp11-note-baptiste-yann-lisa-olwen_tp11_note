#include "Ticket.h"

Ticket::Ticket(int id, const Ville& vA, const Ville& vB) : id(id), villeA(vA), villeB(vB), valide
(true) {}

int Ticket::getId() const { return id; }

const Ville& Ticket::getVilleA() const { return villeA; }

const Ville& Ticket::getVilleB() const { return villeB; }

bool Ticket::estValide() const { return valide; }
