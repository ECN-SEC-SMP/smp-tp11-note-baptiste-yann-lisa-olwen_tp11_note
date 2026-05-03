#pragma once
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>  // ← ajouter
#include <QTransform>         // ← ajouter
#include <QtMath>             // ← ajouter pour atan2
#include "Plateau.h"
#include "Joueur.h"

class Affichage : public QMainWindow {
    Q_OBJECT

private:
    QGraphicsScene* scene;
    QGraphicsView* vue;
    Plateau* plateau;

    void dessinerPlateau();
    void dessinerVille(int x, int y, QString nom);
    void dessinerRoute(int x1, int y1, int x2, int y2, QColor couleur, int longueur, QColor couleur2 = Qt::transparent);
    void dessinerJoueurs();

public:
    Affichage(Plateau* plateau, QWidget* parent = nullptr);
    void mettreAJour();

protected:
    void mousePressEvent(QMouseEvent* event) override;
};