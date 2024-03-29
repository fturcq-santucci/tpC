#include "turcqListeInt.h"
#include "turcqListeInt.c"


/*
Fonction : menu
Description : Affiche un menu de choix et retourne le choix de l'utilisateur
@param : void
@return : int - choix de l'utilisateur
*/
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
        "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
        "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
        "4 Supprimer l'élément de tête\n"
        "5 Supprimer tous les maillons d'une valeur donnee\n"
        "6 Detruire liste\n"
        "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
        "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}

/*
Fonction : main
Description : Fonction principale du programme
@return : int - code de sortie
*/
int main()
{
    maillon_int* premier = NULL;
    maillon_int* nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin)
    {
        i = menu();
        switch (i)
        {

        case 1: // Creer une liste de taille aleatoire
            detruire_liste(&premier);
            nb = rand() % 20 + 1;
            for (int j = 0; j < nb; j++)
            {
                nouveau = init_elt();
                premier = ajout_tete_v1(premier, nouveau);
            }
            parcourir(premier);
            break;

        case 2: // Ajouter
            nouveau = init_elt();
            premier = ajout_tete_v1(premier, nouveau);
            parcourir(premier);
            break;

        case 3: // Inserer (ordre croissant)
            nouveau = init_elt();
            premier = inserer1(premier, nouveau);
            parcourir(premier);
            break;

        case 4: // Supprimer debut:
            supprimer_debut(&premier);
            parcourir(premier);
            break;

        case 5: // Supprimer un maillon d'une valeur donnee
            printf("Entrez la valeur à supprimer : ");
            scanf("%d", &nb);
            rewind(stdin);
            premier = critere_supp_un1(premier, nb);
            parcourir(premier);
            break;

        case 6: // Detruire liste
            detruire_liste(&premier);
            printf("Liste détruite.\n");
            break;

        case 7: // Sauver liste
            sauver_liste(premier);
            printf("Liste sauvegardée dans saveliste.bin.\n");
            break;

        case 8: // Charger liste
            detruire_liste(&premier);
            premier = load_liste();
            parcourir(premier);
            break;

        default:
            fin = 1;
            printf("Fin du programme.\n");
            break;
        }
    }

    return 0;
}

