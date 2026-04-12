# 🚂 Les Aventuriers du Rail

> *Implémentation numérique du célèbre jeu de société d'Alan R. Moon*

---

## Présentation

Ce projet est une **implémentation informatique** du jeu de société **Les Aventuriers du Rail** (*Ticket to Ride*), 
créé par Alan R. Moon.

Le jeu oppose **2 à 5 joueurs** qui cherchent à relier des villes entre elles en construisant des lignes de chemin de fer, tout en accomplissant des missions secrètes pour scorer un maximum de points.

---

## Objectif du jeu

Marquer le plus de **points de victoire (PV)** en :

1. **Construisant des routes** entre des villes sur la carte
2. **Réalisant des cartes destination** (missions reliant deux villes)
3. **Obtenant le bonus** de la route continue la plus longue

Le joueur avec le plus de points à la fin gagne la partie.

---

## Mise en place

Au lancement d'une partie :

- Chaque joueur reçoit **4 cartes wagon** et dispose de **48 wagons**.
- **5 cartes wagon** sont révélées face visible (la "main commune").
- Chaque joueur reçoit **3 cartes destination** et doit en **conserver au minimum 2** (la troisième peut être défaussée).
- L'ordre de jeu est déterminé aléatoirement.

---

## Déroulement d'un tour

À chaque tour, le joueur actif doit effectuer **l'une des 3 actions** suivantes :

---

### Action 1 — Piocher des cartes wagon

Le joueur pioche **2 cartes wagon** parmi :
- Les **5 cartes visibles** (communes à tous)
- La **pioche** (cartes face cachée)

> ⚠️ **Locomotive (joker)** : prendre une locomotive *visible* utilise les **2 droits de pioche** du tour. Une locomotive tirée face cachée ne compte que pour 1 carte.

Si 3 locomotives apparaissent simultanément parmi les cartes visibles, elles sont défaussées et remplacées.

---

### Action 2 — Construire une route

Le joueur revendique une **route** (connexion entre deux villes adjacentes) en dépensant des cartes wagon.

**Règles :**

- Chaque route a une **longueur** (1 à 6 segments) et une **couleur** (ou grise).
- Il faut défausser le **nombre exact de cartes** de la couleur correspondante.
- Les routes **grises** acceptent n'importe quelle couleur, mais toutes les cartes jouées doivent être de la **même couleur**.
- Les **locomotives** jouent le rôle de joker et remplacent n'importe quelle couleur.
- Une route ne peut être revendiquée que par **un seul joueur**.

**Points gagnés immédiatement :**

| Longueur | Points |
|----------|--------|
| 1 wagon  | 1 pt   |
| 2 wagons | 2 pts  |
| 3 wagons | 4 pts  |
| 4 wagons | 7 pts  |
| 5 wagons | 10 pts |
| 6 wagons | 15 pts |

---

### 🗺️ Action 3 — Piocher des cartes destination

Le joueur pioche **3 cartes destination** et doit en **garder au minimum 1**.

Chaque carte destination indique **deux villes à relier** par un chemin continu, ainsi qu'une valeur en points :
- ✅ Connexion réalisée en fin de partie → **+points**
- ❌ Connexion non réalisée → **−points**

---

## Fin de la partie

La fin de partie est déclenchée lorsqu'un joueur descend à **2 wagons ou moins**. Chaque joueur joue alors **un dernier tour**, puis le décompte final a lieu.

---

## Décompte final

1. **Points des routes** : accumulés pendant la partie.
2. **Cartes destination** : chaque carte est vérifiée — les villes sont-elles reliées par un chemin continu ? Points ajoutés ou soustraits en conséquence.
3. **Bonus "Plus Long Parcours"** : +10 pts au joueur possédant la route continue la plus longue. En cas d'égalité, le bonus est partagé.

Le joueur avec le **total le plus élevé** remporte la partie.

---

## Règles complémentaires

- Un **chemin continu** peut emprunter des routes de couleurs variées dans n'importe quelle direction, tant qu'il n'y a pas d'interruption.
- Sur les plateaux avec des **routes doubles** (deux routes parallèles entre les mêmes villes), à 2-3 joueurs un même joueur **ne peut pas** construire les deux routes parallèles.
- Les cartes destination défaussées en début de partie sont remises **au bas de la pioche**.
- Si la pioche de cartes wagon est épuisée, les cartes défaussées sont **mélangées pour reformer une nouvelle pioche**.
- Les joueurs peuvent choisir de **ne pas prendre de cartes destination supplémentaires** s'ils le souhaitent.

- Les joueurs peuvent construire des routes même si elles ne sont pas nécessaires pour leurs cartes destination, afin de bloquer les adversaires ou de marquer des points supplémentaires. 
- Les joueurs peuvent construire des routes pour relier des villes qui ne sont pas sur leurs cartes destination, dans le but de créer des connexions plus longues ou de bloquer les adversaires.
- Les joueurs peuvent choisir de construire des routes pour compléter des cartes destination qu'ils ont déjà réalisées, afin de renforcer leur position ou de marquer des points supplémentaires.