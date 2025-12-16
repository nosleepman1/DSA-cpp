# LISTES CHAÎNÉES MONOCHAÎNÉES (Singly Linked Lists)

## Vue d'ensemble
Ce dossier implémente une **liste chaînée simple** (monochaînée) en utilisant des **listes chaînées dynamiques** et les **templates C++**. Chaque nœud pointe vers le nœud suivant uniquement.

## Principe fondamental
Une liste chaînée monochaînée est une structure de données linéaire où :
- Chaque nœud contient une **valeur** et un **pointeur vers le nœud suivant**
- On peut parcourir la liste uniquement dans une direction (avant)
- La flexibilité d'insertion/suppression au début et à la fin sans coût additionnel

## Fichiers du projet

### `liste.hpp`
Fichier d'en-tête contenant l'implémentation de la classe template `liste<T>`.

#### Structure interne
- **struct node** : Représente chaque élément de la liste
  - `T data` : La valeur stockée dans le nœud
  - `node *next` : Pointeur vers le nœud suivant

#### Attributs privés
- `node *head` : Pointeur vers le premier élément (tête)
- `node *end` : Pointeur vers le dernier élément (queue)

#### Méthodes principales

| Méthode | Description |
|---------|-------------|
| `liste()` | Constructeur - initialise une liste vide |
| `isEmpty()` | Vérifie si la liste est vide |
| `length()` | Retourne le nombre d'éléments |
| `push_front(T val)` | Ajoute un élément au début |
| `push_back(T val)` | Ajoute un élément à la fin |
| `pop_front()` | Retire le premier élément |
| `pop_back()` | Retire le dernier élément |
| `showList()` | Affiche tous les éléments |

### `main.cpp`
Fichier de test démontrant l'utilisation de la classe `liste`.

#### Exemple d'exécution
```
- Création d'une liste d'entiers vide
- Ajout au début : 18, 14, 17, 10
- Ajout à la fin : 222, 227, 311
- Affichage de la liste
```

## Points clés de l'implémentation

1. **Tête et Queue** : Pointeurs aux deux extrémités pour opérations O(1) au début et à la fin
2. **Allocation dynamique** : Nœuds créés avec `new` pour une flexibilité d'allocation
3. **Généricité** : Templates permettent n'importe quel type de données
4. **Parcours simple** : Un seul pointeur `next` par nœud pour accéder au suivant

## Avantages et inconvénients

### Avantages
- ✅ Insertion/suppression rapide au début (O(1))
- ✅ Insertion/suppression rapide à la fin (O(1))
- ✅ Pas de limite de taille (allocation dynamique)

### Inconvénients
- ❌ Pas d'accès direct par index
- ❌ Parcours unidirectionnel
- ❌ Suppression à la fin nécessite O(n)

## Utilisation type
```cpp
liste<int> ma_liste;
ma_liste.push_front(10);   // Ajouter 10 au début
ma_liste.push_back(20);    // Ajouter 20 à la fin
ma_liste.showList();       // Afficher : 10 <-> 20
```
