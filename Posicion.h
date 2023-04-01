#ifndef __POSICION_H__
#define __POSICION_H__

#include "Constantes.h"

class Posicion
{
private:
    int x;
    int y;

public:
    /*Asigna un valor de coordenada X a la posicion, limitandola en el rango permitido*/
    void setX(int x);

    /*Asigna un valor de coordenada Y a la posicion, limitandola en el rango permitido*/
    void setY(int y);

    /*Asigna un valor de las coordenadas X e Y de la posicion, limitandolas en el rango permitido*/
    void set(int x, int y);

    /*Crea una instancia de Posicion*/
    Posicion();

    /*Crea una instancia de Posicion con las coordenadas de X e Y dadas, dentro de los limites permitidos*/
    Posicion(int x, int y);

    /*Devuelve la coordenada X de la posicion*/
    int getX();

    /*Devuelve la coordenada Y de la posicion*/
    int getY();

private:
    /*devuelve un valor entre un minimo y un maxim
    Si es menor que el minimo devolvera el minimo y
    si es mayor que el maximo devolvera el maximo
    */
    int limitarEntreValores(int valor, int minimo, int maximo);
};

#endif