#include"projet.h"

//All methods to use nodes

typedef struct noeud* nd;

/*
*	Function creer_noeud
*	Create node.
*	Parameters:
*	<int val>	:(int)	 Value we need to create new node
*/
nd creer_noeud(int val)
{
	nd res = (nd)malloc(sizeof(noeud));
	res->val=elt;
	res->suivant=NULL;
	return res;
}

/*
*	Function ajouter_noeud_fin
*	Add a node at the end.
*	Parameters:
*	<nd n>	:(noeud) Struct of node
*	<int val>	:(int)	 Value we need to create new node
*/
void ajouter_noeud_fin(nd n, int val)
{
	nd courant = n;
	while(courant->suivant != NULL)
	{
		courant = courant->suivant;
	}
	courant->suivant = creer_noeud(val);
}

/*
*	Function supprimer_noeud_fin
*	Delete last node.
*	Parameters:
*	<nd n>	:(noeud) Struct of node
*/
void supprimer_noeud_fin(nd n)
{
	if(n!=NULL && n->suivant != NULL)
	{
		nd courant = n
		while(courant -> suivant != NULL)
		{	
			supprimer_neud_fin(courant);
			free(courant);
			courant = NULL;
		}
	}
}

/*
*	Function afficher_tout
*	Print all nodes
*	Parameters:
*	<nd n>	:(noeud) Struct of node
*/
void afficher_tout(nd n)
{
	nd courant = n;
	if (courant == NULL)
	{
		printf(“Noeud vide \n”);
	} else {
		while (courant ->suivant != null)
		{
			printf(%d” , courant-> val);
			courant=courant->suivant;
		}
	}
	printf(“\n”);
}

/*
*	Function detruire_tout
*	Delete all nodes
*	Parameters:
*	<nd* n>	:(noeud*) Pointer on node struct
*/
void detruire_tout (nd* n)
{
	if(*n != NULL)
	{
		if(*n->suivant != NULL)
		{
			detruire_tout (&(*n->suivant));
		}
		free (*n);
		*n = NULL;
	}
}


//All methods to use trees

typedef struct arbre* ab;

/*
*	Function creer_arbre
*	Create tree.
*	Parameters:
*	<int val>	:(int)	 Value we need to create the first node of tree
*/
ab creer_arbre(int val)
{
	ab arb = (ab)malloc(sizeof(arbre));

	noeud n = creer_noeud(val);
	noeud* n_fils_droite = NULL;
	noeud* n_fils_gauche = NULL;
	noeud* pere = NULL;

	return arb;
}