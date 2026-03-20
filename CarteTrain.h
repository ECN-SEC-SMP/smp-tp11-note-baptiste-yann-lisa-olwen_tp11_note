#pragma once
#include "CouleurCarte.h"

class CarteTrain
{
private:
    CouleurCarte couleur;
public:
    CarteTrain(CouleurCarte couleur);
    CouleurCarte getCouleur() const;

    // Surcharge d'opérateur
    bool operator==(const CarteTrain& other) const;
};

