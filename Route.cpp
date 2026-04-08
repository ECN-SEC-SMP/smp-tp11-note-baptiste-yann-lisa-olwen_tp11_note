#include "Route.h"
#include "Joueur.h"
#include "Plateau.h"

/**
 * @brief Constructeur par défaut et constructeur avec paramètres pour la classe Route
 * 
 */
//////////////////////////////////////
////// Constructeur par défaut ///////
//////////////////////////////////////
Route::Route()
{
    // Rien à mettre dedans car paramètres par défaut
}

/**
 * @brief Constructeur de la classe Route avec paramètres pour initialiser les éléments d'une route du plateau de jeu
 * 
 * @param longueur 
 * @param estRouteDouble 
 * @param couleurRoute 
 */
Route::Route(int longueur, bool estRouteDouble, CouleurRoute couleurRoute) : longueur(longueur), estRouteDouble(estRouteDouble), couleurRoute(couleurRoute) {}


//////////////////////////////////////
//////////// Accesseurs //////////////
//////////////////////////////////////


/**
 * @brief Fonction qui retourne la ville A de la route
 * 
 * @return Ville 
 */

Ville Route::getVilleA() const
{
    return villeA;
}

/**
 * @brief Fonction qui retourne la ville B de la route
 * 
 * @return Ville 
 */
Ville Route::getVilleB() const
{
    return villeB;
}

/**
 * @brief Fonction qui retourne la couleur de la route
 * 
 * @return CouleurRoute 
 */
CouleurRoute Route::getCouleur() const
{
    return couleurRoute;
}

/**
 * @brief Fonction qui retourne la longueur de la route
 * 
 * @return int 
 */
int Route::getLongueur() const
{
    return longueur;
}

/**
 * @brief Fonction qui retourne le propriétaire de la route
 * 
 * @return Joueur* 
 */
Joueur* Route::getProprio() const
{
    return proprio;
}

/**
 * @brief Fonction qui retourne si la route est double
 * 
 * @return bool 
 */
bool Route::getEstDouble() const
{
    return estRouteDouble;
}


//////////////////////////////////////
///////////// Mutateurs //////////////
//////////////////////////////////////

/**
 * @brief Mutateur pour le propriétaire de la route
 * 
 * @param j 
 */
void Route::setProprio(Joueur* j)
{
    proprio = j;
}


//////////////////////////////////////
///////////// Méthodes ///////////////
//////////////////////////////////////

/**
 * @brief Fonction qui vérifie si la route est disponible
 * 
 * @return true 
 * @return false 
 */
bool Route::estDispo() const
{
    return proprio == nullptr;
}






    





