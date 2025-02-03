#ifndef TESTUNITAIRE_H
#define TESTUNITAIRE_H

#include <conio.h>
#include <windows.h>

typedef struct {
    float frequence;
    int duree;
    char touche;
} Note;

Note* creerNote(float frequence, int duree, char touche);
void libererNotes(Note **notes, int size);
void simulerPiano(Note **notes, int size);

#endif




