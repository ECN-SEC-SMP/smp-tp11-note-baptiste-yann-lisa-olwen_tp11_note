#include "Route.h"
#include "Joueur.h"
#include "Plateau.h"

//////////////////////////////////////
////// Constructeur par défaut ///////
//////////////////////////////////////

/**
 * @brief Constructeur par défaut — crée une route vide sans propriétaire.
 * @ingroup Modele
 */
Route::Route()
{
    proprio = nullptr;
    longueur = 0;
    estRouteDouble = false;
}

/**
 * @brief Crée une route avec ses caractéristiques de base.
 * @param longueur       Nombre de wagons nécessaires pour revendiquer la route.
 * @param estRouteDouble @c true si la route possède une voie parallèle.
 * @param couleurRoute   Couleur de la voie principale (voir @ref CouleurRoute).
 * @ingroup Modele
 */
Route::Route(int longueur, bool estRouteDouble, CouleurRoute couleurRoute)
    : longueur(longueur), estRouteDouble(estRouteDouble), couleurRoute(couleurRoute), proprio(nullptr) {}

//////////////////////////////////////
//////////// Accesseurs //////////////
//////////////////////////////////////

/**
 * @brief Retourne la ville de départ de la route.
 * @return La ville A.
 */
Ville Route::getVilleA() const
{
    return villeA;
}

/**
 * @brief Retourne la ville d'arrivée de la route.
 * @return La ville B.
 */
Ville Route::getVilleB() const
{
    return villeB;
}

/**
 * @brief Retourne la couleur principale de la route.
 * @return La couleur de la voie principale (voir @ref CouleurRoute).
 */
CouleurRoute Route::getCouleur() const
{
    return couleurRoute;
}

/**
 * @brief Retourne la couleur de la voie parallèle (route double).
 * @return La couleur de la seconde voie (voir @ref CouleurRoute).
 */
CouleurRoute Route::getCouleur2() const
{
    return couleurRoute2;
}

/**
 * @brief Retourne le nombre de wagons nécessaires pour revendiquer la route.
 * @return La longueur de la route.
 */
int Route::getLongueur() const
{
    return longueur;
}

/**
 * @brief Retourne le propriétaire de la route.
 * @return Pointeur vers le joueur propriétaire, ou @c nullptr si la route est libre.
 */
Joueur* Route::getProprio() const
{
    return proprio;
}

/**
 * @brief Indique si la route est une route double.
 * @return @c true si la route possède une voie parallèle, @c false sinon.
 */
bool Route::getEstDouble() const
{
    return estRouteDouble;
}

//////////////////////////////////////
///////////// Mutateurs //////////////
//////////////////////////////////////

/**
 * @brief Définit le propriétaire de la route.
 * @param j Pointeur vers le joueur qui revendique la route.
 */
void Route::setProprio(Joueur* j)
{
    proprio = j;
}

/**
 * @brief Définit la ville de départ de la route.
 * @param v Ville de départ.
 */
void Route::setVilleA(Ville v)
{
    villeA = v;
}

/**
 * @brief Définit la ville d'arrivée de la route.
 * @param v Ville d'arrivée.
 */
void Route::setVilleB(Ville v)
{
    villeB = v;
}

/**
 * @brief Définit la couleur de la voie parallèle (route double).
 * @param c Couleur de la seconde voie (voir @ref CouleurRoute).
 */
void Route::setCouleur2(CouleurRoute c)
{
    couleurRoute2 = c;
}

//////////////////////////////////////
///////////// Méthodes ///////////////
//////////////////////////////////////

/**
 * @brief Vérifie si la route est disponible (non revendiquée).
 * @return @c true si aucun joueur ne possède la route, @c false sinon.
 */
bool Route::estDispo() const
{
    return proprio == nullptr;
}