#ifndef PROJET_H
#define PROJET_H

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

struct noeud
{
	int val;
	struct noeud* fils_droit;
	struct noeud* fils_gauche;  
};

typedef struct noeud* nd;

struct arbre 
{
	nd* n;
	nd* racine;
	nd* last;
};

typedef struct arbre* ab;

nd creer_noeud(int val);

void ajouter_noeud_fin(nd n, int val);

void supprimer_noeud_fin(ab arbre);

void afficher_tout_noeud(nd n);

void detruire_tout_noeud(nd* n);

ab creer_arbre(int val);

void detruire_arbre(ab arbre);

void trouver_dans_arbre(ab arbre, int val);

#endif
