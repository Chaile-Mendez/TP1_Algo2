#include <iostream>
#include <fstream>
#include <cstdlib>

#include <chrono>
#include <thread>
#include <stdlib.h>
#include "Constantes.h"
#include "Juego.h"

using namespace std;

int main()
{
    system("clear");
    Juego batallaDigital;

    Jugador *jugador1 = new Jugador(ICONO_JUGADOR_1);
    Jugador *jugador2 = new Jugador(ICONO_JUGADOR_2);

    batallaDigital.agregarJugador(jugador1);
    batallaDigital.agregarJugador(jugador2);

    batallaDigital.generarSoldados();

    for (int i = 0; i < batallaDigital.cantidadJugadores; i++)
    {
        Jugador *jugadorEnTurno = batallaDigital.jugadores[i];
        batallaDigital.mostrarTableroEnArchivo(jugadorEnTurno);
    }

    char equipoGanador = SIN_EQUIPO_GANADOR_AUN;

    int turno = 0;
    while (equipoGanador == SIN_EQUIPO_GANADOR_AUN)
    {
        turno = 0;
        while ((turno < batallaDigital.cantidadJugadores) && (equipoGanador = SIN_EQUIPO_GANADOR_AUN))
        {
            Jugador *jugadorEnTurno = batallaDigital.jugadores[turno];

            batallaDigital.elejirPosicionMina(jugadorEnTurno);

            for (int j = 0; j < batallaDigital.cantidadJugadores; j++)
            {
                Jugador *jugador = batallaDigital.jugadores[j];
                batallaDigital.mostrarTableroEnArchivo(jugador);
            }

            batallaDigital.comprobarGanador(equipoGanador);

            if (equipoGanador == SIN_EQUIPO_GANADOR_AUN)
            {
                batallaDigital.elejirPersonajeAMover(jugadorEnTurno);

                for (int j = 0; j < batallaDigital.cantidadJugadores; j++)
                {
                    Jugador *jugador = batallaDigital.jugadores[j];
                    batallaDigital.mostrarTableroEnArchivo(jugador);
                }
            }

            batallaDigital.pasarTurno();
            batallaDigital.comprobarGanador(equipoGanador);
            turno++;
        }
    }

    system("clear");

    if (equipoGanador == EQUIPO_EMPATE)
    {
        cout << "Hubo un empate" << endl;
    }
    else
    {
        cout << "Gano el equipo : " << equipoGanador;
    }

    batallaDigital.~Juego();
    delete jugador1;
    delete jugador2;
    return 0;
}