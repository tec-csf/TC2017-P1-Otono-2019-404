#include <algorithm>
#include <iostream>

template <class T>
class Nodo
{
public:
    T llave;
    Nodo *izq, *derecho, *padre;
    int balance;

    Nodo(T k, Nodo *p) : llave(k), balance(0), padre(p), izq(NULL), derecho(NULL) {}

    Nodo()
    {
        delete izq;
        delete derecho;
    }
};
template <class T>
class Arbol
{
public:
    Arbol(void);
    ~Arbol(void);
    bool insertar(T llave);
    void borrar(const T llave);
    void obtenerBalance();
    void obtenerAltura();
    void obtenerProfundidad();
    void imprimirArbol();
    void obtenerNivel();
    void buscarDato(T x);

private:
    Nodo<T> *raiz;
    Nodo<T> *rotarizq(Nodo<T> *a);
    Nodo<T> *rotarderecha(Nodo<T> *a);
    Nodo<T> *rotarizqdoble(Nodo<T> *n);
    Nodo<T> *rotarderechadoble(Nodo<T> *n);
    Nodo<T> *buscar(T x, Nodo<T> *t);
    void rebalancear(Nodo<T> *n);
    int altura(Nodo<T> *n);
    void setBalance(Nodo<T> *n);
    void obtenerBalance(Nodo<T> *n);
    void limpiarNodo(Nodo<T> *n);
    void printAscendente(Nodo<T> *n);
    void printDescendente(Nodo<T> *n);
};

template <class T>
void Arbol<T>::rebalancear(Nodo<T> *n)
{
    setBalance(n);

    if (n->balance == -2)
    {
        if (altura(n->izq->izq) >= altura(n->izq->derecho))
            n = rotarderecha(n);
        else
            n = rotarizqdoble(n);
    }
    else if (n->balance == 2)
    {
        if (altura(n->derecho->derecho) >= altura(n->derecho->izq))
            n = rotarizq(n);
        else
            n = rotarderechadoble(n);
    }

    if (n->padre != NULL)
    {
        rebalancear(n->padre);
    }
    else
    {
        raiz = n;
    }
}

template <class T>
Nodo<T> *Arbol<T>::rotarizq(Nodo<T> *a)
{
    Nodo<T> *b = a->derecho;
    b->padre = a->padre;
    a->derecho = b->izq;

    if (a->derecho != NULL)
        a->derecho->padre = a;

    b->izq = a;
    a->padre = b;

    if (b->padre != NULL)
    {
        if (b->padre->derecho == a)
            b->padre->derecho = b;
        else
            b->padre->izq = b;
    }

    setBalance(a);
    setBalance(b);
    return b;
}

template <class T>
Nodo<T> *Arbol<T>::rotarderecha(Nodo<T> *a)
{
    Nodo<T> *b = a->izq;
    b->padre = a->padre;
    a->izq = b->derecho;

    if (a->izq != NULL)
        a->izq->padre = a;

    b->derecho = a;
    a->padre = b;

    if (b->padre != NULL)
    {
        if (b->padre->derecho == a)
            b->padre->derecho = b;
        else
            b->padre->izq = b;
    }

    setBalance(a);
    setBalance(b);
    return b;
}

template <class T>
Nodo<T> *Arbol<T>::rotarizqdoble(Nodo<T> *n)
{
    n->izq = rotarizq(n->izq);
    return rotarderecha(n);
}

template <class T>
Nodo<T> *Arbol<T>::rotarderechadoble(Nodo<T> *n)
{
    n->derecho = rotarderecha(n->derecho);
    return rotarizq(n);
}

template <class T>
int Arbol<T>::altura(Nodo<T> *n)
{
    if (n == NULL)
        return -1;
    return 1 + std::max(altura(n->izq), altura(n->derecho));
}

template <class T>
void Arbol<T>::setBalance(Nodo<T> *n)
{
    n->balance = altura(n->derecho) - altura(n->izq);
}

template <class T>
void Arbol<T>::obtenerBalance(Nodo<T> *n)
{
    if (n != NULL)
    {
        obtenerBalance(n->izq);
        std::cout << n->balance << " ";
        obtenerBalance(n->derecho);
    }
}

template <class T>
Arbol<T>::Arbol(void) : raiz(NULL) {}

template <class T>
Arbol<T>::~Arbol(void)
{
    delete raiz;
}

template <class T>
bool Arbol<T>::insertar(T llave)
{
    if (raiz == NULL)
        raiz = new Nodo<T>(llave, NULL);
    else
    {
        Nodo<T>
            *n = raiz,
            *padre;

        while (true)
        {
            if (n->llave == llave)
                return false;

            padre = n;

            bool goizq = n->llave > llave;
            n = goizq ? n->izq : n->derecho;

            if (n == NULL)
            {
                if (goizq)
                    padre->izq = new Nodo<T>(llave, padre);
                else
                    padre->derecho = new Nodo<T>(llave, padre);

                rebalancear(padre);
                break;
            }
        }
    }
    return true;
}

template <class T>
void Arbol<T>::borrar(const T delllave)
{
    if (raiz == NULL)
        return;

    Nodo<T>
        *n = raiz,
        *delNode = NULL,
        *padre = raiz,
        *child = raiz;

    while (child != NULL)
    {
        padre = n;
        n = child;
        child = delllave >= n->llave ? n->derecho : n->izq;
        if (delllave == n->llave)
            delNode = n;
    }

    if (delNode != NULL)
    {
        delNode->llave = n->llave;

        child = n->izq != NULL ? n->izq : n->derecho;

        if (raiz->llave == delllave)
            raiz = child;
        else
        {
            if (padre->izq == n)
                padre->izq = child;
            else
                padre->derecho = child;

            rebalancear(padre);
        }
    }
}
template <class T>
Nodo<T> *Arbol<T>::buscar(T x, Nodo<T> *t)
{
    while (t != NULL)
    {
        if (x == t->llave)
            return t;
        else if (x < t->llave)
            return buscar(x, t->izq);
        else
            return buscar(x, t->derecho);
    }
    return NULL;
}
template <class T>
void Arbol<T>::obtenerAltura()
{
    T dato;
    std::cout << "Inserte llave de nodo deseado" << std::endl;
    std::cin >> dato;
    std::cout << altura(buscar(dato, raiz)) << std::endl;
}

template <class T>
void Arbol<T>::obtenerProfundidad()
{
    T dato;
    std::cout << "Inserte llave de nodo deseado" << std::endl;
    std::cin >> dato;
    std::cout << altura(buscar(dato, raiz)) - altura(raiz) << std::endl;
}

template <class T>
void Arbol<T>::obtenerNivel()
{
    T dato;
    std::cout << "Inserte llave de nodo deseado" << std::endl;
    std::cin >> dato;
    std::cout << altura(buscar(dato, raiz)) - altura(raiz) << std::endl;
}

template <class T>
void Arbol<T>::obtenerBalance()
{
    obtenerBalance(raiz);
    std::cout << std::endl;
}

template <class T>
void Arbol<T>::printAscendente(Nodo<T> *n)
{
    if (n->izq != NULL)
    {
        printAscendente(n->izq);
    }

    std::cout << n->llave << " ";

    if (n->derecho != NULL)
    {
        printAscendente(n->derecho);
    }
}

template <class T>
void Arbol<T>::printDescendente(Nodo<T> *n)
{
    if (n->derecho != NULL)
    {
        printDescendente(n->derecho);
    }

    std::cout << n->llave << " ";

    if (n->izq != NULL)
    {
        printDescendente(n->izq);
    }
}

template <class T>
void Arbol<T>::imprimirArbol()
{
    bool metodo;
    std::cout << "Ascendente: 0 \n Descendente: 1" << std::endl;
    std::cin >> metodo;
    if (metodo == 0)
        printAscendente(raiz);
    else
        printDescendente(raiz);

    std::cout << std::endl;
}
template<class T>
void Arbol<T>::buscarDato(T x){
    if (buscar(x, raiz) != NULL)
        std::cout << "Dato encontrado" << std::endl; 
    else
        std::cout << "Dato no encontrado" << std::endl;
    
}
