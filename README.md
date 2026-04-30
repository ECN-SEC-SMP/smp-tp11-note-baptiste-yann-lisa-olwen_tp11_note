Règles du jeu :

# L'Aventurier du Rail

## |Présentation|
Ce projet est une implémentation informatique du jeu de société Les Aventuriers du Rail (Ticket to Ride), créé par Alan R. Moon.

## |But du jeu|
Le jeu oppose 2 à 4 joueurs qui cherchent à relier des villes entre elles en construisant des lignes de chemin de fer.

## |Objectif du jeu|
Avoir le plus de tickets validés

## |Comment y arriver ?|
- En construisant des routes entre des villes sur la carte
- En réalisant des cartes destination (missions reliant deux villes)

## |Mise en place|
Au lancement d'une partie chaque joueur reçoit :
    - 4 cartes wagon et 
    - 20 wagons.
    - 2 cartes destination.
L'ordre de jeu est déterminé par l'odre de création des joueurs.

## |Déroulement d'un tour|
À chaque tour, le joueur actif doit effectuer l'une des 3 actions suivantes :

    Action 1 - Piocher un carte wagon
    Le joueur pioche 1 cartes wagon dans la pioche.


    Action 2 - Construire une route
    Le joueur pose des wagons (connexion entre deux villes adjacentes) en dépensant des cartes wagon.

        Règles :

        Chaque route a une longueur (1 à 6 segments) et une couleur (ou grise).
        Il faut défausser le nombre exact de cartes de la couleur correspondante.
        Les routes grises acceptent n'importe quelle couleur, mais toutes les cartes jouées doivent être de la même couleur.
        Les locomotives jouent le rôle de joker et remplacent n'importe quelle couleur.
        Une route ne peut être revendiquée que par un seul joueur.


    Action 3 - Piocher des cartes destination
    Le joueur échange ses deux tickets destination contre deux nouveaux piocher aléatoirement dans la pioche.

        Chaque carte destination indique deux villes à relier par un chemin continu.


## |Fin de la partie|
La fin de partie est déclenchée lorsqu'un joueur descend à 0 wagons. Chaque joueur joue alors un dernier tour, puis le décompte final a lieu. Mais egallment si l'un des joueurs possède 6 tickets valides.

##| Décompte final|
Chaque joueur compte ses tickets validés.
Le joueur avec le plus de tickets valides remporte la partie.

## |Règles complémentaires|
    Un chemin continu peut emprunter des routes de couleurs variées dans n'importe quelle direction, tant qu'il n'y a pas d'interruption.

    Si la pioche de cartes wagon est épuisée, les cartes défaussées sont mélangées pour reformer une nouvelle pioche.

    Les joueurs peuvent construire des routes même si elles ne sont pas nécessaires pour leurs cartes destination, afin de bloquer les adversaires ou de marquer des points supplémentaires.


