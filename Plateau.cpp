# include "Plateau.h"
#include "Joueur.h"
#include "Ticket.h"
#include "Route.h"
#include "CarteTrain.h"
#include "Ville.h"

#include <iostream>
#include <string>
#include <vector>

Plateau::Plateau()
{
    // Rien à mettre dedans car paramètres par défaut
}

Plateau::Plateau(int A, int B)
{
    // Paramètres à compléter
}

std::vector<Ville> Plateau::getVille() const
{
    return ville;
}

std::vector<Route> Plateau::getRoute() const
{
    return route;
}

std::vector<CarteTrain> Plateau::getPioche() const
{
    return pioche;
}

std::vector<Ticket> Plateau::getDefausseTicket() const
{
    return defausseTicket;
}

std::vector<Route*> Plateau::setRouteJoueur(Joueur* j)
{
    std::vector<Route*> routesPrises;
    for (int i = 0; i < route.size(); i++)      // Parcours de toutes les routes du plateau
    {
        if (route[i].getProprio() == j)         // Si le propriétaire de la route est le joueur j   
        {
            routesPrises.push_back(&route[i]);  // On ajoute un pointeur vers la route à la liste des routes prises par le joueur
        }
    }
    return routesPrises;                        // On retourne la liste des routes prises par le joueur
}

void Plateau::chargerVilleCsv()
{
    // Charger le fichier .csv des villes
}

void Plateau::chargerRouteCsv()
{
    // Charger le fichier .csv des routes
}

void Plateau::afficher()
{
    // Afficher le plateau de jeu
}

void Plateau::retirerCartePioche()
{
    pioche.pop_back(); // Retire la dernière carte de la pioche
}

void Plateau::ajouterDefausseTicket(Ticket ticket)
{
    defausseTicket.push_back(ticket); // Ajoute un ticket à la défausse
}


