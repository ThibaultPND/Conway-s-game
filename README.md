# Noeud2Conway

Bienvenue dans mon projet! Voici quelques rappels rapides pour travailler avec Git.
Je ne suis l'auteur que du include/  (hors include/SDL2 ) et du  src/

### Avant Utilisation /!\
Ce projet est compilé avec CMake c'est à dire qu'avant tout vous devrez supprimer tout les fichier de build/.
Sauf SDL2.dll et sdl2-config.
Et refaire une configuration (le logiciel CMake gère tout seul sur VisualStudioCode).

## Cloner le Repository

Si vous n'avez pas encore le projet sur votre machine locale, utilisez la commande suivante pour le cloner :

```bash
git clone https://github.com/ThibaultPND/Noeud2Conway.git
```


## Récupérer les Dernières Modifications

Avant de commencer à travailler, assurez-vous d'avoir les dernières modifications du dépôt :

```bash
git pull origin main
```


## Ajouter et Valider vos Modifications

Ajoutez vos fichiers modifiés au suivi de Git et effectuez un commit :
```bash
git add .
git commit -m "Description concise des modifications"
```


## Envoyer vos Modifications sur GitHub

Poussez vos modifications vers le dépôt sur GitHub :

```bash
git push origin main
```

## Ajout rapide :
```bash
git add .
git commit -m "modifications"
git push origin main
```
