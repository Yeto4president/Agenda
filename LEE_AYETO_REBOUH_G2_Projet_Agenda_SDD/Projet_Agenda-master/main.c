//
// Created by lzcst on 26/10/2023.
//
#include "list.c"
#include "cell.c"
#include "contact.c"
#include "timer.c"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>


int main() {
    // Partie 2 ( Test complexité)
    // Vous pouvez retrouver différentes démonstrations concernant les différetes parties en-dessous mise sous forme commentaire.
    int niv_actu = 7;
    int niv_final = 16;

    FILE *log_file = fopen("log.txt","w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;
    srand(time(NULL));
    // Boucle pour calculer le temps d'éxution
    while (niv_actu <= niv_final){
        printf("Le niveau courant est %d\n", niv_actu);
        int nbr_cell = pow(2,niv_actu)-1;
        int tab_levels[nbr_cell];
        t_d_list *list_p2 = create_multi_level_list(niv_final);
        // Init les éléments du tab à 0
        for (int i = 0; i < nbr_cell;i++){
            tab_levels[i] = 0;
        }
        // Création de la liste à niveaux
        for (int step = 2; step <= nbr_cell; step *= 2) {
            int temp = step-1;
            while (temp <=nbr_cell-1){
                tab_levels[temp] += 1;
                temp += step;
            }
        }
        // On insère les éléments du tableau dans la liste de niveaux
        for (int i = 0;i < nbr_cell;i++){
            insertion_en_ordre(list_p2,tab_levels[i],i+1);
        }
        // Recherche niveau 0
        startTimer();
        for (int i = 0; i < 10000; i++){ // Une boucle for de allant de 0 à 10 000
            int nbr_aleatoire = (rand() % nbr_cell) + 1; // Nombre aléatoire compris entre 1 et le nombre de cellules
            int temp_niv0 = recherche_0(*list_p2,nbr_aleatoire); // Recherche au niveau 0 du nbr_aléatoire
        }
        stopTimer();
        time_lvl0 = getTimeAsString(); // fonction du module timer
        printf("Le temps de recherche au niveau 0 est %s\n", getTimeAsString());
        // Recherche à partir des niveaux supérieurs
        startTimer();
        for (int i = 0; i < 10000; i++){ // Une boucle for de allant de 0 à 10 000
            int nbr_aleatoire = (rand() % nbr_cell) + 1; // Nombre aléatoire compris entre 1 et le nombre de cellules
            int temp_niv0 = recherche_du_plus_haut(*list_p2,nbr_aleatoire); // Recherche à partir des niveaux supérieurs du nbr_aléatoire
        }
        stopTimer();
        time_all_levels = getTimeAsString();
        fprintf(log_file,format,niv_actu,time_lvl0, time_all_levels);
        printf("Le temps de recherche pour du multi_niveaux est %s\n", getTimeAsString());
        niv_actu += 1;
    }
    fclose(log_file);


    // Partie 2 (Test création de la liste à niveaux 2^n -1)
    /*
    int n = 3;
    int nbr_cell = pow(2,n)-1; // Nombre de cellules
    int tab_levels[nbr_cell]; // On définit un tableau avec le nombre de cellules
    t_d_list *list_p2 = create_multi_level_list(n); // On crée une liste de "n" niveaux
    for (int i = 0; i < nbr_cell;i++){ // Remplissage du tableau avec des 0 pour après
        tab_levels[i] = 0;
    }
    printf("\n");
    // Remplir le tableau en suivant la méthode de M.Flasques
    for (int step = 2; step <= nbr_cell; step *= 2) { // Une boucle for avec un pas de 2
        int temp = step-1; // Initialisation de la variable temp qui correspond à l'indice du tableau
        while (temp <=nbr_cell-1){ // Tant que temp est inférieur ou égale aux nombre de cellules alors
            tab_levels[temp] += 1; // On ajoute +1 à la valeur de l'indice temp du tableau
            temp += step; // Temp est égal à lui-même + le pas
        }
    }
    for (int i = 0;i < nbr_cell;i++){ // Une boucle for qui parcourt le nombre de cellule
        insertion_en_ordre(list_p2,tab_levels[i],i+1); // On transforme ensuite les valeurs du tableau en cellule avec la solution de M.Flasques
    }
    display_all_levels(*list_p2);
    int test_recherche_0 = recherche_0(*list_p2,2); // Test recherche au niveau 0
    printf("Recherche niveau 0 : %d\n", test_recherche_0);
    int test_recherche_haut = recherche_du_plus_haut(*list_p2,8); // Test recherche à partir des niveaux supérieurs
    printf("Recherche niveau_plus_haut : %d", test_recherche_haut);
    */


    // Partie 1 (Test)
    /*
    int max_levels = 5;
    t_d_list *list = create_multi_level_list(max_levels);
    t_d_cell *cell = create_multi_level_cell(1, 5);
    insertion_en_tete(list,cell);
    //display_all_levels(*list);
    // Niveau 0
    insertion_en_ordre(list,0,25);
    insertion_en_ordre(list,0,59);
    // Niveau 1
    insertion_en_ordre(list,1,31);
    //Niveau 2
    insertion_en_ordre(list,2,56);
    insertion_en_ordre(list,2,91);
    //Niveau 3
    insertion_en_ordre(list,3,18);
    //Niveau 4
    insertion_en_ordre(list,4,32);
    insertion_en_ordre(list,4,59);
    // Affichage de tous les niveaux
    display_all_levels(*list);
    // affichage du niveau 1
    display_cells_at_level(*list,1);
    */


    // Partie 3 (test menu)
    /*
    int exit = 0;
    t_d_listAgenda * agenda = createAgenda();
    printf("Que désirez-vous faire ?\n");
    printf("1. Afficher les rendez-vous d'un contact ? Tapez : 1\n");
    printf("2. Créer un contact ? Tapez : 2\n");
    printf("3. Créer un rendez-vous pour un contact ? Tapez : 3\n");
    printf("4. Supprimer un rendez-vous ? Tapez : 4\n");
    printf("5. Quitter le programme ? Tapez : 5\n");
    while (exit == 0){
        printf("Si vous voulez de l'aide, tapez : 6\n");
        int choix;
        scanf("%d", &choix);
        if (choix == 1){
            char nom[50];
            printf("Veuillez taper le nom du contact (nom)\n");
            scanf("%s",&nom);
            afficherRendezVous(agenda, nom);
        }
        else if (choix == 2){
            createContact(agenda);
        }
        else if (choix == 3){
            createRdv(agenda);
        }
        else if (choix == 4){
            supprRdv(agenda);
        }
        else if (choix == 5){
            exit = 1;
            return 0;
        }
        else{
            printf("Que désirez-vous faire ?\n");
            printf("1. Afficher les rendez-vous d'un contact ? Tapez : 1\n");
            printf("2. Créer un contact ? Tapez : 2\n");
            printf("3. Créer un rendez-vous pour un contact ? Tapez : 3\n");
            printf("4. Supprimer un rendez-vous ? Tapez : 4\n");
            printf("5. Quitter le programme ? Tapez : 5\n");
        }
    }
    */

    return 0;
}