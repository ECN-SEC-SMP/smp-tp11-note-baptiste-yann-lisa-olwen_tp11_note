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
#include "Ticket.h"
#include "Ville.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    Plateau plateau;
    Affichage fenetre(&plateau);
    fenetre.show();
    app.processEvents();  // ← affiche la fenêtre immédiatement

    int nbJoueurs = 0;
    std::cout << "Combien de joueurs ? (2 a 5) :";
    std::cin >> nbJoueurs;

    std::vector<CouleurWagon> couleurs =
    {
        CouleurWagon::Rouge,
        CouleurWagon::Bleu,
        CouleurWagon::Jaune,
        CouleurWagon::Vert
    };

    std::vector<Joueur> joueurs;
    for (int i = 0; i < nbJoueurs; i++)
    {
        std::string prenom;
        std::cout << "Prenom du joueur " << i+1 << " : ";
        std::cin >> prenom;
        joueurs.push_back(Joueur(prenom, couleurs[i]));
        std::cout << "Joueur " << prenom << " créé " << std::endl;
        app.processEvents();
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
        for (int i = 0; i < 10; i++)
        {
            pioche.push_back(CarteTrain(couleur));
        }
    }
    for (int i = 0; i < 12; i++)
    {
        pioche.push_back(CarteTrain(CouleurCarte::Locomotive));
    }

    srand(time(nullptr));

    // Mélange de la pioche
    for (int i = pioche.size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        CarteTrain temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }

    plateau.setPioche(pioche);
    std::cout << "Pioche créée : " << pioche.size() << " cartes dans la pioche." << std::endl;

    // Distribuer 4 cartes à chaque joueur
    for (Joueur& j : joueurs)
    {
        for (int i = 0; i < 4; i++)
        {
            j.piocherCarte(&plateau);
        }
        std::cout << j.getPrenom() << " a eu ses cartes." << std::endl;
    }

    std::vector<Ticket> piocheTickets;

    std::ifstream fichier("ticket.csv");

    if (!fichier.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir ticket.csv" << std::endl;
        return -1;
    }

    std::string ligne;
    std::getline(fichier, ligne);

    while (std::getline(fichier, ligne))
    {
        std::stringstream ss(ligne);
        std::string id_str, nomA, nomB;

        std::getline(ss, id_str, ',');
        std::getline(ss, nomA, ',');
        std::getline(ss, nomB, ',');

        int id = std::stoi(id_str);

        Ville vA(nomA);
        Ville vB(nomB);

        piocheTickets.push_back(Ticket(id, vA, vB));
    }

    fichier.close();
    std::cout << piocheTickets.size() << " tickets charges." << std::endl;

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
        std::cout << j.getPrenom() << " a recu ses tickets." << std::endl;
    }

    int nombredeTour = 0;
    bool partieFinie = false;

    while (!partieFinie)
    {
        app.processEvents();  // ← garde la fenêtre Qt réactive

        Joueur& joueurCourant = joueurs[nombredeTour % nbJoueurs];

        std::cout << std::endl << "=============================" << std::endl;
        std::cout << "C'est le tour de : " << joueurCourant.getPrenom() << std::endl;
        std::cout << "Wagons restants : " << joueurCourant.getNbWagon() << std::endl;
        std::cout << "Tickets valides : " << joueurCourant.getTicketValide() << std::endl;
        std::cout << "Vos tickets :" << std::endl;

        std::vector<Ticket> tickets = joueurCourant.getTicket();
        if (tickets.empty())
        {
            std::cout << "Le joueur n'a pas encore de ticket" << std::endl;
        }
        else
        {
            for (int i = 0; i < (int)tickets.size(); i++)
            {
                std::cout << "- " << tickets[i].getVilleA().getNom() << " <-> " << tickets[i].getVilleB().getNom() << std::endl;
            }
        }

        std::cout << "Vos cartes : " << std::endl;
        joueurCourant.afficherMain();
        std::cout << "=============================" << std::endl;

        int action = 0;
        std::cout << "\nQue voulez-vous faire ?" << std::endl;
        std::cout << "1. Piocher une carte train" << std::endl;
        std::cout << "2. Poser des wagons" << std::endl;
        std::cout << "3. Echanger ses deux tickets contre deux nouveaux" << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> action;

        app.processEvents();  // ← après chaque action

        if (action == 1)
        {
            for (int i = 0; i < 2; i++)
            {
                if (!plateau.getPioche().empty())
                {
                    joueurCourant.piocherCarte(&plateau);
                    std::cout << "Carte piochee " << std::endl;
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
        else if (action == 3)
        {
            std::vector<Ticket> anciensTickets = joueurCourant.getTicket();

            if ((int)anciensTickets.size() < 2)
            {
                std::cout << "Vous n'avez pas assez de tickets." << std::endl;
            }
            else
            {
                joueurCourant.defausserTicket(anciensTickets[0], &plateau);
                joueurCourant.defausserTicket(anciensTickets[1], &plateau);

                if ((int)piocheTickets.size() >= 2)
                {
                    joueurCourant.piocherTicket(piocheTickets.back());
                    piocheTickets.pop_back();

                    joueurCourant.piocherTicket(piocheTickets.back());
                    piocheTickets.pop_back();

                    system("clear");

                    std::cout << "Nouveaux tickets de " << joueurCourant.getPrenom() << " :" << std::endl;

                    std::vector<Ticket> nouveauxTickets = joueurCourant.getTicket();
                    for (int i = 0; i < (int)nouveauxTickets.size(); i++)
                    {
                        std::cout << "- " << nouveauxTickets[i].getVilleA().getNom() << " <-> " << nouveauxTickets[i].getVilleB().getNom() << std::endl;
                    }
                }
                else
                {
                    std::cout << "Plus assez de tickets dans la pioche." << std::endl;
                }
            }
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

        nombredeTour++;
    }

    return app.exec();
}