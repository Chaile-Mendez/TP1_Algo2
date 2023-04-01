#ifndef __JUEGO_H__
#define __JUEGO_H__

#include "Constantes.h"
#include <iostream>
#include <fstream>

#include "Casilla.h"
#include "Posicion.h"
#include "Jugador.h"

class Juego
{
public:
    Casilla **tablero;
    Jugador **jugadores;
    int cantidadJugadores = 0;

    Juego();

    ~Juego();

    /*Agrega en el tablero la cantidad maxima de Soldados por cada Jugador, en posiciones aleatorias.*/
    void generarSoldados();

    /*Agrega un Jugador a la lista de Jugadores del Juego*/
    void agregarJugador(Jugador *jugador);

    /*Muestra en consola el punto de vista de la partida del JugadorEnTurno*/
    void mostrarEnConsola(Jugador *jugadorEnTurno);

    /*Crea un archivo de texto con el punto de vista de la partida del JugadorEnTurno*/
    void mostrarTableroEnArchivo(Jugador *jugadorEnTurno);

    /*Escribe en el archivo del jugador en Turno un Texto*/
    void escribirMensajeEnArchivo(Jugador *jugadorEnTurno, std::string texto);

    /*Pregunta al jugadorEnTurno donde poner una mina, solo podra hacerlo en una Casilla Activa*/
    void elejirPosicionMina(Jugador *jugadorEnTurno);

    /*Pregunta al jugadorEnTurno que soldado mover indicando sus coordenadas iniciales y finales*/
    void elejirPersonajeAMover(Jugador *jugadorEnTurno);

    /*Pregunta al jugador en turno a que posicion desea mover el Soldado, continuara preguntando hasta que elija una posicion valida*/
    void moverPersonajeElejido(Posicion ubicacion);

    /*Pasa un turno en cada casilla del mapa*/
    void pasarTurno();

    /*Comprueba la cantidad de solados en la partida y asigna en equipoGanador si hay un ganador, un empate, o si la partida continua*/
    void comprobarGanador(char &equipoGanador);

private:
    /*Elimina a un Jugador del vector Jugadores, dado su indice en el vector*/
    void eliminarJugador(int indice);

    /*Elimina a los jugadores que no tengan soldados en el tablero*/
    void contarSoldadosEnEquipo();

    /*Agrega a un Soldado del jugadorEnTurno en una casilla del tablero dada una posicion*/
    void agregarSoldado(Jugador *jugadorEnTurno, Posicion posicion);

    /*Devuelve una posicion aleatoria dentro del tablero donde no haya ningun Soldado*/
    Posicion obtenerPosicionAleatoria();

    /*Dado un vector de posiciones, devuelve la posicion de un elemento buscado o en su defento NO_ENCONTRADO si no existe en el vector*/
    int buscarPosicionEnVector(Posicion vector[], int tope, Posicion posicion);
};

#endif /* __JUEGO_H__ */