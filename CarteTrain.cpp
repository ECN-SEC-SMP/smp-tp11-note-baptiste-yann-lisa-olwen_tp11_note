#include "CarteTrain.h"

/**
 * @brief   Constructeur de la classe CarteTrain qui initialise la couleur de la carte de train
 * 
 * @param couleur 
 */
CarteTrain::CarteTrain(CouleurCarte couleur) : couleur(couleur) 
{
    // Rien à faire
}

/**
 * @brief Accesseur pour la couleur de la carte de train
 * 
 * @return CouleurCarte 
 */
CouleurCarte CarteTrain::getCouleur() const
{
    return couleur;
}

/**
 * @brief Surcharge d'opérateur d'égalité pour comparer deux cartes de train en fonction de leur couleur
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool CarteTrain::operator==(const CarteTrain& other) const
{
    return couleur == other.couleur;
}
