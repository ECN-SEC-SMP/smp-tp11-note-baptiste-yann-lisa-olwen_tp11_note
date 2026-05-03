/**
 * @file Ville.h
 * @brief Déclaration de la classe Ville.
 * @ingroup Modele
 */

#ifndef VILLE_H
#define VILLE_H

#include <string>

/**
 * @brief Représente une ville sur le plateau de jeu.
 *
 * Une ville est un nœud du réseau ferroviaire. Elle peut être
 * située sur la côte ouest ou est, ce qui est utilisé pour
 * déterminer les conditions de la grande traversée.
 *
 * @ingroup Modele
 */
class Ville
{
private:
    std::string nom;       ///< Nom de la ville.
    bool        coteOuest; ///< @c true si la ville est sur la côte ouest.
    bool        coteEst;   ///< @c true si la ville est sur la côte est.

public:
    /** @brief Constructeur par défaut — crée une ville sans nom. */
    Ville();

    /**
     * @brief Crée une ville avec le nom donné.
     * @param nom Nom de la ville.
     */
    Ville(const std::string& nom);

    /** @brief Retourne le nom de la ville. */
    const std::string& getNom() const;

    /**
     * @brief Indique si la ville est sur la côte ouest.
     * @return @c true si la ville est côté ouest, @c false sinon.
     */
    bool estCoteOuest() const;

    /**
     * @brief Indique si la ville est sur la côte est.
     * @return @c true si la ville est côté est, @c false sinon.
     */
    bool estCoteEst() const;
};

#endif