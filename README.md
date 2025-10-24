# Juego de Cuadrados - Proyecto LP1

## Descripción del Proyecto

Este es un juego de estrategia implementado en C donde el objetivo es **evitar formar cuadrados** en un tablero. Es una variante del clásico juego de conectar puntos, pero con la particularidad de que el jugador que forme un cuadrado **pierde** la partida.

### Características Principales

- **Juego de estrategia**: El jugador compite contra la computadora
- **Tablero configurable**: Tamaño ajustable hasta 10x10
- **Sistema de estadísticas**: Seguimiento de partidas ganadas, perdidas y empatadas
- **Ranking de jugadores**: Top 5 de mejores jugadores
- **Persistencia de datos**: Archivos de configuración y resultados por jugador
- **IA básica**: La computadora evita formar cuadrados y bloquea al jugador

## Estructura del Proyecto

```
Proyecto LP1/
├── main.c          # Programa principal con menú y lógica de inicialización
├── Funciones.c     # Implementación de todas las funciones del juego
├── Librerias.h     # Headers, estructuras y prototipos de funciones
└── README.md       # Este archivo
```

## Reglas del Juego

1. **Objetivo**: Evitar formar cuadrados con tus fichas
2. **Turnos**: Alterna entre jugador humano y computadora
3. **Colocación**: Cada turno, se coloca una ficha en una casilla vacía
4. **Victoria**: Ganas si la computadora forma un cuadrado
5. **Derrota**: Pierdes si formas un cuadrado con tus fichas
6. **Empate**: Si el tablero se llena sin que nadie forme un cuadrado

## Funcionalidades

### Menú Principal
1. **Visualizar configuración**: Muestra el tamaño actual del tablero
2. **Configurar parámetros**: Cambia las dimensiones del tablero (máximo 10x10)
3. **Ver estadísticas**: Muestra estadísticas personales y ranking global
4. **Jugar partida**: Inicia una nueva partida contra la computadora
5. **Ayuda**: Muestra las reglas del juego
6. **Salir**: Termina el programa

### Sistema de Archivos
- `{nick}_configuracion.txt`: Configuración del tablero por jugador
- `{nick}_resultados.txt`: Estadísticas de partidas por jugador
- `{nick}_ultimapartida.dat`: Datos binarios de la última partida
- `jugadores.txt`: Lista de todos los jugadores registrados

## Compilación y Ejecución

### Requisitos
- Compilador de C (gcc recomendado)
- Sistema Windows (usa PowerShell)

### Compilar
```powershell
gcc -o juego main.c Funciones.c
```

### Ejecutar
```powershell
./juego
```
## Capturas de Pantalla
<img width="580" height="511" alt="Captura de pantalla 2025-10-24 032123" src="https://github.com/user-attachments/assets/13e19620-635a-488f-92bc-d3c0952c8624" />

<img width="577" height="428" alt="Captura de pantalla 2025-10-24 032153" src="https://github.com/user-attachments/assets/7a7a5aad-937c-46cf-b323-330290d9f808" />

<img width="565" height="423" alt="Captura de pantalla 2025-10-24 032214" src="https://github.com/user-attachments/assets/1017ee10-2355-4cf6-9a73-fdf50f8e4322" />

<img width="555" height="492" alt="Captura de pantalla 2025-10-24 032304" src="https://github.com/user-attachments/assets/288dbd3e-d994-46a7-9207-f86beb9a1652" />

<img width="682" height="362" alt="Captura de pantalla 2025-10-24 032616" src="https://github.com/user-attachments/assets/4918cc65-e105-4d62-9d3d-a7a195a6b1c1" />

## Algoritmo de la Computadora

La IA implementa una estrategia defensiva:

1. **Detección de amenazas**: Identifica posiciones donde el jugador podría formar cuadrados
2. **Autoprotección**: Evita posiciones donde ella misma formaría cuadrados
3. **Selección aleatoria**: Cuando no hay restricciones, elige posiciones al azar
4. **Estrategia de supervivencia**: En situaciones límite, prioriza evitar su propia derrota

## Estructuras de Datos

- **ListaCoordenadas**: Lista enlazada para almacenar coordenadas de fichas
- **ResultadosJugador**: Estructura para estadísticas de partidas
- **Jugador**: Estructura para ranking con nombre y puntaje

## Características Técnicas

- **Gestión dinámica de memoria**: Para tableros de tamaño variable
- **Listas enlazadas**: Para manejo eficiente de coordenadas
- **Persistencia de datos**: Archivos de texto y binarios
- **Validación de entrada**: Control de movimientos inválidos
- **Sistema de puntuación**: Basado en ratio ganadas/perdidas

## Autor

**Maria Cielito Melgarejo Baez**
Proyecto desarrollado para la asignatura **Lenguajes de Programación 1 (LP1)**

## Notas de Desarrollo

- El juego está diseñado para ser intuitivo y educativo
- Implementa conceptos fundamentales de programación en C
- Incluye manejo de archivos, estructuras de datos y algoritmos básicos
