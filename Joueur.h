#pragma once
#include <string>
#include <vector>

#include "CouleurWagon.h"
#include "Ticket.h"
#include "CarteTrain.h"
#include <map>
#include "Route.h"

class Route;
class Plateau;  // déclaration anticipée

class Joueur {
public :
    // Constructeurs :
    Joueur();   // Constructeur par défaut
    Joueur(std::string prenom, CouleurWagon couleurWagon); // Constructeur classique

    // Accesseurs
    std::string getPrenom() const; // Accesseur pour le prénom
    std::vector<CarteTrain>& getMain(); // Acesseur pour les cartes de train dans la main
    int getNbWagon() const; // Accesseur pour connaitre le nombre de wagon
    std::vector<Ticket>& getTicket(); // Accesseur pour prendre un ticket
    int getTicketValide() const ;
    CouleurWagon getCouleurWagon() const; // Accesseur pour connaitre la couleur d'un wagon
    
    // Mutateur
    void setNbTicketValide(int nbTicketValide);

    // Méthodes
    void piocherCarte(Plateau* plateau);
    void defausserCarte(CarteTrain carteTrain);
    void piocherTicket(Ticket nouvTicket);
    void defausserTicket(Ticket ticket, Plateau* plateau);
    void validerTicket(Ticket* t);
    bool peutPrendreRoute(Route* route);
    void afficherMain();
    void GrandeTraversee(bool B); 
    void afficherMain() const;
    bool verifierTicket(Ticket t, std::vector<Route>& routes);

private :
    std::string prenom;
    std::vector<CarteTrain> main;
    CouleurWagon couleurWagon;
    int nbWagon;
    std::vector<Ticket> ticket;
    int nbTicketValide;
    int grdTraversee;
};
