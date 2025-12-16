# LISTES CHAÎNÉES DOUBLEMENT CHAÎNÉES (Doubly Linked Lists)

## Vue d'ensemble
Ce dossier implémente une **liste chaînée double** (doublement chaînée) en utilisant des **listes chaînées dynamiques** et les **templates C++**. Chaque nœud pointe vers le nœud précédent ET le nœud suivant.

## Principe fondamental
Une liste chaînée doublement chaînée est une structure de données linéaire où :
- Chaque nœud contient une **valeur**, un **pointeur vers le suivant** ET un **pointeur vers le précédent**
- On peut parcourir la liste dans les **deux directions** (avant et arrière)
- Plus de flexibilité qu'une liste monochaînée au prix d'une mémoire supplémentaire

## Fichiers du projet

### `liste.hpp`
Fichier d'en-tête contenant l'implémentation de la classe template `liste<T>`.

#### Structure interne
- **struct node** : Représente chaque élément de la liste
  - `T data` : La valeur stockée dans le nœud
  - `node *prev` : Pointeur vers le nœud précédent
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
| `insert_at(T val, int pos)` | Insère un élément à une position |
| `showList()` | Affiche les éléments (avant vers arrière) |
| `showReversedList()` | Affiche les éléments en sens inverse |

### `main.cpp`
Fichier de test vide préparé pour les démonstrations.

## Points clés de l'implémentation

### Insertion au début (`push_front`)
```
ÉTAPES :
1. Créer un nouveau nœud
2. Si la liste est vide : le nouveau nœud devient head ET end
3. Sinon :
   - Le nouveau pointe vers l'ancienne tête (newNode->next = head)
   - L'ancienne tête pointe en arrière (head->prev = newNode)
   - Mettre à jour head vers le nouveau nœud
```

### Insertion à la fin (`push_back`)
```
ÉTAPES :
1. Créer un nouveau nœud
2. Si la liste est vide : le nouveau nœud devient head ET end
3. Sinon :
   - L'ancien end pointe vers le nouveau (end->next = newNode)
   - Le nouveau pointe en arrière (newNode->prev = end)
   - Mettre à jour end vers le nouveau nœud
```

### Avantages et inconvénients

#### Avantages
- ✅ Insertion/suppression O(1) au début ET à la fin
- ✅ Parcours bidirectionnel
- ✅ Suppression à la fin en O(1)
- ✅ Flexibilité maximale

#### Inconvénients
- ❌ Consomme plus de mémoire (2 pointeurs par nœud au lieu de 1)
- ❌ Plus complexe à gérer (4 pointeurs à mettre à jour lors d'insertion)
- ❌ Pas d'accès direct par index

## Utilisation type
```cpp
liste<int> ma_liste;
ma_liste.push_front(10);   // Ajouter 10 au début
ma_liste.push_back(20);    // Ajouter 20 à la fin
ma_liste.showList();       // Afficher : 10 <-> 20
ma_liste.showReversedList(); // Afficher en sens inverse : 20 <-> 10
```

## Complexité temporelle

| Opération | Complexité |
|-----------|-----------|
| Accès par index | O(n) |
| Recherche | O(n) |
| Insertion au début | O(1) |
| Insertion à la fin | O(1) |
| Suppression au début | O(1) |
| Suppression à la fin | O(1) |
| Insertion au milieu | O(n) |
| Suppression au milieu | O(n) |
