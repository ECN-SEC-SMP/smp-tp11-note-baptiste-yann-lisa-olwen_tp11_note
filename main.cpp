/**
 * @file main.cpp
 * @brief Point d'entrée du jeu Les Aventuriers du Rail.
 *
 * Initialise l'application Qt, le plateau, les joueurs, la pioche de cartes
 * et les tickets destination. Gère ensuite la boucle principale de jeu en
 * mode console, avec affichage graphique Qt synchronisé.
 *
 * @section flux Flux général
 * 1. Création du plateau et de la fenêtre Qt.
 * 2. Saisie du nombre de joueurs et de leurs prénoms.
 * 3. Génération et mélange de la pioche de cartes train.
 * 4. Distribution de 4 cartes et 2 tickets à chaque joueur.
 * 5. Boucle de jeu : chaque joueur choisit une action par tour.
 * 6. Fin de partie dès qu'un joueur atteint 6 tickets validés ou n'a plus de wagons.
 *
 * @section actions Actions disponibles par tour
 * - **1** : Piocher deux cartes train.
 * - **2** : Poser des wagons sur une route disponible.
 * - **3** : Échanger ses deux tickets contre deux nouveaux.
 */

#include <QApplication>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
#include <map>

#include "CouleurWagon.h"
#include "Joueur.h"
#include "Plateau.h"
#include "Affichage.h"
#include "CarteTrain.h"
#include "CouleurCarte.h"
#include "Ticket.h"
#include "Ville.h"

/**
 * @brief Point d'entrée principal de l'application.
 * @param argc Nombre d'arguments de la ligne de commande.
 * @param argv Tableau des arguments de la ligne de commande.
 * @return Code de retour de l'application Qt, ou -1 en cas d'erreur.
 */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    Plateau plateau;
    Affichage fenetre(&plateau);
    fenetre.show();
    app.processEvents();  // ← affiche la fenêtre immédiatement

    int nbJoueurs = 0;
    std::cout << "Combien de joueurs ? (2 a 4) :";
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

    // 10 cartes par couleur + 12 locomotives supplémentaires
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
    std::getline(fichier, ligne); // ignorer l'en-tête

    plateau.chargerMapCsv();

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
        std::cout << "1. Piocher deux cartes 'train'" << std::endl;
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
            fenetre.mettreAJour();
            app.processEvents();
        }
        else if (action == 2)
        {
            std::vector<Route> routes = plateau.getRoute();
            std::cout << "Nombre de routes chargées : " << routes.size() << std::endl;
            std::cout << "Routes disponibles :" << std::endl;

            for (int i = 0; i < (int)routes.size(); i++)
            {
                if (routes[i].estDispo())
                {
                    std::cout << i << ". " << routes[i].getVilleA().getNom()
                            << " <-> " << routes[i].getVilleB().getNom()
                            << " (longueur: " << routes[i].getLongueur() << ")"
                            << std::endl;
                }
            }

            std::cout << "Choisissez le numéro de la route (-1 pour annuler) : ";
            int choixRoute;
            std::cin >> choixRoute;

            if (choixRoute >= 0 && choixRoute < (int)routes.size() && routes[choixRoute].estDispo())
            {
                int longueur = plateau.getRoute()[choixRoute].getLongueur();
                CouleurRoute couleurRoute = plateau.getRoute()[choixRoute].getCouleur();

                // Compter les cartes par couleur
                std::map<CouleurCarte, int> compteur;
                int nbLocomotives = 0;
                for (CarteTrain& carte : joueurCourant.getMain())
                {
                    if (carte.getCouleur() == CouleurCarte::Locomotive)
                        nbLocomotives++;
                    else
                        compteur[carte.getCouleur()]++;
                }

                // Vérifier les couleurs disponibles
                bool peutPoser = false;
                CouleurCarte couleurChoisie;
                std::vector<CouleurCarte> couleursDisponibles;

                for (auto& pair : compteur)
                {
                    if (pair.second + nbLocomotives >= longueur)
                    {
                        bool bonneCouleur = false;
                        if (pair.first == CouleurCarte::Vert   && couleurRoute == CouleurRoute::Vert)   bonneCouleur = true;
                        if (pair.first == CouleurCarte::Blanc  && couleurRoute == CouleurRoute::Blanc)  bonneCouleur = true;
                        if (pair.first == CouleurCarte::Rouge  && couleurRoute == CouleurRoute::Rouge)  bonneCouleur = true;
                        if (pair.first == CouleurCarte::Bleu   && couleurRoute == CouleurRoute::Bleu)   bonneCouleur = true;
                        if (pair.first == CouleurCarte::Noir   && couleurRoute == CouleurRoute::Noir)   bonneCouleur = true;
                        if (pair.first == CouleurCarte::Jaune  && couleurRoute == CouleurRoute::Jaune)  bonneCouleur = true;

                        if (bonneCouleur)
                            couleursDisponibles.push_back(pair.first);
                    }
                }

                // Vérifier aussi la couleur de la route double
                CouleurRoute couleurRoute2 = plateau.getRoute()[choixRoute].getCouleur2();
                for (auto& pair : compteur)
                {
                    if (pair.second + nbLocomotives >= longueur)
                    {
                        bool bonneCouleur = false;
                        if (pair.first == CouleurCarte::Vert   && couleurRoute2 == CouleurRoute::Vert)   bonneCouleur = true;
                        if (pair.first == CouleurCarte::Blanc  && couleurRoute2 == CouleurRoute::Blanc)  bonneCouleur = true;
                        if (pair.first == CouleurCarte::Rouge  && couleurRoute2 == CouleurRoute::Rouge)  bonneCouleur = true;
                        if (pair.first == CouleurCarte::Bleu   && couleurRoute2 == CouleurRoute::Bleu)   bonneCouleur = true;
                        if (pair.first == CouleurCarte::Noir   && couleurRoute2 == CouleurRoute::Noir)   bonneCouleur = true;
                        if (pair.first == CouleurCarte::Jaune  && couleurRoute2 == CouleurRoute::Jaune)  bonneCouleur = true;

                        if (bonneCouleur)
                        {
                            // Eviter les doublons
                            bool dejaDans = false;
                            for (CouleurCarte c : couleursDisponibles)
                                if (c == pair.first) dejaDans = true;
                            if (!dejaDans)
                                couleursDisponibles.push_back(pair.first);
                        }
                    }
                }

                if (!couleursDisponibles.empty())
                    peutPoser = true;

                // Si plusieurs couleurs disponibles, laisser choisir
                if (couleursDisponibles.size() > 1)
                {
                    std::cout << "Quelle couleur voulez-vous utiliser ?" << std::endl;
                    for (int i = 0; i < (int)couleursDisponibles.size(); i++)
                    {
                        std::cout << i << ". " << couleurToString(couleursDisponibles[i]) << std::endl;
                    }
                    int choixCouleur;
                    std::cin >> choixCouleur;
                    if (choixCouleur >= 0 && choixCouleur < (int)couleursDisponibles.size())
                        couleurChoisie = couleursDisponibles[choixCouleur];
                    else
                        couleurChoisie = couleursDisponibles[0];
                }
                else if (couleursDisponibles.size() == 1)
                {
                    couleurChoisie = couleursDisponibles[0];
                }

                // Locomotives seules
                if (!peutPoser && nbLocomotives >= longueur)
                {
                    peutPoser = true;
                    couleurChoisie = CouleurCarte::Locomotive;
                }

                if (!peutPoser)
                {
                    std::cout << "Vous n'avez pas assez de cartes !" << std::endl;
                    nombredeTour--;
                }
                else
                {
                    int cartesNormales = (couleurChoisie == CouleurCarte::Locomotive) ? 0 : std::min(compteur[couleurChoisie], longueur);
                    int cartesLoco = longueur - cartesNormales;

                    for (int i = 0; i < cartesNormales; i++)
                    {
                        joueurCourant.defausserCarte(CarteTrain(couleurChoisie));
                        plateau.ajouterDefausseCartes(CarteTrain(couleurChoisie));
                    }

                    for (int i = 0; i < cartesLoco; i++)
                    {
                        joueurCourant.defausserCarte(CarteTrain(CouleurCarte::Locomotive));
                        plateau.ajouterDefausseCartes(CarteTrain(CouleurCarte::Locomotive));
                    }

                    plateau.getRoute()[choixRoute].setProprio(&joueurCourant);
                    std::cout << "Route posée avec succès !" << std::endl;

                    // Vérifier les tickets
                    std::vector<Ticket>& ticketsJoueur = joueurCourant.getTicket();
                    for (int i = 0; i < (int)ticketsJoueur.size(); i++)
                    {
                        if (joueurCourant.verifierTicket(ticketsJoueur[i], plateau.getRoute()))
                        {
                            std::cout << "Ticket ! " << ticketsJoueur[i].getVilleA().getNom() 
                                    << " <-> " << ticketsJoueur[i].getVilleB().getNom() 
                                    << " validé !" << std::endl;
                            joueurCourant.setNbTicketValide(joueurCourant.getTicketValide() + 1);
                            ticketsJoueur.erase(ticketsJoueur.begin() + i);
                            i--;

                            // Recycler la défausse si pioche vide
                            if (piocheTickets.empty())
                            {
                                piocheTickets = plateau.getDefausseTicket();
                                for (int k = piocheTickets.size() - 1; k > 0; k--)
                                {
                                    int j = rand() % (k + 1);
                                    Ticket temp = piocheTickets[k];
                                    piocheTickets[k] = piocheTickets[j];
                                    piocheTickets[j] = temp;
                                }
                                plateau.viderDefausseTicket();
                                std::cout << "Pioche de tickets recyclée !" << std::endl;
                            }

                            if (!piocheTickets.empty())
                            {
                                joueurCourant.piocherTicket(piocheTickets.back());
                                piocheTickets.pop_back();
                                std::cout << "Nouveau ticket pioché !" << std::endl;
                            }
                            else
                            {
                                std::cout << "Plus de tickets disponibles !" << std::endl;
                            }
                        }
                    }
                    fenetre.mettreAJour();
                    app.processEvents();
                }
            }
            else
            {
                std::cout << "Choix invalide." << std::endl;
                nombredeTour--;
            }
            fenetre.mettreAJour();
            app.processEvents();
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

                // Recycler si besoin
                if (piocheTickets.size() < 2)
                {
                    std::vector<Ticket> defausse = plateau.getDefausseTicket();
                    for (Ticket& t : defausse)
                        piocheTickets.push_back(t);
                    for (int k = piocheTickets.size() - 1; k > 0; k--)
                    {
                        int j = rand() % (k + 1);
                        Ticket temp = piocheTickets[k];
                        piocheTickets[k] = piocheTickets[j];
                        piocheTickets[j] = temp;
                    }
                    plateau.viderDefausseTicket();
                    std::cout << "Pioche de tickets recyclée !" << std::endl;
                }

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
            fenetre.mettreAJour();
            app.processEvents();
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

/*
cmake_minimum_required(VERSION 3.16)
...
*/