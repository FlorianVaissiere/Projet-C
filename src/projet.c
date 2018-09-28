#include"projet.h"

int main(int argc, char* argv[])
{	

	FILE* fichierL = NULL;
	FILE* fichierE = NULL;
	// nd n = creer_noeud(1);
	// nd n1 = creer_noeud(3);
	// nd n2 = creer_noeud(2);
	/*n->fils_droit = n1;
	n->fils_gauche = n2; 
	afficher_tout_noeud(n);
	detruire_tout_noeud(&n);*/
	return 0;
}

//All methods to use nodes

/*
*	Function creer_noeud
*	Create node.
*	Parameters:
*	<int val>	:(int)	 Value we need to create new node
*	<char letter>	:(char)		Symbol we need to found
*/
nd creer_noeud(int val, char letter)
{
	nd res = (nd)malloc(sizeof(struct noeud));
	res->val 			= val;
	res->alphabet 		= letter;
	res->fils_droit 	= NULL;
	res->fils_gauche 	= NULL;
	return res;
}

/*
*	Function ajouter_noeud_fin
*	Add a node at the end.
*	Parameters:
*	<nd n>	:(noeud) Struct of node
*	<int val>	:(int)	 Value we need to create new node
*	<char letter>	:(char)		Symbol we need to found
*/
void ajouter_noeud_fin(nd n, int val, char letter)
{
	nd courant = n;

	while(courant->fils_droit != NULL)
	{
		if(val > courant->val)
		{
			courant = courant->fils_droit;
		} else {
			courant = courant->fils_gauche;
		}
	}

	if (courant->fils_droit == NULL)
	{
		courant->fils_droit = creer_noeud(val,letter);
	} else {
		courant->fils_gauche = creer_noeud(val,letter);
	}
}

/*
*	Function supprimer_noeud_fin
*	Delete last node.
*	Parameters:
*	<ab arbre>	:(arbre) Struct of arbre
*/
void supprimer_noeud_fin(ab arbre)
{
	if(arbre!=NULL)
	{
		nd courant = arbre->last;
		free(courant);
		courant = NULL;
	}
}

/*
*	Function afficher_tout
*	Print all nodes
*	Parameters:
*	<nd n>	:(noeud) Struct of node
*/
void afficher_tout_noeud(nd n)
{
	nd courant = n;
	if (courant == NULL)
	{
		printf("Noeud vide \n");
	} else {
		printf("Cle = %d Lettre = %s\n", courant->val, courant->alphabet);
		if(courant->fils_gauche)
		{
			afficher_tout_noeud(courant->fils_gauche);
		}
		
		if(courant->fils_droit)
		{
			afficher_tout_noeud(courant->fils_droit);
		}
	}
}

/*
*	Function detruire_tout
*	Delete all nodes
*	Parameters:
*	<nd* n>	:(noeud*) Pointer on node struct
*/
void detruire_tout_noeud(nd* n)
{
	if((*n) != NULL)
	{
		if((*n)->fils_gauche != NULL)
		{
			detruire_tout_noeud((&((*n)->fils_gauche)));
		}
		if((*n)->fils_droit != NULL)
		{
			detruire_tout_noeud((&((*n)->fils_droit)));
		}

		free (*n);
		(*n) = NULL;
	}
}


//All methods to use trees

/*
*	Function creer_arbre
*	Create tree.
*	Parameters:
*	<int val>	:(int)	 Value we need to create the first node of tree
*	<char letter>	:(char)		Symbol we need to found
*/
ab creer_arbre(int val, char letter)
{
	ab arb 		= (ab)malloc(sizeof(struct arbre));
	nd* n 		= creer_noeud(val,letter);
	nd* racine 	= n;
	nd* last 	= n;

	return arb;
}

/*
*	Function detruire_arbre
*	Delete tree.
*	Parameters:
*	<ab arbre>	:(arbre)	Struct of tree
*/
void detruire_arbre(ab arbre)
{
	if(arbre != NULL)
	{
		nd* node = &arbre->racine;
		detruire_tout_noeud(&arbre->racine);

		free (arbre->n);
		(arbre->n) = NULL;
		free (arbre->racine);
		(arbre->racine) = NULL;
		free (arbre->last);
		(arbre->last) = NULL;
		free (arbre);
		(arbre) = NULL;
	}
}

/*
*	Function trouver_dans_arbre
*	Delete tree.
*	Parameters:
*	<ab arbre>	:(arbre)	Struct of tree
*/
void trouver_dans_arbre(ab arbre, int val)
{
	nd courant = arbre->racine;
	if (arbre == NULL)
	{
		printf("Arbre vide \n");
	}
	else if (courant == NULL)
	{
		printf("Noeud vide \n");
	} else {
		if(courant->fils_droit->val > val)
		{	
			if (courant->fils_gauche->val != val)
			{
				courant = courant->fils_gauche;
			} else {
				return 1;
			}
		}
		else 
		{
			if (courant->fils_droit->val != val)
			{
				courant = courant->fils_droit;
			} else {
				return 1;
			}
		}
	}
}

/*
*	Function trouver_prefixe
*	Return code for letter.
*	Parameters:
*	<ab arbre>		:(arbre)	Struct of tree
*	<char letter>	:(char)		Symbol we need to found
*	<int val>		:(int)		Value
*/
char trouver_prefixe(ab arbre, char letter)
{
	nd courant = arbre->racine;
	char prefixe;
	if (arbre == NULL)
	{
		printf("Arbre vide \n");
	}
	else if (courant == NULL)
	{
		printf("Noeud vide \n");
	} else {
		if(courant->fils_gauche->alphabet == letter)
		{	
			prefixe = prefixe + '0';
			courant = courant->fils_gauche;
			return prefixe;
		}
		else 
		{
			if(courant->fils_droit->alphabet == letter){
				prefixe = prefixe + '1';
				return prefixe;
			}
			courant = courant->fils_droit;
			prefixe = prefixe + '1';
		}
	}
	return prefixe;
}

/*
*	Function creer_code
*	Return code for letter.
*	Parameters:
*	<ab arbre>		:(arbre)	Struct of tree
*	<char letter>	:(char)		Symbol we need to found
*	<int val>		:(int)		Symbol we need to found
*/
int creer_code_lettre(ab arbre, char letter)
{
	int tab_code;
	int tab_code = int(trouver_prefixe(arbre, letter));
	return tab_code;
}

/*
*	Function compresse
*	Return code text.
*	Parameters:
*	<ab arbre>			:(arbre)Struct of tree
*	<FILE* fichierL>	:(FILE)	Pointer on reading file
*	<FILE* fichierE>	:(FILE)	Pointer on writing file
*/
void compresse(ab arbre, FILE* fichierL, FILE* fichierE)
{
	fichierL fopen("lecture.txt", "r");
	fichierE fopen("ecriture.txt", "w");
	int caractere = 0;
	char code;


	if (fichierL != NULL)
	{
		do
		{
			caractere = fgetc(fichierL);
			code = creer_code_lettre(arbre, caractere)
			fprintf(fichierE, "%c\n", code);
		} while (caractereActuel != EOF);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier lecture.txt");
	}

	fclose(fichierL);
	fclose(fichierE);
	return 0;
}

/*
*	Function decompresse
*	Return code text.
*	Parameters:
*	<ab arbre>			:(arbre)Struct of tree
*	<FILE* fichierL>	:(FILE)	Pointer on reading file
*	<FILE* fichierE>	:(FILE)	Pointer on writing file	
*/
void decompresse(ab arbre, FILE* fichierL, FILE* fichierE)
{
	fichierL fopen("ecriture.txt", "r");
	fichierE fopen("lecture.txt", "w");
	int caractere = 0;
	char decode;

	if (fichierL != NULL)
	{
		do
		{
			caractere = fgetc(fichierE);
			decode = decode_lettre(arbre, caractere)
			fprintf(fichierL, "%c\n", decode);
		} while (caractereActuel != EOF);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier ecriture.txt");
	}

	fclose(fichierL);
	fclose(fichierE);
	return 0;
}

/*
*	Function decode_lettre
*	Return decode text.
*	Parameters:
*	
*/

