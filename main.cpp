#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

#include "CouleurWagon.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Affichage.h"
#include "CarteTrain.h"
#include "CouleurCarte.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Plateau plateau;
    Affichage fenetre(&plateau);
    fenetre.show();

    int nbJoueurs = 0;
    std::cout << "Combien de joueurs ? (2 a 4) :";
    std::cin >> nbJoueurs;

    std :: vector<CouleurWagon> couleurs=
    {
        CouleurWagon::Rouge,
        CouleurWagon::Bleu,
        CouleurWagon::Jaune,
        CouleurWagon::Vert
    };

    std::vector<Joueur> joueurs;
    for (int i=0; i<nbJoueurs; i++)
    {
        std::string prenom;
        std::cout << "Prenom du joueur " << i+1 << " : ";
        std::cin >> prenom;
        joueurs.push_back(Joueur(prenom, couleurs[i]));
        std::cout << "Joueur " << prenom << " créé " << std::endl;

    }

    std::vector<CarteTrain> pioche;

    std::vector<CouleurCarte> couleursCartes =
    {
        CouleurCarte::Rouge,
        CouleurCarte::Bleu,
        CouleurCarte::Jaune,
        CouleurCarte::Vert,
        CouleurCarte::Noir,
        CouleurCarte::Blanc,
        CouleurCarte::Locomotive
    };

    for (CouleurCarte couleur : couleursCartes) 
    {
        for (int i = 0; i < 10; i++) // 10 cartes de chaque couleur
        { 
            pioche.push_back(CarteTrain(couleur));
        }
    }
    for (int i = 0; i < 12; i++) // 12 cartes locomotive
        {
            pioche.push_back(CarteTrain(CouleurCarte::Locomotive));
        }
    

    srand(time(nullptr)); // initialisation

    // Mélange de la pioche
    for (int i = pioche.size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        CarteTrain temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }

    
    //poser la pioche sur le plateau
    plateau.setPioche(pioche); 

    std::cout << "Pioche créée : " << pioche.size() << " cartes dans la pioche."<< std::endl;

    // Distribuer 4 cartes à chaque joueur
    for (Joueur& j : joueurs)
    {
        for (int i = 0; i < 4; i++)
        {
            j.piocherCarte(&plateau);
        }
        std::cout << j.getPrenom() << " a eu ses cartes.\n";
    }

    std::vector<Ticket> piocheTickets;
 
    std::ifstream fichier("ticket.csv"); // ouvrir le fichier
 
    if (!fichier.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir ticket.csv\n";
        return -1;
    }
 
    std::string ligne;
    std::getline(fichier, ligne); // ignorer la première ligne (en-tête)
 
    while (std::getline(fichier, ligne))
    {
        std::stringstream ss(ligne);
        std::string id_str, nomA, nomB;
 
        // Découper la ligne par les virgules
        std::getline(ss, id_str, ',');
        std::getline(ss, nomA, ',');
        std::getline(ss, nomB, ',');
 
        int id = std::stoi(id_str);
 
        // Créer les deux villes
        Ville vA(nomA);
        Ville vB(nomB);
 
        // Créer le ticket et l'ajouter à la pioche
        piocheTickets.push_back(Ticket(id, vA, vB));
    }
 
    fichier.close();
    std::cout << piocheTickets.size() << " tickets charges.\n";
 
    // Mélanger les tickets
    for (int i = piocheTickets.size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Ticket temp = piocheTickets[i];
        piocheTickets[i] = piocheTickets[j];
        piocheTickets[j] = temp;
    }
 
    // Distribuer 2 tickets à chaque joueur
    for (Joueur& j : joueurs)
    {
        for (int i = 0; i < 2; i++)
        {
            j.piocherTicket(piocheTickets.back());
            piocheTickets.pop_back();
        }
        std::cout << j.getPrenom() << " a recu ses tickets.\n";
    }

    int nombredeTour = 0;
    bool partieFinie = false;

    while (!partieFinie)
    {
        // Quel joueur est en train de jouer ?
        Joueur& joueurCourant = joueurs[nombredeTour % nbJoueurs];

        // Afficher l'état du joueur
        std::cout << std::endl << "============================="<< std::endl;
        std::cout << "C'est le tour de : " << joueurCourant.getPrenom() << std::endl;
        std::cout << "Wagons restants : " << joueurCourant.getNbWagon() << std::endl;
        std::cout << "Tickets valides : " << joueurCourant.getTicketValide() << std::endl;
        std::cout << "Vos cartes : "<< std::endl;
        joueurCourant.afficherMain();
        std::cout << "=============================" << std::endl;

        // Demander une action
        int action = 0;
        std::cout << "\nQue voulez-vous faire ?"<< std::endl;
        std::cout << "1. Piocher 2 cartes"<< std::endl;
        std::cout << "2. Passer son tour"<< std::endl;
        std::cout << "Votre choix : ";
        std::cin >> action;

        if (action == 1)
        {
            // Piocher 2 cartes
            for (int i = 0; i < 2; i++)
            {
                if (!plateau.getPioche().empty())
                {
                    joueurCourant.piocherCarte(&plateau);
                    std::cout << "Carte piochee !" << std::endl;
                }
                else
                {
                    std::cout << "La pioche est vide !" << std::endl;
                }
            }
        }
        else if (action == 2)
        {
            std::cout << joueurCourant.getPrenom() << " passe son tour." << std::endl;
        }

        // Vérifier la fin de partie
        for (Joueur& j : joueurs)
        {
            if (j.getTicketValide() >= 6 || j.getNbWagon() <= 0)
            {
                std::cout << std::endl << j.getPrenom() << " a gagne ! ***" << std::endl;
                partieFinie = true;
            }
        }

        // Passer au joueur suivant
        nombredeTour++;
    }
 
    return app.exec();
}
 