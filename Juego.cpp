#include "Juego.h"

Juego::Juego()
{
    tablero = new Casilla *[ALTO_TABLERO];
    for (int i = 0; i < ALTO_TABLERO; i++)
    {
        tablero[i] = new Casilla[ANCHO_TABLERO];
    }
    jugadores = new Jugador *[MAX_CANTIDAD_JUGADORES];
}

Juego::~Juego()
{
    for (int i = 0; i < ALTO_TABLERO; i++)
    {
        delete[] tablero[i];
    }
    delete[] tablero;
    delete[] jugadores;
}

void Juego::generarSoldados()
{
    for (int i = 0; i < cantidadJugadores; i++)
    {
        Jugador *jugadorEnTurno = jugadores[i];
        for (int j = 0; j < MAX_SOLDADOS; j++)
        {
            agregarSoldado(jugadorEnTurno, obtenerPosicionAleatoria());
        }
    }
}

void Juego::agregarJugador(Jugador *jugador)
{
    if (cantidadJugadores < MAX_CANTIDAD_JUGADORES)
    {
        jugadores[cantidadJugadores] = jugador;
        cantidadJugadores++;
    }
}

void Juego::mostrarEnConsola(Jugador *jugadorEnTurno)
{
    for (int i = 0; i < ALTO_TABLERO; i++)
    {
        for (int j = 0; j < ANCHO_TABLERO; j++)
        {
            std::cout << "[" << tablero[i][j].getIcono(jugadorEnTurno) << "]";
        }
        std::cout << " " << i + 1 << std::endl;
    }

    for (int i = 1; i <= ANCHO_TABLERO; i++)
    {
        if (i < 10)
        {
            std::cout << " " << i << " ";
        }
        else
        {
            std::cout << " " << i;
        }
    }
    std::cout << std::endl;
}

void Juego::mostrarTableroEnArchivo(Jugador *jugadorEnTurno)
{
    std::fstream myFile;
    std::string identificador;
    identificador.push_back(jugadorEnTurno->getIcono());
    std::string nombre_archivo = NOMBRE_BASE_ARCHIVO + identificador + EXTENSION_ARCHIVO;

    myFile.open(nombre_archivo, std::ios::out);

    if (myFile.is_open())
    {

        /*Dibujar tablero*/
        for (int i = 0; i < ALTO_TABLERO; i++)
        {
            for (int j = 0; j < ANCHO_TABLERO; j++)
            {
                myFile << "[" << tablero[i][j].getIcono(jugadorEnTurno) << "]";
            }
            myFile << " " << i + 1 << "\n";
        }

        for (int i = 1; i <= ANCHO_TABLERO; i++)
        {
            if (i < 10)
            {
                myFile << " " << i << " ";
            }
            else
            {
                myFile << " " << i;
            }
        }
    }
    myFile.close();
}

void Juego::escribirMensajeEnArchivo(Jugador *jugadorEnTurno, std::string texto)
{
    std::fstream myFile;
    std::string identificador;
    identificador.push_back(jugadorEnTurno->getIcono());

    std::string nombre_archivo = "Jugador_" + identificador + ".txt";

    myFile.open(nombre_archivo, std::ios::out);

    if (myFile.is_open())
    {
        myFile << texto;
    }
    myFile.close();
}

void Juego::elejirPosicionMina(Jugador *jugadorEnTurno)
{
    int posicionMinaX;
    int posicionMinaY;
    std::cout
        << "Ingrese una posicion en X para la mina: " << std::endl;
    std::cin >> posicionMinaX;

    std::cout
        << "Ingrese una posicion en Y para la mina: " << std::endl;
    std::cin >> posicionMinaY;

    std::cout
        << "Se ha colocado una mina en ( " << posicionMinaX << " , " << posicionMinaY << " )" << std::endl;

    Posicion posicionMina(posicionMinaX, posicionMinaY);
    tablero[posicionMina.getY() - 1][posicionMina.getX() - 1].ponerMina(jugadorEnTurno);
}

void Juego::elejirPersonajeAMover(Jugador *jugadorEnTurno)
{
    Posicion ubicacion;
    int personajeValido = false;

    while (!personajeValido)
    {
        int posicionX;
        int posicionY;
        std::cout
            << "Elija coordenada X del personaje a mover: ";
        std::cin >> posicionX;
        std::cout << std::endl
                  << "Elija coordenada Y del personaje a mover: ";
        std::cin >> posicionY;

        ubicacion.set(posicionX, posicionY);

        Jugador *jugadorEnCasilla = tablero[ubicacion.getY() - 1][ubicacion.getX() - 1].getHabitante();

        if (jugadorEnTurno == jugadorEnCasilla)
        {
            personajeValido = true;
        }
        else
        {
            std::cout << "No hay ningun soldado en esa posicion !" << std::endl;
        }
    }

    moverPersonajeElejido(ubicacion);
}

void Juego::moverPersonajeElejido(Posicion ubicacion)
{
    Posicion *posicionesValidas;
    posicionesValidas = new Posicion[9];
    int topePosicionesValidas = 0;

    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            Posicion nuevaPosicion;
            nuevaPosicion.set(ubicacion.getX() + i, ubicacion.getY() + j);
            bool esValida = tablero[nuevaPosicion.getY() - 1][nuevaPosicion.getX() - 1].esActiva();
            if (esValida)
            {
                posicionesValidas[topePosicionesValidas] = nuevaPosicion;
                topePosicionesValidas++;
            }
        }
    }

    Posicion nuevaPosicion;

    bool esperandoEntradaCorrecta = true;

    while (esperandoEntradaCorrecta)
    {
        int nuevaCoordenadaX;
        int nuevaCoordenadaY;
        std::cout
            << "Ingrese nueva posicion en X" << std::endl;
        std::cin >> nuevaCoordenadaX;
        std::cout
            << "Ingrese nueva posicion en Y" << std::endl;
        std::cin >> nuevaCoordenadaY;

        nuevaPosicion.set(nuevaCoordenadaX, nuevaCoordenadaY);

        int indiceEnVector = buscarPosicionEnVector(posicionesValidas, topePosicionesValidas, nuevaPosicion);
        if (indiceEnVector != NO_ENCONTRADO)
        {
            esperandoEntradaCorrecta = false;
        }
        else
        {
            std::cout << "Posicion no valida." << std::endl;
        }
    }

    Jugador *jugadorEnCasilla = tablero[ubicacion.getY() - 1][ubicacion.getX() - 1].getHabitante();
    tablero[ubicacion.getY() - 1][ubicacion.getX() - 1].borrarSoldado();
    tablero[nuevaPosicion.getY() - 1][nuevaPosicion.getX() - 1].colocarSoldado(jugadorEnCasilla);

    delete[] posicionesValidas;
}

void Juego::pasarTurno()
{
    for (int i = 0; i < ALTO_TABLERO; i++)
    {
        for (int j = 0; j < ANCHO_TABLERO; j++)
        {
            tablero[i][j].pasarTurno();
        }
    }
}

void Juego::comprobarGanador(char &equipoGanador)
{
    contarSoldadosEnEquipo();

    if (cantidadJugadores == 1)
    {
        equipoGanador = jugadores[0]->getIcono();
    }
    if (cantidadJugadores == 0)
    {
        equipoGanador = EQUIPO_EMPATE;
    }
}

void Juego::eliminarJugador(int indice)
{
    if ((indice < cantidadJugadores) && (indice > 0))
    {
        for (int i = indice; i < cantidadJugadores; i++)
        {
            jugadores[i] = jugadores[i + 1];
        }
        cantidadJugadores--;
    }
}

void Juego::contarSoldadosEnEquipo()
{
    int jg = cantidadJugadores - 1;
    while (jg >= 0)
    {
        int cantidad = 0;
        for (int j = 0; j < ALTO_TABLERO; j++)
        {
            for (int k = 0; k < ANCHO_TABLERO; k++)
            {
                if (tablero[j][k].getHabitante() == jugadores[jg])
                {
                    cantidad++;
                }
            }
        }
        if (cantidad <= 0)
        {
            eliminarJugador(jg);
        }
        jg--;
    }
}

void Juego::agregarSoldado(Jugador *jugadorEnTurno, Posicion posicion)
{
    tablero[posicion.getY() - 1][posicion.getX() - 1].colocarSoldado(jugadorEnTurno);
}

Posicion Juego::obtenerPosicionAleatoria()
{
    bool probando = true;
    srand((unsigned)time(NULL));
    Posicion posicionVacia;
    while (probando)
    {
        int x = POSICION_MINIMA_X + (rand() % (POSICION_MAXIMO_EN_X - POSICION_MINIMA_X));
        int y = POSICION_MINIMA_Y + (rand() % (POSICION_MAXIMO_EN_Y - POSICION_MINIMA_Y));

        Jugador *jugadorEnCasilla = tablero[y - 1][x - 1].getHabitante();

        if (jugadorEnCasilla == NULL)
        {
            posicionVacia.set(x, y);
            probando = false;
        }
    }

    return posicionVacia;
}

int Juego::buscarPosicionEnVector(Posicion vector[], int tope, Posicion posicion)
{
    int indice = NO_ENCONTRADO;
    bool buscando = true;
    int i = 0;

    while ((i < tope) && buscando)
    {
        if (vector[i].getX() == posicion.getX() && vector[i].getY() == posicion.getY())
        {
            indice = i;
            buscando = false;
        }
        i++;
    }

    return indice;
}
