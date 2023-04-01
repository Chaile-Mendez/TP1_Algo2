#include "Casilla.h"

Casilla::Casilla()
{
    turnosInactiva = 0;
    habitante = NULL;
    duenioMina = NULL;
}

char Casilla::getIcono(Jugador *solicitante)
{
    if (!esActiva())
    {
        return ICONO_CASILLA_INACTIVA;
    }
    if (esHabitada() && (solicitante == habitante))
    {
        return habitante->getIcono();
    }
    if (estaMinada() && (solicitante == duenioMina))
    {
        return ICONO_MINA;
    }
    return ICONO_CASILLA_VACIA;
}

void Casilla::colocarSoldado(Jugador *jugador)
{
    if (!estaMinada() && esActiva())
    {
        if (!esHabitada())
        {
            habitante = jugador;
        }
        else
        {
            habitante = NULL;
        }
    }
    else if (estaMinada())
    {
        explotarMina();
    }
}

void Casilla::borrarSoldado()
{
    habitante = NULL;
}

void Casilla::ponerMina(Jugador *jugador)
{
    if (esActiva())
    {
        if (esHabitada())
        {
            explotarMina();
        }
        else
        {
            duenioMina = jugador;
        }
    }
}

bool Casilla::esActiva()
{
    if (turnosInactiva <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Casilla::pasarTurno()
{
    if (this->turnosInactiva > 0)
    {
        this->turnosInactiva = turnosInactiva - 1;
    }
}

Jugador *Casilla::getHabitante()
{
    return this->habitante;
}

bool Casilla::esHabitada()
{
    if (habitante != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Casilla::estaMinada()
{
    return (duenioMina != NULL);
}

void Casilla::explotarMina()
{
    turnosInactiva = DURACION_DE_TURNOS_INACTIVA;
    habitante = NULL;
    duenioMina = NULL;
}