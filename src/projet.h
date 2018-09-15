#ifndef PROJET_H
#define PROJET_H

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

struct arbre 
{
	noeud n;
	noeud* n_fils_droite;
	noeud* n_fils_gauche;
	noeud* pere;
};

struct noeud
{
	int val;
	struct noeud* suivant; 
};

nd creer_noeud(int val);

void ajouter_noeud_fin(nd n, int val);

void supprimer_noeud_fin(nd n);

void afficher_tout(nd n);

void detruire_tout (nd* n);

#endif
