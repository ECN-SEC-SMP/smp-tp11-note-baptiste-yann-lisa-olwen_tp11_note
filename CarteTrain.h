#include "CouleurCarte.h"
#ifndef CARTETRAIN_H
#define CARTETRAIN_H

class CarteTrain
{
private:
    CouleurCarte couleur;
public:
    CarteTrain(CouleurCarte couleur);
    CouleurCarte getCouleur() const;
};

#endif 