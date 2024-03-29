#include "turcqListeInt.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

/*
Fonction : init_elt
Description : Initialise un nouvel élément de liste avec une valeur aléatoire entre 0 et 20
@param : void
@return : maillon_int* - pointeur vers le nouvel élément initialisé
*/
maillon_int* init_elt()
{
    maillon_int* p_nv_elt = malloc(sizeof(maillon_int));
    p_nv_elt->val = rand() % 21;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

/*
Fonction : ajout_tete_v1
Description : Ajoute un élément en tête de liste (version 1)
@param : maillon_int* p_tete - pointeur vers la tête de liste
@param : maillon_int* p_nv_elt - pointeur vers le nouvel élément à ajouter
@return : maillon_int* - pointeur vers la nouvelle tête de liste
*/
maillon_int* ajout_tete_v1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = p_tete;
    p_tete = p_nv_elt;
    return p_tete;
}


/*
Fonction : ajout_tete_v2
Description : Ajoute un élément en tête de liste (version 2)
@param : maillon_int** p_p_tete - pointeur vers le pointeur de tête de liste
@param : maillon_int* p_nv_elt - pointeur vers le nouvel élément à ajouter
@return : void
*/
void ajout_tete_v2(maillon_int** p_p_tete, maillon_int* p_nv_elt)
{
    p_nv_elt->p_suiv = *p_p_tete;
    *p_p_tete = p_nv_elt;
}


/*
Fonction : parcourir
Description : Parcourt et affiche les éléments de la liste
@param : maillon_int* p_tete - pointeur vers la tête de liste
@return : void
*/
void parcourir(maillon_int* p_tete)
{
    if (p_tete == NULL)
        printf("liste vide");
    else
        while (p_tete != NULL) {
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
        }
    putchar('\n');
}

/*
Fonction : inserer1
Description : Insère un nouvel élément dans la liste suivant l'ordre croissant des premiers éléments
@param : maillon_int* p_tete - pointeur vers la tête de liste
@param : maillon_int* p_nv_elt - pointeur vers le nouvel élément à insérer
@return : maillon_int* - pointeur vers la tête de liste mise à jour
*/
maillon_int* inserer1(maillon_int* p_tete, maillon_int* p_nv_elt)
{
    maillon_int* n, * prec;
    
    if (p_tete == NULL || p_nv_elt->val <= p_tete->val) {  
        p_nv_elt->p_suiv = p_tete;
        p_tete = p_nv_elt;
    }
    else {  
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
    }
    return p_tete;
}


/*
Fonction : inserer2
Description : Insère un nouvel élément dans la liste suivant l'ordre croissant des premiers éléments
@param : maillon_int** prem - pointeur vers le pointeur de tête de liste
@param : maillon_int* e - pointeur vers le nouvel élément à insérer
@return : void
*/
void inserer2(maillon_int** prem, maillon_int* e)
{
    maillon_int* n, * prec;
    if (*prem == NULL || e->val <= (*prem)->val){ 
        e->p_suiv = *prem;
        *prem = e;
    }
    else {  
        n = prec = *prem;
        while (n != NULL && e->val > n->val) {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n;
        prec->p_suiv = e;
    }
}


/*
Fonction : supprimer_debut
Description : Supprime l'élément de tête de la liste
@param : maillon_int** prem - pointeur vers le pointeur de tête de liste
@return : void
*/
void supprimer_debut(maillon_int** prem)
{
    maillon_int* n;
    if (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}


/*
Fonction : critere_supp_un1
Description : Supprime tous les maillons d'une valeur donnée dans la liste
@param : maillon_int* prem - pointeur vers la tête de liste
@param : int val - valeur à supprimer
@return : maillon_int* - pointeur vers la tête de liste mise à jour
*/
maillon_int* critere_supp_un1(maillon_int* prem, int val)
{
    maillon_int* e = prem, * prec = NULL, * n;

    while (e != NULL) {
        n = NULL;
        if (e->val == val) {
            n = e;
            if (prec == NULL)
                prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
    return prem;
}


/*
Fonction : critere_supp_un2
Description : Supprime tous les maillons d'une valeur donnée dans la liste
@param : maillon_int** prem - pointeur vers le pointeur de tête de liste
@param : int val - valeur à supprimer
@return : void
*/
void critere_supp_un2(maillon_int** prem, int val)
{
    maillon_int* e = *prem, * prec = NULL, * n;

    while (e != NULL) {
        n = NULL;
        if (e->val == val) {
            n = e;
            if (prec == NULL)
                *prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
}

/*
Fonction : detruire_liste
Description : Libère la mémoire occupée par tous les éléments de la liste
@param : maillon_int** prem - pointeur vers le pointeur de tête de liste
@return : void
*/
void detruire_liste(maillon_int** prem)
{
    maillon_int* n;
    while (*prem != NULL) {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}


/*
Fonction : detruire_liste2
Description : Libère la mémoire occupée par tous les éléments de la liste
@param : maillon_int** prem - pointeur vers le pointeur de tête de liste
@return : void
*/
void detruire_liste2(maillon_int** prem)
{
    while (*prem != NULL)
        supprimer_debut(prem);
}


/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture 
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste 
                dont le premier élément est pointé par prem. 
                Nota : il n'y a pas de libération de la mémoire occupée par la 
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int* prem)
{
    FILE* f=fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n",f);
    if (prem != NULL) {
        if (f==NULL)
            fprintf(stderr,"erreur création fichier :%i\n",errno);
        else
            while (prem != NULL) {
                if (1 !=fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr,"Erreur d'écriture du maillon %p\n",prem);
                else 
                    prem = prem->p_suiv;
            }
        fclose(f);  
    }
    else
        fprintf(stderr,"pas de sauvegarde pour une liste vide\n");
}



/*
Fonction : load_liste
Description : Charge une liste depuis le fichier "saveliste.bin"
@return : maillon_int* - pointeur vers la tête de liste chargée
*/
maillon_int* load_liste()
{
    FILE* f;
    maillon_int* prem = NULL, * p, e;
    if ((f= fopen("saveliste.bin", "rb")) != NULL) {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f)) {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
}