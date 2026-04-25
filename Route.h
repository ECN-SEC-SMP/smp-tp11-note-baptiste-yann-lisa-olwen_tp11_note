#pragma once
#include <string>

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
    CouleurRoute getCouleur2() const;
    int getLongueur() const;
    Joueur* getProprio() const;
    bool getEstDouble() const;

    // Mutateurs
    void setProprio(Joueur* j);
    void setCouleur2(CouleurRoute c);
    void setVilleA(Ville v);
    void setVilleB(Ville v);

    // Méthodes
    bool estDispo() const;

private :
    Ville villeA;
    Ville villeB;
    CouleurRoute couleurRoute;
    CouleurRoute couleurRoute2;
    int longueur;
    bool estRouteDouble;
    Joueur* proprio;
};



    