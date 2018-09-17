#include"projet.h"

int main(int argc, char* argv[])
{	
	nd n = creer_noeud(1);
	nd n1 = creer_noeud(3);
	nd n2 = creer_noeud(2);
	n->fils_droit = n1;
	n->fils_gauche = n2; 
	afficher_tout_noeud(n);
	//supprimer_noeud_fin(n);
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
/*void supprimer_noeud_fin(nd n)
{
	if(n!=NULL && n->fils_droit != NULL)
	{
		nd courant = n;
		while(courant->fils_droit != NULL)
		{	
			if(courant->fils_gauche != NULL)
			{
				courant = courant->fils_gauche;
				supprimer_noeud_fin(courant);
			}

			if(courant->fils_droit != NULL)
			{
				courant = courant->fils_droit;
				supprimer_noeud_fin(courant);
			}

			free(courant);
			courant = NULL;
		}
	}
}*/

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
		if(courant->fils_gauche)
		{
			afficher_tout_noeud(courant->fils_gauche);
		}
		
		if(courant->fils_droit)
		{
			afficher_tout_noeud(courant->fils_droit);
		}

		printf("Cle = %d\n", courant->val);
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
	nd* racine = NULL;

	return arb;
}
