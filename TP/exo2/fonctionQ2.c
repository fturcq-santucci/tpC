//Tester si la pile est vide 
// Cette fonction renvoie 1 si la pile est vide et 0 sinon. Elle prend en paramètre un pointeur vers la pile.

int est_vide(Pile *pile) {
    return (pile == NULL);
}


//Empiler un nouvel élément 
// Cette fonction ajoute un nouvel élément au sommet de la pile. Elle prend en paramètre un pointeur vers un pointeur de pile et la valeur à empiler.

void empiler(Pile **pile, int valeur) {
    Pile *nouveau = malloc(sizeof(Pile));
    if (nouveau == NULL) {
        fprintf(stderr, "Erreur : allocation de mémoire échouée\n");
        return;
    }
    nouveau->valeur = valeur;
    nouveau->suivant = *pile;
    *pile = nouveau;
}

//Récupérer la valeur de l'élément de sommet de pile
// Cette fonction renvoie la valeur de l'élément en haut de la pile sans le retirer de la pile. Si la pile est vide, la fonction renvoie INT_MIN (ou toute autre valeur pour indiquer une erreur).

int sommet(Pile *pile) {
    if (est_vide(pile)) {
        fprintf(stderr, "Erreur : la pile est vide\n");
        return INT_MIN; 
    }
    return pile->valeur;
}

//Récupérer la valeur et enlever l'élément de sommet de pile 
// Cette fonction renvoie la valeur de l'élément en haut de la pile et le retire de la pile. Si la pile est vide, la fonction renvoie INT_MIN (ou toute autre valeur pour indiquer une erreur).

int depiler(Pile **pile) {
    if (est_vide(*pile)) {
        fprintf(stderr, "Erreur : la pile est vide\n");
        return INT_MIN; 
    }
    int valeur = (*pile)->valeur;
    Pile *temp = *pile;
    *pile = (*pile)->suivant;
    free(temp);
    return valeur;
}

//Vider la pile
// Cette fonction libère la mémoire allouée pour tous les éléments de la pile. Elle prend en paramètre un pointeur vers un pointeur de pile.
typedef struct Pile {
    int valeur;
    struct Pile *suivant;
} Pile;

