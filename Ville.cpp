#include "Ville.h"

Ville::Ville() {}
Ville::Ville(const std::string& nom) : nom(nom), coteOuest(false), coteEst(false) {}

const std::string& Ville::getNom() const 
{
    return nom;
}

bool Ville::estCoteOuest() const 
{
    return coteOuest;
}

bool Ville::estCoteEst() const 
{
    return coteEst;
}
