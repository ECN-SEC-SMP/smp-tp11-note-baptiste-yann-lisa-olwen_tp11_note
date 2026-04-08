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

#include <vector>
#include <string>
#include <limits>



/**
 * @brief Fonction principale du programme
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
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

void afficherEtatJoueur(const Joueur& joueur)
{
    std::cout << "----------------------------------\n";
    std::cout << "Joueur : " << joueur.getPrenom() << "\n";
    std::cout << "Wagons restants : " << joueur.getNbWagon() << "\n";
    std::cout << "Tickets valides : " << joueur.getTicketValide() << "\n";
    std::cout << "Main :\n";
    joueur.afficherMain();
    std::cout << "----------------------------------\n";
}

int demanderNombreJoueurs()
{
    int nbJoueurs = 0;

    do
    {
        std::cout << "Entrez le nombre de joueurs (2 a 4) : ";
        std::cin >> nbJoueurs;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            nbJoueurs = 0;
        }

    } while (nbJoueurs < 2 || nbJoueurs > 4);

    return nbJoueurs;
}

CouleurWagon couleurSelonIndice(int i)
{
    switch (i)
    {
        case 0: return CouleurWagon::Rouge;
        case 1: return CouleurWagon::Bleu;
        case 2: return CouleurWagon::Jaune;
        default: return CouleurWagon::Vert;
    }
}

void creerJoueurs(std::vector<Joueur>& joueurs, int nbJoueurs)
{
    for (int i = 0; i < nbJoueurs; i++)
    {
        std::string prenom;
        std::cout << "Prenom du joueur " << i + 1 << " : ";
        std::cin >> prenom;

        joueurs.emplace_back(prenom, couleurSelonIndice(i));
    }
}

void distribuerCartesInitiales(std::vector<Joueur>& joueurs, Plateau& plateau)
{
    for (Joueur& joueur : joueurs)
    {
        for (int i = 0; i < 4; i++)
        {
            if (!plateau.getPioche().empty()) // Vérifie que la pioche n'est pas vide avant de piocher
            {
                if (plateau.getPioche().back().getCouleur() == CouleurCarte::Locomotive)
                {
                    joueur.piocherCarte(&plateau);   
                }
                
            }
        }
    }
}

void afficherTousLesJoueurs(const std::vector<Joueur>& joueurs)
{
    for (const Joueur& joueur : joueurs)
    {
        afficherEtatJoueur(joueur);
    }
}

int demanderAction()
{
    int action = 0;

    do
    {
        std::cout << "\nChoisissez une action :\n";
        std::cout << "1. Piocher 2 cartes train\n";
        std::cout << "2. Prendre une route\n";
        std::cout << "3. Echanger ses tickets\n";
        std::cout << "Votre choix : ";
        std::cin >> action;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            action = 0;
        }

    } while (action < 1 || action > 3);

    return action;
}

bool finDePartie(const std::vector<Joueur>& joueurs)
{
    for (const Joueur& joueur : joueurs)
    {
        if (joueur.getTicketValide() >= 6 || joueur.getNbWagon() <= 0)
        {
            return true;
        }
    }
    return false;
}
