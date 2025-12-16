# FILES (Queues) - Documentation

## Vue d'ensemble
Ce dossier implémente une structure de données **FILE** (Queue en anglais) en utilisant des **listes chaînées dynamiques** et les **templates C++** pour permettre une généricité maximale.

## Principe fondamental
Les FILES fonctionnent selon le principe du **FIFO** (First In, First Out) :
- Le **premier élément ajouté** sera le **premier à être retiré**
- C'est comme une file d'attente réelle où la première personne à entrer est la première à sortir

## Fichiers du projet

### `files.hpp`
Fichier d'en-tête contenant l'implémentation de la classe template `file<T>`.

#### Structure interne
- **struct noeud** : Représente chaque élément de la file
  - `T valeur` : La valeur stockée dans le nœud
  - `noeud *suivant` : Pointeur vers le nœud suivant

#### Attributs privés
- `noeud *tete` : Pointeur vers le premier élément de la file

#### Méthodes principales

| Méthode | Description |
|---------|-------------|
| `file()` | Constructeur - initialise une file vide |
| `isEmpty()` | Vérifie si la file est vide |
| `length()` | Retourne le nombre d'éléments dans la file |
| `enfiler(T val)` | Ajoute un élément au début de la file |
| `defiler()` | Retire et supprime le premier élément |
| `afficherFile()` | Affiche tous les éléments de la file |

### `main.cpp`
Fichier de test démontrant l'utilisation de la classe `file`.

#### Exemple d'exécution
```
- Création d'une file d'entiers
- Ajout des valeurs : 15, 16, 17, 18, 19
- Affichage de la file
- Suppression des trois premiers éléments (15, 16, 17)
- Affichage de la file après suppression
```

## Points clés de l'implémentation

1. **Utilisation de templates** : La classe peut fonctionner avec n'importe quel type de données
2. **Allocation dynamique** : Les nœuds sont créés en mémoire dynamique avec `new`
3. **Gestion de la mémoire** : Les nœuds supprimés sont libérés avec `delete`
4. **Genericité** : Aucune restriction sur le type de données stockées

## Utilisation type
```cpp
file<int> ma_file;
ma_file.enfiler(10);    // Ajouter 10
ma_file.enfiler(20);    // Ajouter 20
ma_file.afficherFile(); // Afficher : 20 -> 10
ma_file.defiler();      // Retirer 20
```
