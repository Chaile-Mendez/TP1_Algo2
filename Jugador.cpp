#include "Jugador.h"

Jugador::Jugador()
{
    this->icono = ICONO_PERSONAJE_POR_DEFECTO;
};

Jugador::Jugador(char icono)
{
    this->icono = icono;
}

char Jugador::getIcono()
{
    return icono;
}