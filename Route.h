/**
 * @file Route.h
 * @brief Déclaration de la classe Route.
 * @ingroup Modele
 */

#pragma once

#include <string>
#include "Joueur.h"
#include "Ville.h"
#include "CouleurCarte.h"
#include "CouleurRoute.h"
#include "CouleurWagon.h"

class Joueur; ///< Déclaration anticipée pour éviter les inclusions circulaires.

/**
 * @brief Représente une route entre deux villes sur le plateau.
 *
 * Une route est caractérisée par ses deux villes extrémités, sa couleur,
 * sa longueur (nombre de wagons requis) et son éventuelle voie parallèle
 * dans le cas d'une route double. Elle peut être revendiquée par un joueur.
 *
 * @ingroup Modele
 */
class Route {
public:
    // ── Constructeurs ─────────────────────────────────────────────────────────

    /** @brief Constructeur par défaut — crée une route vide sans propriétaire. */
    Route();

    /**
     * @brief Crée une route avec ses caractéristiques de base.
     * @param longueur       Nombre de wagons nécessaires pour revendiquer la route.
     * @param estRouteDouble @c true si la route possède une voie parallèle.
     * @param couleurRoute   Couleur de la voie principale (voir @ref CouleurRoute).
     */
    Route(int longueur, bool estRouteDouble, CouleurRoute couleurRoute);

    // ── Accesseurs ────────────────────────────────────────────────────────────

    /** @brief Retourne la ville de départ de la route. */
    Ville getVilleA() const;

    /** @brief Retourne la ville d'arrivée de la route. */
    Ville getVilleB() const;

    /** @brief Retourne la couleur principale de la route (voir @ref CouleurRoute). */
    CouleurRoute getCouleur() const;

    /** @brief Retourne la couleur de la voie parallèle (voir @ref CouleurRoute). */
    CouleurRoute getCouleur2() const;

    /** @brief Retourne le nombre de wagons nécessaires pour revendiquer la route. */
    int getLongueur() const;

    /**
     * @brief Retourne le propriétaire de la route.
     * @return Pointeur vers le joueur propriétaire, ou @c nullptr si la route est libre.
     */
    Joueur* getProprio() const;

    /** @brief Indique si la route est une route double. */
    bool getEstDouble() const;

    // ── Mutateurs ─────────────────────────────────────────────────────────────

    /**
     * @brief Définit le propriétaire de la route.
     * @param j Pointeur vers le joueur qui revendique la route.
     */
    void setProprio(Joueur* j);

    /**
     * @brief Définit la couleur de la voie parallèle.
     * @param c Couleur de la seconde voie (voir @ref CouleurRoute).
     */
    void setCouleur2(CouleurRoute c);

    /**
     * @brief Définit la ville de départ de la route.
     * @param v Ville de départ.
     */
    void setVilleA(Ville v);

    /**
     * @brief Définit la ville d'arrivée de la route.
     * @param v Ville d'arrivée.
     */
    void setVilleB(Ville v);

    // ── Méthodes ──────────────────────────────────────────────────────────────

    /**
     * @brief Vérifie si la route est disponible (non revendiquée).
     * @return @c true si aucun joueur ne possède la route, @c false sinon.
     */
    bool estDispo() const;

private:
    Ville        villeA;         ///< Ville de départ.
    Ville        villeB;         ///< Ville d'arrivée.
    CouleurRoute couleurRoute;   ///< Couleur de la voie principale.
    CouleurRoute couleurRoute2;  ///< Couleur de la voie parallèle (route double).
    int          longueur;       ///< Nombre de wagons requis.
    bool         estRouteDouble; ///< @c true si la route possède une voie parallèle.
    Joueur*      proprio;        ///< Propriétaire de la route (@c nullptr si libre).
};