#pragma once
#include <string>

#include "Joueur.h"
#include "Ville.h"
#include "CouleurCarte.h"
#include "CouleurRoute.h"
#include "CouleurWagon.h"

class Joueur;

class Route { 
public :   
    // Constructeurs 
    Route();
    Route(int longueur, bool estRouteDouble, CouleurRoute couleurRoute); 

    // Accesseurs
    Ville getVilleA() const;
    Ville getVilleB() const;
    CouleurRoute getCouleur() const;
    int getLongueur() const;
    Joueur* getProprio() const;
    bool getEstDouble() const;

    // Mutateurs
    void setProprio(Joueur* j);

    // Méthodes
    bool estDispo() const;

private :
    Ville villeA;
    Ville villeB;
    CouleurRoute couleurRoute;
    int longueur;
    bool estRouteDouble;
    Joueur* proprio;
};