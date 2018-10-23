# Push_swap
Projet réalisé en équipe avec Freddy Pupier (https://github.com/pups-enterprise).

Ce projet demande de trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles.

Usage :

    • ./push_swap "set d'instructions" | ./checker "même set d'instructions"

Principales notions :

    • Algorithmes de tri (tri par insertion dans notre cas),
    • Initiation à l'optimisation :
      ◦ Performance : Calcul du coup suivant (en récursif),
      ◦ Rapidité : Gestion des piles et des types de tris.

Résumé du sujet :

Le projet Push_swap est un projet d’algo simple et efficace : il faut trier. Vous avez
à votre disposition un ensemble d’entiers, deux piles, et un ensemble d’instructions pour
manipuler les piles.

Votre but ? Ecrire deux programmes en C :\
• Un premier nommé checker qui prend des entiers en paramètres et qui lit des instructions\
sur l’entrée standard. Une fois ces instructions lues, checker les exécute
puis affiche OK si les entiers sont triés, ou KO sinon.

• Un second nommé push_swap qui calcule et affiche sur la sortie standard le plus
petit programme dans le langage des instructions de Push_swap qui trie les entiers
passés en paramètre.

Facile ?

Et bien on va voir ça...

Règles du jeu

    • Le jeu est constitué de 2 piles nommées a et b.
    • Au départ :
    
      ◦ a contient un nombre arbitraire d’entiers positifs ou négatifs, sans doublons.
      ◦ b est vide
      
    • Le but du jeu est de trier a dans l’ordre croissant.
    • Pour ce faire, on ne dispose que des opérations suivantes :
    
      ◦ sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
      
      ◦ sb : swap b - intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
      
      ◦ ss : sa et sb en même temps.
      
      ◦ pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
      
      ◦ pb : push b - prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
      
      ◦ ra : rotate a - décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
      
      ◦ rb : rotate b - décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
      
      ◦ rr : ra et rb en même temps.
      
      ◦ rra : reverse rotate a - décale d’une position vers le bas tous les élements de la pile a. Le dernier élément devient le premier.
      
      ◦ rrb : reverse rotate b - décale d’une position vers le bas tous les élements de la pile b. Le dernier élément devient le premier.
      
      ◦ rrr : rra et rrb en même temps
