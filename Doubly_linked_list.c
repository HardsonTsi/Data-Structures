#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void Object;
typedef struct CelluleDbl *PCelluleDbl;
typedef struct CelluleDbl
{
    Object *valeur;
    PCelluleDbl suivant;
    PCelluleDbl precedent;
} CelluleDbl;

// Success creer liste
void creerListeDbl(PCelluleDbl l, int n)
{
    PCelluleDbl tete = malloc(sizeof(PCelluleDbl)), p;
    int i, donnee;

    printf("Entrez le premier element: ");
    scanf("%d", &donnee);
    tete = l;
    tete->valeur = donnee;
    tete->suivant = NULL;
    tete->precedent = NULL;
    for (i = 2; i <= n; i++)
    {
        p = malloc(sizeof(PCelluleDbl));
        printf("Entrez l'element suivant: ");
        scanf("%d", &donnee);
        p->valeur = donnee;
        // p->valeur =i;
        p->suivant = NULL;
        p->precedent = tete;
        tete->suivant = p;
        tete = p;
    }
    printf("Liste creee...\n");
}

// Success afficher liste
void afficherListeDbl(PCelluleDbl l)
{
    PCelluleDbl tete;
    tete = l;
    if (tete != NULL)
    {
        while (tete != NULL)
        {
            printf("%d", tete->valeur);
            if (tete->suivant != NULL)
            {
                printf("->");
            }
            tete = tete->suivant;
        }
    }
    else
    {
        printf("Liste vide");
    }
    printf("\n");
}

// Success ajouter tete
PCelluleDbl ajouterTeteDbl(PCelluleDbl l, Object *donnee)
{
    PCelluleDbl tete = malloc(sizeof(PCelluleDbl));
    tete->valeur = donnee;
    tete->precedent = NULL;
    tete->suivant = l;
    l->precedent = tete;
    printf("Tete ajoute...\n");
    return tete;
}

// Success ajouter queue
void ajouterQueue(PCelluleDbl l, Object *donnee)
{
    PCelluleDbl queue = malloc(sizeof(PCelluleDbl));
    queue->valeur = donnee;
    queue->suivant = NULL;
    if (l != NULL)
    {
        while (l->suivant != NULL)
        {
            l = l->suivant;
        }
        l->suivant = queue;
        queue->precedent = l;
        printf("Queue ajoutee");
    }
    else
    {
        printf("Liste vide");
    }
    printf("\n");
}

// Success afficher inverse liste
void afficherInverseListeDbl(PCelluleDbl l)
{
    if (l != NULL)
    {
        printf("Affichage inverse de la liste...\n");
        while (l->suivant != NULL)
        {
            l = l->suivant;
        }
        while (l != NULL)
        {
            printf("%d", l->valeur);
            if (l->precedent != NULL)
            {
                printf("->");
            }
            l = l->precedent;
        }
        printf("\n");
    }
    else
    {
        printf("Liste vide\n");
    }
}

// Success longueur liste
int longueurListeDbl(PCelluleDbl l)
{
    int longueur = 0;
    if (l != NULL)
    {
        while (l != NULL)
        {
            longueur++;
            l = l->suivant;
        }
    }
    return longueur;
}

// Success tri a bulle
void triBullDbl(PCelluleDbl l)
{
    if (l != NULL)
    {
        int tmp = 0, i, j;
        printf("Trie en cours...\n");
        PCelluleDbl a, b;

        for (a = l; a->suivant != NULL; a = a->suivant)
        {
            for (b = a->suivant; b != NULL; b = b->suivant)
            {
                if (a->valeur > b->valeur)
                {
                    tmp = b->valeur;
                    b->valeur = a->valeur;
                    a->valeur = tmp;
                }
            }
        }
    }
    else
    {
        printf("Liste vide\n");
    }
}

// Success supprimer tete
PCelluleDbl supprimerTeteListeDbl(PCelluleDbl l)
{
    if (l != NULL)
    {
        printf("Suppression de la tete...\n");
        PCelluleDbl p = l->suivant;
        p->precedent = NULL;
        free(l);
        printf("Tete supprimee\n");
        return p;
    }
    else
    {
        printf("Liste vide\n");
    }
}

// Success supprimer queue
void supprimerQueue(PCelluleDbl l)
{

    if (l != NULL)
    {
        printf("Suppression de la queue...\n");
        while (l->suivant != NULL)
        {
            l = l->suivant;
        }
        l->precedent->suivant = NULL;
        free(l);
        printf("Queue supprimee\n");
    }
    else
    {
        printf("Liste vide\n");
    }
}

// Success palyndrome
int palyndrome(PCelluleDbl l)
{
    int i = 0, nbreParcours = longueurListeDbl(l) / 2;
    int palyndrome = 0;
    PCelluleDbl normal = l, inverse = l;

    if (l != NULL)
    {
        printf("Palyndrome... ?\n");
        while (inverse->suivant != NULL)
        {
            inverse = inverse->suivant;
        }

        // while (normal->suivant != NULL && palyndrome == 0)
        while (i <= nbreParcours && palyndrome == 0)
        {
            if (normal->valeur != inverse->valeur)
            {
                palyndrome = 1;
            }
            normal = normal->suivant;
            inverse = inverse->precedent;
            i++;
        }
        return palyndrome;
    }
    else
    {
        printf("Liste vide");
    }
}

// Success concactener liste
PCelluleDbl concactenerListeDbl(PCelluleDbl l1, PCelluleDbl l2)
{
    PCelluleDbl l = l1;
    if (l1 != NULL)
    {
        printf("Concactenation...\n");
        while (l1->suivant != NULL)
        {
            l1 = l1->suivant;
        }
        l1->suivant = l2;
        l2->precedent = l1;
    }
    else
    {
        l = l2;
    }
    printf("Listes concactenees...\n");
    return l;
}

// Success rechercher element
PCelluleDbl rechercher(PCelluleDbl l, Object *valeurRecherchee)
{
    int trouver = 0;
    if (l != NULL)
    {
        while (l != NULL && trouver == 0)
        {
            if (l->valeur == valeurRecherchee)
            {
                trouver = 1;
                break;
            }
            l = l->suivant;
        }

        if (trouver == 1)
        {
            printf("Element existant\n");
        }
        else
        {
            printf("Element non existant\n");
        }
        return l;
    }
    else
    {
        return NULL;
    }
}

// Success supprimer elememt
PCelluleDbl supprimerApresRecherche(PCelluleDbl head, Object *valeurRecherchee)
{
    PCelluleDbl l = head, p;
    if (head != NULL)
    {
        if (valeurRecherchee == l->valeur)
        {
            p = l->suivant;
            p->precedent = NULL;
            free(l);
            return p;
        }
        else
        {
            p = rechercher(head, valeurRecherchee);
            printf("Suppression de %d de la liste...\n", valeurRecherchee);
            p->precedent->suivant = p->suivant;

            if (p->suivant != NULL)
            {
                p->suivant->precedent = p->precedent;
            }
            free(p);
            printf("Element supprime\n");
            return l;
        }
        // return l;
    }
    else
    {
        printf("Liste vide\n");
    }
}

// Success supprimer les doublons
void supprimerDoublonListeDbl(PCelluleDbl head)
{
    if (head != NULL)
    {
        PCelluleDbl a = head, b = head->suivant;
        triBullDbl(head);

        while (a->suivant != NULL)
        {
            printf("Suppression des %d\n", a->valeur);
            while (a->valeur == b->valeur)
            {
                a->suivant = b->suivant;

                if (b->suivant != NULL)
                {
                    b->suivant->precedent = a;
                }
                // free(b);
                b = b->suivant;
            }
            a = a->suivant;
        }
        printf("Suppression des doublons terminee...\n");
    }
    else
    {
        printf("Liste vide\n");
    }
}

// Success Fusionner deux listes
PCelluleDbl fusionnerListeDbl(PCelluleDbl gauche, PCelluleDbl droit)
{
    PCelluleDbl l = concactenerListeDbl(gauche, droit);
    supprimerDoublonListeDbl(l);
    return l;
}

//Success Inverser une liste
void inverserListe(PCelluleDbl head)
{
    PCelluleDbl p = head, end;
    if (head != NULL)
    {
        printf("Inversion de la liste... \n");
        while (p->suivant != NULL)
        {
            p = p->suivant;
        }
        end = p;

        while (head->suivant != end->precedent)
        {
            int tmp;
            tmp = head->valeur;
            head->valeur = end->valeur;
            end->valeur = tmp;
            head = head->suivant;
            end = end->precedent;
        }
    }
    else
    {
        printf("Liste vide...\n");
    }
}

int main()
{
    PCelluleDbl maListeDbl = malloc(sizeof(PCelluleDbl));
    PCelluleDbl maListeDbl2 = malloc(sizeof(PCelluleDbl));
    printf("============================\nCreation de la premiere liste\n");
    creerListeDbl(maListeDbl, 6);
    // printf("============================\nCreation de la deuxieme liste\n");
    // creerListeDbl(maListeDbl2, 3);
    afficherListeDbl(maListeDbl);
    inverserListe(maListeDbl);
    afficherListeDbl(maListeDbl);
    afficherInverseListeDbl(maListeDbl);
// 
    // afficherInverseListeDbl(maListeDbl);
    // maListeDbl = fusionnerListeDbl(maListeDbl, maListeDbl2);
    // supprimerDoublonListeDbl(maListeDbl);
    // maListeDbl = inverserListe(maListeDbl);
    // afficherListeDbl(maListeDbl);
    // afficherInverseListeDbl(maListeDbl);
    // PCelluleDbl p = rechercher(maListeDbl, 99);
    // maListeDbl = supprimerApresRecherche(maListeDbl, 4);
    // afficherListeDbl(maListeDbl);
    // afficherListeDbl(maListeDbl2);
    // maListeDbl = concactenerListeDbl(maListeDbl, maListeDbl2);
    // afficherListeDbl(maListeDbl);
    // afficherInverseListeDbl(maListeDbl);
    //  afficherReverseListeDbl(maListeDbl);
    // maListeDbl = ajouterTeteDbl(maListeDbl, 0);
    // afficherListeDbl(maListeDbl);
    // ajouterQueue(maListeDbl, 6);
    // afficherListeDbl(maListeDbl);
    // afficherListeDbl(maListeDbl);
    // afficherReverseListeDbl(maListeDbl);
    // rechercher(maListeDbl, 1);
    // int longueur = longueurListeDbl(maListeDbl);
    // printf("Nombre d'elements: %d\n", longueur);
    // ajouterAtPosition(maListeDbl, 2, 150);
    //  triBullDbl(maListeDbl);
    // maListeDbl = supprimerTeteListeDbl(maListeDbl);
    // afficherListeDbl(maListeDbl);
    // supprimerQueue(maListeDbl);
    // afficherListeDbl(maListeDbl);
    /*  int palyn = palyndrome(maListeDbl);
    if (palyn == 0)
    {
        printf("La liste est un palyndrome\n");
    }
    else
    {
        printf("La liste n'est pas un palyndrome\n");
    } */

    /* supprimerCellule(maListeDbl, 3);
    afficherListeDbl(maListeDbl); */

    return 0;
}
