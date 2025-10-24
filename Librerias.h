#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definir las constantes para los valores de las fichas
#define JUGADOR 1
#define COMPUTADORA 2

#define MAX_NICK_LENGTH 100
#define MAX_RESULTADOS_FILENAME (MAX_NICK_LENGTH + 15)

// Estructura para almacenar las coordenadas en formato (fila, columna)
typedef struct {
    int fila;
    int columna;
} Coordenada;

typedef struct Nodo {
    Coordenada coordenada;
    struct Nodo* siguiente;
} Nodo;

typedef struct {
    Nodo* cabeza;
} ListaCoordenadas;

typedef struct {
    int totalPartidas;
    int partidasGanadas;
    int partidasPerdidas;
    int partidasEmpatadas;
} ResultadosJugador;

typedef struct {
    char nombre[MAX_NICK_LENGTH];
    float puntaje;
} Jugador;


// Funciones prototipo
void mostrarConfiguracion(const char* nick);
void configurarParametros(const char* nick);
void verEstadisticas(const char* nick);
void jugarPartida(const char* nick);
void mostrarAyuda();

//Funciones utilizadas durante el juego
int** crearTablero(int filas, int columnas);
void liberarTablero(int** tablero, int filas);
bool verificarGanador(ListaCoordenadas* listaVerificar, int filas, int columnas, ListaCoordenadas* listaEvitar);
bool tableroLleno(int** tablero, int filas, int columnas);
void agregarCoordenada(ListaCoordenadas* lista, int fila, int columna);
void mostrarCoordenadas(ListaCoordenadas* lista);
int numCoordenadas(Nodo* cabeza);
int verificarTablero(ListaCoordenadas *lista, int** tablero, int filas, int columnas);
int coordenadaExistente(ListaCoordenadas* lista, int x, int y);
int longitudLista(ListaCoordenadas* lista);
void eliminarNodo(ListaCoordenadas* lista, Nodo* nodoEliminar);
void seleccionarAleatorio(ListaCoordenadas* lista, int* fila, int* columna);
void guardarJugador(const char* nombre);

