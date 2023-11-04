#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a music track
typedef struct Track {
    char title[100];
    char artist[100];
    struct Track* next;
} Track;

// Function to create a new track
Track* createTrack(const char* title, const char* artist) {
    Track* newTrack = (Track*)malloc(sizeof(Track));
    if (newTrack == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    strncpy(newTrack->title, title, sizeof(newTrack->title));
    strncpy(newTrack->artist, artist, sizeof(newTrack->artist));
    newTrack->next = NULL;
    return newTrack;
}

// Function to add a track to the jukebox
void addTrack(Track** jukebox, const char* title, const char* artist) {
    Track* newTrack = createTrack(title, artist);
    newTrack->next = *jukebox;
    *jukebox = newTrack;
}

// Function to play all tracks in the jukebox
void playJukebox(Track* jukebox) {
    while (jukebox != NULL) {
        printf("Playing: %s by %s\n", jukebox->title, jukebox->artist);
        jukebox = jukebox->next;
    }
}

// Function to free memory used by the jukebox
void freeJukebox(Track* jukebox) {
    while (jukebox != NULL) {
        Track* current = jukebox;
        jukebox = jukebox->next;
        free(current);
    }
}

int main() {
    Track* jukebox = NULL;

    // Adding tracks to the jukebox
    addTrack(&jukebox, "Song 1", "Artist 1");
    addTrack(&jukebox, "Song 2", "Artist 2");
    addTrack(&jukebox, "Song 3", "Artist 3");

    // Playing the tracks in the jukebox
    playJukebox(jukebox);

    // Freeing the memory used by the jukebox
    freeJukebox(jukebox);

    return 0;
}
