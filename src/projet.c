#include"projet.h"

int main(int argc, char* argv[])
{	
	FILE* fichierL = NULL;
	FILE* fichierE = NULL;

	char choix = fscanf(stdin, "Voulez vous utiliser un fichier ou l'entré standard? (f/s)");
	if(choix == "s")
	{
		fichierL = fopen("lecture.txt", "w");
		char compresse = fscanf(stdin, "Que désirez-vous compresser?");
		fprintf(fichierL, "%c\n", compresse);
		fclose(fichierL);
	}

	ab arbre = assembler_arbre(frequence(fichierL));
	compresse(arbre, fichierL, fichierE);
	decompresse(arbre, fichierL, fichierE);

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
*	<nd node>	:(noeud)	Value of first node
*/
ab creer_arbre(nd node)
{
	ab arb 		= (ab)malloc(sizeof(struct arbre));
	nd* racine 	= node;
	return arb;
}

/*
*	Function assembler_arbre
*	Merge trees.
*	Parameters:
*	<nd node>	:(noeud)	 Value we need to create the first node of tree
*	<ab arbre>	:(arbre)	 Symbol we need to found
*/
ab assembler_arbre(nd* node)
{
	if(node != NULL)
	{
		while (sizeof(node) != 1)
		{
			for(int i = 0; i < sizeof(node); i++)
			{
				for(int j = 1; j < sizeof(node); j++)
				{
					if(node[i]->val == node[j]->val)
					{
						node[i] = creer_noeud(node[i]->val + node[j]->val, NULL);
						node[i]->fils_droit = node[i];
						node[i]->fils_gauche = node[j];
						free (node[j]);
					}
				}
			}
		}
	}
	ab arbre = creer_arbre(node[1]);
	return arbre;
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
		detruire_tout_noeud(arbre->racine);

		free (arbre->racine);
		(arbre->racine) = NULL;
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
int trouver_dans_arbre(ab arbre, int val)
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


//Huffman

/*
*	Function frequence
*	Return tab frequence letter.
*	Parameters:
*	<FILE* fichierL>	:(FILE)	Pointer on reading file
*/
nd frequence (FILE* fichierL)
{
	nd noeud[53];
    // file opening
    char  buff[BUFF_SIZE] ;
    int   lines ;

    if (!(fichierL = fopen("leture.txt", "r")))
    {
       fprintf (stderr, "%s\n", "Cannot open file") ; 
       exit (EXIT_FAILURE) ;
    }

    // counters
    int spaces = 0;
    int caract_occurences[ALPHABET*2];
    for(int i = 0; i < ALPHABET*2; ++i)
    {
        caract_occurences[i] = 0;
    }

    // reading each line
    while (fgets(buff, BUFF_SIZE, fichierL))
    {
        // reading each char
        for (int i = 0; i < (int)strlen(buff); ++i) 
        {
            // handling spaces
            if(buff[i] == 32)
            {
                ++spaces;
                continue;
            }

            // handling lowercase
            if(buff[i] >= BEG_LOWER && buff[i] <= END_LOWER)
            {
                ++caract_occurences[buff[i] - BEG_LOWER];
            }

            // handling uppercase
            if(buff[i] >= BEG_UPPER && buff[i] <= END_UPPER)
            {
                ++caract_occurences[buff[i] - BEG_UPPER+ALPHABET];
            }
        }
    }
    fclose (fichierL) ;

    // displaying result
    for (int i = 0; i < ALPHABET; ++i)
    {
        printf(
            "%c: %d\t|\t%c: %d\n", 
            BEG_LOWER + i, 
            caract_occurences[i], 
            BEG_UPPER + i, 
            caract_occurences[i+ALPHABET]
        );
    }

    for (int j = 0; j<53; j++)
    {	
    	if(j<26)
    	{
    		noeud [j] = creer_noeud(caract_occurences[j],  BEG_LOWER + j);
    	}
    	if(j>26 && j<52)
    	{
    		noeud [j] = creer_noeud(caract_occurences[j],  BEG_UPPER + j);
    	}
    	if(j == 52)
    	{
    		noeud [j] = creer_noeud(spaces, 32);
    	}
    	
    }
    return noeud;
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
		if(courant->fils_gauche->alphabet == NULL)
		{
			courant = courant->fils_gauche;
			if(courant->fils_gauche->alphabet == letter)
			{	
				prefixe = prefixe + '0';
				courant = courant->fils_gauche;
				return prefixe;
			}
			else 
			{
				if(courant->fils_droit->alphabet == letter)
				{
					prefixe = prefixe + '1';
					return prefixe;
				}
				courant = courant->fils_droit;
				prefixe = prefixe + '1';
			}
		}
		if(courant->fils_droit->alphabet == NULL)
		{
			courant = courant->fils_droit;
			if(courant->fils_gauche->alphabet == letter)
			{	
				prefixe = prefixe + '0';
				courant = courant->fils_gauche;
				return prefixe;
			}
			else 
			{
				if(courant->fils_droit->alphabet == letter)
				{
					prefixe = prefixe + '1';
					return prefixe;
				}
				courant = courant->fils_droit;
				prefixe = prefixe + '1';
			}
		}
	}
}

/*
*	Function creer_code
*	Return code for letter.
*	Parameters:
*	<ab arbre>		:(arbre)	Struct of tree
*	<char letter>	:(char)		Symbol we need to found
*/
int creer_code_lettre(ab arbre, char letter)
{
	int tab_code;
	tab_code = atoi(trouver_prefixe(arbre, letter));
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
	fichierL = fopen("lecture.txt", "r");
	fichierE = fopen("ecriture.txt", "w");
	int caractere = 0;
	int code;


	if (fichierL != NULL)
	{
		do
		{
			caractere = fgetc(fichierL);
			code = creer_code_lettre(arbre, caractere);
			fprintf(fichierE, "%d\n", code);
			fprintf(stdout, "%d\n", code);
		} while (caractere != EOF);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier lecture.txt");
	}

	fclose(fichierL);
	fclose(fichierE);
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
	fichierL = fopen("ecriture.txt", "r");
	fichierE = fopen("lecture.txt", "w");
	char caractere = 0;
	char decode;

	if (fichierL != NULL)
	{
		do
		{
			caractere = fgetc(fichierE);
			decode = decode_lettre(arbre, &caractere);
			fprintf(fichierL, "%c\n", decode);
			fprintf(stdout, "%c\n", decode);
		} while (caractere != EOF);
	}
	else
	{
		printf("Impossible d'ouvrir le fichier ecriture.txt");
	}

	fclose(fichierL);
	fclose(fichierE);
}

/*
*	Function decode_lettre
*	Return decode text.
*	Parameters:
*	<ab arbre>		:(arbre)	Struct of tree
*	<char letter>	:(char)		Symbol we need to found
*/
char decode_lettre(ab arbre, char* letter)
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
		for(int i = 0; i<strlen(letter); i++)
		{
			if(letter[i] == "1")
			{
				courant = courant->fils_droit;	
			} else {
				courant = courant->fils_gauche;
			}
		}
		prefixe = courant->alphabet;
	}
	return prefixe;
}