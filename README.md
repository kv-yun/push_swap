# push_swap

Projet en C ayant pour but de découvrir les algorithmes de tris

Objectif: Fournir le moins d'instructions possible pour trier une liste de nombres entier fournis.

Afin de réaliser cette tâche nous disposons de 2 piles (A et B) qui vont nous servir à trier.

Liste des instructions disponibles:

```
pa: insérer un élement de la pile B dans la pile A (l'élément n'est donc plus présent dans la pile A)
pb: pareil que pa mais en inversant les piles
ra, rb: effectuer une rotation sur la pile indiqué
rr: effectuer une rotation sur les 2 piles
rra, rrb: rotation inverse de ra et rb
rrr: rotation inverse de rr
sa, sb: switch les 2 premiers éléments de la pile indiqué
ss: switch les 2 premiers éléments des 2 piles
```

 Liste d'erreurs pris en compte:
```
- 2 arguments identique
- utilisation de nombres plus grand que int max ou int min
- parametre qui n'est pas un nombre
```

# methode utilisé et amelioration possible

Algorithme: 
```
Algorithme de tri utilisé: QuickSort (modifié pour répondre au sujet)

Algorithme possible: `Radix sort`

Avantage par rapport au QuiSort: Nombre d'instruction stable et meilleurs performance

Le Quicksort a été le premier algorithme qui correspondait à mes criteres de performances.
J'ai découvert le Radix sort à travers d'autres étudiants pendant des corrections et j'ai beaucoup aimé son fonctionnement.
```

Autres améliorations:
```
Méthode pour stoquer les piles: char *

Autre méthode possible: Liste chainée

Avantage par rapport aux char * : Meilleurs gestion de l'allocation mémoire, plus simple à manipuler et moins d'appel systeme

Les listes chainées sont vraiments plus adaptés au projet.
Si j'ai choisi les char * c'est surtout pour m'exercer sur les pointers afin d'effectuer divers tests.
Enfin l'utilisation d'int * auraient été plus judicieux afin d'éviter de convertir fréquemment les char * en int.
```

# execution

Compilation: `Make`

Format d'execution: `./push_swap arg1 arg2 arg3 ... argn` ou encore:
```
bash
ARGS="arg1 arg2 arg3 ... argn"; ./push_swap $ARGS
```
`argn` sont des int 

# resultat

```
instruction 1
instruction 2
...
instruction n
```

Exemple:

```
Make
bash
ARGS="10 -5 4 2 -1 1"./push_swap $ARGS
ra
pb
ra
ra
pb
pb
sa
rra
pa
pa
pa
```
