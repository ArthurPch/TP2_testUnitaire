#include <stdio.h>
#include <stdlib.h>
#include "testunitaire.h"

Note* creerNote(float frequence, int duree, char touche) {
    Note* note = (Note*)malloc(sizeof(Note));   
    note->frequence = frequence;
    note->duree = duree;
    note->touche = touche;
    return note;
}

void libererNotes(Note **notes, int size) {
    for (int i = 0; i < size; i++) {
        free(notes[i]);
    }
    free(notes);
}

void simulerPiano(Note **notes, int size) {
    system("cls");  
    printf("Piano virtuel \n");
    printf("================================\n");
    printf("Touches : a,z,e,r,t,y,u,i,o,p,m,l\n");
    printf("Pour quitter : q\n");
    while (1) {
        if (_kbhit()) {  
            char touche = _getch();  
            if (touche == 'q') {
                break;
            }
            
            for (int i = 0; i < size; i++) {
                if (touche == notes[i]->touche) {
                    Beep((int)notes[i]->frequence, notes[i]->duree);
                    break;
                }
            }
        }
    }
}