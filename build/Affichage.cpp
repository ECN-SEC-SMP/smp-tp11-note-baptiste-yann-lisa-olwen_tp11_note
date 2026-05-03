#include "Affichage.h"
#include <QGraphicsTextItem>
#include <QMouseEvent>
#include <QDebug>

void Affichage::mousePressEvent(QMouseEvent* event)
{
    QPointF pos = vue->mapToScene(event->pos());
    qDebug() << "x =" << pos.x() << ", y =" << pos.y();
}

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


    dessinerRoute(80,  168, 310, 68,    Qt::black,  3, Qt::red);            // Seattle - Calgary
    dessinerRoute(80,  168, 70,  444,   Qt::blue,   3, Qt::green);          // Seattle - San Francisco
    dessinerRoute(80,  168, 274, 388,   Qt::white,  3, Qt::transparent);    // Seattle - Salt Lake City
    dessinerRoute(80,  168, 314, 222,   Qt::yellow, 2, Qt::transparent);    // Seattle - Helena
    dessinerRoute(310, 68,  314, 222,   Qt::white,  1, Qt::red);            // Calgary - Helena
    dessinerRoute(310, 68,  584, 99,    Qt::yellow, 3, Qt::green);          // Calgary - Winnipeg
    dessinerRoute(314, 222, 584, 99,    Qt::blue,   3, Qt::transparent);    // Helena - Winnipeg
    dessinerRoute(314, 222, 274, 388,   Qt::green,  1, Qt::black);          // Helena - Salt Lake City
    dessinerRoute(314, 222, 484, 413,   Qt::yellow, 2, Qt::transparent);    // Helena - Denver
    dessinerRoute(274, 388, 484, 413,   Qt::black,  2, Qt::blue);           // Salt Lake City - Denver
    dessinerRoute(274, 388, 70,  444,   Qt::green,  2, Qt::yellow);         // Salt Lake City - San Francisco
    dessinerRoute(274, 388, 439, 570,   Qt::yellow, 2, Qt::transparent);    // Salt Lake City - Albuquerque
    dessinerRoute(70,  444, 157, 577,   Qt::black,  1, Qt::red);            // San Francisco - Los Angeles
    dessinerRoute(157, 577, 439, 570,   Qt::blue,   3, Qt::white);          // Los Angeles - Albuquerque
    dessinerRoute(157, 577, 274, 388,   Qt::red,    2, Qt::transparent);    // Los Angeles - Salt Lake City
    dessinerRoute(439, 570, 484, 413,   Qt::red,    1, Qt::transparent);    // Albuquerque - Denver
    dessinerRoute(484, 413, 692, 413,   Qt::white,  2, Qt::green);          // Denver - Kansas City
    dessinerRoute(584, 99,  730, 173,   Qt::black,  1, Qt::red);            // Winnipeg - Duluth
    dessinerRoute(692, 413, 655, 581,   Qt::red,    1, Qt::yellow);         // Kansas City - Dallas
    dessinerRoute(692, 413, 953, 531,   Qt::blue,   3, Qt::transparent);    // Kansas City - Atlanta
    dessinerRoute(825, 309, 953, 531,   Qt::green,  2, Qt::transparent);    // Chicago - Atlanta
    dessinerRoute(655, 581, 856, 657,   Qt::red,    2, Qt::blue);           // Dallas - New Orleans
    dessinerRoute(856, 657, 953, 531,   Qt::red,    1, Qt::black);          // New Orleans - Atlanta
    dessinerRoute(655, 581, 953, 531,   Qt::white,  3, Qt::transparent);    // Dallas - Atlanta
    dessinerRoute(655, 581, 439, 570,   Qt::black,  2, Qt::green);          // Dallas - Albuquerque
    dessinerRoute(730, 173, 484, 413,   Qt::black,  4, Qt::transparent);    // Duluth - Denver
    dessinerRoute(730, 173, 825, 309,   Qt::red,    1, Qt::blue);           // Duluth - Chicago
    dessinerRoute(730, 173, 1015, 96,   Qt::blue,   3, Qt::green);          // Duluth - Montreal
    dessinerRoute(730, 173, 692, 413,   Qt::white,  2, Qt::transparent);    // Duluth - Kansas City
    dessinerRoute(1015, 96,  1135, 199, Qt::black,  1, Qt::white);          // Montreal - New York
    dessinerRoute(1015, 96,  825, 309,  Qt::yellow, 3, Qt::transparent);    // Montreal - Chicago
    dessinerRoute(1135, 199, 1101, 357, Qt::yellow, 1, Qt::blue);           // New York - Washington
    dessinerRoute(1135, 199, 825, 309,  Qt::white,  3, Qt::red);            // New York - Chicago
    dessinerRoute(825, 309, 1101, 357,  Qt::black,  3, Qt::transparent);    // Chicago - Washington
    dessinerRoute(825, 309, 692, 413,   Qt::yellow, 1, Qt::black);          // Chicago - Kansas City
    dessinerRoute(953, 531, 1101, 357,  Qt::white,  2, Qt::yellow);         // Atlanta - Washington
    dessinerRoute(953, 531, 1127, 698,  Qt::blue,   2, Qt::black);          // Atlanta - Miami
    dessinerRoute(1127, 698, 1101, 357, Qt::green,  4, Qt::red);            // Miami - Washington
    dessinerRoute(1127, 698, 856, 657,  Qt::white,  3, Qt::yellow);         // Miami - New Orleans
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


void Affichage::mettreAJour()
{
    scene->clear();
    dessinerPlateau();
}


void Affichage::dessinerRoute(int x1, int y1, int x2, int y2, QColor couleur, int longueur, QColor couleur2)
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
