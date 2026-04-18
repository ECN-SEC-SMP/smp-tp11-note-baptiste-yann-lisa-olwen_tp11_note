#include "Ville.h"

Ville::Ville() {}
Ville::Ville(const std::string& nom) : nom(nom), coteOuest(false), coteEst(false) {}

/**
 * @brief Fonction qui retourne le nom de la ville
 * 
 * @return const std::string& 
 */
const std::string& Ville::getNom() const 
{
    return nom;
}

/**
 * @brief Fonction qui vérifie si la ville est sur le côté ouest
 * 
 * @return bool 
 */
bool Ville::estCoteOuest() const 
{
    return coteOuest;
}

/**
 * @brief Fonction qui vérifie si la ville est sur le côté est
 * 
 * @return bool 
 */
bool Ville::estCoteEst() const 
{
    return coteEst;
}
