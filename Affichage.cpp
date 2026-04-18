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
    scene->setBackgroundBrush(Qt::white); 
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
    //scene->addPixmap(QPixmap("plateau.png"));
    //QPixmap img("plateau.png");
    //scene->addPixmap(img.scaled(1200, 800, Qt::KeepAspectRatio));

    dessinerVille(80,  168, "Seattle");
    dessinerVille(310, 68,  "Calgary");
    dessinerVille(70,  444, "San Francisco");
    dessinerVille(157,  577, "Los Angeles");
    dessinerVille(274, 388, "Salt Lake City");
    dessinerVille(314, 222, "Helena");
    dessinerVille(484, 413, "Denver");
    dessinerVille(439, 570, "Albuquerque");
    dessinerVille(584, 99,  "Winnipeg");
    dessinerVille(692, 413, "Kansas City");
    dessinerVille(655, 581, "Dallas");
    dessinerVille(856, 657, "New Orleans");
    dessinerVille(730, 173, "Duluth");
    dessinerVille(1015, 96,  "Montreal");
    dessinerVille(1135, 199, "New York");
    dessinerVille(825, 309, "Chicago");
    dessinerVille(1101, 357, "Washington");
    dessinerVille(953, 531, "Atlanta");
    dessinerVille(1127, 698, "Miami");

    // Dessiner les Routes
    dessinerRoute(100, 300, 300, 200, Qt::black,       4,    true);  // Seattle - Calgary
    dessinerRoute(100, 300, 280, 380, Qt::yellow,      3,    false); // Seattle - Salt Lake City
    dessinerRoute(300, 200, 280, 280, Qt::white,       4,    false); // Calgary - Helena
    dessinerRoute(280, 280, 580, 200, Qt::blue,        4,    false); // Helena - Winnipeg
    // ...
}


void Affichage::dessinerVille(int x, int y, QString nom)
{
    scene->addEllipse(x-28, y-28, 56, 56, QPen(Qt::black, 1), QBrush(Qt::white));
    QGraphicsTextItem* texte = scene->addText(nom);
    
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    texte->setFont(font);
    texte->setDefaultTextColor(Qt::darkRed);
    
    // Centrage automatique dans le rond
    float textWidth = texte->boundingRect().width();
    float textHeight = texte->boundingRect().height();
    texte->setPos(x - textWidth/2, y - textHeight/2);
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
    float totalDx = x2 - x1;
    float totalDy = y2 - y1;
    float angle = atan2(totalDy, totalDx);
    float dist = sqrt(totalDx*totalDx + totalDy*totalDy);
    
    float segmentW = 60.0f;   // largeur fixe du segment
    float segmentH = 12.0f;   // hauteur fixe du segment
    float gap = 6.0f;         // espace entre segments
    float total = longueur * segmentW + (longueur - 1) * gap;  // taille totale
    float rayonVille = 28.0f;  // même valeur que dans dessinerVille
    float offset = (dist - total) / 2.0f;  // centrage entre les deux villes

    float px = -sin(angle) * 17;  // perpendiculaire pour route double
    float py = cos(angle) * 17;

    for (int i = 0; i < longueur; i++)
    {
        float d = offset + i * (segmentW + gap);
        float x = x1 + cos(angle) * d;
        float y = y1 + sin(angle) * d;

        QGraphicsRectItem* segment = scene->addRect(0, -segmentH/2, segmentW, segmentH);
        segment->setBrush(QBrush(couleur));
        segment->setPen(QPen(Qt::black));
        QTransform transform;
        transform.translate(x, y);
        transform.rotateRadians(angle);
        segment->setTransform(transform);

        if (couleur2 != Qt::transparent)
        {
            QGraphicsRectItem* segment2 = scene->addRect(0, -segmentH/2, segmentW, segmentH);
            segment2->setBrush(QBrush(couleur2));
            segment2->setPen(QPen(Qt::black));
            QTransform transform2;
            transform2.translate(x + px, y + py);
            transform2.rotateRadians(angle);
            segment2->setTransform(transform2);
        }
    }
}
