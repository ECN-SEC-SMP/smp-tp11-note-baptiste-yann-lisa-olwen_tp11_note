# include "Plateau.h"
#include "Joueur.h"
#include "Ticket.h"
#include "Route.h"
#include "CarteTrain.h"
#include "Ville.h"

#include <iostream>
#include <string>
#include <vector>

#include <fstream> // Pour la lecture de fichiers.csv
#include <sstream> // Pour la manipulation de chaînes de caractères lors de la lecture de fichiers.csv

Plateau::Plateau()
{
    // Rien à mettre dedans car paramètres par défaut
}

Plateau::Plateau(int A, int B)
{
    // Paramètres à compléter
}

std::vector<Ville> Plateau::getVille() const
{
    return ville;
}

std::vector<Route> Plateau::getRoute() const
{
    return route;
}

std::vector<CarteTrain> Plateau::getPioche() const
{
    return pioche;
}

std::vector<Ticket> Plateau::getTickets() const
{
    return tickets;
}

std::vector<Ticket> Plateau::getDefausseTicket() const
{
    return defausseTicket;
}

std::vector<Route*> Plateau::setRouteJoueur(Joueur* j)
{
    std::vector<Route*> routesPrises;
    for (int i = 0; i < route.size(); i++)      // Parcours de toutes les routes du plateau
    {
        if (route[i].getProprio() == j)         // Si le propriétaire de la route est le joueur j   
        {
            routesPrises.push_back(&route[i]);  // On ajoute un pointeur vers la route à la liste des routes prises par le joueur
        }
    }
    return routesPrises;                        // On retourne la liste des routes prises par le joueur
}

void Plateau::chargerMapCsv()
{
    // Charger le fichier .csv des villes
    
}

void Plateau::chargerTicketCsv()
{
    std::fstream fichierTicket("Ticket.csv"); // Ouvre le fichier Ticket.csv en lecture

    if (!fichierTicket.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier Ticket.csv" << std::endl;
        return;
    }

    std::string ligne; // Variable pour stocker chaque ligne du fichier

    std::getline(fichierTicket, ligne); // Lit la première ligne (en-tête) et l'ignore

    std::stringstream flux_string(ligne);  // Créer un flux de string pour la ligne lue
    std::string id_str, city_A, city_B;  // Variables pour stocker les valeurs extraites de la ligne

    // Lire les valeurs séparées par des virgules
    if (std::getline(flux_string, id_str, ',') && 
        std::getline(flux_string, city_A, ',') &&
        std::getline(flux_string, city_B, ',')) 
    {
        int id = std::stoi(id_str); // Convertir l'ID en entier

        // Trouver les villes par nom
        Ville* villeA = nullptr;
        Ville* villeB = nullptr;

        for (int i = 0; i < ville.size(); i++) { // Parcours de toutes les villes du plateau
            Ville& v = ville[i];        // Référence à la ville courante
            if (v.getNom() == city_A) { // Si le nom de la ville correspond à city_A
                villeA = &v;            // On stocke un pointeur vers la villeA trouvée
            }
            if (v.getNom() == city_B) { // Si le nom de la ville correspond à city_B
                villeB = &v;            // On stocke un pointeur vers la villeB trouvée
            }
        }

        if (villeA && villeB) {         // Si les deux villes ont été trouvées, on peut créer le ticket
            Ticket nouveauTicket(id, *villeA, *villeB); // Création du ticket avec les villes trouvées 
            tickets.push_back(nouveauTicket); // Ajout du ticket à la liste des tickets du plateau
        } else {
            std::cerr << "Erreur : villes non trouvées pour le ticket " << id << std::endl;
        }
    }
    fichierTicket.close(); // Ferme le fichier après la lecture
}

void Plateau::afficher()
{
    // Afficher le plateau de jeu
}

void Plateau::retirerCartePioche()
{
    pioche.pop_back(); // Retire la dernière carte de la pioche
}

void Plateau::ajouterDefausseTicket(Ticket ticket)
{
    defausseTicket.push_back(ticket); // Ajoute un ticket à la défausse
}


