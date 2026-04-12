#include <iostream>

#include "CarteTrain.h"
#include "CouleurCarte.h"
#include "CouleurWagon.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Route.h"
#include "Ticket.h"
#include "Ville.h"
#include <QApplication>
#include "Affichage.h"



int main(int argc, char *argv[]) 
{
    ///////////////////////////////////////////
    //-------- Mise en place du jeu ---------//
    ///////////////////////////////////////////
    
    QApplication app(argc, argv);
    
    Plateau plateau;
    Affichage fenetre(&plateau);
    fenetre.show();
    
    return app.exec();


    // Nombre de joueur

}