//
// Created by lzcst on 26/10/2023.
//

#ifndef PROJET_AGENDA_CELL_H
#define PROJET_AGENDA_CELL_H
typedef struct s_d_cell
{
    int value;
    int level;
    struct s_d_cell **next;
} t_d_cell;
t_d_cell *create_multi_level_cell(int , int );

#endif //PROJET_AGENDA_CELL_H
