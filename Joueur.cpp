#include <string>
#include <iostream>

#include "Joueur.h"
#include "CouleurWagon.h"
#include "CouleurCarte.h"
#include "Ticket.h"
#include "Plateau.h"

//////////////////////////////////////
////// Constructeur par défaut ///////
//////////////////////////////////////
Joueur::Joueur()
{
    // Rien à mettre dedans car paramètres par défaut
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

void Joueur::setNbTicketValide(int nbTicketValide)
{
    this->nbTicketValide = nbTicketValide;
}



//////////////////////////////////////
///////////// Méthodes ///////////////
//////////////////////////////////////

void Joueur::piocherCarte(Plateau* plateau)
{   
    main.push_back(plateau->getPioche().back()); // Prend la dernière carte de la pioche
    plateau->retirerCartePioche();               // Retire la dernière carte de la pioche
}

void Joueur::defausserCarte(CarteTrain carteTrain)
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

void Joueur::defausserTicket(Ticket ticket, Plateau* plateau)
{
    plateau->ajouterDefausseTicket(ticket);

}

void Joueur::validerTicket(Ticket* t)
{
    if (t->estValide())
    {
        int TicVal = getTicketValide();
        TicVal += 1;
        setNbTicketValide(TicVal);
    }
}

bool Joueur::peutPrendreRoute(Route* route)
{
    if (route->estDispo())
    {
        return true;
    }
    return false;
}

void Joueur::afficherMain()
{
    for (auto it = main.begin(); it != main.end(); it++)
    {
        std::cout << couleurToString(it->getCouleur()) << std::endl;
    }
}

void Joueur::GrandeTraversee(bool B)
{
    if (B == true)
    {
        int TicVal = getTicketValide();
        TicVal += 1;
        setNbTicketValide(TicVal);
    }
    else 
    {
        std::cout << "La grande traversée n'est pas valide." << std::endl;
    }
}
