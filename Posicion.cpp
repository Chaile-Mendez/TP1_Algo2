#include "Posicion.h"

void Posicion::setX(int x)
{
    this->x = limitarEntreValores(x, POSICION_MINIMA_X, POSICION_MAXIMO_EN_X);
}
void Posicion::setY(int y)
{
    this->y = limitarEntreValores(y, POSICION_MINIMA_Y, POSICION_MAXIMO_EN_Y);
}

void Posicion::set(int x, int y)
{
    setX(x);
    setY(y);
}

Posicion::Posicion()
{
}
Posicion::Posicion(int x, int y)
{
    this->set(x, y);
}

int Posicion::getX()
{
    return x;
}
int Posicion::getY()
{
    return y;
}

int Posicion::limitarEntreValores(int valor, int minimo, int maximo)
{
    if (valor < minimo)
    {
        return minimo;
    }
    else if (valor > maximo)
    {
        return maximo;
    }
    else
    {
        return valor;
    }
}