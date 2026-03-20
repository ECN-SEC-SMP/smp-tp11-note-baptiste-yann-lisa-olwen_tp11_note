#pragma once
#include <string>

#include "Joueur.h"
#include "Ville.h"
#include "CouleurCarte.h"
#include "CouleurRoute.h"
#include "CouleurWagon.h"

class Route { 
public :   
    // Constructeurs 
    Route();
    Route(int A, int B); // Paramètres à compléter

    // Accesseurs
    Ville getVilleA() const;
    Ville getVilleB() const;
    CouleurRoute getCouleur() const;
    int getLongueur() const;
    Joueur getProprio() const;

    // Mutateurs
    void setProprio(Joueur* j);

    // Méthodes
    bool estDouble();
    bool estDispo();

private :
    Ville VilleA();
    Ville VilleB();
    CouleurRoute Couleur;
    int longueur;
    bool estDouble;
    Joueur proprio;
};