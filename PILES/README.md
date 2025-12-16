# PILES (Stacks) - Documentation

## Vue d'ensemble
Ce dossier est destiné à contenir une implémentation de structure de données **PILE** (Stack en anglais).

## Statut actuel
⚠️ **Dossier vide** - Aucun fichier source présent actuellement. Ce dossier attend la mise en œuvre d'une structure de pile.

## Qu'est-ce qu'une PILE ?

Une **pile** est une structure de données qui fonctionne selon le principe du **LIFO** (Last In, First Out) :
- Le **dernier élément ajouté** sera le **premier à être retiré**
- C'est comme une pile d'assiettes où vous retirez l'assiette du haut d'abord

## Principe fondamental

```
Opération : PUSH (empiler) - Ajouter un élément
┌─────┐
│  3  │  <- Sommet (Top) - dernier ajouté
├─────┤
│  2  │
├─────┤
│  1  │  <- Base (Bottom)
└─────┘

Opération : POP (dépiler) - Retirer un élément
On retire le 3 en premier (le dernier ajouté)
```

## Opérations principales attendues

| Opération | Description |
|-----------|-------------|
| `push(T val)` | Ajoute un élément au sommet |
| `pop()` | Retire et retourne le sommet |
| `peek()` | Retourne le sommet sans le retirer |
| `isEmpty()` | Vérifie si la pile est vide |
| `size()` | Retourne le nombre d'éléments |
| `display()` | Affiche tous les éléments |

## Implémentation attendue

Les fichiers à créer devraient probablement inclure :

- **pile.hpp** : Classe template `pile<T>` avec les méthodes principales
- **main.cpp** : Tests et démonstrations de la pile

## Cas d'utilisation des piles

- 📚 **Gestion de l'historique** (Ctrl+Z)
- 🔧 **Syntaxe des parenthèses** (vérification d'équilibre)
- 🌳 **Parcours en profondeur** (DFS)
- 📞 **Appels de fonctions** (call stack)
- 🔙 **Navigation arrière** (browser back button)

## À venir

Cette implémentation complétera la série de structures de données avec :
- ✅ FILES (Queues)
- ✅ LISTES MONOCHAÎNÉES
- ✅ LISTES DOUBLEMENT CHAÎNÉES
- ⏳ PILES (Stacks) - En attente d'implémentation
