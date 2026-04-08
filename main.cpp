#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

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
        for (int i = 0; i < 12; i++) // 12 cartes de chaque couleur
        { 
            pioche.push_back(CarteTrain(couleur));
        }
    }
    for (int i = 0; i < 14; i++) // 14 cartes de couleur grise
        {
            pioche.push_back(CarteTrain(CouleurCarte::Locomotive));
        }
    

    srand(time(nullptr)); // initialise le hasard avec l'heure actuelle

    // Mélange manuel
    for (int i = pioche.size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        CarteTrain temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }

    plateau.setPioche(pioche); 

    std::cout << "Pioche créée : " << pioche.size() << " cartes dans la pioche.\n";

    // Distribuer 4 cartes à chaque joueur
    for (Joueur& j : joueurs)
    {
        for (int i = 0; i < 4; i++)
        {
            // std::cout << "Pioche avant de piocher : " << pioche.size() << " cartes restantes.\n";
            j.piocherCarte(&plateau);
            // std::cout << "carte picohée pour " << j.getPrenom() << std::endl;
        }
        std::cout << j.getPrenom() << " a reçu ses cartes.\n";
    }

    return app.exec();
}