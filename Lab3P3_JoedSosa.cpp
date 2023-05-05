#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
void XOR(){
int opc = 0;
while (opc != 4) {
	int xor1[8];
	int xor2[8];
	int XOR[8];
	cout << "1. Guardar datos en XOR" << endl;
	cout << "2. Obtener datos de disco 1" << endl;
	cout << "3. Obtener datos de disco 2" << endl;
	cout << "4. Salir" << endl;
	cout << "Ingrese la opcion: " << endl;
	cin >> opc;
	switch (opc) {
	case 1:
		cout << "Ingrese datos de DISCO 1" << endl;
		for (int i = 0; i < 8; i++) {
			cout << "Disco 1 [" << i << "]: ";
			cin >> xor1[i];
		}
		
		cout << "Ingrese datos de DISCO 2" << endl;
		for (int i = 0; i < 8; i++) {
			cout << "Disco 2 [" << i << "]: ";
			cin >> xor2[i];
		}
		for (int i = 0; i < 8; i++) {
			if (xor1[i] == xor2[i])
				XOR[i] = 0;
			else
				XOR[i] = 1;
				
		}		
		cout << "Disco XOR: [ ";
	    for (int i = 0; i < 8; i++){
			cout << XOR[i] << " ";
		}
		cout << "]" << endl;
		break;
	case 2:
		cout << "Disco XOR: [ ";
		for (int i = 0; i < 8; i++) {
			cout << XOR[i] << " ";
		}
		cout << "]" << endl;
		
		cout << "\nDisco 2: [ ";
		for (int i = 0; i < 8; i++) {
			cout << xor2[i] << " ";
		}
		cout << "]" << endl;
		
		
		for (int i = 0; i < 8; i++) {
			if (xor2[i] == XOR[i])
				xor1[i] = 0;
			else
				xor1[i] = 1;
		}
		cout << "Datos calculados del disco 1: [ ";
		for (int i = 0; i < 8; i++) {
			cout << xor1[i] << " ";
		}

		cout << "]" << endl;
		break;
	case 3:
		
		cout << "Disco XOR: [ " << endl;
		for (int i = 0; i < 8; i++) {
			cout << XOR[i] << " ";
		}
		cout << "]" << endl;
		
			cout << "\nDisco 1: [ ";
		for (int i = 0; i < 8; i++) {
			cout << xor1[i] << " ";
		}
		cout << "]" << endl;

		cout << "Datos calculados del disco 2: [ ";
		for (int i = 0; i < 8; i++) {
			if (xor1[i] == XOR[i])
				xor2[i] = 0;
			else
				xor2[i] = 1;
			
		}
		for (int i = 0; i < 8; i++){
			cout << xor2[i] << " ";
		}
		cout << "]" << endl;
		break;
	}
}
}

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
// Pone los obstaculos aleatoriamente mandando el numero de filas y columnas al metodo de posicion_random
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
// recibe la matriz filas y columnas e imprime ordenamente las barras y comillas con el estilo pedido
void imprimir_matriz(char** matriz, int filas, int columnas) {
	
	for (int i = 0;i < filas;i++) {
		cout << "|";
		for (int j = 0;j < columnas; j++) {
			cout << "'" << matriz[i][j] << "' ";
		}
		cout <<"|" << endl;
	}
}
//borra la memoria y las posiciones de la matriz
void mem_delete(char** matriz, int filas) {
	for (int i = 0;i < filas;i++) {
		delete[] matriz[i];

	}
	delete[] matriz;
}
// Pide al usuario la informacion requerida para crear la matriz y se valida el numero de filas y columnas y los obstaculos
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
			XOR();
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


