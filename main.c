#include <stdio.h>
#include <stdlib.h>
#include "testunitaire.h"



int main() {

const float frequence[] = {
    261.63,  
    277.18,  
    293.66,  
    311.13,  
    329.63,  
    349.23, 
    369.99,  
    392.00,  
    415.30,  
    440.00, 
    466.16,  
    493.88   
};

const char touches[] = {'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'm', 'l'};
    Note **notes = (Note**)malloc(12 * sizeof(Note*));  
    for (int i = 0; i < 12; i++) {
        notes[i] = creerNote(frequence[i], 300, touches[i]);
    }
    
    simulerPiano(notes, 12);
    
    libererNotes(notes, 12);
    return 0;
}

//au clair de la lune : do do do re mi re do mi re re dooo do do do re mi re do mi re re do re re re 