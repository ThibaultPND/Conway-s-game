# Noeud de Conway

Noeud de Conway est une implémentation du célèbre **Jeu de la vie** de Conway en C++ utilisant la librairie **SDL2** pour l'affichage graphique. Ce projet simule l'évolution d'une grille de cellules selon des règles simples d'automate cellulaire. Dans cette version, l'avancement du temps (la génération suivante) se déclenche par l'appui sur la touche **Espace**.

## Table des matières

- [Description](#description)
- [Fonctionnalités](#fonctionnalités)
- [Prérequis](#prérequis)
- [Compilation et Exécution](#compilation-et-exécution)
- [Captures d'écran](#captures-décran)
- [Contribution](#contribution)
- [Licence](#licence)
- [Cloner le Repository](#cloner-le-repository)

## Description

Le Jeu de la vie est un automate cellulaire où chaque cellule d'une grille évolue en fonction de règles précises appliquées aux cellules voisines. Dans **Noeud de Conway**, chaque cellule est soit vivante, soit morte, et les règles d'évolution sont appliquées à chaque "tic" de l'horloge, que vous pouvez déclencher en appuyant sur la touche **Espace**.

Cette version a été réalisée rapidement dans le but de montrer qu'il était possible d'implémenter le concept en peu de temps. Des améliorations pourront être apportées au fil des contributions de la communauté.

## Fonctionnalités

- Simulation du Jeu de la vie avec des règles classiques d'automate cellulaire.
- Contrôle manuel de l'évolution des générations (avancement avec la touche **Espace**).
- Utilisation de la librairie **SDL2** pour un rendu graphique simple et efficace.

## Prérequis

- **CMake** pour la configuration et la génération des fichiers de build.
- **SDL2** pour la gestion graphique.
- Un compilateur supportant le C++.

## Compilation et Exécution

Pour compiler et exécuter le projet, suivez ces étapes :

1. **Cloner le dépôt** (voir la section ci-dessous).

2. **Créer un dossier de build** et y accéder :

   ```bash
   mkdir build
   cd build
