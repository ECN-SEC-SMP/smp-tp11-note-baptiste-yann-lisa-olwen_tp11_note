#pragma once
#include <vector>

#include "Ville.h"
#include "Route.h"

class Plateau {
public:
    // Constructeurs 
    Plateau();
    Plateau(int A, int B); // Paramètres à compléter

    // Accesseurs
    std::vector<Ville> getVille() const;
    std::vector<Route> getRoute() const;
    std::vector<CarteTrain>& getPioche();
    void setPioche(std::vector<CarteTrain> p);
    std::vector<Ticket> getTickets() const;
    std::vector<Ticket> getDefausseTicket() const;

    // Mutateurs
    std::vector<Route*> setRouteJoueur(Joueur* j);

    // Méthodes
    void chargerMapCsv(); // Charger le fichier .csv des villes
    void chargerTicketCsv(); // Charger le fichier .csv des routes
    void afficher();
    void retirerCartePioche();
    void ajouterDefausseTicket(Ticket ticket);

private:
    std::vector<Ville> ville;
    std::vector<Route> route;
    std::vector<CarteTrain> pioche;
    std::vector<Ticket> tickets;
    std::vector<Ticket> defausseTicket;

};
