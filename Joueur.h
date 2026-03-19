#pragma once
#include <string>
#include <vector>

#include "CouleurWagon.h"
#include "Ticket.h"
#include "Route.h"
#include "CarteTrain.h"

class Joueur {
public :
    // Constructeurs :
    Joueur();   // Constructeur par défault
    Joueur(std::string prenom, CouleurWagon couleurWagon); // Constructeur classique

    // Accesseurs
    std::string getPrenom() const; // Accesseur pour le prénom
    std::vector<CarteTrain> getMain() const; // Acesseur pour les cartes de train dans la main
    int getNbWagon() const; // Accesseur pour connaitre le nombre de wagon
    std::vector<Ticket> getTicket() const; // Accesseur pour prendre un ticket
    int getTicketValide() const ;
    CouleurWagon getCouleurWagon(); // Accesseur pour connaitre la couleur d'un wagon
    
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


private :
    std::string prenom;
    std::string nom;
    // vector<CoutTrai> main ???
    CouleurWagon couleurWagon;
    int nbWagon;
    std::vector<Ticket> ticket;
    int nbTicketValide;
    int grdTraversee;
};
