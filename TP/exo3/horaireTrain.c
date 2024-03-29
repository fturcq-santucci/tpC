#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    Question 1

    Structure pour stocker les informations d'un trajet de train :

    - depart : chaîne de caractères représentant la ville de départ
    - arrivee : chaîne de caractères représentant la ville d'arrivée
    - heure_depart : chaîne de caractères représentant l'heure de départ
    - heure_arrivee : chaîne de caractères représentant l'heure d'arrivée
    - distance : entier représentant la distance entre la ville de départ et la ville d'arrivée
    - suivant : pointeur vers une structure HoraireTrain représentant l'horaire de train suivant

    Cette structure permet de stocker toutes les informations nécessaires à un horaire de train
    et le pointeur suivant permet de créer une liste chaînée pour représenter plusieurs horaires de train
    successifs.
*/

typedef struct HoraireTrain {
    char depart[50];
    char arrivee[50];
    char heure_depart[10];
    char heure_arrivee[10];
    int distance;
    struct HoraireTrain *suivant;
} HoraireTrain;

/*
    Fonction pour créer un nouvel horaire de train

    On crée une fonction qui prend en paramètre les informations d'un trajet de train 
    et qui renvoie un pointeur vers une structure HoraireTrain
*/

HoraireTrain* creer_horaire(char* depart, char* arrivee, char* heure_depart, char* heure_arrivee, int distance) {
    HoraireTrain* nouveau = malloc(sizeof(HoraireTrain));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return NULL;
    }
    strcpy(nouveau->depart, depart);
    strcpy(nouveau->arrivee, arrivee);
    strcpy(nouveau->heure_depart, heure_depart);
    strcpy(nouveau->heure_arrivee, heure_arrivee);
    nouveau->distance = distance;
    nouveau->suivant = NULL;
    return nouveau;
}

/*
    Question 2

    Fonction pour ajouter un horaire à la fin de la liste

    On crée une fonction qui prend en paramètre un pointeur
    vers un pointeur vers une structure HoraireTrain et un pointeur vers une structure HoraireTrain
*/

void ajouter_horaire_fin(HoraireTrain **liste, HoraireTrain* nouvelHoraire) {
    if (*liste == NULL) {
        *liste = nouvelHoraire;
    } else {
        HoraireTrain* temp = *liste;
        while (temp->suivant != NULL) {
            temp = temp->suivant;
        }
        temp->suivant = nouvelHoraire;
    }
}

/*
    Question 3

    Fonction pour afficher tous les trains au départ d'une ville donnée

    On crée une fonction qui prend en paramètre un pointeur vers une structure HoraireTrain 
    et une chaîne de caractères représentant la ville de départ
*/

void afficher_trains_depart(HoraireTrain* liste, char* ville_depart) {
    printf("Trains au départ de %s :\n", ville_depart);
    int found = 0;
    while (liste != NULL) {
        if (strcmp(liste->depart, ville_depart) == 0) {
            printf("Départ : %s, Arrivée : %s, Heure départ : %s, Heure arrivée : %s, Distance : %dkm\n", liste->depart, liste->arrivee, liste->heure_depart, liste->heure_arrivee, liste->distance);
            found = 1;
        }
        liste = liste->suivant;
    }
    if (!found) {
        printf("Aucun train trouvé au départ de %s.\n", ville_depart);
    }
}
/*
    Question 4

    Fonction pour déterminer le trajet sur lequel la vitesse moyenne est la plus élevée

    On crée une fonction qui prend en paramètre un pointeur vers une structure HoraireTrain 
    et qui renvoie un pointeur vers une structure HoraireTrain
*/

HoraireTrain* trajet_vitesse_max(HoraireTrain* liste) {
    HoraireTrain* trajet_max = NULL;
    double vitesse_max = 0.0;
    while (liste != NULL) {
        double temps_trajet = atof(liste->heure_arrivee) - atof(liste->heure_depart); // Supposant que les heures sont au format "hh:mm"
        double vitesse = (double)liste->distance / temps_trajet;
        if (vitesse > vitesse_max) {
            vitesse_max = vitesse;
            trajet_max = liste;
        }
        liste = liste->suivant;
    }
    return trajet_max;
}

/*
    Question 5

    Fonction pour trier la liste des horaires par ordre croissant de l'heure de départ

    On crée une fonction qui prend en paramètre un pointeur vers un pointeur vers une structure HoraireTrain
*/

void trier_horaires_depart(HoraireTrain **liste) {
    if (*liste == NULL || (*liste)->suivant == NULL) {
        return;
    }
    HoraireTrain* current = *liste;
    HoraireTrain* next = NULL;
    HoraireTrain* temp = NULL;
    int changed = 1;
    while (changed) {
        changed = 0;
        current = *liste;
        while (current->suivant != NULL) {
            next = current->suivant;
            if (strcmp(current->heure_depart, next->heure_depart) > 0) {
                if (current == *liste) {
                    *liste = next;
                } else {
                    temp->suivant = next;
                }
                current->suivant = next->suivant;
                next->suivant = current;
                temp = next;
                changed = 1;
            } else {
                temp = current;
                current = current->suivant;
            }
        }
    }
}

/* 
    Question 6

    Fonction pour déterminer le moyen le plus rapide pour aller d'une ville à une autre avec au plus une correspondance

    On crée une fonction qui prend en paramètre un pointeur vers une structure HoraireTrain et deux chaînes de caractères
    représentant les villes de départ et d'arrivée
*/

void moyen_rapide_voyage(HoraireTrain* liste, char* depart, char* arrivee) {
    if (strcmp(depart, arrivee) == 0) {
        printf("Vous êtes déjà à destination.\n");
        return;
    }
    while (liste != NULL) {
        if (strcmp(liste->depart, depart) == 0) {
            HoraireTrain* next = liste;
            while (next != NULL) {
                if (strcmp(next->depart, arrivee) == 0 && atof(next->heure_depart) - atof(liste->heure_arrivee) >= 0.083333333 && atof(next->heure_depart) - atof(liste->heure_arrivee) <= 2.0) {
                    printf("Correspondance disponible de %s à %s via %s.\n", depart, arrivee, liste->arrivee);
                    return;
                }
                next = next->suivant;
            }
        }
        liste = liste->suivant;
    }
    printf("Aucun trajet disponible de %s à %s avec correspondance.\n", depart, arrivee);
}

int main() {
    HoraireTrain *liste = NULL;

    // Création et ajout des horaires de train

    // Question 2 
    
    ajouter_horaire_fin(&liste, creer_horaire("Lille", "Paris", "08:00", "08:59", 237));
    ajouter_horaire_fin(&liste, creer_horaire("Paris", "Lyon", "09:00", "11:30", 450));
    ajouter_horaire_fin(&liste, creer_horaire("Lille", "Marseille", "08:30", "12:30", 800));
    ajouter_horaire_fin(&liste, creer_horaire("Lyon", "Marseille", "12:00", "15:30", 320));

    // Affichage des trains au départ de Lille
    printf("\nQuestion 3\n");
    afficher_trains_depart(liste, "Lille");

    printf("__________________________________________________");

    // Détermination du trajet avec la vitesse moyenne la plus élevée
    printf("\nQuestion 4\n");
    HoraireTrain* trajet_max = trajet_vitesse_max(liste);
    printf("Trajet avec la vitesse moyenne la plus élevée :\n");
    printf("Départ : %s, Arrivée : %s, Heure départ : %s, Heure arrivée : %s, Distance : %dkm\n", trajet_max->depart, trajet_max->arrivee, trajet_max->heure_depart, trajet_max->heure_arrivee, trajet_max->distance);

    printf("__________________________________________________");

    // Tri de la liste des horaires par ordre croissant de l'heure de départ
    printf("\nQuestion 5\n");
    trier_horaires_depart(&liste);
    printf("\nHoraires triés par ordre croissant de l'heure de départ :\n");
    HoraireTrain* current = liste;
    while (current != NULL) {
        printf("Départ : %s, Arrivée : %s, Heure départ : %s, Heure arrivée : %s, Distance : %dkm\n", current->depart, current->arrivee, current->heure_depart, current->heure_arrivee, current->distance);
        current = current->suivant;
    }

    printf("__________________________________________________");


    // Détermination du moyen le plus rapide pour aller de Lille à Paris

    printf("\nQuestion 6\n");
    moyen_rapide_voyage(liste, "Lille", "Paris");

    // Libération de la mémoire allouée
    while (liste != NULL) {
        HoraireTrain* temp = liste;
        liste = liste->suivant;
        free(temp);
    }

    return 0;
}
