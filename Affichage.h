#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTransform>
#include <QtMath>

#include "Plateau.h"
#include "Joueur.h"

/**
 * @brief Fenêtre principale de l'application – affichage du plateau de jeu.
 *
 * La classe @c Affichage hérite de QMainWindow et centralise tout le rendu
 * graphique du jeu : plateau, villes, routes et pions des joueurs.
 * Elle utilise un QGraphicsScene / QGraphicsView pour le dessin 2D.
 *
 * @ingroup Affichage
 */
class Affichage : public QMainWindow {
    Q_OBJECT

private:
    QGraphicsScene* scene;   ///< Scène Qt contenant tous les éléments graphiques.
    QGraphicsView*  vue;     ///< Vue Qt affichant la scène dans la fenêtre.
    Plateau*        plateau; ///< Pointeur vers le plateau logique du jeu.

    /**
     * @brief Dessine l'intégralité du plateau (villes + routes).
     * @note Appelée une seule fois à l'initialisation, puis sur demande de mise à jour.
     */
    void dessinerPlateau();

    /**
     * @brief Dessine une ville sous forme de cercle étiqueté.
     * @param x   Coordonnée X du centre de la ville (pixels scène).
     * @param y   Coordonnée Y du centre de la ville (pixels scène).
     * @param nom Nom affiché sous le symbole de la ville.
     */
    void dessinerVille(int x, int y, QString nom);

    /**
     * @brief Dessine une route entre deux points, avec support des routes doubles.
     *
     * Si @p couleur2 est différente de Qt::transparent, une seconde voie
     * parallèle est tracée à côté de la première (route double).
     * Si @p proprio est non vide, la route est coloriée aux couleurs du joueur
     * propriétaire.
     *
     * @param x1       Coordonnée X du point de départ (pixels scène).
     * @param y1       Coordonnée Y du point de départ (pixels scène).
     * @param x2       Coordonnée X du point d'arrivée (pixels scène).
     * @param y2       Coordonnée Y du point d'arrivée (pixels scène).
     * @param couleur  Couleur principale de la route.
     * @param longueur Nombre de wagons nécessaires pour revendiquer la route.
     * @param couleur2 Couleur de la voie parallèle (Qt::transparent = route simple).
     * @param proprio  Nom du joueur propriétaire (vide = route libre).
     */
    void dessinerRoute(int x1, int y1, int x2, int y2,
                       QColor couleur, int longueur,
                       QColor couleur2 = Qt::transparent,
                       QString proprio = "");

    /**
     * @brief Dessine les pions et informations de chaque joueur sur le plateau.
     */
    void dessinerJoueurs();

public:
    /**
     * @brief Construit la fenêtre principale et initialise la scène graphique.
     * @param plateau Pointeur vers le plateau logique (ne doit pas être nul).
     * @param parent  Widget Qt parent (nullptr = fenêtre racine).
     */
    explicit Affichage(Plateau* plateau, QWidget* parent = nullptr);

    /**
     * @brief Redessine l'intégralité de la scène pour refléter l'état courant du jeu.
     * @note À appeler après chaque modification du modèle (pose de wagons, etc.).
     */
    void mettreAJour();

protected:
    /**
     * @brief Intercepte les clics souris pour la sélection de routes ou de villes.
     * @param event Événement souris fourni par Qt.
     */
    void mousePressEvent(QMouseEvent* event) override;
};