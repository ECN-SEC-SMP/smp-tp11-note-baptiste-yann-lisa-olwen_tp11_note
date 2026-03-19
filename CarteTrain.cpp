#include "CarteTrain.h"

CarteTrain::CarteTrain(CouleurCarte couleur) : couleur(couleur) {}

CouleurCarte CarteTrain::getCouleur() const
{
    return couleur;
}
