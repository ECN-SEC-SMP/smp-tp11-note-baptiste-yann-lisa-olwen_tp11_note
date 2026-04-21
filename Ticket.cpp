#include "Ticket.h"

/**
 * @brief Constructeur de la classe Ticket
 * 
 * @param id 
 * @param vA 
 * @param vB 
 */
Ticket::Ticket(int id, const Ville& vA, const Ville& vB) : id(id), villeA(vA), villeB(vB), valide
(true) {}

/**
 * @brief Fonction qui retourne l'identifiant du ticket
 * 
 * @return int 
 */
int Ticket::getId() const 
{ 
    return id; 
}

/**
 * @brief Fonction qui retourne la ville A du ticket
 * 
 * @return Ville 
 */
const Ville& Ticket::getVilleA() const 
{ 
    return villeA; 
}

/**
 * @brief Fonction qui retourne la ville B du ticket
 * 
 * @return Ville 
 */
const Ville& Ticket::getVilleB() const 
{ 
    return villeB; 
}

/**
 * @brief Fonction qui vérifie si le ticket est valide
 * 
 * @return true 
 * @return false 
 */
bool Ticket::estValide() const 
{ 
    return valide; 
}

/**
 * @brief Surcharge de l'opérateur ==
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Ticket::operator==(const Ticket& other) const
{
    return this->id == other.id;
}