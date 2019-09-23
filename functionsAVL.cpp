#include "AVL.h"
#include <iostream>


/*

Programa que prueba las funciones de un argol AVL

*/

int main(){

    Arbol<int> t;

    std::cout << "Insertando 10 numeros" << std::endl;
    for (int i = 1; i <= 10; ++i)
        t.insertar(i);

    std::cout << "Visualizacion de balances" << std::endl;
    t.obtenerBalance();

    t.imprimirArbol();

    t.imprimirArbol();

    t.obtenerAltura();

    t.obtenerProfundidad();

    t.obtenerNivel();

    t.buscarDato(5);
}
