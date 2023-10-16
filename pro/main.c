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
void seccartas(struct player *jugador, int cartasdisp) {
    int cartaselegidas = 0;

    printf("Seleccione sus cartas (1-%d):\n", cartasdisp);
    while (cartaselegidas < 3) {
        int numeroCarta;
        printf("Carta %d: ", cartaselegidas + 1);
        scanf("%d", &numeroCarta);

        if (numeroCarta >= 1 && numeroCarta <= cartasdisp) {
            jugador->mano[cartaselegidas] = jugador->mazo[numeroCarta - 1];
            cartaselegidas++;
            printf("Carta %d seleccionada.\n", cartaselegidas);
        } else {
            printf("Número de carta inválido. Seleccione una carta del 1 al %d.\n", cartasdisp);
        }
    }

    return cartaselegidas;
}



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
    seccartas(&jugadores[i], cartaxjugador);

    }
}

int main()
{
    int numcartas = 60;
    struct Carta baraja[numcartas];

    //printf("guard.txt\n");
    /*FILE *guardians = fopen("guard.txt", "r");
    char line[MAX_LINE_LENGTH];
    while(fgets(line, MAX_LINE_LENGTH, guardians)){

        Carta *card = (Carta*)malloc(sizeof(Carta));

        char *text = strtok(line, ",");
        strcpy(card->nombres, text);

        card->tipo = atoi(strtok(NULL, ","));
        card->PV = atoi(strtok(NULL, ","));
        card->PA = atoi(strtok(NULL, ","));
        card->PD = atoi(strtok(NULL, ","));

        card->next = NULL;
        printf("\n \n%s, %d, %d, %d, %d", card->nombres, card->PA, card->PD, card->PV, card->tipo);
    }*/

    int numjugadores = 2;
    struct player jugadores[numjugadores];
    asignarcartas(jugadores, numjugadores, baraja, numcartas);

    int opcion;

    /*while (1) {
        printf("Menú:\n");
        printf("1. Crear nueva carta\n");
        printf("2. Comenzar juego\n");
        printf("3. Ver historial de la partida\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Opcion invalida. Intente de nuevo.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1:
                //crearNuevaCarta();
                break;
            case 2:
                //comenzarJuego();
                mezclarbaraja(baraja, numcartas);
                break;
            case 3:
                //verHistorial();
                break;
            case 4:
                printf("Saliendo del juego. ¡Hasta luego!\n");
                exit(0);
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    }*/

    //fclose(guardians);

    return 0;
}
