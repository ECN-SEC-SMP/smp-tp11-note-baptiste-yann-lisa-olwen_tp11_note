# Les Aventuriers du Rail

Implémentation C++ du jeu de société *Les Aventuriers du Rail*, avec interface graphique Qt6.

## Règles du jeu

### Objectif

Chaque joueur cherche à relier des villes sur la carte des États-Unis en posant ses wagons sur des routes. La partie se termine quand un joueur a validé **6 tickets destination** ou n'a **plus de wagons**.

### Mise en place

- 2 à 4 joueurs, chacun reçoit une couleur de wagon unique.
- Chaque joueur reçoit **4 cartes train** et **2 tickets destination** au départ.
- La pioche contient **70 cartes train** (10 par couleur + 12 locomotives supplémentaires).

### Déroulement d'un tour

À chaque tour, le joueur choisit **une** des trois actions suivantes :

1. **Piocher deux cartes train** — prendre les deux premières cartes de la pioche.
2. **Poser des wagons** — revendiquer une route disponible en défaussant les cartes de la couleur correspondante.
3. **Échanger ses tickets** — défausser ses deux tickets actuels et en piocher deux nouveaux.

### Poser des wagons

Pour revendiquer une route, le joueur doit défausser un nombre de cartes train égal à la **longueur de la route**, toutes de la **couleur de la route** (ou des locomotives en joker).

Les **routes doubles** ont deux voies de couleurs différentes : une seule peut être revendiquée par joueur.

### Tickets destination

Chaque ticket impose de relier deux villes par un chemin continu de routes. Si le joueur y parvient, le ticket est **validé** et retiré de sa main — un nouveau ticket est alors pioché automatiquement.

### Locomotives

Les cartes **Locomotive** sont des jokers : elles peuvent remplacer n'importe quelle couleur pour revendiquer une route.

### Fin de partie

La partie se termine immédiatement quand un joueur :
- a validé **6 tickets destination**, ou
- n'a **plus aucun wagon** disponible.

Ce joueur est déclaré vainqueur.

---

## Compilation

### Prérequis

- CMake ≥ 3.16
- Qt6 (Core + Widgets)
- Doxygen + Graphviz (optionnel, pour la documentation)

### Compiler le jeu

```bash
mkdir build && cd build
cmake ..
cmake --build .
./AventuriersDuRail
```

### Générer la documentation

```bash
cmake --build . --target doc
# Puis ouvrir docs/html/index.html
```

---

## Architecture

| Classe | Rôle |
|---|---|
| `Plateau` | Données centrales : villes, routes, pioche, tickets |
| `Joueur` | Main, wagons, tickets, actions |
| `Route` | Connexion entre deux villes, couleur, longueur |
| `Ville` | Nœud du réseau ferroviaire |
| `CarteTrain` | Carte identifiée par sa couleur |
| `Ticket` | Objectif destination à relier |
| `Affichage` | Interface graphique Qt (QGraphicsScene) |

---

## Auteurs

- Lisa Le Goff
- Olwen Pichard
- Baptiste De Paul de Barchifontaine
- Yann Buttet