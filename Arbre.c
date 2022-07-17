#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void Object;
typedef struct Noeud *PNoeud;
typedef struct Noeud
{
    Object *valeur;
    PNoeud filsGauche;
    PNoeud filsDroit;
} Arbre;

typedef struct Cellule *PCellule;
typedef struct Cellule
{
    PNoeud *valeur;
    PCellule suivant;
} Liste;

typedef struct
{
    Liste *tete;
    Liste *que;
} LFile;

int estFileVide(LFile *fl)
{
    if (fl->tete != NULL && fl->que != NULL)
        return 0;
    else
        return 1;
}

void enfiler(LFile *fl, PNoeud noeud)
{
    PCellule nouveau = malloc(sizeof(PCellule));
    nouveau->valeur = noeud;
    nouveau->suivant = NULL;

    if (estFileVide(fl) != 1)
    {
        fl->que->suivant = nouveau;
    }
    else
    {
        fl->tete = nouveau;
    }
    fl->que = nouveau;
}

PNoeud defiler(LFile *fl)
{
    PNoeud noeud = NULL;
    if (estFileVide(fl) != 1)
    {
        noeud = fl->tete->valeur;
        fl->tete = fl->tete->suivant;
    }

    if (fl->tete == NULL)
        fl->que = NULL;
    return noeud;
}

PNoeud creationNoeud(Object *obj, PNoeud filsG, PNoeud filsD)
{
    PNoeud nouveau = malloc(sizeof(PNoeud));
    nouveau->valeur = obj;
    nouveau->filsGauche = filsG;
    nouveau->filsDroit = filsD;
    return nouveau;
}

PNoeud creationFeuille(Object *obj)
{
    return creationNoeud(obj, NULL, NULL);
}

Object *renvoyerNoeud(PNoeud noeud)
{
    return noeud->valeur;
}

// Parcours Postfixé
void parcoursPostFixe(PNoeud noeud)
{
    if (noeud != NULL)
    {
        parcoursPostFixe(noeud->filsGauche);
        parcoursPostFixe(noeud->filsDroit);
        printf("[%d] ", renvoyerNoeud(noeud));
    }
}

// Parcours Préfixé
void parcoursPreFixe(PNoeud noeud)
{
    if (noeud != NULL)
    {
        printf("[%d] ", noeud->valeur);
        parcoursPreFixe(noeud->filsGauche);
        parcoursPreFixe(noeud->filsDroit);
    }
}

// Parcours infixé
void parcoursInfixe(PNoeud noeud)
{
    if (noeud != NULL)
    {
        parcoursInfixe(noeud->filsGauche);
        printf("[%d] ", noeud->valeur);
        parcoursInfixe(noeud->filsDroit);
    }
}

// Parcours en largeur
void parcoursLargeur(PNoeud noeud)
{
    LFile *fl = malloc(sizeof(LFile *));
    fl->tete = NULL;
    fl->que = NULL;
    enfiler(fl, noeud);

    PNoeud extrait;
    while (estFileVide(fl) != 1)
    {
        extrait = defiler(fl);
        printf("[%d] ", extrait->valeur);
        if (extrait->filsGauche != NULL)
        {
            enfiler(fl, extrait->filsGauche);
        }
        if (extrait->filsDroit != NULL)
        {
            enfiler(fl, extrait->filsDroit);
        }
    }
}

// Rechercher un élément
int rechercher(PNoeud noeud, Object *element)
{
    if (noeud != NULL)
    {
        if (renvoyerNoeud(noeud) == element)
        {
            return 1;
        }
        else
        {
            if (renvoyerNoeud(noeud) > element)
            {
                rechercher(noeud->filsGauche, element);
            }
            else
            {
                rechercher(noeud->filsDroit, element);
            }
        }
    }
    else
    {
        return 0;
    }
}

int main()
{

    int element;
    PNoeud arbre = creationNoeud(8, creationNoeud(6, creationFeuille(3), creationFeuille(7)), creationFeuille(9));

    printf("Parcours poste fixe:\t");
    parcoursPostFixe(arbre);
    printf("\n");
    printf("Parcours pre fixe:\t");
    parcoursPreFixe(arbre);
    printf("\n");
    printf("Parcours infixe:\t");
    parcoursInfixe(arbre);
    printf("\n");
    printf("Parcours en largeur:\t");
    parcoursLargeur(arbre);
    printf("\n");
    printf("Element recherche: ");
    scanf("%d", &element);
    if (rechercher(arbre, element) == 1)
    {
        printf("Element retrouve");
    }
    else
    {
        printf("Element non retrouve");
    }

    return 0;
}
