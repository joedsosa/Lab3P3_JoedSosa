#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


char** Llenar_Matriz(int filas, int columnas) {
	char** matriz = new char*[filas];
	for  (int i = 0;  i < filas; i++){
		matriz[i] = new char[columnas];
			for (int j = 0; j < columnas; j++){
				matriz[i][j] = '-';
			}
	
	}
	return matriz;
} 
int posicion_random(int n) {
	return rand() % n;
}
void agregar_osbtaculos(char** matriz, int obstaculos, int filas, int columnas) {
	int i = 0;
	while (i < obstaculos) {
		int fila = posicion_random(filas);
		int columna = posicion_random(columnas);
		if (matriz[fila][columna] != '#') {
			matriz[fila][columna] = '#';
			i++;
		}
	}
}
void imprimir_matriz(char** matriz, int filas, int columnas) {
	for (int i = 0;i < filas;i++) {
		for (int j = 0;j < columnas; j++) {
			cout << "|" << matriz[i][j] << " ";
		}
		cout <<"|" << endl;
	}
}
void mem_delete(char** matriz, int filas) {
	for (int i = 0;i < filas;i++) {
		delete[] matriz[i];

	}
	delete[] matriz;
}
void Matrix() {
	srand(time(NULL));
	int filas = 0, columnas = 0, obstaculos, casillastot;
	
	
	cout << "Ingrese la cantidad de filas(mayor o igual a 5): ";
	cin >> filas;
	cout << "Ingrese la cantidad de columnas(mayor o igual a 5: ";
	cin >> columnas;
	cout << "Ingrese la cantidad de obstaculos(entre 1 y la cantidad de casillas: ";
	cin >> obstaculos;
	if (filas < 5 || columnas < 5) {
		cout << "La cantidad de filas y columnas deben ser mayores o iguales a 5" << endl;
		
	}
	casillastot = filas * columnas;
	if (obstaculos < 1 || obstaculos >= casillastot) {
		cout << "La cantidad de obstaculos debe ser mayor o igual 1 y menor que la cantidad de casillas" << endl;
	}
	
	char** matriz = Llenar_Matriz(filas, columnas);
	agregar_osbtaculos(matriz, obstaculos, filas, columnas);
	cout << "Matriz generada: " << endl;
	imprimir_matriz(matriz, filas, columnas);

}
int main(){
	
	char opcion;
	bool continuar = true;
	
	
	do {
		cout << "MENU\n";
		cout << "1. Ejercicio 1: Disco XOR \n";
		cout << "2. Ejercicio 2: Matriz con Obstaculos \n";
		cout << "3. Salir\n";
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		switch (opcion) {
		case '1':
			
			break;
		case '2':
			Matrix();
			break;
		case '3':
			cout << "Saliendo del programa" << endl;
			break;
		default:
			cout << "Opcion ivalida" << endl;
		}
		if (opcion != '3') {
			cout << "Desea continuar ? (S / N) :";
			cin >> opcion;
		}

	} while (opcion == 'S' || opcion == 's');
	return 0;

}


