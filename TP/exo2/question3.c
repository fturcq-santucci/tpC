#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Maillon pour représenter un élément de la pile
// Chaque maillon contient une valeur entière et un pointeur vers le maillon suivant
typedef struct Maillon {
    int valeur;
    struct Maillon *suivant;
} Maillon;

// Définition de la structure Pile
// La pile contient un pointeur vers le sommet de la pile
typedef struct {
    Maillon *sommet; // Pointeur vers le sommet de la pile
} Pile;

// Fonction pour créer une nouvelle pile vide
// Cette fonction alloue de la mémoire pour une nouvelle pile et initialise le sommet à NULL
Pile *creer_pile() {
    Pile *nouvelle_pile = (Pile *)malloc(sizeof(Pile));
    if (nouvelle_pile != NULL) {
        nouvelle_pile->sommet = NULL;
    }
    return nouvelle_pile;
}

// Fonction pour empiler un élément sur la pile
// Cette fonction prend en paramètre un pointeur vers la pile et la valeur à empiler
void empiler(Pile *pile, int element) {
    Maillon *nouveau_maillon = (Maillon *)malloc(sizeof(Maillon));
    if (nouveau_maillon != NULL) {
        nouveau_maillon->valeur = element;
        nouveau_maillon->suivant = pile->sommet;
        pile->sommet = nouveau_maillon;
    } else {
        printf("Erreur : impossible d'allouer de la mémoire pour empiler l'élément.\n");
    }
}

// Fonction pour vérifier si la pile est vide
// Cette fonction renvoie 1 si la pile est vide et 0 sinon
int est_vide(Pile *pile) {
    return (pile->sommet == NULL);
}

// Fonction pour dépiler un élément de la pile
// Cette fonction renvoie la valeur de l'élément en haut de la pile et le retire de la pile
int depiler(Pile *pile) {
    if (!est_vide(pile)) {
        Maillon *a_retirer = pile->sommet;
        int valeur_retiree = a_retirer->valeur;
        pile->sommet = a_retirer->suivant;
        free(a_retirer);
        return valeur_retiree;
    } else {
        printf("Erreur : la pile est vide, impossible de dépiler.\n");
        return -1; // Valeur d'erreur
    }
}

// Fonction pour libérer la mémoire utilisée par la pile
// Cette fonction dépile tous les éléments de la pile et libère la mémoire
void detruire_pile(Pile *pile) {
    while (!est_vide(pile)) {
        depiler(pile);
    }
    free(pile);
}

// Définition de la fonction renverser_et_afficher_liste
// Cette fonction prend un tableau d'entiers et sa taille en paramètres
void renverser_et_afficher_liste(int *liste, int taille) {
    Pile *pile = creer_pile(); // Créer une nouvelle pile

    // Empiler chaque élément sur la pile
    for (int i = 0; i < taille; i++) {
        empiler(pile, liste[i]);
    }

    // Dépiler les éléments et les afficher (c'est l'affichage de la liste renversée)
    printf("Liste renversée : ");
    while (!est_vide(pile)) {
        printf("%d ", depiler(pile));
    }
    printf("\n");

    // Libérer la mémoire utilisée par la pile
    detruire_pile(pile);
}

// Fonction principale
// le main test la fonction renverser_et_afficher_liste avec un exemple de liste d'entiers
int main() {
    int ma_liste[] = {1, 2, 3, 4, 5}; // Exemple de liste d'entiers
    int taille = sizeof(ma_liste) / sizeof(ma_liste[0]); // Calcul de la taille de la liste

    printf("Liste originale : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", ma_liste[i]);
    }
    printf("\n");

    // Appel de la fonction pour renverser et afficher la liste
    renverser_et_afficher_liste(ma_liste, taille);

   

    return 0;
}
