cmake_minimum_required(VERSION 3.24)
project(Projet_Agenda C)

set(CMAKE_C_STANDARD 11)

add_executable(Projet_Agenda main.c
        cell.c
        cell.h
        list.c
        list.h timer.c timer.h contact.c contact.h)
