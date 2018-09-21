#include"projet.h"

int main(int argc, char* argv[])
{	
	nd n = creer_noeud(1);
	nd n1 = creer_noeud(3);
	nd n2 = creer_noeud(2);
	n->fils_droit = n1;
	n->fils_gauche = n2; 
	afficher_tout_noeud(n);
	detruire_tout_noeud(&n);
	return 0;
}

//All methods to use nodes

/*
*	Function creer_noeud
*	Create node.
*	Parameters:
*	<int val>	:(int)	 Value we need to create new node
*/
nd creer_noeud(int val)
{
	nd res = (nd)malloc(sizeof(struct noeud));
	res->val=val;
	res->fils_droit=NULL;
	res->fils_gauche=NULL;
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
		courant->fils_droit = creer_noeud(val);
	} else {
		courant->fils_gauche = creer_noeud(val);
	}
}

/*
*	Function supprimer_noeud_fin
*	Delete last node.
*	Parameters:
*	<nd n>	:(noeud) Struct of node
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
		printf("Cle = %d\n", courant->val);
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
*/
ab creer_arbre(int val)
{
	ab arb = (ab)malloc(sizeof(struct arbre));

	nd* n = creer_noeud(val);
	nd* racine = n;
	nd* last = n;

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
*	Delete tree.
*	Parameters:
*	<ab arbre>	:(arbre)	Struct of tree
*/
void trouver_prefixe(ab arbre, int val)
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
		if(courant->fils_droit->val < val)
		{	
			if(courant->fils_droit->val == val){
				return prefixe;
			}
			courant = courant->fils_droit;
			prefixe = prefixe + '1';
		}
		else 
		{
			if(courant->fils_gauche->val == val){
				return prefixe;
			}
			courant = courant->fils_gauche;
			prefixe = prefixe + '0';
		}
	}
}