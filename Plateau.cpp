#include "Plateau.h"
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

/**
 * @brief Constructeur par défaut et constructeur avec paramètres pour la classe Plateau
 * 
 */
Plateau::Plateau()
{
    // Rien à mettre dedans car paramètres par défaut
}

/**
 * @brief Constructeur de la classe Plateau avec paramètres pour initialiser les éléments du plateau de jeu
 * 
 * @param A 
 * @param B 
 */
Plateau::Plateau(int A, int B)
{
    // Paramètres à compléter
}

/**
 * @brief Accesseurs pour les éléments du plateau de jeu
 * 
 * @return std::vector<Ville> 
 */
std::vector<Ville> Plateau::getVille() const
{
    return ville;
}

/**
 * @brief  Accesseur pour les routes du plateau de jeu
 * 
 * @return std::vector<Route> 
 */
std::vector<Route> Plateau::getRoute() const
{
    return route;
}

/**
 * @brief Accesseur pour la pioche de cartes de train du plateau de jeu
 * 
 * @return std::vector<CarteTrain> 
 */
std::vector<CarteTrain>& Plateau::getPioche() {
    return pioche;
}

void Plateau::setPioche(std::vector<CarteTrain> p) {
    pioche = p;
}

/**
 * @brief Accesseur pour les tickets du plateau de jeu 
 * 
 * @return std::vector<Ticket> 
 */
std::vector<Ticket> Plateau::getTickets() const
{
    return tickets;
}

/**
 * @brief Accesseur pour la défausse de tickets du plateau de jeu
 * 
 * @return std::vector<Ticket> 
 */
std::vector<Ticket> Plateau::getDefausseTicket() const
{
    return defausseTicket;
}

/**
 * @brief   Méthode qui retourne une liste de pointeurs vers les routes prises par un joueur donné en paramètre
 * 
 * @param j 
 * @return std::vector<Route*> 
 */
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

/**
 * @brief 
 * 
 */
void Plateau::chargerMapCsv()
{
    // Charger le fichier .csv des villes
    
}

/**
 * @brief  
 * 
 */
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
    if (std::getline(flux_string, id_str, ',') && std::getline(flux_string, city_A, ',') && std::getline(flux_string, city_B, ',')) 
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

/**
 * @brief   Affiche le plateau de jeu (villes, routes, cartes de train disponibles, etc.)
 * 
 */
void Plateau::afficher()
{
    // Afficher le plateau de jeu
}

/**
 * @brief  
 * 
 */
void Plateau::retirerCartePioche()
{
    pioche.pop_back(); // Retire la dernière carte de la pioche
}

/**
 * @brief   Ajoute un ticket à la défausse du plateau de jeu
 * 
 * @param ticket 
 */
void Plateau::ajouterDefausseTicket(Ticket ticket)
{
    defausseTicket.push_back(ticket); // Ajoute un ticket à la défausse
}


