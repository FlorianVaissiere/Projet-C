#ifndef PROJET_H
#define PROJET_H

#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<unistd.h>

#define BUFF_SIZE 1024
#define ALPHABET    26

#define SPACES      32

#define BEG_LOWER   97
#define END_LOWER  122

#define BEG_UPPER   65
#define END_UPPER   90

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
	nd* racine;
};

typedef struct arbre* ab;

nd creer_noeud(int val, char letter);

void ajouter_noeud_fin(nd n, int val, char letter);

void afficher_tout_noeud(nd n);

void detruire_tout_noeud(nd* n);

ab creer_arbre(nd node);

ab assembler_arbre(nd* node);

void detruire_arbre(ab arbre);

int trouver_dans_arbre(ab arbre, int val);

char trouver_prefixe(ab arbre, char letter);

int creer_code_lettre(ab arbre, char letter);

void compresse(ab arbre, FILE* fichierL, FILE* fichierE);

void decompresse(ab arbre, FILE* fichierL, FILE* fichierE);

char decode_lettre(ab arbre, char* letter);

nd frequence (FILE* fichierL);

#endif
