#include <string>
#include <iostream>

#include "Joueur.h"
#include "CouleurWagon.h"
#include "CouleurCarte.h"
#include "Ticket.h"
#include "Plateau.h"

//////////////////////////////////////
////// Constructeur par défaut ///////
//////////////////////////////////////

/**
 * @brief Constructeur par défaut — crée un joueur sans nom ni couleur.
 * @ingroup Joueurs
 */
Joueur::Joueur()
{
}

/**
 * @brief Crée un joueur avec un prénom et une couleur de wagon.
 *
 * Le joueur commence avec 20 wagons, 0 ticket validé et 0 grande traversée.
 *
 * @param prenom       Prénom du joueur.
 * @param couleurWagon Couleur des wagons attribuée au joueur (voir @ref CouleurWagon).
 * @ingroup Joueurs
 */
Joueur::Joueur(std::string prenom, CouleurWagon couleurWagon) : prenom(prenom), couleurWagon(couleurWagon), nbWagon(20), nbTicketValide(0), grdTraversee(0)
{
}

//////////////////////////////////////
//////////// Accesseurs //////////////
//////////////////////////////////////

/**
 * @brief Retourne le prénom du joueur.
 * @return Le prénom du joueur.
 */
std::string Joueur::getPrenom() const
{
    return prenom;
} 

/**
 * @brief Retourne la main du joueur (cartes train en sa possession).
 * @return Référence vers le vecteur de cartes train.
 */
std::vector<CarteTrain>& Joueur::getMain()
{
    return main;
}

/**
 * @brief Retourne la couleur de wagon du joueur.
 * @return La couleur de wagon (voir @ref CouleurWagon).
 */
CouleurWagon Joueur::getCouleurWagon() const
{
    return couleurWagon;
}

/**
 * @brief Retourne le nombre de wagons restants du joueur.
 * @return Nombre de wagons disponibles.
 */
int Joueur::getNbWagon() const
{
    return nbWagon;
}

/**
 * @brief Retourne les tickets destination du joueur.
 * @return Référence vers le vecteur de tickets.
 */
std::vector<Ticket>& Joueur::getTicket()
{
    return ticket;
}

/**
 * @brief Retourne le nombre de tickets validés du joueur.
 * @return Nombre de tickets complétés.
 */
int Joueur::getTicketValide() const
{
    return nbTicketValide;
}

//////////////////////////////////////
///////////// Mutateurs //////////////
//////////////////////////////////////

/**
 * @brief Modifie le nombre de tickets validés du joueur.
 * @param nbTicketValide Nouveau nombre de tickets validés.
 */
void Joueur::setNbTicketValide(int nbTicketValide)
{
    this->nbTicketValide = nbTicketValide;
}

//////////////////////////////////////
///////////// Méthodes ///////////////
//////////////////////////////////////

/**
 * @brief Pioche la carte du dessus de la pioche et l'ajoute à la main du joueur.
 * @param plateau Pointeur vers le plateau contenant la pioche.
 */
void Joueur::piocherCarte(Plateau* plateau)
{   
    main.push_back(plateau->getPioche().back()); // Prend la dernière carte de la pioche
    plateau->retirerCartePioche();               // Retire la dernière carte de la pioche
}

/**
 * @brief Retire une carte train de la main du joueur.
 *
 * Seule la première occurrence de la carte est supprimée.
 *
 * @param carteTrain Carte à défausser.
 */
void Joueur::defausserCarte(CarteTrain carteTrain)
{
    for (auto it = main.begin(); it != main.end(); it++)
    {
        if (*it == carteTrain)
        {
            main.erase(it);
            break;
        }
    }
}

/**
 * @brief Ajoute un ticket destination à la main du joueur.
 * @param nouvTicket Ticket à ajouter.
 */
void Joueur::piocherTicket(Ticket nouvTicket)
{
    ticket.push_back(nouvTicket);
}

/**
 * @brief Défausse un ticket vers la défausse du plateau.
 * @param ticket  Ticket à défausser.
 * @param plateau Pointeur vers le plateau contenant la défausse.
 */
void Joueur::defausserTicket(Ticket ticket, Plateau* plateau)
{
    plateau->ajouterDefausseTicket(ticket);
}

/**
 * @brief Valide un ticket si son objectif est atteint et incrémente le compteur.
 * @param t Pointeur vers le ticket à valider.
 */
void Joueur::validerTicket(Ticket* t)
{
    if (t->estValide())
    {
        int TicVal = getTicketValide();
        TicVal += 1;
        setNbTicketValide(TicVal);
    }
}

/**
 * @brief Vérifie si le joueur peut revendiquer une route.
 * @param route Pointeur vers la route à tester.
 * @return @c true si la route est disponible, @c false sinon.
 */
bool Joueur::peutPrendreRoute(Route* route)
{
    if (route->estDispo())
    {
        return true;
    }
    return false;
}

/**
 * @brief Affiche dans la console toutes les cartes train de la main du joueur.
 */
void Joueur::afficherMain()
{
    for (auto it = main.begin(); it != main.end(); it++)
    {
        std::cout << couleurToString(it->getCouleur()) << std::endl;
    }
}

/**
 * @brief Gère le bonus de la grande traversée.
 *
 * Si @p B est @c true, incrémente le compteur de tickets validés.
 * Sinon, affiche un message d'échec dans la console.
 *
 * @param B @c true si la grande traversée est réussie, @c false sinon.
 */
void Joueur::GrandeTraversee(bool B)
{
    if (B == true)
    {
        int TicVal = getTicketValide();
        TicVal += 1;
        setNbTicketValide(TicVal);
    }
    else 
    {
        std::cout << "La grande traversée n'est pas valide." << std::endl;
    }
}

/**
 * @brief Vérifie si un ticket destination est complété par les routes du joueur.
 *
 * Construit un graphe à partir des routes appartenant au joueur, puis effectue
 * un parcours en largeur (BFS) depuis la ville de départ du ticket pour
 * déterminer si la ville d'arrivée est atteignable.
 *
 * @complexity O(V + E) où V est le nombre de villes et E le nombre de routes du joueur.
 *
 * @param t      Ticket destination à vérifier.
 * @param routes Liste complète des routes du plateau.
 * @return @c true si le joueur relie les deux villes du ticket, @c false sinon.
 */
bool Joueur::verifierTicket(Ticket t, std::vector<Route>& routes)
{
    std::string villeA = t.getVilleA().getNom();
    std::string villeB = t.getVilleB().getNom();

    // Construire le graphe des routes du joueur
    std::map<std::string, std::vector<std::string>> graphe;
    for (Route& r : routes)
    {
        if (r.getProprio() == this)  // seulement les routes du joueur
        {
            graphe[r.getVilleA().getNom()].push_back(r.getVilleB().getNom());
            graphe[r.getVilleB().getNom()].push_back(r.getVilleA().getNom());
        }
    }

    // BFS depuis villeA
    std::vector<std::string> visites;
    std::vector<std::string> file = {villeA};

    while (!file.empty())
    {
        std::string ville = file.front();
        file.erase(file.begin());

        if (ville == villeB)
            return true;  // chemin trouvé !

        // Marquer comme visitée
        bool dejaVisite = false;
        for (std::string v : visites)
            if (v == ville) dejaVisite = true;

        if (!dejaVisite)
        {
            visites.push_back(ville);
            for (std::string voisin : graphe[ville])
                file.push_back(voisin);
        }
    }
    return false;  // pas de chemin
}

/**
 * @brief Vider les tickets destination du joueur.
 *
 * Permet de réinitialiser l'état du joueur entre les parties ou après un échange de tickets.
 */
void Joueur::viderTickets()
{
    ticket.clear();
}