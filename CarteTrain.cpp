#include "CarteTrain.h"

CarteTrain::CarteTrain(CouleurCarte couleur) : couleur(couleur) 
{
    // Rien à faire
}

CouleurCarte CarteTrain::getCouleur() const
{
    return couleur;
}


bool CarteTrain::operator==(const CarteTrain& other) const
{
    return couleur == other.couleur;
}
