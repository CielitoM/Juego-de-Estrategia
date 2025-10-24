#include"Librerias.h"
void mostrarConfiguracion(const char* nick)
{
    char nombreFichero[MAX_NICK_LENGTH + 15];
    FILE* fichero;
    int filas, columnas;

    // Construir el nombre del fichero de configuracion
    strcpy(nombreFichero, nick);
    strcat(nombreFichero, "_configuracion.txt");

    // Abrir el fichero en modo lectura
    fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) {
        printf("Error al abrir el fichero de configuracion\n");
        return;
    }

    // Leer el tamano del tablero
    fscanf(fichero, "%d %d", &filas, &columnas);

    // Cerrar el fichero
    fclose(fichero);

    // Mostrar la configuracion
    printf("Configuracion del tablero:\n");
    printf("Filas: %d\n", filas);
    printf("Columnas: %d\n", columnas);
}

void configurarParametros(const char* nick)
{
    char nombreFichero[MAX_NICK_LENGTH + 15];
    FILE* fichero;
    int filas, columnas;

    // Construir el nombre del fichero de configuracion
    strcpy(nombreFichero, nick);
    strcat(nombreFichero, "_configuracion.txt");

    // Abrir el fichero en modo lectura
    fichero = fopen(nombreFichero, "r");
    if (fichero == NULL) {
        printf("Error al abrir el fichero de configuracion.\n");
        return;
    }

    // Leer el tamano actual del tablero
    fscanf(fichero, "%d %d", &filas, &columnas);

    // Cerrar el fichero
    fclose(fichero);

    // Mostrar la configuracion actual
    printf("Configuracion actual del tablero:\n");
    printf("Filas: %d\n", filas);
    printf("Columnas: %d\n", columnas);

    // Solicitar al usuario el nuevo tamano del tablero
    printf("Ingresa la nueva escala del tablero (filas columnas): ");
    int nuevasFilas, nuevasColumnas;
    scanf("%d %d", &nuevasFilas, &nuevasColumnas);

    // Validar el nuevo tamano del tablero
    if (nuevasFilas <= 0 || nuevasColumnas <= 0 || nuevasFilas > 10 || nuevasColumnas > 10) {
        printf("Error: La escala del tablero debe ser mayor que 0 y no puede superar 10 filas y 10 columnas.\n");
        return;
    }

    // Abrir el fichero en modo escritura para actualizar la configuracion
    fichero = fopen(nombreFichero, "w");
    if (fichero == NULL) {
        printf("Error al abrir el fichero de configuracion.\n");
        return;
    }

    // Escribir el nuevo tamano del tablero en el fichero
    fprintf(fichero, "%d %d", nuevasFilas, nuevasColumnas);

    // Cerrar el fichero
    fclose(fichero);

    printf("Se ha actualizado la configuracion del tablero.\n");
    printf("Nuevo tamano del tablero:\n");
    printf("Filas: %d\n", nuevasFilas);
    printf("Columnas: %d\n", nuevasColumnas);
}

void verEstadisticas(const char* nick)
{
    // Construir el nombre del fichero de resultados
    char nombreResultados[MAX_NICK_LENGTH + 14];
    sprintf(nombreResultados, "%s_resultados.txt", nick);

    FILE* ficheroResultados = fopen(nombreResultados, "r");
    if (ficheroResultados == NULL) {
        printf("Error al abrir el fichero de resultados.\n");
        return;
    }

    ResultadosJugador resultados;
    fscanf(ficheroResultados, "Total de partidas jugadas: %d\n", &resultados.totalPartidas);
    fscanf(ficheroResultados, "Partidas ganadas: %d\n", &resultados.partidasGanadas);
    fscanf(ficheroResultados, "Partidas perdidas: %d\n", &resultados.partidasPerdidas);
    fscanf(ficheroResultados, "Partidas empatadas: %d\n", &resultados.partidasEmpatadas);
    fclose(ficheroResultados);

    // Calcular el porcentaje de partidas ganadas, perdidas y empatadas
    float porcentajeGanadas = (float)resultados.partidasGanadas / resultados.totalPartidas * 100;
    float porcentajePerdidas = (float)resultados.partidasPerdidas / resultados.totalPartidas * 100;
    float porcentajeEmpatadas = (float)resultados.partidasEmpatadas / resultados.totalPartidas * 100;

    // Mostrar las estadísticas
    printf("Estadisticas para el jugador: %s\n", nick);
    printf("Total de partidas jugadas: %d\n", resultados.totalPartidas);
    printf("Partidas ganadas: %d (%.2f%%)\n", resultados.partidasGanadas, porcentajeGanadas);
    printf("Partidas perdidas: %d (%.2f%%)\n", resultados.partidasPerdidas, porcentajePerdidas);
    printf("Partidas empatadas: %d (%.2f%%)\n", resultados.partidasEmpatadas, porcentajeEmpatadas);

    // Mostrar los puntajes de los 5 mejores jugadores


        // Leer los nombres de todos los jugadores desde el archivo "jugadores"
    FILE* ficheroJugadores = fopen("jugadores.txt", "r");
    if (ficheroJugadores == NULL) {
        printf("Error al abrir el fichero de jugadores.\n");
        return;
    }

    Jugador jugadores[20];
    int numJugadores = 0;
    char nombreJugador[MAX_NICK_LENGTH];

    while (fgets(nombreJugador, MAX_NICK_LENGTH, ficheroJugadores) != NULL) {
        // Eliminar el salto de línea del nombre del jugador
        nombreJugador[strcspn(nombreJugador, "\n")] = '\0';

        // Construir el nombre del archivo de resultados para el jugador actual
        char nombreResultadosJugador[MAX_RESULTADOS_FILENAME];
        sprintf(nombreResultadosJugador, "%s_resultados.txt", nombreJugador);

        FILE* ficheroResultadosJugador = fopen(nombreResultadosJugador, "r");
        if (ficheroResultadosJugador == NULL) {
            printf("Error al abrir el fichero de resultados para el jugador %s.\n", nombreJugador);
            continue;
        }

        // Leer los resultados del archivo para el jugador actual
        ResultadosJugador resultadosJugador;
        resultadosJugador.totalPartidas = 0;
        resultadosJugador.partidasGanadas = 0;
        resultadosJugador.partidasPerdidas = 0;
        resultadosJugador.partidasEmpatadas = 0;

        fscanf(ficheroResultadosJugador, "Total de partidas jugadas: %d\n", &resultadosJugador.totalPartidas);
        fscanf(ficheroResultadosJugador, "Partidas ganadas: %d\n", &resultadosJugador.partidasGanadas);
        fscanf(ficheroResultadosJugador, "Partidas perdidas: %d\n", &resultadosJugador.partidasPerdidas);
        fscanf(ficheroResultadosJugador, "Partidas empatadas: %d\n", &resultadosJugador.partidasEmpatadas);
        fclose(ficheroResultadosJugador);

        // Calcular el puntaje del jugador actual
        float puntaje = (float)(resultadosJugador.partidasGanadas - resultadosJugador.partidasPerdidas) / resultadosJugador.totalPartidas;

        // Almacenar el nombre del jugador y su puntaje en la estructura de jugadores
        strcpy(jugadores[numJugadores].nombre, nombreJugador);
        jugadores[numJugadores].puntaje = puntaje;
        numJugadores++;

        if (numJugadores >= 20) {
            break;  // Se alcanzo el máximo de jugadores a procesar
        }
    }

    fclose(ficheroJugadores);

    // Ordenar el arreglo de jugadores según sus puntajes de forma descendente
    for (int i = 0; i < numJugadores - 1; i++) {
        for (int j = 0; j < numJugadores - i - 1; j++) {
            if (jugadores[j].puntaje < jugadores[j + 1].puntaje) {
                Jugador temp = jugadores[j];
                jugadores[j] = jugadores[j + 1];
                jugadores[j + 1] = temp;
            }
        }
    }

    // Mostrar los puntajes de los 5 mejores jugadores
    printf("Puntaje de los 5 mejores jugadores:\n");
    for (int i = 0; i < numJugadores && i < 5; i++) {
        printf("%s - %.2f\n", jugadores[i].nombre, jugadores[i].puntaje);
    }

}

bool verificarJugadorExistente(const char* nombre)
{
    FILE* ficheroJugadores = fopen("jugadores.txt", "r");
    if (ficheroJugadores == NULL) {
        printf("Error al abrir el fichero de jugadores.\n");
        return false;
    }

    char linea[100];
    while (fgets(linea, sizeof(linea), ficheroJugadores) != NULL) {
        // Eliminar el carácter de nueva línea al final de la línea
        linea[strcspn(linea, "\n")] = '\0';

        if (strcmp(linea, nombre) == 0) {
            // El nombre ya existe en el archivo
            fclose(ficheroJugadores);
            return true;
        }
    }

    fclose(ficheroJugadores);
    return false;
}


void guardarJugador(const char* nombre)
{
    if (verificarJugadorExistente(nombre)) {
        //printf("El jugador ya existe en el archivo.\n");
        return;
    }

    FILE* ficheroJugadores = fopen("jugadores.txt", "a");
    if (ficheroJugadores == NULL) {
        printf("Error al abrir el fichero de jugadores.\n");
        return;
    }

    fprintf(ficheroJugadores, "%s\n", nombre);

    fclose(ficheroJugadores);
}
// Funcion para obtener la longitud de la lista enlazada
int longitudLista(ListaCoordenadas* lista) {
    int longitud = 0;
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        longitud++;
        actual = actual->siguiente;
    }
    return longitud;
}

// Funcion para eliminar un nodo de la lista enlazada
void eliminarNodo(ListaCoordenadas* lista, Nodo* nodoEliminar) {
    if (lista->cabeza == nodoEliminar) {
        lista->cabeza = nodoEliminar->siguiente;
    } else {
        Nodo* actual = lista->cabeza;
        while (actual != NULL && actual->siguiente != nodoEliminar) {
            actual = actual->siguiente;
        }
        if (actual != NULL) {
            actual->siguiente = nodoEliminar->siguiente;
        }
    }
    free(nodoEliminar);
}

void igualarListas(ListaCoordenadas* listaDestino, ListaCoordenadas* listaOrigen)
{

    // Recorremos la lista de origen y copiamos los elementos a la lista de destino
    Nodo* actual = listaOrigen->cabeza;
    while (actual != NULL) {
        agregarCoordenada(listaDestino, actual->coordenada.fila, actual->coordenada.columna);
        actual = actual->siguiente;
    }
}

// Funcion para seleccionar un elemento aleatorio de la lista enlazada y obtener fila y columna
void seleccionarAleatorio(ListaCoordenadas* lista, int* fila, int* columna) {
    int longitud = longitudLista(lista);
    if (longitud > 0) {
        // Generar un índice aleatorio entre 0 y longitud-1
        int indice = rand() % longitud;

        // Recorrer la lista hasta llegar al nodo correspondiente al índice aleatorio
        Nodo* actual = lista->cabeza;
        for (int i = 0; i < indice; i++) {
            actual = actual->siguiente;
        }

        // Asignar las coordenadas del nodo seleccionado a fila y columna
        *fila = actual->coordenada.fila;
        *columna = actual->coordenada.columna;

        // Eliminar el nodo seleccionado de la lista
        eliminarNodo(lista, actual);
    } else {
        // Si la lista esta vacía, asignar valores por defecto a fila y columna
        *fila = -1;
        *columna = -1;
    }
}


int verificarTablero(ListaCoordenadas* lista, int** tablero, int filas, int columnas) {
  // Iterar sobre cada coordenada del tablero
  for (int fila = 0; fila < filas; fila++) {
    for (int columna = 0; columna < columnas; columna++) {
      // Verificar si el valor de la coordenada es igual a 0
      if (tablero[fila][columna] == 0) {
        // Verificar si la coordenada no esta en la lista
        if (!coordenadaExistente(lista, fila, columna)) {
          // Existe al menos una coordenada igual a 0 que no esta en la lista
          return 0;
        }
      }
    }
  }

  // No se encontro ninguna coordenada igual a 0 que no este en la lista
  return 1;
}

int coordenadaExistente(ListaCoordenadas *lista, int x, int y) {
  Nodo *actual = lista->cabeza;

  while (actual != NULL) {
    if (actual->coordenada.fila == x && actual->coordenada.columna == y) {
      // La coordenada ya existe en la lista
      return 1;
    }
    actual = actual->siguiente;
  }

  // La coordenada no existe en la lista
  return 0;
}

bool verificarGanador(ListaCoordenadas* listaVerificar, int filas, int columnas, ListaCoordenadas* listaEvitar)
{
   // printf("\nFILAS Y COLUMNAS: %d, %d\n", filas, columnas);
    Nodo* actual = listaVerificar->cabeza;

    //printf("Lista: PARA VERIFICAR EL GANADOR");
    while (actual != NULL) {
        //printf("(%d, %d) ", actual->coordenada.fila, actual->coordenada.columna);
        actual = actual->siguiente;
    }
    //printf("\n");

    int isCoordenadaPresente(ListaCoordenadas* lista, int x, int y) {
        Nodo* actual = lista->cabeza;
        while (actual != NULL) {
            if (actual->coordenada.fila == x && actual->coordenada.columna == y) {
                return 1;
            }
            actual = actual->siguiente;
        }
        return 0;
    }

    int tieneCuadrado(Nodo* cabeza) {
        Nodo* actual = cabeza;

        while (actual != NULL) {
            int x1 = actual->coordenada.fila;
            int y1 = actual->coordenada.columna;

            Nodo* siguienteNodo = actual->siguiente;
            while (siguienteNodo != NULL) {
                int x2 = siguienteNodo->coordenada.fila;
                int y2 = siguienteNodo->coordenada.columna;

                //printf("\nSE HA INGRESADO EN VERIFICAR CUADRADO CORRECTAMENTE");

                int x3 = x2 - (y2 - y1);
                int y3 = y2 + (x2 - x1);
                int x4 = x1 - (y2 - y1);
                int y4 = y1 + (x2 - x1);


                //printf("\n*********************************");
                //printf("\nx1 es igual a: %d", x1);
                //printf("\ny1 es igual a: %d", y1);
              // printf("\n*********************************");
               //printf("\nx2 es igual a: %d", x2);
               //printf("\ny2 es igual a: %d", y2);
              // printf("\n*********************************");
              // printf("\nx3 es igual a: %d", x3);
               //printf("\ny3 es igual a: %d", y3);
               //printf("\n*********************************");
              // printf("\nx4 es igual a: %d", x4);
              // printf("\ny4 es igual a: %d", y4);
              // printf("\n*********************************");


                // Verificar si las coordenadas cumplen con las condiciones para agregarlas a la lista de coordenadas que la computadora debe evitar
                 if (x3 >= 0 && x3 < filas &&
                    y3 >= 0 && y3 < columnas) {
                  if (x4 >= 0 && x4 < filas &&
                      y4 >= 0 && y4 < columnas) {
                    if (!coordenadaExistente(listaEvitar, x3, y3)) {
                      agregarCoordenada(listaEvitar, x3, y3);
                    }
                    if (!coordenadaExistente(listaEvitar, x4, y4)) {
                      agregarCoordenada(listaEvitar, x4, y4);
                    }
                    //printf("\nLas coordenadas que la computadora debe evitar son:\n");
                    mostrarCoordenadas(listaEvitar);
                  }
                }


                if (isCoordenadaPresente(listaVerificar, x3, y3) && isCoordenadaPresente(listaVerificar, x4, y4)) {
                    if ((x1 != x2 || y1 != y2) && (x1 != x3 || y1 != y3) && (x1 != x4 || y1 != y4)) {
                        printf("SE HA ENCONTRADO UN CUADRADO: (%d,%d) (%d,%d) (%d,%d) (%d,%d)\n", x1, y1, x2, y2, x3, y3, x4, y4);
                        return 1;
                    }
                }

                siguienteNodo = siguienteNodo->siguiente;
            }

            actual = actual->siguiente;
        }

        return 0;
    }

    if (tieneCuadrado(listaVerificar->cabeza)) {
       return true;
    } else {
       return false;
    }
}



// Funcion para jugar una partida
void jugarPartida(const char* nick)
{
    bool bandera = false;
    bool bandera_ganado = false;
    bool bandera_perdido = false;
    bool bandera_empatado = false;
    bool bandera_partida = false;

    guardarJugador(nick);

    ListaCoordenadas listaCoordenadasUsuario;
    listaCoordenadasUsuario.cabeza = NULL;

    ListaCoordenadas listaCoordenadasComputadora;
    listaCoordenadasComputadora.cabeza = NULL;

    ListaCoordenadas listaCoordenadasEvitar1; //para que el jugador pierda
    listaCoordenadasEvitar1.cabeza = NULL;

    ListaCoordenadas listaCoordenadasEvitar2; //para que la computadora no pierda
    listaCoordenadasEvitar2.cabeza = NULL;

    ListaCoordenadas listaCoordenadasEvitar3; //cuando la computadora se queda sin poder evitar movimientos
    listaCoordenadasEvitar3.cabeza = NULL;

    ResultadosJugador resultados;

    // Construir los nombres de los ficheros
    char nombreConfiguracion[MAX_NICK_LENGTH + 15];
    char nombreResultados[MAX_NICK_LENGTH + 14];
    char nombreUltimaPartida[MAX_NICK_LENGTH + 16];
    sprintf(nombreConfiguracion, "%s_configuracion.txt", nick);
    sprintf(nombreResultados, "%s_resultados.txt", nick);
    sprintf(nombreUltimaPartida, "%s_ultimapartida.dat", nick);

    FILE* ficheroConfiguracion = fopen(nombreConfiguracion, "r");
    FILE* ficheroResultados = fopen(nombreResultados, "r");
    FILE* ficheroUltimaPartida = fopen(nombreUltimaPartida, "wb");

    if (ficheroConfiguracion == NULL || ficheroResultados == NULL || ficheroUltimaPartida == NULL) {
        printf("Error al abrir los ficheros.\n");
        return;
    }

    int filas, columnas;
    fscanf(ficheroConfiguracion, "%d %d", &filas, &columnas);
    fclose(ficheroConfiguracion);

    // Crear el tablero
    int** tablero = crearTablero(filas, columnas);

    // Inicializar tablero con ceros
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            tablero[i][j] = 0;
        }
    }

    int jugadorActual = JUGADOR;
    bool partidaTerminada = false;

    while (!partidaTerminada) {
        // Mostrar el tablero actual y las coordenadas del jugador
        printf("\nTablero actual:\n");
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                printf("%d ", tablero[i][j]);
            }
            printf("\n");
        }

        // Mostrar las coordenadas del jugador
       // printf("Coordenadas del jugador:\n");
       // mostrarCoordenadas(&listaCoordenadasUsuario);

        // Mostrar las coordenadas de la computadora
        //printf("Coordenadas de la computadora:\n");
        //mostrarCoordenadas(&listaCoordenadasComputadora);


        int fila, columna;
        if (jugadorActual == JUGADOR) {
            // Turno del jugador
            printf("Es tu turno. Ingresa la fila y columna donde quieres depositar tu ficha: ");
            scanf("%d %d", &fila, &columna);
        } else {
            // Turno de la computadora (algoritmo aleatorio)
            printf("Turno de la computadora.\n");
            // Generar una posicion aleatoria hasta encontrar una casilla vacía
            do {
                fila = rand() % filas;
                columna = rand() % columnas;

                // Verificar si la coordenada generada esta en la lista de coordenadas a evitar
                if (coordenadaExistente(&listaCoordenadasEvitar1, fila, columna) != 0 || coordenadaExistente(&listaCoordenadasEvitar2, fila, columna) != 0) {
                    // La coordenada generada esta en la lista, buscar otra posicion
                //printf("LA CORDENADA GENERADA ESTA EN LA LISTA, HAY QUE BUSCAR OTRA POSICION");
                    //Verificar que exista al menos una posicion que sea igual a 0 y que no este en la lista.
                if(verificarTablero(&listaCoordenadasEvitar1,tablero,filas,columnas) == 0 || verificarTablero(&listaCoordenadasEvitar2, tablero,filas,columnas) == 0){

                }else{
                    //Si ya no quedan posiciones en el tablero que se puedan evitar, entonces la computadora va a tomar las posiciones en donde no pierda
                    //es decir, evitara aquellas donde la computadora forme un cuadrado, y se posicionara en donde el jugador forma un cuadrado.
                    if (bandera == false){
                        //igualar la tercera lista a la primera para poder trabajar con ella en particular
                        igualarListas(&listaCoordenadasEvitar3, &listaCoordenadasEvitar1);
                        bandera = true;
                    }
                    seleccionarAleatorio(&listaCoordenadasEvitar3, &fila,&columna);
                    //salir del bucle
                    //printf("\nSe ha llegado al punto limite, la computadora empieza a seleccionar posiciones donde el jugador forma un cuadrado......");
                    //printf("\nLa computadora ha seleccionado la posicion %d %d......", fila, columna);
                    break;
                    }

                }

                // La coordenada generada no esta en la lista, salir del bucle
                break;
            } while (1);
        }

        // Validar la posicion ingresada
        if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas || tablero[fila][columna] != 0) {
            printf("Posicion invalida. Intenta de nuevo.\n");
            continue;
        }

    tablero[fila][columna] = jugadorActual;
           if (jugadorActual == JUGADOR) {
            agregarCoordenada(&listaCoordenadasUsuario, fila, columna);
            if(verificarGanador(&listaCoordenadasUsuario, filas, columnas, &listaCoordenadasEvitar1)){
                printf("\nHAS FORMADO UN CUADRADO. HAS PERDIDO LA PARTIDA");
                partidaTerminada = true;
                bandera_perdido = true;
            }
        } else {
            agregarCoordenada(&listaCoordenadasComputadora, fila, columna);
            if(verificarGanador(&listaCoordenadasComputadora, filas, columnas, &listaCoordenadasEvitar2)){
                printf("\nHAS GANADO. LA COMPUTADORA HA FORMADO UN CUADRADO");
                partidaTerminada = true;
                bandera_ganado = true;
            }
        }

        // Verificar si el tablero esta lleno
        if (tableroLleno(tablero, filas, columnas) == 1 && partidaTerminada == false) {
            partidaTerminada = true;
            bandera_empatado = true;
            bandera_partida = true;
            printf("\nHA RESULTADO UN EMPATE");
        }


        // Cambiar el jugador actual
        jugadorActual = (jugadorActual == JUGADOR) ? COMPUTADORA : JUGADOR;

    }

    // Mostrar el tablero final
    printf("\nTablero final:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
// Actualizar el fichero de resultados
if (ficheroResultados == NULL) {
    // Establecer valores iniciales si el archivo está vacío
    resultados.totalPartidas = 0;
    resultados.partidasGanadas = 0;
    resultados.partidasPerdidas = 0;
    resultados.partidasEmpatadas = 0;
} else {
    // Leer los resultados existentes del archivo
    fscanf(ficheroResultados, "Total de partidas jugadas: %d\n", &resultados.totalPartidas);
    fscanf(ficheroResultados, "Partidas ganadas: %d\n", &resultados.partidasGanadas);
    fscanf(ficheroResultados, "Partidas perdidas: %d\n", &resultados.partidasPerdidas);
    fscanf(ficheroResultados, "Partidas empatadas: %d\n", &resultados.partidasEmpatadas);
}

// Actualizar los resultados según el resultado de la partida actual

if (bandera_partida){
        if (resultados.totalPartidas == 6421624){
            resultados.totalPartidas = 0;
        }
    resultados.totalPartidas++;
}

if (bandera_ganado) {
    resultados.partidasGanadas++;
} else if (bandera_perdido) {
    resultados.partidasPerdidas++;
} else if (bandera_empatado) {
    resultados.partidasEmpatadas++;
}

// Guardar los resultados actualizados en el archivo de resultados
ficheroResultados = fopen(nombreResultados, "w");
if (ficheroResultados == NULL) {
    printf("Error al abrir el fichero de resultados.\n");
    return;
}

        if (resultados.totalPartidas == 6421624){
            resultados.totalPartidas = 1;
        }else{
        resultados.totalPartidas = resultados.totalPartidas + 1;
        }
fprintf(ficheroResultados, "Total de partidas jugadas: %d\n", resultados.totalPartidas);
fprintf(ficheroResultados, "Partidas ganadas: %d\n", resultados.partidasGanadas);
fprintf(ficheroResultados, "Partidas perdidas: %d\n", resultados.partidasPerdidas);
fprintf(ficheroResultados, "Partidas empatadas: %d\n", resultados.partidasEmpatadas);

fclose(ficheroResultados);




    // Guardar la última partida en el fichero correspondiente
    fwrite(*tablero, sizeof(int), filas * columnas, ficheroUltimaPartida);
    fclose(ficheroUltimaPartida);

    // Liberar la memoria del tablero
    liberarTablero(tablero, filas);

    printf("Partida terminada. Los resultados han sido actualizados.\n");
}

// Funcion para crear un tablero dinamico
int** crearTablero(int filas, int columnas)
{
    int** tablero = (int**)malloc(filas * sizeof(int*));
    for (int i = 0; i < filas; i++) {
        tablero[i] = (int*)malloc(columnas * sizeof(int));
    }
    return tablero;
}

// Funcion para liberar la memoria del tablero
void liberarTablero(int** tablero, int filas)
{
    for (int i = 0; i < filas; i++) {
        free(tablero[i]);
    }
    free(tablero);
}


// Funcion para verificar si el tablero esta lleno
bool tableroLleno(int** tablero, int filas, int columnas)
{
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (tablero[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void agregarCoordenada(ListaCoordenadas* lista, int fila, int columna)
{
    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->coordenada.fila = fila;
    nuevoNodo->coordenada.columna = columna;
    nuevoNodo->siguiente = NULL;

    if (lista->cabeza == NULL) {
        lista->cabeza = nuevoNodo;
    } else {
        Nodo* actual = lista->cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void mostrarCoordenadas(ListaCoordenadas* lista)
{
    Nodo* actual = lista->cabeza;
    while (actual != NULL) {
        //printf("Fila: %d, Columna: %d\n", actual->coordenada.fila, actual->coordenada.columna);
        actual = actual->siguiente;
    }
}

void mostrarAyuda()
{
    printf("=== AYUDA ===\n");
    printf("El objetivo del juego es formar cuadrados en un tablero.\n");
    printf("Cada jugador, ya sea humano o computadora, coloca una ficha en el tablero.\n");
    printf("Cuando un jugador forma un cuadrado con sus fichas, gana la partida.\n");
    printf("Si el tablero se llena y nadie ha formado un cuadrado, la partida termina en empate.\n");
    printf("Durante tu turno, ingresa la fila y la columna donde deseas colocar tu ficha.\n");
    printf("Si en algún momento necesitas ayuda, puedes usar la opcion 'ayuda' para mostrar esta informacion nuevamente.\n");
    printf("¡Diviertete jugando!\n");
}
