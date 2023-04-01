#ifndef __CONSTANTES_H__
#define __CONSTANTES_H__

#include <string>

#define ANCHO_TABLERO 20
#define ALTO_TABLERO 20

#define MAX_JUGADORES 2
#define MAX_CANTIDAD_JUGADORES 2
#define MAX_SOLDADOS 4

static const std::string NOMBRE_BASE_ARCHIVO = "jugador_";
static const std::string EXTENSION_ARCHIVO = ".txt";

static const char ICONO_JUGADOR_1 = '1';
static const char ICONO_JUGADOR_2 = '2';

static const char ICONO_MINA = '#';
static const char ICONO_PERSONAJE_POR_DEFECTO = 'P';
static const char ICONO_CASILLA_VACIA = ' ';
static const char ICONO_CASILLA_INACTIVA = 'X';

static const int DURACION_DE_TURNOS_INACTIVA = 5;

static const int POSICION_MINIMA_X = 1;
static const int POSICION_MAXIMO_EN_X = ANCHO_TABLERO;
static const int POSICION_MINIMA_Y = 1;
static const int POSICION_MAXIMO_EN_Y = ALTO_TABLERO;

static const int NO_ENCONTRADO = -1;

static const char SIN_EQUIPO_GANADOR_AUN = '-';
static const char EQUIPO_EMPATE = '0';

#endif /*__CONSTANTES_H__*/