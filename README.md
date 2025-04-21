## Diary management project


Command-line diary management project with optimised search and organisation. 


![C](https://img.shields.io/badge/C-11-00599C?logo=c&logoColor=white)
![Data Structures](https://img.shields.io/badge/Data_Structures-Linked_Lists-9cf)
![License](https://img.shields.io/badge/License-MIT-blue.svg)
## Description

This project is a console-mode application for managing a diary simply and efficiently, using linked lists in particular. It makes it easy to add, view and organise contacts and appointments.

## Features

- **Contact and appointment management** :
- Add, view and delete contacts
 - Add, view and delete appointments
 - Intuitive search with automatic completion
- **Optimised searches** for quick access to data
- **Backup and load** data to keep the diary

## Project structure

## 1. Main modules

- **Contact and list management**
 - `cell.h` / `cell.c` : Managing list items
 - `list.h` / `list.c` : Organising and sorting contacts
- **Calendar management**
 - `contact.h` / `contact.c` : Adding and deleting contacts and appointments
 - `timer.h` / `timer.c` : Performance measurement tools

### 2. Source files

- **`main.c`** : Program entry point
- **`contact.c`** : Contact and appointment management
- **`list.c`** : Contact list management
- **`timer.c`** : Performance analysis

## Available commands

| Command | Action |
| -------- | -------------------------------- |
| `1` | Find a contact |
| `2` | Add a contact |
| `3` | Add an appointment |
| `4` | Delete an appointment |
| `5` | Exit the program |
| `6` | Show available commands |

## Performance comparison

The application allows you to evaluate the speed of access to contacts and appointments by comparing different search methods. Tests are carried out on large quantities of data to measure effectiveness.
