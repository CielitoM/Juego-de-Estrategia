#include"Librerias.h"
int filas;
int columnas;

int main()
{
    char nick[MAX_NICK_LENGTH];
    printf("Ingresa tu nick para comenzar el juego: ");
    scanf("%s", nick);

    // Crear el archivo de configuración si no existe
    char nombreFichero[MAX_NICK_LENGTH + 15];
    FILE* fichero;

    strcpy(nombreFichero, nick);
    strcat(nombreFichero, "_configuracion.txt");

    fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) {
        fichero = fopen(nombreFichero, "w");
        if (fichero == NULL) {
            printf("Error al crear el fichero de configuración.\n");
            return 1;
        }

        int filas = 10;
        int columnas = 10;
        fprintf(fichero, "%d %d", filas, columnas);

        fclose(fichero);
    } else {
        fclose(fichero);
    }

    int opcion;

    // Crear el archivo de resultados si no existe
    char nombreFicheroResultados[MAX_NICK_LENGTH + 15];
    FILE* ficheroResultados;

    sprintf(nombreFicheroResultados, "%s_resultados.txt", nick);

    ficheroResultados = fopen(nombreFicheroResultados, "r");
    if (ficheroResultados == NULL) {
        ficheroResultados = fopen(nombreFicheroResultados, "w");
        if (ficheroResultados == NULL) {
            printf("Error al crear el fichero de resultados.\n");
            return 1;
        }

        fclose(ficheroResultados);
    } else {
        fclose(ficheroResultados);
    }

    do {
        printf("\nMenu para jugar\n");
        printf("1. Visualizar configuracion del tablero\n");
        printf("2. Configurar parametros\n");
        printf("3. Ver estadisticas\n");
        printf("4. Jugar partida\n");
        printf("5. Ayuda\n");
        printf("6. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                mostrarConfiguracion(nick);
                break;
            case 2:
                configurarParametros(nick);
                break;
            case 3:
                verEstadisticas(nick);
                break;
            case 4:
                jugarPartida(nick);
                break;
            case 5:
                mostrarAyuda(nick);
                break;
        }
    } while (opcion != 6);

    return 0;
}
