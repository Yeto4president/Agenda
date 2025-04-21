//
// Created by Yeto.wrld on 12/3/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef PROJET_AGENDA_CONTACT_H
#define PROJET_AGENDA_CONTACT_H

// Structure pour un contact
typedef struct Contact {
    char* nom;
    char* prenom;
} Contact;


// Structure pour un rendez-vous
typedef struct RendezVous {
    int jour;
    int mois;
    int annee;
    int heure;
    int minute;
    int dureeHeure;
    int dureeMinute;
    char* objet;
} RendezVous;


// Structure pour entréeAgenda
typedef struct EntreeAgenda {
    Contact contact;
    RendezVous Rdv;
    struct EntreeAgenda **next; // Liste simplement chaînée de rendez-vous
} Agenda_cell;


// Structure pour liste à niveau d'un Agenda
typedef struct s_d_listagenda {  // Liste à niveaux qui stock les entrees d'agenda
    int max_levels;             // Nombre maximum à 4 de niveaux dans la liste
    Agenda_cell ** head;      // Tableau de pointeurs vers la tête de chaque niveau agenda
} t_d_listAgenda;

t_d_listAgenda * createAgenda();
void afficherRendezVous(t_d_listAgenda *, char *);
void createContact(t_d_listAgenda *);
void createRdv(t_d_listAgenda *);
void supprRdv(t_d_listAgenda *);


#endif //PROJET_AGENDA_CONTACT_H
