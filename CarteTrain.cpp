#include "CarteTrain.h"

/**
 * @brief Initialise une carte train avec la couleur donnée.
 * @param couleur Couleur de la carte (voir @ref CouleurCarte).
 * @ingroup Cartes
 */
CarteTrain::CarteTrain(CouleurCarte couleur) : couleur(couleur) 
{
    // Rien à faire
}

/**
 * @brief Retourne la couleur de la carte train.
 * @return La couleur de cette carte (voir @ref CouleurCarte).
 */
CouleurCarte CarteTrain::getCouleur() const
{
    return couleur;
}

/**
 * @brief Compare deux cartes train par leur couleur.
 * @param other Carte à comparer.
 * @return @c true si les deux cartes ont la même couleur, @c false sinon.
 */
bool CarteTrain::operator==(const CarteTrain& other) const
{
    return couleur == other.couleur;
}