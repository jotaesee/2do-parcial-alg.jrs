#include <iostream>
using namespace std;


int m;
int k;
int repetir = 1;

void carga (float v[][3]){
	int i = 0;
	while (i < m) {
		cout << "Ingrese codigo de producto" << endl;
		cin >> v[i][0];
		cout << "Ingrese cantidad existente del producto" << endl ;
		cin >> v[i][1];
		cout << "Ingrese el precio del producto" << endl;
		cin >> v[i][2];
		i++;
	}
}

void impresion(float v[][3]){
	int i = 0;
	while (i < m) {
		int j = 0;
		while (j < 3) {
			cout << v[i][j] << "  ";
			j++;
		}
		cout << endl;
		i++;
	}
}

void impresionultima(float v[][3]){
	int i = 0;
	while (i < m) {
		if ((v[i][1] * v[i][2]) > 100000) {
				cout << v[i][0] << "  " << (v[i][1] * v[i][2]) ;
			}
		cout << endl;
		i++;
	}
}


void actualizacion(float v[][3]){
	int cod;
	float porcentaje;
	int i = 0;
	int b = 0;
	int aux = 0;
	cout << "Ingrese el codigo de producto que quiere actualizar" << endl;
	
	cin >> cod;
	 
	while (i < m ) {
		if (v[i][0] == cod) {
			
			b = 1;
			aux = i;
		}
		i++;
	}
	if (b != 0) {
		cout << "Ingrese el porcentaje a aumentar" << endl;
		cin >> porcentaje; 
		porcentaje = porcentaje / 100;
		v[aux][2] = v[aux][2] + (porcentaje * v[aux][2]);
	}
	else cout << "Producto no existente" << endl;
}

void stock(int stock[], float v[][3]){
	int i = 0;
	k = 0;
	while (i < m) {
		if (v[i][1] <= 30) {
			stock[k] = v[i][0];
			k++;
		}
		i++;
	}
	cout << "cargado vector stock"<< endl;
}

void impresionstock(int stock[]){
	int i = 0;
	while (i < k) {
		cout << stock[i] << "  ";
		i++;
	}
}
  
void ordenamiento(float v[][3]) {
	int i = 0;
	int aux;
	while (i < m-1) {
		if (v[i][0] > v[i+1][0] ) {
			int j = 0;
			while ( j < 3) {
			aux = v[i+1][j];
			v[i+1][j] = v[i][j];
			v[i][j] = aux;
			j++;	
			}
			i=0;
		}
		i++;
	}
	
	
}

int main() {
	cout << "Ingrese las filas de la matriz PROD" << endl;
	cin >> m;
	float PROD[m][3];
	int STOCK[m];
	carga(PROD);
	int caso = 0;
	
	while (repetir == 1) {
		cout << "Ingrese la accion a realizar" << endl << "1 para generar de vuelta la matriz PROD." << endl << "2 para actualizar un precio" << endl << "3 para generar vector STOCK" << endl << "4 para la impresion de productos cuyo valor de stock sea mayor a cien mil" << endl << "5 para salir" << endl; 
		
		cin >> caso;
		switch (caso) {
			case 1 : carga(PROD);
			break;
			 
			case 2 : actualizacion(PROD);
			impresion(PROD);
			break;
			
			case 3 : 
				stock(STOCK, PROD);
				cout << "los productos con menos de 30 de stock son: (AVISO, si no aparece nada, ningun producto necesita restock)" << endl ;
				impresionstock(STOCK);
				cout << endl;
			break;
			
			case 4 : ordenamiento(PROD);
			impresionultima(PROD);
			break;
			
			case 5 : repetir = 0;
			break;
			
		}	
		
		
		
		
		
	}
	
}
