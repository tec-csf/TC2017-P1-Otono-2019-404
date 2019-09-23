#include "AVL.h"
#include "RedTreeP.h"
#include "two3tree.h"
#include <iostream>
#include<time.h>
#include <ctime> 

int main(){
	/*AVL*/
	Arbol<int> t;
	
	/*RojiNegro*/
	NIL.left = NIL.right = NIL.p = NILPTR;
	NIL.color = BLACK;
	NODERB tree = NILPTR;
	
	/*DOS TRES*/
	ArbolDosTres<int> nuevoArbol;

	#define MAX_NUMEROS 99990
	for(int a=0;a<MAX_NUMEROS;a++)
	{
  	// generamos un numero
	int M = (rand() % 889476);
  	// Lo insertamos
	t.insertar(M);       //al AVL
	rbinsert(&tree, M); //al rojinegro
	nuevoArbol.insertar(M); //DOS TRES
	printf("%d\n",M);
  	}
  	
  	//elementos que vamos a buscar en el árbol AVL
  	t.insertar(10);
  	t.insertar(100);
  	t.insertar(1000);
  	t.insertar(10000);
  	t.insertar(123);
  	t.insertar(987);
  	t.insertar(444);
  	t.insertar(95786);
  	t.insertar(1);
  	t.insertar(7834);
	
	//Elementos que vamos a buscar en Rojinegro 
	rbinsert(&tree, 10);
	rbinsert(&tree, 100);
	rbinsert(&tree, 1000);
	rbinsert(&tree, 10000);
	rbinsert(&tree, 123);
	rbinsert(&tree, 987);
	rbinsert(&tree, 444);
	rbinsert(&tree, 95786);
	rbinsert(&tree, 1);
	rbinsert(&tree, 7834);
	
	//Elementos que vamos a ingresar al DOS TRES
	
	nuevoArbol.insertar(10);
	nuevoArbol.insertar(100);
	nuevoArbol.insertar(1000);
	nuevoArbol.insertar(10000);
	nuevoArbol.insertar(123);
	nuevoArbol.insertar(987);
	nuevoArbol.insertar(444);
	nuevoArbol.insertar(95786);
	nuevoArbol.insertar(1);
	nuevoArbol.insertar(7834);

//midiendo tiempos para AVL
	unsigned t0_avl, t1_avl;
	t0_avl=clock();    //Corre tiempo
	t.buscarDato(10);
	t.buscarDato(100);
	t.buscarDato(1000);
	t.buscarDato(10000);
	t.buscarDato(123);
	t.buscarDato(987);
	t.buscarDato(444);
	t.buscarDato(95786);
	t.buscarDato(1);
	t.buscarDato(7834);
	t1_avl = clock();  //Termina de ejecutarse
	
	double time_avl = (double(t1_avl-t0_avl)/CLOCKS_PER_SEC); //Se calcula el tiempo
	std::cout << "\nExecution Time: " << time_avl << std::endl; //Imprimimos tiempo de ejecucion
	
	
//midiendo tiempo para RojoNegro
unsigned t0_RN, t1_RN;
	t0_RN=clock();    //Corre tiempo
	
	
	if (Busqueda(tree, 10) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	
	
	if (Busqueda(tree, 100) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	

	if (Busqueda(tree, 1000) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	
	
	if (Busqueda(tree, 10000) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	
	
	if (Busqueda(tree, 123) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	
	
	if (Busqueda(tree, 987) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	

	if (Busqueda(tree, 444) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	
	
	if (Busqueda(tree, 95786) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");		
		
	if (Busqueda(tree, 1) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");	
	
	if (Busqueda(tree, 7834) == NILPTR){
		printf("no encontrado\n");
		}
	else
		printf("Encontrado\n");		

	t1_RN = clock();  //Termina de ejecutarse
	
	double time_RN = (double(t1_RN-t0_RN)/CLOCKS_PER_SEC); //Se calcula el tiempo
	std::cout << "\nExecution Time: " << time_RN << std::endl; //Imprimimos tiempo de ejecucion

//midiendo tiempos para DOS TRES
	unsigned t0_dostres, t1_dostres;
	t0_dostres=clock();    //Corre tiempo
	nuevoArbol.buscar(10);
	nuevoArbol.buscar(100);
	nuevoArbol.buscar(1000);
	nuevoArbol.buscar(10000);
	nuevoArbol.buscar(123);
	nuevoArbol.buscar(987);
	nuevoArbol.buscar(444);
	nuevoArbol.buscar(95786);
	nuevoArbol.buscar(1);
	nuevoArbol.buscar(7834);
	t1_dostres = clock();  //Termina de ejecutarse
	
	double time_dostres = (double(t1_dostres-t0_dostres)/CLOCKS_PER_SEC); //Se calcula el tiempo
	std::cout << "\nExecution Time: " << time_dostres << std::endl; //Imprimimos tiempo de ejecucion
	



	return 0; 
	
}
