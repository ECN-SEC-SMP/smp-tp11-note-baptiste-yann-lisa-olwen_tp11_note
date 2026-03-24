#include "Route.h"


//////////////////////////////////////
////// Constructeur par défaut ///////
//////////////////////////////////////
Route::Route()
{
    // Rien à mettre dedans car paramètres par défaut
}

Route::Route(int longueur, bool estRouteDouble, CouleurRoute couleurRoute) : longueur(longueur), estRouteDouble(estRouteDouble), couleurRoute(couleurRoute) {}


//////////////////////////////////////
//////////// Accesseurs //////////////
//////////////////////////////////////
Ville Route::getVilleA() const
{
    return villeA;
}

Ville Route::getVilleB() const
{
    return villeB;
}

CouleurRoute Route::getCouleur() const
{
    return couleurRoute;
}

int Route::getLongueur() const
{
    return longueur;
}

Joueur* Route::getProprio() const
{
    return proprio;
}

bool Route::getEstDouble() const
{
    return estRouteDouble;
}


//////////////////////////////////////
///////////// Mutateurs //////////////
//////////////////////////////////////
void Route::setProprio(Joueur* j)
{
    proprio = j;
}


//////////////////////////////////////
///////////// Méthodes ///////////////
//////////////////////////////////////
bool Route::estDispo()
{
    return proprio == nullptr;
}






    





