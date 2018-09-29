#ifndef PROJET_H
#define PROJET_H

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>

struct noeud
{
	char alphabet;
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

nd creer_noeud(int val, char letter);

void ajouter_noeud_fin(nd n, int val, char letter);

void supprimer_noeud_fin(ab arbre);

void afficher_tout_noeud(nd n);

void detruire_tout_noeud(nd* n);

ab creer_arbre(int val, char letter);

void detruire_arbre(ab arbre);

int trouver_dans_arbre(ab arbre, int val);

char trouver_prefixe(ab arbre, char letter);

int creer_code_lettre(ab arbre, char letter);

void compresse(ab arbre, FILE* fichierL, FILE* fichierE);

void decompresse(ab arbre, FILE* fichierL, FILE* fichierE);

char decode_lettre(ab arbre, char* letter);

#endif
