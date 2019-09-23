#include<two3tree.h>

int main()
{
    ArbolDosTres<int> nuevoArbol;
     high_resolution_clock::time_point t1;
   high_resolution_clock::time_point t2;
   duration<double> tiempo;
   /* Leer archivos desde un txt
 --------------------------------------------------------------------*/
ifstream fin("elementos.txt");
int num;
int i;
for(i=0; i<=100000; i++){
fin>> num;
nuevoArbol.insertar(num);
}
/*----------------------------------------------------------*/
int n;
  while (1) {
		printf("1.Insertar\n2.Buscar\n3.Menor a Mayor\n4.Mayor a Menor\n5.Borrar\n6.Altura de nodo\n7.Salida\n");
		scanf("%d", &n);
		if (n == 1) {
			printf("Ingresa el Numero\n");
			int num;
			scanf("%d", &num);
			nuevoArbol.insertar(num);
		}
		else if (n == 2) {
			printf("Ingresa el Numero\n");
			int num;
			scanf("%d", &num);
			t1 = high_resolution_clock::now();
			nuevoArbol.buscar(num);
			t2 = high_resolution_clock::now();
			 tiempo = duration_cast<duration<double>>(t2-t1);
        tiempo=tiempo*1000;
        cout << tiempo.count() << "milisegundos" << endl;
		}
		else if (n == 3) {
			nuevoArbol.printAsc();
			printf("\n");
		}
		else if (n == 4){
			nuevoArbol.printDesc();
			printf("\n");
		}
		else if (n == 5) {
			printf("Ingresa el numero\n");
			int num;
			scanf("%d", &num);
			nuevoArbol.borrar(num);
		}
		else if (n == 6) {
			printf("Ingresa el numero\n");
			int num;
			scanf("%d", &num);
				//printf("%d encontrado\n", nuevoArbol.getAltura());	
		}
		else 
			break;
	}
   
   return 0;
}
