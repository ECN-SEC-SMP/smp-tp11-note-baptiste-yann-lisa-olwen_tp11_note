/**
 * @file CouleurWagon.h
 * @brief Définition des couleurs de wagons des joueurs.
 * @ingroup Joueurs
 */

#pragma once

/**
 * @brief Couleurs possibles des wagons d'un joueur.
 *
 * Chaque joueur se voit attribuer une couleur de wagon unique
 * qui l'identifie visuellement sur le plateau.
 *
 * @ingroup Joueurs
 */
enum class CouleurWagon
{
    Bleu,   ///< Wagons bleus.
    Rouge,  ///< Wagons rouges.
    Jaune,  ///< Wagons jaunes.
    Vert,   ///< Wagons verts.
};