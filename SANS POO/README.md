# SANS POO (Sans Programmation Orientée Objet)

## Vue d'ensemble
Ce dossier implémente des **listes chaînées en C procédural** (sans classes, sans templates). Il contient deux types de listes :
1. **Liste Monochaînée** (listeMono)
2. **Liste Doublement Chaînée** (listeBi)

Cette approche utilise des **structures** (struct) et des **pointeurs** plutôt que des **classes orientées objet**.

## Philosophie
Contrairement aux dossiers LISTES_MONO et LISTES_BI qui utilisent des **classes C++**, cette implémentation utilise :
- Des `typedef struct` pour définir les nœuds et les listes
- Des **fonctions libres** passant les listes en paramètre
- Des **pointeurs de référence** (`listeMono *&li`) pour modifier la liste directement
- Pas de genericité complète (types fixes, notamment `int`)

---

## LISTE MONOCHAÎNÉE (listeMono)

### Fichiers
- `listeMono.hpp` : Déclaration des structures et prototypes
- `listeMono.cpp` : Implémentation des fonctions

### Structure interne

#### Node
```cpp
typedef struct Node {
    int value;           // Valeur stockée
    Node *next;          // Pointeur vers le nœud suivant
}
```

#### listeMono
```cpp
typedef struct listeMono {
    Node *Front;         // Pointeur vers le premier élément
    Node *Rear;          // Pointeur vers le dernier élément
}
```

### Fonctions disponibles

| Fonction | Description |
|----------|-------------|
| `push_front()` | Ajoute un élément au début |
| `push_back()` | Ajoute un élément à la fin |
| `pop_front()` | Retire le premier élément |
| `pop_back()` | Retire le dernier élément |
| `push_At()` | Insère un élément à une position spécifique |
| `pop_At()` | Retire un élément à une position spécifique |
| `showList()` | Affiche tous les éléments |
| `is_Empty()` | Vérifie si la liste est vide |
| `Length()` | Retourne le nombre d'éléments |

### Points clés

1. **Passage par référence** : `listeMono *&li` permet de modifier le pointeur Front/Rear
2. **Gestion manuelle** : Les listes sont créées et manipulées en dehors de la classe
3. **Types fixes** : Uniquement des `int` (pas de généricité)

### Exemple d'utilisation
```cpp
listeMono *liste = new listeMono();  // Créer une liste
push_front(liste, 10);               // Ajouter 10 au début
push_back(liste, 20);                // Ajouter 20 à la fin
showList(liste);                     // Afficher la liste
```

---

## LISTE DOUBLEMENT CHAÎNÉE (listeBi)

### Fichiers
- `listeBi.hpp` : Déclaration des structures et prototypes
- `listeBi.cpp` : Implémentation des fonctions

### Structure interne

#### Node
```cpp
typedef struct Node {
    int value;           // Valeur stockée
    Node *prev;          // Pointeur vers le nœud précédent
    Node *next;          // Pointeur vers le nœud suivant
}
```

#### listeBi
```cpp
typedef struct listeBi {
    Node *Front;         // Pointeur vers le premier élément
    Node *Rear;          // Pointeur vers le dernier élément
}
```

### Fonctions disponibles

| Fonction | Description |
|----------|-------------|
| `push_front()` | Ajoute un élément au début |
| `push_back()` | Ajoute un élément à la fin |
| `pop_front()` | Retire le premier élément |
| `pop_back()` | Retire le dernier élément |
| `push_At()` | Insère un élément à une position spécifique |
| `pop_At()` | Retire un élément à une position spécifique |
| `showList()` | Affiche les éléments (avant vers arrière) |
| `showReversedList()` | Affiche les éléments (arrière vers avant) |
| `is_Empty()` | Vérifie si la liste est vide |
| `Length()` | Retourne le nombre d'éléments |

### Points clés

1. **Doublement chaînée** : Chaque nœud a `prev` et `next`
2. **Parcours bidirectionnel** : Possible d'afficher en sens inverse
3. **Même approche procédurale** : Pas de classes

---

## main.cpp

Fichier de test démontrant l'utilisation de la liste doublement chaînée (listeBi).

### Exemple d'exécution
```
- Création d'une liste vide
- Ajout au début : 10, 20, 30, 40
- Ajout à la fin : 500, 600, 700, 800
- Affichage de la liste
- Insertion de 555 à la position 3
- Affichage de la liste
- Suppression de l'élément à la position 4
- Affichage de la liste
```

---

## Comparaison : POO vs Sans POO

| Aspect | Avec POO | Sans POO |
|--------|----------|----------|
| **Structure** | Classe template | Struct + fonctions |
| **Généricité** | ✅ Complète (T) | ❌ Types fixes |
| **Encapsulation** | ✅ Private/Public | ❌ Tout public |
| **Allocations** | ✅ Automatique (constructeur) | ❌ Manuel |
| **Flexibilité** | ✅ Haute | ⚠️ Moyenne |
| **Complexité** | ⚠️ Plus haute | ✅ Plus simple |
| **Performance** | ✅ Identique | ✅ Identique |

---

## Avantages de l'approche Sans POO

- ✅ Compréhension des **pointeurs et de la mémoire**
- ✅ Apprentissage du C procédural
- ✅ Code simple et direkt
- ✅ Proche du langage machine

## Inconvénients

- ❌ Pas de généricité
- ❌ Pas d'encapsulation
- ❌ Gestion manuelle plus verbteuse
- ❌ Erreurs possibles avec les pointeurs
