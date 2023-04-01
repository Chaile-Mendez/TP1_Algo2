#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "Constantes.h"

class Jugador
{
private:
    char icono;

public:
    /*Instancia el jugador con un Caracter por defecto como 'icono'*/
    Jugador();

    /*Asigna un Caracter como 'icono', al instanciar el Jugador*/
    Jugador(char icono);

    /*Devuelve el caracter icono del personaje*/
    char getIcono();
};

#endif /*__JUGADOR_H__*/