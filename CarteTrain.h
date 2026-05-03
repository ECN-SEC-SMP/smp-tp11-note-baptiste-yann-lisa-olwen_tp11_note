/**
 * @file CarteTrain.h
 * @author Lisa Le Goff (lisalegoff29@gmail.com)
 * @brief Description de la classe CarteTrain
 * @version 0.1
 * @date 2026-03-31
 * @ingroup Cartes
 */

#pragma once

#include "CouleurCarte.h"

/**
 * @brief Représente une carte train identifiée par sa couleur.
 *
 * Les joueurs collectent des cartes train pour revendiquer des routes
 * dont la couleur correspond à celle de leurs cartes.
 *
 * @ingroup Cartes
 */
class CarteTrain
{
private:
    CouleurCarte couleur; ///< Couleur de cette carte train.

public:
    /**
     * @brief Initialise une carte train avec la couleur donnée.
     * @param couleur Couleur de la carte (voir @ref CouleurCarte).
     */
    CarteTrain(CouleurCarte couleur);

    /**
     * @brief Retourne la couleur de la carte train.
     * @return La couleur de cette carte (voir @ref CouleurCarte).
     */
    CouleurCarte getCouleur() const;

    /**
     * @brief Compare deux cartes train par leur couleur.
     * @param other Carte à comparer.
     * @return @c true si les deux cartes ont la même couleur, @c false sinon.
     */
    bool operator==(const CarteTrain& other) const;
};