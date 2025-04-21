//
// Created by Yeto.wrld on 11/25/2023.
//

#include "contact.h"
t_d_listAgenda * createAgenda(){
    t_d_listAgenda *Agenda = malloc(sizeof(t_d_listAgenda));
    Agenda->max_levels = 4;
    Agenda->head = malloc(4 * sizeof(Agenda_cell));
    return Agenda;

}
void afficherRendezVous(t_d_listAgenda *agenda, char *nom) {
    // Si l'agenda est vide alors on affiche rien
    if (agenda == NULL) {
        printf("L'agenda est vide.\n");
        return;
    }
    // On parcourt tous les cellules de l'agenda au niveau 0 car au niveau 0 on a tous les rendez-vous
    Agenda_cell *current = agenda->head[0];
    while (current != NULL) {
        if (strcmp(current->contact.nom, nom) == 0 ) { // On compare le nom de la cellule avec le nom qu'on cerche
            printf("Rendez-vous: %d/%d/%d à %d:%d, Durée: %d heures %d minutes, Objet: %s\n", // On affiche le rdv en question
                   current->Rdv.jour, current->Rdv.mois, current->Rdv.annee,
                   current->Rdv.heure, current->Rdv.minute,
                   current->Rdv.dureeHeure, current->Rdv.dureeMinute,
                   current->Rdv.objet);
        }
        current = *(current->next);
    }
}
void createRdv(t_d_listAgenda * agenda){
    return;
}
void supprRdv(t_d_listAgenda * agenda){
    return;
}
void createContact(t_d_listAgenda * agenda){
    return;
}



