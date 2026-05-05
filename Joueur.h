/**
 * @file Joueur.h
 * @brief Déclaration de la classe Joueur.
 * @ingroup Joueurs
 */

#pragma once

#include <string>
#include <vector>
#include <map>

#include "CouleurWagon.h"
#include "Ticket.h"
#include "CarteTrain.h"
#include "Route.h"

class Route;
class Plateau; ///< Déclaration anticipée pour éviter les inclusions circulaires.

/**
 * @brief Représente un joueur de la partie.
 *
 * Un joueur possède un prénom, une couleur de wagon, une main de cartes train,
 * des tickets destination et un stock de wagons. Il peut piocher, défausser,
 * revendiquer des routes et valider ses tickets.
 *
 * @ingroup Joueurs
 */
class Joueur {
public:
    /**
     * @brief Constructeur par défaut — crée un joueur sans nom ni couleur.
     */
    Joueur();

    /**
     * @brief Crée un joueur avec un prénom et une couleur de wagon.
     * @param prenom       Prénom du joueur.
     * @param couleurWagon Couleur des wagons attribuée au joueur (voir @ref CouleurWagon).
     */
    Joueur(std::string prenom, CouleurWagon couleurWagon);

    // ── Accesseurs ────────────────────────────────────────────────────────────

    /** @brief Retourne le prénom du joueur. */
    std::string getPrenom() const;

    /** @brief Retourne la main du joueur (cartes train en sa possession). */
    std::vector<CarteTrain>& getMain();

    /** @brief Retourne le nombre de wagons restants. */
    int getNbWagon() const;

    /** @brief Retourne les tickets destination du joueur. */
    std::vector<Ticket>& getTicket();

    /** @brief Retourne le nombre de tickets validés. */
    int getTicketValide() const;

    /** @brief Retourne la couleur de wagon du joueur (voir @ref CouleurWagon). */
    CouleurWagon getCouleurWagon() const;

    // ── Mutateurs ─────────────────────────────────────────────────────────────

    /**
     * @brief Modifie le nombre de tickets validés.
     * @param nbTicketValide Nouveau nombre de tickets validés.
     */
    void setNbTicketValide(int nbTicketValide);

    /**
     * @brief Modifie le nombre de wagons restants.
     * @param nb Nouveau nombre de wagons.
     */
    void setNbWagon(int nb);

    // ── Méthodes ──────────────────────────────────────────────────────────────

    /**
     * @brief Pioche la carte du dessus de la pioche et l'ajoute à la main.
     * @param plateau Pointeur vers le plateau contenant la pioche.
     */
    void piocherCarte(Plateau* plateau);

    /**
     * @brief Retire la première occurrence d'une carte de la main.
     * @param carteTrain Carte à défausser.
     */
    void defausserCarte(CarteTrain carteTrain);

    /**
     * @brief Ajoute un ticket destination à la main du joueur.
     * @param nouvTicket Ticket à ajouter.
     */
    void piocherTicket(Ticket nouvTicket);

    /**
     * @brief Défausse un ticket vers la défausse du plateau.
     * @param ticket  Ticket à défausser.
     * @param plateau Pointeur vers le plateau contenant la défausse.
     */
    void defausserTicket(Ticket ticket, Plateau* plateau);

    /**
     * @brief Valide un ticket si son objectif est atteint.
     * @param t Pointeur vers le ticket à valider.
     */
    void validerTicket(Ticket* t);

    /**
     * @brief Vérifie si le joueur peut revendiquer une route.
     * @param route Pointeur vers la route à tester.
     * @return @c true si la route est disponible, @c false sinon.
     */
    bool peutPrendreRoute(Route* route);

    /** @brief Affiche dans la console toutes les cartes train de la main. */
    void afficherMain();

    /** @brief Surcharge const de l'affichage de la main. */
    void afficherMain() const;

    /**
     * @brief Gère le bonus de la grande traversée.
     * @param B @c true si la grande traversée est réussie, @c false sinon.
     */
    void GrandeTraversee(bool B);

    /**
     * @brief Vérifie si un ticket destination est complété par les routes du joueur.
     *
     * Effectue un BFS sur le graphe des routes appartenant au joueur.
     *
     * @complexity O(V + E) où V est le nombre de villes et E le nombre de routes du joueur.
     *
     * @param t      Ticket destination à vérifier.
     * @param routes Liste complète des routes du plateau.
     * @return @c true si le joueur relie les deux villes du ticket, @c false sinon.
     */
    bool verifierTicket(Ticket t, std::vector<Route>& routes);

    /** 
     * @brief Vider les tickets destination du joueur. 
     * Permet de réinitialiser l'état du joueur entre les parties ou après un échange de tickets.
     * */
    void viderTickets();

private:
    std::string              prenom;         ///< Prénom du joueur.
    std::vector<CarteTrain>  main;           ///< Cartes train en main.
    CouleurWagon             couleurWagon;   ///< Couleur des wagons du joueur.
    int                      nbWagon;        ///< Nombre de wagons restants.
    std::vector<Ticket>      ticket;         ///< Tickets destination en main.
    int                      nbTicketValide; ///< Nombre de tickets complétés.
    int                      grdTraversee;   ///< Indicateur de grande traversée.
};