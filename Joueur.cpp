#include <string>
#include <iostream>

#include "Joueur.h"
#include "CouleurWagon.h"
#include "Ticket.h"
#include "Plateau.h"

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

void setGrandeTraversee(bool B)
{
    // a remplir
}


//////////////////////////////////////
///////////// Méthodes ///////////////
//////////////////////////////////////

void Joueur::piocherCarte(Plateau& plateau)
{   
    main.push_back(plateau.getPioche().back()); // Prend la dernière carte de la pioche
    plateau.retirerCartePioche();               // Retire la dernière carte de la pioche
}

void Joueur::defausserCarte(std::vector<CarteTrain> main, CarteTrain carteTrain)
{
    for (auto it = main.begin(); it != main.end(); it++) 
    {
        if (*it == carteTrain)
        {
            main.erase(it);
            break;
        }
    }
}

void Joueur::piocherTicket(Ticket nouvTicket)
{
    ticket.push_back(nouvTicket);
}

void Joueur::defausserTicket(Ticket ticket, Plateau& plateau)
{
    plateau.ajouterDefausseTicket(ticket);

}

void Joueur::validerTicket(Ticket* t)
{
    if (Ticket::estValide)
    {
        setNbTicketValide(t);
    }
}

bool Joueur::peutPrendreRoute(Route* R)
{
    
}

void afficherMain()
{

}







    




