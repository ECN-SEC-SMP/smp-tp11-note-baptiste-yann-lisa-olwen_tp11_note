/**
 * @file Plateau.h
 * @brief Déclaration de la classe Plateau.
 * @ingroup Modele
 */

#pragma once

#include <vector>
#include "Ville.h"
#include "Route.h"

class Joueur; ///< Déclaration anticipée pour éviter les inclusions circulaires.

/**
 * @brief Représente le plateau de jeu.
 *
 * Le plateau centralise toutes les données du jeu : villes, routes,
 * pioche de cartes train, tickets destination et défausses.
 * Il fournit également les méthodes de chargement depuis des fichiers CSV.
 *
 * @ingroup Modele
 */
class Plateau {
public:
    // ── Constructeurs ─────────────────────────────────────────────────────────

    /** @brief Constructeur par défaut — crée un plateau vide. */
    Plateau();

    /**
     * @brief Constructeur avec paramètres (à compléter).
     * @param A Premier paramètre de configuration.
     * @param B Second paramètre de configuration.
     */
    Plateau(int A, int B);

    // ── Accesseurs ────────────────────────────────────────────────────────────

    /** @brief Retourne la liste des villes du plateau. */
    std::vector<Ville> getVille() const;

    /** @brief Retourne la liste des routes du plateau. */
    std::vector<Route>& getRoute();

    /** @brief Retourne la pioche de cartes train. */
    std::vector<CarteTrain>& getPioche();

    /**
     * @brief Remplace la pioche par un nouveau jeu de cartes.
     * @param p Nouveau vecteur de cartes train.
     */
    void setPioche(std::vector<CarteTrain> p);

    /** @brief Retourne les tickets destination disponibles. */
    std::vector<Ticket> getTickets() const;

    /** @brief Retourne la défausse de tickets. */
    std::vector<Ticket> getDefausseTicket() const;

    /** @brief Retourne la défausse de cartes train. */
    std::vector<CarteTrain> getDefausseCartes() const;

    // ── Mutateurs ─────────────────────────────────────────────────────────────

    /**
     * @brief Retourne la liste des routes appartenant à un joueur donné.
     * @param j Pointeur vers le joueur dont on cherche les routes.
     * @return Vecteur de pointeurs vers les routes du joueur.
     */
    std::vector<Route*> setRouteJoueur(Joueur* j);

    // ── Méthodes ──────────────────────────────────────────────────────────────

    /**
     * @brief Charge les routes depuis le fichier @c route.csv.
     * @see chargerTicketCsv()
     */
    void chargerMapCsv();

    /**
     * @brief Charge les tickets destination depuis le fichier @c Ticket.csv.
     * @see chargerMapCsv()
     */
    void chargerTicketCsv();

    /** @brief Affiche le plateau dans la console (à implémenter). */
    void afficher();

    /** @brief Retire la carte du dessus de la pioche. */
    void retirerCartePioche();

    /**
     * @brief Ajoute un ticket à la défausse.
     * @param ticket Ticket à défausser.
     */
    void ajouterDefausseTicket(Ticket ticket);

    /** @brief Vide la défausse de tickets. */
    void viderDefausseTicket();

    /**
     * @brief Ajoute une carte train à la défausse de cartes.
     * @param carte Carte à défausser.
     */
    void ajouterDefausseCartes(CarteTrain carte);

    /** @brief Vide la défausse de cartes train. */
    void viderDefausseCartes();

private:
    std::vector<Ville>      ville;          ///< Villes du plateau.
    std::vector<Route>      route;          ///< Routes du plateau.
    std::vector<CarteTrain> pioche;         ///< Pioche de cartes train.
    std::vector<Ticket>     tickets;        ///< Tickets destination disponibles.
    std::vector<Ticket>     defausseTicket; ///< Défausse de tickets.
    std::vector<CarteTrain> defausseCartes; ///< Défausse de cartes train.
};