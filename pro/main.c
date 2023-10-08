#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_LINE_LENGTH 500

typedef struct Carta {
    char nombres[60];
    int tipo;
    int PD, PA, PV;
    struct Carta *next;
}Carta;

void mezclarbaraja(struct Carta baraja[], int numcartas)
{
    srand(time(NULL));
    int i;
    for (i = 0; i < numcartas; i++) {
        int j = rand() % numcartas;
        struct Carta temp = baraja[i];
        baraja[i] = baraja[j];
        baraja[j] = temp;
    }
}

struct player
{
    char nombre[50];
    struct Carta mano[15];
    int nummano;
    struct Carta mazo[45];
};

void asignarcartas(struct player *jugadores, int numjugadores, struct Carta baraja[], int numcartas) {
    int cartaxjugador = 15;
    int i, j;

    for (i = 0; i < numjugadores; i++) {
        jugadores[i].nummano = 0;
        strcpy(jugadores[i].nombre, "Jugador");

        for (j = 0; j < cartaxjugador; j++) {
            jugadores[i].mano[j] = baraja[i * cartaxjugador + j];
            jugadores[i].nummano++;
        }
    }
}

int main()
{
    int numcartas = 60;
    struct Carta baraja[numcartas];

    printf("guard.txt\n");
    FILE *guardians = fopen("guard.txt", "r");
    char line[MAX_LINE_LENGTH]; //MAX_LINE_LENGTH es un valor global que definen ustedes
    while(fgets(line, MAX_LINE_LENGTH, guardians)){

        Carta *card = (Carta*)malloc(sizeof(Carta));

        char *text = strtok(line, ",");
        strcpy(card->nombres, text);

        card->tipo = atoi(strtok(NULL, ",")); //atoi para valores enteros
        card->PV = atoi(strtok(NULL, ",")); //atof para valores decimales
        card->PA = atoi(strtok(NULL, ","));
        card->PD = atoi(strtok(NULL, ","));

        card->next = NULL;

        // Se añade el Struct creado a la lista existente.
        //addStruct(lista, card);
        printf("\n \n%s, %d, %d, %d, %d", card->nombres, card->PA, card->PD, card->PV, card->tipo);
    }

    int numjugadores = 2;
    struct player jugadores[numjugadores];
    asignarcartas(jugadores, numjugadores, baraja, numcartas);

    fclose(guardians);
    mezclarbaraja(baraja, numcartas);

    return 0;
}
