/**
 * @file CarteTrain.h
 * @author Lisa Le Goff (lisalegoff29@gmail.com)
 * @brief Description de la classe CarteTrain
 * @version 0.1
 * @date 2026-03-31
 */
 
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

