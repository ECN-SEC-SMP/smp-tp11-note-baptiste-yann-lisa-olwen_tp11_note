/**
 * @file CouleurCarte.h
 * @brief Définition des couleurs de cartes train et utilitaire de conversion.
 * @ingroup Cartes
 */

#pragma once

#include <string>

/**
 * @brief Couleurs possibles d'une carte train.
 *
 * La valeur @c Locomotive est une carte joker utilisable à la place
 * de n'importe quelle autre couleur.
 *
 * @ingroup Cartes
 */
enum class CouleurCarte
{
    Bleu,        ///< Carte bleue.
    Blanc,       ///< Carte blanche.
    Rouge,       ///< Carte rouge.
    Noir,        ///< Carte noire.
    Jaune,       ///< Carte jaune.
    Vert,        ///< Carte verte.
    Locomotive   ///< Carte locomotive (joker).
};

/**
 * @brief Convertit une @ref CouleurCarte en chaîne de caractères lisible.
 * @param couleur La couleur à convertir.
 * @return Le nom de la couleur en français, ou @c "Inconnu" si non reconnue.
 * @ingroup Cartes
 */
inline std::string couleurToString(CouleurCarte couleur)
{
    switch (couleur) {
        case CouleurCarte::Bleu:       return "Bleu";
        case CouleurCarte::Blanc:      return "Blanc";
        case CouleurCarte::Rouge:      return "Rouge";
        case CouleurCarte::Noir:       return "Noir";
        case CouleurCarte::Jaune:      return "Jaune";
        case CouleurCarte::Vert:       return "Vert";
        case CouleurCarte::Locomotive: return "Locomotive";
        default:                       return "Inconnu";
    }
}