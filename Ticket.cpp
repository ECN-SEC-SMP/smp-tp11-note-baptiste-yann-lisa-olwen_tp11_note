#include "Ticket.h"

/**
 * @brief Crée un ticket destination entre deux villes.
 * @param id Identifiant unique du ticket.
 * @param vA Ville de départ.
 * @param vB Ville d'arrivée.
 * @ingroup Cartes
 */
Ticket::Ticket(int id, const Ville& vA, const Ville& vB)
    : id(id), villeA(vA), villeB(vB), valide(true) {}

/**
 * @brief Retourne l'identifiant du ticket.
 * @return L'identifiant unique du ticket.
 */
int Ticket::getId() const
{
    return id;
}

/**
 * @brief Retourne la ville de départ du ticket.
 * @return Référence constante vers la ville A.
 */
const Ville& Ticket::getVilleA() const
{
    return villeA;
}

/**
 * @brief Retourne la ville d'arrivée du ticket.
 * @return Référence constante vers la ville B.
 */
const Ville& Ticket::getVilleB() const
{
    return villeB;
}

/**
 * @brief Indique si le ticket est encore valide.
 * @return @c true si le ticket est valide, @c false sinon.
 */
bool Ticket::estValide() const
{
    return valide;
}

/**
 * @brief Marque le ticket comme valide ou non.
 * @param v @c true pour valider le ticket, @c false pour l'invalider.
 * @return Le ticket lui-même pour permettre le chaînage.
 */
bool Ticket::operator==(const Ticket& other) const
{
    return id == other.id;
}