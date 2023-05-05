#include "EjerciciosComienzo.h"

int suma(int a, int b) {;
    return a+b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
	for (desde; desde <= hasta;desde++) {
		cout << desde << "*" << tablaDel << "=" << tablaDel * desde;
		if (desde < hasta) {
			cout << ";";
		}
	}
}

//PRE: Recibe dos enteros
//POS: Devuelve el maximo comun divisor de ambos
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}


void simplificar(int n, int d) {
	int n1;
	int d1;
	int factor;

	factor = gcd(n, d);
	n1 = n / factor;
	d1 = d / factor;

	cout << n1 << "/" << d1;
}

int ocurrencias123Repetidos(int* vector, int largo) {
	int contador = 0; 
	for (int i = 0; i < largo - 1; i++) {
		if (vector[i] == 1) {
			for (int j = i + 1; j < largo - 1 && (vector[j] == 1 || vector[j] == 2); j++) {
				if (vector[j] == 2) {
					if (vector[j + 1] == 3) {
						contador++;
						i = j;//buscar mas ocurrencias a partir de la ultima
					}
				}
			}
		}
	}
	return contador;
}

int maximoNumero(unsigned int n) {
	int numAnt, max=0;
	bool primeraVez = true;
	for (int i = 0; i < n;i++) {
		cin >> numAnt;
		if (primeraVez){
			max = numAnt ;
			primeraVez = false;
		}
		else {
			if (numAnt>max) {
				max = numAnt;
			}
		}
	}
	return max;
}

//Bubblesort
void ordenarVecInt(int *vec, int largoVec) {
	for (int i = 0; i < largoVec; i++) {
		for (int j = 0; j < largoVec - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				int aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}
}

// PRE: Recibe un string
// POS: Devuelve el largo de un string
int largoStr(char*str){
	int i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return i;
}

// PRE: Recibe un string
// POS: Devuelve una copia de dicho string sin compartir memoria
char* copiarStr(char* str) {
	int largo = largoStr(str);
	char* ret = new char[largo+1];
	int i = 0;
	while (str[i] != '\0') {
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return ret;
}


char* invertirCase(char* str){
	int diferencia = 'a' - 'A', i = 0;
	char* str2 = copiarStr(str);
	while(str[i]!='\0') {
		if (str[i] >= 'a'&& str[i] <= 'z') {//si es minuscula
			str2[i] -= diferencia;
		}
		else {
			if (str[i] >= 'A' && str[i] <= 'Z') {//si es mayuscula
				str2[i] += diferencia;
			}
		}
		i++;
	}
	return str2;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

//PRE: Recibe dos strings
//POS: Devuelve true si el primer string es mayor que el segundo en funcion a la tabla ascii
bool strEsMayor(char* str1, char* str2) {
	bool es = false, fin = false;
	int i = 0, j = 0;
	while (str1[i] != '\0' && str2[j] != '\0' && !es && !fin)
	{
		if (str1[i] == str2[i])
		{
			i++;
		}
		else
		{
			if (str1[i] > str2[i])
			{
				es = true;
			}
			else {
				fin = true;
			}
		}
	}
	if (!es && !fin)
	{
		if (largoStr(str1) > largoStr(str2))
		{
			es = true;
		}
	}
	return es;
}

//PRE: Recibe un vector de strings y un entero
//POS: Ordena el vector de strings de forma ascendente 
void bubblesortVec( char** vecRet, int largo) {
	for (int i = 0; i < largo; i++) {
		for (int j = 0; j < largo - 1; j++) {
			if (strEsMayor(vecRet[j], vecRet[j + 1])) {
				char* aux = copiarStr(vecRet[j]);
				vecRet[j] = copiarStr(vecRet[j + 1]);
				vecRet[j + 1] = aux;
			}
		}
	}
}

char** ordenarVecStrings(char** vecStr, int largoVecStr) {
	char** vecRet = new char* [largoVecStr];
	for (int i = 0; i < largoVecStr;i++) {
		vecRet[i] = copiarStr(vecStr[i]);
	}
	bubblesortVec(vecRet, largoVecStr);
    return vecRet;
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	int* ret = new int[l1+l2];
	int i = 0, j = 0, k = 0;
	if (l1==0 && l2==0 ) {
		ret = NULL;
	}
	else {
		while (i < l1 && j < l2) {
			if (v1[i] == v2[j]) {
				ret[k] = v1[i];
				i++;
				k++;
				ret[k] = v2[j];
				j++;
				k++;
			}
			else {
				if (v1[i] < v2[j]) {
					ret[k] = v1[i];
					i++;
					k++;
				}
				else {
					ret[k] = v2[j];
					j++;
					k++;
				}
			}
		}

		while (i < l1) {
			ret[k] = v1[i];
			i++;
			k++;
		}

		while (j < l2) {
			ret[k] = v2[j];
			j++;
			k++;
		}
	}

	return ret;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	bool fin = false, ret = false;
	int i = 0;
	if (v1 != NULL) {
		for (i; i < l1 && !fin; i++) {
			bool esta = false;
			for (int j = 0; j < l2 && !esta; j++) {
				if (v1[i] == v2[j]) {
					esta = true;
				}
			}
			if (!esta) {// si uno ya no esta, termina el programa
				fin = true;
			}
		}
		if (i == l1) {//si el primer for recorrio el largo de v1, es que todos los elementos estan
			ret = true;
		}
	}
	else {
		ret = true;
	}
	return ret;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
}
