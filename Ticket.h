/**
 * @file Ticket.h
 * @brief Déclaration de la classe Ticket.
 * @ingroup Cartes
 */

#pragma once

#include "Ville.h"
#include <string>

/**
 * @brief Représente un ticket destination entre deux villes.
 *
 * Un ticket impose au joueur de relier deux villes par ses routes
 * pour marquer des points en fin de partie. S'il n'y parvient pas,
 * les points sont déduits de son score.
 *
 * @ingroup Cartes
 */
class Ticket {
private:
    int   id;     ///< Identifiant unique du ticket.
    Ville villeA; ///< Ville de départ.
    Ville villeB; ///< Ville d'arrivée.
    bool  valide; ///< @c true si le ticket est encore en jeu.

public:
    /**
     * @brief Crée un ticket destination entre deux villes.
     * @param id Identifiant unique du ticket.
     * @param vA Ville de départ.
     * @param vB Ville d'arrivée.
     */
    Ticket(int id, const Ville& vA, const Ville& vB);

    /** @brief Retourne l'identifiant unique du ticket. */
    int getId() const;

    /** @brief Retourne la ville de départ du ticket. */
    const Ville& getVilleA() const;

    /** @brief Retourne la ville d'arrivée du ticket. */
    const Ville& getVilleB() const;

    /**
     * @brief Indique si le ticket est encore valide.
     * @return @c true si le ticket est valide, @c false sinon.
     */
    bool estValide() const;

    // Potentiellement fonction pour afficher le ticket
};