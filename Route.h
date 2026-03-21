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
    Route(int longueur, bool estRouteDouble, CouleurRoute couleurRoute); 

    // Accesseurs
    Ville getVilleA() const;
    Ville getVilleB() const;
    CouleurRoute getCouleur() const;
    int getLongueur() const;
    Joueur* getProprio() const;

    // Mutateurs
    void setProprio(Joueur* j);

    // Méthodes
    bool estDouble();
    bool estDispo();

private :
    Ville villeA;
    Ville villeB;
    CouleurRoute couleurRoute;
    int longueur;
    bool estRouteDouble;
    Joueur* proprio;
};