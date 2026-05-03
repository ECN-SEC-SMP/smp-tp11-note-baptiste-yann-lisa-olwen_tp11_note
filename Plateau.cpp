#include "Plateau.h"
#include "Joueur.h"
#include "Ticket.h"
#include "Route.h"
#include "CarteTrain.h"
#include "Ville.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

/**
 * @brief Constructeur par défaut — crée un plateau vide.
 * @ingroup Modele
 */
Plateau::Plateau()
{
    // Rien à mettre dedans car paramètres par défaut
}

/**
 * @brief Constructeur avec paramètres (à compléter).
 * @param A Premier paramètre de configuration du plateau.
 * @param B Second paramètre de configuration du plateau.
 * @ingroup Modele
 */
Plateau::Plateau(int A, int B)
{
    // Paramètres à compléter
}

/**
 * @brief Retourne la liste des villes du plateau.
 * @return Copie du vecteur de villes.
 */
std::vector<Ville> Plateau::getVille() const
{
    return ville;
}

/**
 * @brief Retourne la liste des routes du plateau.
 * @return Référence vers le vecteur de routes.
 */
std::vector<Route>& Plateau::getRoute()
{
    return route;
}

/**
 * @brief Retourne la pioche de cartes train.
 * @return Référence vers le vecteur de cartes de la pioche.
 */
std::vector<CarteTrain>& Plateau::getPioche()
{
    return pioche;
}

/**
 * @brief Remplace la pioche par un nouveau jeu de cartes.
 * @param p Nouveau vecteur de cartes train.
 */
void Plateau::setPioche(std::vector<CarteTrain> p)
{
    pioche = p;
}

/**
 * @brief Retourne les tickets destination disponibles sur le plateau.
 * @return Copie du vecteur de tickets.
 */
std::vector<Ticket> Plateau::getTickets() const
{
    return tickets;
}

/**
 * @brief Retourne la défausse de tickets du plateau.
 * @return Copie du vecteur de tickets défaussés.
 */
std::vector<Ticket> Plateau::getDefausseTicket() const
{
    return defausseTicket;
}

/**
 * @brief Retourne la liste des routes appartenant à un joueur donné.
 * @param j Pointeur vers le joueur dont on cherche les routes.
 * @return Vecteur de pointeurs vers les routes du joueur.
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
 * @brief Charge les tickets destination depuis le fichier @c Ticket.csv.
 *
 * Le fichier doit contenir une ligne d'en-tête suivie de lignes au format :
 * @code
 * id,villeA,villeB
 * @endcode
 * Les villes référencées doivent déjà être présentes dans le vecteur @c ville.
 *
 * @note Affiche une erreur sur @c stderr si le fichier est introuvable ou si
 *       les villes ne sont pas trouvées.
 */
void Plateau::chargerTicketCsv()
{
    std::fstream fichierTicket("Ticket.csv");

    if (!fichierTicket.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier Ticket.csv" << std::endl;
        return;
    }

    std::string ligne;
    std::getline(fichierTicket, ligne); // Lit la première ligne (en-tête) et l'ignore

    std::stringstream flux_string(ligne);
    std::string id_str, city_A, city_B;

    if (std::getline(flux_string, id_str, ',') &&
        std::getline(flux_string, city_A, ',') &&
        std::getline(flux_string, city_B, ','))
    {
        int id = std::stoi(id_str);

        Ville* villeA = nullptr;
        Ville* villeB = nullptr;

        for (int i = 0; i < ville.size(); i++) {
            Ville& v = ville[i];
            if (v.getNom() == city_A) {
                villeA = &v;
            }
            if (v.getNom() == city_B) {
                villeB = &v;
            }
        }

        if (villeA && villeB) {
            Ticket nouveauTicket(id, *villeA, *villeB);
            tickets.push_back(nouveauTicket);
        } else {
            std::cerr << "Erreur : villes non trouvées pour le ticket " << id << std::endl;
        }
    }
    fichierTicket.close();
}

/**
 * @brief Affiche le plateau de jeu dans la console (à implémenter).
 */
void Plateau::afficher()
{
    // Afficher le plateau de jeu
}

/**
 * @brief Retire la carte du dessus de la pioche.
 */
void Plateau::retirerCartePioche()
{
    pioche.pop_back();
}

/**
 * @brief Ajoute un ticket à la défausse du plateau.
 * @param ticket Ticket à défausser.
 */
void Plateau::ajouterDefausseTicket(Ticket ticket)
{
    defausseTicket.push_back(ticket);
}

/**
 * @brief Charge les routes depuis le fichier @c route.csv.
 *
 * Le fichier doit contenir une ligne d'en-tête suivie de lignes au format :
 * @code
 * villeA,villeB,longueur,couleur,couleur2
 * @endcode
 * Si @c couleur2 vaut @c "Aucune", la route est simple ; sinon elle est double.
 *
 * @note Affiche une erreur sur @c stderr si le fichier est introuvable.
 */
void Plateau::chargerMapCsv()
{
    std::ifstream fichier("route.csv");
    if (!fichier.is_open()) {
        std::cerr << "Erreur : impossible d'ouvrir route.csv" << std::endl;
        return;
    }

    std::string ligne;
    std::getline(fichier, ligne); // ignorer l'en-tête

    while (std::getline(fichier, ligne))
    {
        std::stringstream ss(ligne);
        std::string nomA, nomB, longueur_str, couleur_str, double_str;
        std::getline(ss, nomA, ',');
        std::getline(ss, nomB, ',');
        std::getline(ss, longueur_str, ',');
        std::getline(ss, couleur_str, ',');
        std::getline(ss, double_str, ',');

        int longueur = std::stoi(longueur_str);
        bool estDouble = (double_str != "Aucune");

        CouleurRoute couleur = CouleurRoute::Blanc;
        if (couleur_str == "Noir")   couleur = CouleurRoute::Noir;
        if (couleur_str == "Blanc")  couleur = CouleurRoute::Blanc;
        if (couleur_str == "Rouge")  couleur = CouleurRoute::Rouge;
        if (couleur_str == "Bleu")   couleur = CouleurRoute::Bleu;
        if (couleur_str == "Vert")   couleur = CouleurRoute::Vert;
        if (couleur_str == "Jaune")  couleur = CouleurRoute::Jaune;

        Route r(longueur, estDouble, couleur);
        r.setVilleA(Ville(nomA));
        r.setVilleB(Ville(nomB));

        if (double_str != "Aucune")
        {
            CouleurRoute couleur2 = CouleurRoute::Blanc;
            if (double_str == "Noir")   couleur2 = CouleurRoute::Noir;
            if (double_str == "Blanc")  couleur2 = CouleurRoute::Blanc;
            if (double_str == "Rouge")  couleur2 = CouleurRoute::Rouge;
            if (double_str == "Bleu")   couleur2 = CouleurRoute::Bleu;
            if (double_str == "Vert")   couleur2 = CouleurRoute::Vert;
            if (double_str == "Jaune")  couleur2 = CouleurRoute::Jaune;
            r.setCouleur2(couleur2);
        }

        route.push_back(r);
    }
    fichier.close();
}

/**
 * @brief Vide la défausse de tickets.
 */
void Plateau::viderDefausseTicket()
{
    defausseTicket.clear();
}

/**
 * @brief Ajoute une carte train à la défausse de cartes.
 * @param carte Carte à défausser.
 */
void Plateau::ajouterDefausseCartes(CarteTrain carte)
{
    defausseCartes.push_back(carte);
}

/**
 * @brief Retourne la défausse de cartes train.
 * @return Copie du vecteur de cartes défaussées.
 */
std::vector<CarteTrain> Plateau::getDefausseCartes() const
{
    return defausseCartes;
}

/**
 * @brief Vide la défausse de cartes train.
 */
void Plateau::viderDefausseCartes()
{
    defausseCartes.clear();
}