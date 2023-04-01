#ifndef __CASILLA_H__
#define __CASILLA_H__
#include "Constantes.h"
#include "Jugador.h"

/*Representa una casilla de un Tablero.
Contiene informacion de que Jugador tiene control sobre ella*/
class Casilla
{
public:
    /*Genera una casilla con ACTIVA, sin ningun Jugador en ella y sin estar Minada.*/
    Casilla();

    /*Devuelve un caracter dependiendo de si la casilla es Activa, si lo es entonces
    devuelve un caracter dependiendo si el Jugador Solicitante es habitante de la casilla o si fue quien coloco la mina.
    En caso contrario mostrara devolvera un caracter como si fuese vacia.*/
    char getIcono(Jugador *solicitante);

    /*Si la casilla no esta Minada, asigna al Jugador como el habitante de la casilla*/
    void colocarSoldado(Jugador *jugador);

    /*Deja la casilla sin ningun habitante*/
    void borrarSoldado();

    /*Coloca una mina en la casilla cuyo dueño es el Jugador, si la casilla esta habitada entonces la casilla queda deshabitada y fija la cantidad turnos inactiva en 5*/
    void ponerMina(Jugador *jugador);

    /*Devuelve Verdadero si la casilla es tiene 0 turnos de inactividad, y falso en caso contrario*/
    bool esActiva();

    /*Reduce en 1 los turnos de inactividad hasta un minimo de 0*/
    void pasarTurno();

    /*Devuelve un puntero al Jugador que habita la casilla*/
    Jugador *getHabitante();

private:
    Jugador *habitante;
    Jugador *duenioMina;
    int turnosInactiva;

    /*Devuelve true si la casilla esta habitada por un Jugador*/
    bool esHabitada();

    /*Devuelve true si la casilla esta minada por un Jugador*/
    bool estaMinada();

    /*Detona una casilla, eliminado dejandola sin mina, sin ningun jugador en ella e inactiva por 5 turnos*/
    void explotarMina();
};

#endif /*__CASILLA_H__*/