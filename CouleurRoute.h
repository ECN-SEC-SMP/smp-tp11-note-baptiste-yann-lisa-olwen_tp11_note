/**
 * @file CouleurRoute.h
 * @brief Définition des couleurs de routes du plateau.
 * @ingroup Modele
 */

#pragma once

/**
 * @brief Couleurs possibles d'une route sur le plateau de jeu.
 *
 * Chaque route du plateau possède une couleur ; le joueur doit poser
 * des cartes train de la couleur correspondante (ou des locomotives)
 * pour la revendiquer.
 *
 * @ingroup Modele
 */
enum class CouleurRoute
{
    Bleu,   ///< Route bleue.
    Blanc,  ///< Route blanche.
    Rouge,  ///< Route rouge.
    Jaune,  ///< Route jaune.
    Noir,   ///< Route noire.
    Vert    ///< Route verte.
};