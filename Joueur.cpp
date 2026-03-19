/*    
    // Mutateur
    void setGrdTraversee(bool B); // ??????????????

    // Méthodes
    void piocherCarte();
    void defausserCarte();
    void piocherTicket();
    void defausserTicket();
    void validerTicket(Ticket* t);
    bool peutPrendreRoute(Route* R);
    void afficherMain();
*/
#include <string>

#include "Joueur.h"
#include "CouleurWagon.h"

//////////////////////////////////////
////// Constructeur par défaut ///////
//////////////////////////////////////
Joueur::Joueur()
{
    // Rien à mettre dedans cas paramètres par défaut
}

Joueur::Joueur(std::string prenom, CouleurWagon couleurWagon) : prenom(prenom), couleurWagon(couleurWagon)
{
    // Rien d'autre à faire
}

//////////////////////////////////////
//////////// Accesseurs //////////////
//////////////////////////////////////
std::string Joueur::getPrenom() const
{
    return prenom;
} 

std::vector<CarteTrain> Joueur::getMain() const
{
    return main;
}

CouleurWagon Joueur::getCouleurWagon() const
{
    return couleurWagon;
}

int Joueur::getNbWagon() const
{
    return nbWagon;
}

std::vector<Ticket> Joueur::getTicket() const
{
    return ticket;
}

int Joueur::getTicketValide() const
{
    return nbTicketValide;
}

//////////////////////////////////////
///////////// Mutateurs //////////////
//////////////////////////////////////


    




