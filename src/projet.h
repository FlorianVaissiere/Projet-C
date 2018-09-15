#ifndef PROJET_H
#define PROJET_H

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

struct noeud
{
	int val;
	struct noeud* suivant; 
};

typedef struct noeud* nd;

struct arbre 
{
	nd* n;
	nd* n_fils_droite;
	nd* n_fils_gauche;
	nd* pere;
};

typedef struct arbre* ab;

nd creer_noeud(int val);

void ajouter_noeud_fin(nd n, int val);

void supprimer_noeud_fin(nd n);

void afficher_tout_noeud(nd n);

void detruire_tout_noeud(nd* n);

ab creer_arbre(int val);

#endif
