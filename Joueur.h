#pragma once
#include <string>
#include <vector>

#include "CouleurWagon.h"

class Joueur {
public :


private :
    std::string prenom;
    std::string nom;
    // vector<CoutTrai> main ???
    CouleurWagon couleurWagon;
    int nbWagon;
    vector<Ticket> ticket;
    int nbTicketValide;
    int grdTraversee;
}
