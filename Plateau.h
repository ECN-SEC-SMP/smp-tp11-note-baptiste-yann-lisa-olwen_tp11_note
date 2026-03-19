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

    // Mutateurs
    std::vector<Route*> setRouteJoueur(Joueur* j);

    // Méthodes
    void chargerVilleOn(); // ??????????????
    void chargerRouteOn(); // ??????????????
    void afficher();

private:
    std::vector<Ville> ville;
    std::vector<Route> route;

};
