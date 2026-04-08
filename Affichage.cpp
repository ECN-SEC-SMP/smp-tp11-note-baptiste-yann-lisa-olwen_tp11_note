#include "Affichage.h"
#include <QGraphicsTextItem>

/**
 * @brief Constructeur de la classe Affichage qui initialise la fenêtre de jeu et dessine le plateau de jeu
 * 
 * @param plateau 
 * @param parent 
 */
Affichage::Affichage(Plateau* plateau, QWidget* parent)
    : QMainWindow(parent), plateau(plateau)
{
    scene = new QGraphicsScene();
    vue = new QGraphicsView(scene);
    setCentralWidget(vue);
    setWindowTitle("Les Aventuriers du Rail");
    resize(1200, 800);

    dessinerPlateau();
}

/**
 * @brief  Méthode qui dessine le plateau de jeu en utilisant les éléments du plateau (villes, routes, etc.)
 * 
 */
void Affichage::dessinerPlateau()
{
    // Image de fond
    scene->addPixmap(QPixmap("plateau.png"));

    // Dessiner les villes
    // Ouest
    dessinerVille(100, 300, "Seattle");
    dessinerVille(300, 200, "Calgary");
    dessinerVille(100, 450, "San Francisco");
    dessinerVille(150, 550, "Los Angeles");
    dessinerVille(280, 380, "Salt Lake City");
    dessinerVille(280, 280, "Helena");
    dessinerVille(380, 480, "Denver");
    dessinerVille(380, 580, "Albuquerque");

    // Centre
    dessinerVille(580, 200, "Winnipeg");
    dessinerVille(580, 380, "Kansas City");
    dessinerVille(480, 580, "Dallas");
    dessinerVille(580, 620, "New Orleans");

    // Est
    dessinerVille(780, 150, "Duluth");
    dessinerVille(880, 100, "Montreal");
    dessinerVille(980, 200, "New York");
    dessinerVille(880, 300, "Chicago");
    dessinerVille(950, 350, "Washington");
    dessinerVille(880, 500, "Atlanta");
    dessinerVille(1050, 600, "Miami");

    // Dessiner les Routes
    dessinerRoute(100, 300, 300, 200, Qt::black,       4,    true);  // Seattle - Calgary
    dessinerRoute(100, 300, 280, 380, Qt::yellow,      3,    false); // Seattle - Salt Lake City
    dessinerRoute(300, 200, 280, 280, Qt::white,       4,    false); // Calgary - Helena
    dessinerRoute(280, 280, 580, 200, Qt::blue,        4,    false); // Helena - Winnipeg
    // ...
}

/**
 * @brief Dessine une ville sur le plateau de jeu avec un cercle et son nom à côté
 * 
 * @param x 
 * @param y 
 * @param nom 
 */
void Affichage::dessinerVille(int x, int y, QString nom)
{
    scene->addEllipse(x-8, y-8, 16, 16, QPen(Qt::black), QBrush(Qt::white));
    QGraphicsTextItem* texte = scene->addText(nom);
    texte->setPos(x+10, y-10);
    texte->setDefaultTextColor(Qt::darkRed);
}

/**
 * @brief  Méthode qui met à jour l'affichage du plateau de jeu en redessinant les éléments du plateau
 * 
 */
void Affichage::mettreAJour()
{
    scene->clear();
    dessinerPlateau();
}

/**
 * @brief  Méthode qui dessine une route entre deux villes avec une couleur et une longueur donnée, et gère les routes doubles
 * 
 * @param x1 
 * @param y1 
 * @param x2 
 * @param y2 
 * @param couleur 
 * @param longueur 
 * @param estDouble 
 */
void Affichage::dessinerRoute(int x1, int y1, int x2, int y2, QColor couleur, int longueur, bool estDouble)
{
    // Calcule la direction entre les deux villes
    float dx = (x2 - x1) / (float)longueur;
    float dy = (y2 - y1) / (float)longueur;

    // Perpendiculaire pour décaler les routes doubles
    float px = -dy * 0.3f;
    float py = dx * 0.3f;

    for (int i = 0; i < longueur; i++)
    {
        float x = x1 + dx * i + dx * 0.1f;
        float y = y1 + dy * i + dy * 0.1f;

        QGraphicsRectItem* segment = scene->addRect(0, 0, 25, 12);
        segment->setBrush(QBrush(couleur));
        segment->setPen(QPen(Qt::black));

        // Rotation du segment dans la bonne direction
        QTransform transform;
        transform.translate(x, y);
        transform.rotateRadians(atan2(dy, dx));
        segment->setTransform(transform);

        // Si route double, décale légèrement
        if (estDouble)
        {
            QGraphicsRectItem* segment2 = scene->addRect(0, 0, 25, 12);
            segment2->setBrush(QBrush(Qt::gray));  // 2ème route souvent grise
            segment2->setPen(QPen(Qt::black));
            QTransform transform2;
            transform2.translate(x + px * 15, y + py * 15);
            transform2.rotateRadians(atan2(dy, dx));
            segment2->setTransform(transform2);
        }
    }
}
