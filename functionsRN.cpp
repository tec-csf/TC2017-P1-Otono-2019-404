#include"RedTreeP.h"
/**

Programa que prueba todas las funciones del arbol Roji Negro desde un archivo de texto

*/
main(){
	int t1,t2,tiempo;//para la función de tiempo 


	NIL.left = NIL.right = NIL.p = NILPTR;
	NIL.color = BLACK;
	NODERB tree = NILPTR;
	int n;
	int i;
 /* Leer archivos desde un txt
 --------------------------------------------------------------------*/
ifstream fin("elementos.txt");
int num;
for(i=0; i<=100000; i++){
fin>> num;
rbinsert(&tree, num);

}
/*----------------------------------------------------------*/
	while (1) {
		printf("1.Insertar\n2.Buscar\n3.Menor a Mayor\n4.Mayor a Menor\n5.Borrar\n6.Altura de nodo\n7.Salida\n");
		scanf("%d", &n);
		if (n == 1) {
			printf("Ingresa el Numero\n");
			int num;
			scanf("%d", &num);
			rbinsert(&tree, num);
		}
		else if (n == 2) {
			printf("Ingresa el Numero\n");
			int num;
			scanf("%d", &num);
			t1=clock();
			
			
			
			
			if (Busqueda(tree, num) == NILPTR){
				printf("%d no encontrado\n", num);
			}
			
			
			else
				printf("%d Encontrado\n", num);
			t2=clock();
			 tiempo=getMilisegundos(t2-t1);
 				printf(" Tiempo = [ %d ] ", tiempo);
		}
		else if (n == 3) {
			menorMayor(tree);
			printf("\n");
		}
		else if (n == 4){
			mayorMenor(tree);
			printf("\n");
		}
		else if (n == 5) {
			printf("Ingresa el numero\n");
			int num;
			scanf("%d", &num);
			rbdelete(&tree, num);
		}
		else if (n == 6) {

			printf("Ingresa el numero\n");
			int num;
			scanf("%d", &num);
			if (high(tree, num, 0) == NILPTR){
				printf("%d no encontrado\n", num);
			}
			else{
				printf("%d encontrado\n", high(tree, num,0));	
			}
		}
		else 
			break;
	}
	return 0;
}

/*
Insertar listo
Borrar Listo
Imprimir Ordenado Listo
Imprimir Ordenado hacia abajo listo
Obtener la altura de cualquier nodo falta Creo que los tres son lo mismo
Obtener la profundidad falta
Obtener el nivel de cualquier nodo falta
*/
