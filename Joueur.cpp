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
Joueur::Joueur()
{
}

Joueur::Joueur(std::string prenom, CouleurWagon couleurWagon) : prenom(prenom), couleurWagon(couleurWagon), nbWagon(20), nbTicketValide(0), grdTraversee(0)
{
}



//////////////////////////////////////
//////////// Accesseurs //////////////
//////////////////////////////////////

/**
 * @brief Fonction qui retourne le prénom du joueur
 * 
 * @return std::string 
 */
std::string Joueur::getPrenom() const
{
    return prenom;
} 

/**
 * @brief Fonction qui retourne la main du joueur
 * 
 * @return std::vector<CarteTrain> 
 */
std::vector<CarteTrain>& Joueur::getMain()
{
    return main;
}

/**
 * @brief Fonction qui retourne la couleur du wagon du joueur 
 * 
 * @return CouleurWagon 
 */
CouleurWagon Joueur::getCouleurWagon() const
{
    return couleurWagon;
}

/**
 * @brief Fonction qui retourne le nombre de wagons du joueur
 * 
 * @return int 
 */
int Joueur::getNbWagon() const
{
    return nbWagon;
}

/**
 * @brief Fonction qui retourne les tickets du joueur
 * 
 * @return std::vector<Ticket> 
 */
std::vector<Ticket>& Joueur::getTicket()
{
    return ticket;
}

/**
 * @brief Fonction qui retourne le nombre de tickets validés du joueur
 * 
 * @return int 
 */
int Joueur::getTicketValide() const
{
    return nbTicketValide;
}

//////////////////////////////////////
///////////// Mutateurs //////////////
//////////////////////////////////////

/**
 * @brief Mutateur pour le nombre de tickets validés du joueur  
 * 
 * @param nbTicketValide 
 */
void Joueur::setNbTicketValide(int nbTicketValide)
{
    this->nbTicketValide = nbTicketValide;
}



//////////////////////////////////////
///////////// Méthodes ///////////////
//////////////////////////////////////

/**
 * @brief Fonction qui permet au joueur de piocher une carte de train
 * 
 * @param plateau 
 */
void Joueur::piocherCarte(Plateau* plateau)
{   
    main.push_back(plateau->getPioche().back()); // Prend la dernière carte de la pioche
    plateau->retirerCartePioche();               // Retire la dernière carte de la pioche
}

/**
 * @brief Fonction qui permet au joueur de défausser une carte de train
 * 
 * @param carteTrain 
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
 * @brief Fonction qui permet au joueur de piocher un ticket
 * 
 * @param nouvTicket 
 */
void Joueur::piocherTicket(Ticket nouvTicket)
{
    ticket.push_back(nouvTicket);
}

/**
 * @brief Fonction qui permet au joueur de défausser un ticket
 * 
 * @param ticket 
 * @param plateau 
 */
void Joueur::defausserTicket(Ticket t, Plateau* plateau)
{
    plateau->ajouterDefausseTicket(t);

    for (auto it = this->ticket.begin(); it != this->ticket.end(); it++)
    {
        if (*it == t)
        {
            this->ticket.erase(it);
            break;
        }
    }
}

/**
 * @brief Fonction qui permet au joueur de valider un ticket
 * 
 * @param t 
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
 * @brief Fonction qui vérifie si le joueur peut prendre une route en fonction de sa disponibilité
 * 
 * @param route 
 * @return true 
 * @return false 
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
 * @brief Fonction qui affiche la main du joueur
 * 
 */
void Joueur::afficherMain()
{
    for (auto it = main.begin(); it != main.end(); it++)
    {
        std::cout << couleurToString(it->getCouleur()) << std::endl;
    }
}

/**
 * @brief Fonction qui permet au joueur de réaliser la grande traversée
 * 
 * @param B 
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
