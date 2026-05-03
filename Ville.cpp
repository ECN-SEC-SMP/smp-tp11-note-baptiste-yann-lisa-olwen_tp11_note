#include "Ville.h"

/**
 * @brief Constructeur par défaut — crée une ville sans nom.
 * @ingroup Modele
 */
Ville::Ville() {}

/**
 * @brief Crée une ville avec le nom donné.
 *
 * Par défaut, la ville n'est ni côté ouest ni côté est.
 *
 * @param nom Nom de la ville.
 * @ingroup Modele
 */
Ville::Ville(const std::string& nom) : nom(nom), coteOuest(false), coteEst(false) {}

/**
 * @brief Retourne le nom de la ville.
 * @return Référence constante vers le nom de la ville.
 */
const std::string& Ville::getNom() const
{
    return nom;
}

/**
 * @brief Indique si la ville est située sur la côte ouest.
 * @return @c true si la ville est côté ouest, @c false sinon.
 */
bool Ville::estCoteOuest() const
{
    return coteOuest;
}

/**
 * @brief Indique si la ville est située sur la côte est.
 * @return @c true si la ville est côté est, @c false sinon.
 */
bool Ville::estCoteEst() const
{
    return coteEst;
}