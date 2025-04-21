//
// Created by lzcst on 26/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
t_d_list *create_multi_level_list(int max_levels) {
    // On aloue dynamiquement de la mémoire
    t_d_list *list = (t_d_list *)malloc(sizeof(t_d_list));
    if (list == NULL) {
        // Gérer les erreurs de mémoire
        return NULL;
    }

    // On initialise les variables de la structure
    list->max_levels = max_levels;
    list->head = malloc(max_levels * sizeof(t_d_cell *));
    if (list->head == NULL) {
        // Gérer les erreurs de mémoire
        free(list);
        return NULL;
    }

    // Initialiser les têtes de chaque niveau
    for (int i = 0; i < max_levels; i++) {
        list->head[i] = create_multi_level_cell(0, i+1); // 0 est la valeur de la cellule de base
    }

    return list;
}

void insertion_en_tete(t_d_list *list, t_d_cell *cell) {
    int levels;

    if (cell->level <= list->max_levels) {
        levels = cell->level;
    } else {
        levels = list->max_levels;
    }
    for (int i = 0; i < levels; i++) {
        cell->next[i] = list->head[i]->next[i];
        list->head[i]->next[i] = cell;
    }
}
void display_cells_at_level(t_d_list list, int level) {
    if (level < 0 || level >= list.max_levels) {
        // niveau invalide
        return;
    }

    printf("Cellules au niveau %d : ", level);

    t_d_cell *courant = list.head[level]->next[level];
    while (courant != NULL) {
        printf("%d ", courant->value);
        courant = courant->next[level];
    }

    printf("\n");
}
void display_all_levels(t_d_list list) {
    for (int level = 0; level < list.max_levels; level++) { // Parcourir tous les niveaux à partir du niveau 0
        printf("[list head_%d @-]", level);

        t_d_cell *courant = list.head[level]->next[level];
        t_d_cell *niv_premier = list.head[0]->next[0]; // On initialise un pointeur qui pointe sur le niveau 0

        // Traitement pour le niveau 0
        if (level == 0) {
            while (courant != NULL) {
                printf("-->[ %d|@-]", courant->value);
                courant = courant->next[level]; // On passe à la cellule suivante du niveau courant
            }
        }
        else { // Traitement pour les niveaux supérieurs
            while (niv_premier != NULL) {
                // Si la valeur de la cellule courante est égale à la valeur de la cellule du niveau 0 alors
                if (courant != NULL && courant->value == niv_premier->value) {
                    printf("-->[ %d|@-]", courant->value);
                    courant = courant->next[level]; // On passe à la cellule suivante du niveau courant
                } else {
                    printf("-----------"); // Espace pour cellule manquante
                }
                niv_premier = niv_premier->next[0]; // On next dans le premier niveau
            }
        }
        printf("-->NULL\n");
    }
}


void insertion_en_ordre(t_d_list *list, int level, int value) {
    // Créez une nouvelle cellule à insérer
    t_d_cell *newCell = create_multi_level_cell(value, list->max_levels);


    // Mettre à jour les niveaux à partir du supérieur
    for (int i = level; i >= 0;i--){
        t_d_cell * current = list->head[i];
        while (current->next[i] != NULL && current->next[i]->value < value ){
            current = current->next[i];
        }
        newCell->next[i] = current->next[i];
        current->next[i] = newCell;
    }

}
int recherche_0(t_d_list list, int value) {
    t_d_cell *current = list.head[0]; // On initialise la variable current qui pointe sur la première cellule du niveau 0
    while (current != NULL && current->value != value) { // On compare la valeur de la cellule courante avec la valeur qu'on cherche
        current = current->next[0]; // On avance d'une cellule toujours sur le niveau 0
    }
    if (current  == NULL){  // Si current == NULL, nous sommes sortis du niveau 0 donc
        return 0; // On retourne 0
    }
    else{  // Sinon
        return 1; // On retourne 1
    }
}
int recherche_du_plus_haut(t_d_list list, int value) {
    int currentLevel = list.max_levels - 1;

    t_d_cell *current = list.head[currentLevel];
    while (currentLevel >= 0) {
        // Avancez au niveau actuel jusqu'à ce que trouvez la bonne position
        while (current != NULL && current->value < value) {
            current = current->next[currentLevel];
        }

        // Si la valeur est trouvée au niveau actuel
        if (current != NULL && current->value == value) {
            return 1; // Retournez la cellule correspondante
        }

        // Si la valeur n'est pas trouvée, descendez d'un niveau
        currentLevel--;
        if (currentLevel >= 0) {
            // Si current == NULL, ça veut dire qu'on a dépassé les cellules du coup, on descend d'un niveau inférieur à la tête
            if (current == NULL) {
                current = list.head[currentLevel];
            }
            // Sinon, on descend d'un niveau mais à la prochaine cellule du niveau supérieur.
            else{
                current = current->next[currentLevel];
            }
        }
    }
    return 0;
}