#include "EjerciciosArboles.h"

//PRE: Recibe un dos enteros
//POS:Devuelve el maximo de ambos
int max(int n1, int n2) {
	if (n1>=n2) {
		return n1;
	}
	else {
		return n2;
	}
}

int altura(NodoAB* raiz){
	if (raiz==NULL) {
		return 0;
	}
	else {
		return 1 + max(altura(raiz->izq), altura(raiz->der));
	}
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if(p==NULL&&q==NULL){
		return true;
	}
	else {
		if(p==NULL&&q!=NULL){
			return false;
		}
		else {
			if (p != NULL && q == NULL) {
				return false;
			}
			else {
				return p->dato == q->dato && sonIguales(p->izq, q->izq) && sonIguales(p->der, q->der);
			}
		}
	}
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {
	if (raiz==NULL) {
		return sum == 0;
	}
	else {
		if (raiz->izq == NULL && raiz->der == NULL) {
			return sum - raiz->dato == 0;
		}
		else {
			if (raiz->izq != NULL && raiz->der == NULL) {
				return existeCaminoConSuma(raiz->izq,sum-raiz->dato);
			}
			else {
				if (raiz->izq == NULL && raiz->der != NULL) {
					return existeCaminoConSuma(raiz->der, sum - raiz->dato);
				}
				else {
					if (raiz->izq != NULL && raiz->der != NULL) {
						return existeCaminoConSuma(raiz->izq, sum - raiz->dato) || existeCaminoConSuma(raiz->der, sum - raiz->dato);
					}
				}
			}
		}
	}
	return false;
}

bool esArbolBalanceado(NodoAB *raiz) {
	if (raiz == NULL) {
		return true;
	}
	else {
		int alturaIzq = altura(raiz->izq);
		int alturaDer = altura(raiz->der);
		int diferencia = alturaIzq - alturaDer;
		if (diferencia <= 1 && diferencia >=-1) {
			return (esArbolBalanceado(raiz->izq) && esArbolBalanceado(raiz->der));
		} 
		else {
			return false;
		}
	}
}

void insertarEnNivel(NodoAB* a,int k, NodoLista* &l) {
	if (a != NULL) {
		if (k == 1) {
			NodoLista* nodo = new NodoLista;
			nodo->dato = a->dato;
			nodo->sig = l;
			l = nodo;
		}
		else {
			insertarEnNivel(a->der, k - 1, l);
			insertarEnNivel(a->izq, k - 1, l);
		}
	}
}

NodoLista* enNivel(NodoAB *a, int k) {
	NodoLista* ret = NULL;
	if (a == NULL)return NULL;
	insertarEnNivel(a,k, ret);
	return ret;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}


NodoLista* camino(NodoAB *arbol, int x) {
	NodoLista* ret = NULL;
	if (arbol != NULL) {
		if (x == arbol->dato) {
			NodoLista* nuevoNodo = new NodoLista;
			nuevoNodo->dato = x;
			nuevoNodo->sig = ret;
			ret = nuevoNodo;
			return ret;
		}
		else {
			if (x > arbol->dato) {
				NodoLista* nuevoNodo = new NodoLista;
				nuevoNodo->dato = arbol->dato;
				nuevoNodo->sig = camino(arbol->der, x);;
				ret = nuevoNodo;
			}
			else {
				NodoLista* nuevoNodo = new NodoLista;
				nuevoNodo->dato = arbol->dato;
				nuevoNodo->sig = camino(arbol->izq, x);;
				ret = nuevoNodo;
			}
			return ret;
		}
	}
	else {
		return ret;
	}
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	if (A!=NULL){
		if (A->izq == NULL && A->der!= NULL) {
			NodoAB* aBorrar = A;
			A = A->der;
			delete aBorrar;
		}
		else {
			if (A->izq != NULL && A->der == NULL) {
				NodoAB* aBorrar = A;
				A = A->izq;
				delete aBorrar;
			}
			else {
				if (A->izq == NULL && A->der == NULL) {
					NodoAB* aBorrar = A;
					A = NULL;
					delete aBorrar;
				}
				else {
					NodoAB* nuevaRaiz = A->izq;
					NodoAB* antNuevaRaiz = NULL;
					while (nuevaRaiz->der != NULL) {
						antNuevaRaiz = nuevaRaiz;
						nuevaRaiz = nuevaRaiz->der;
					}
					NodoAB* aBorrar = nuevaRaiz;
					if (antNuevaRaiz != NULL) {
						antNuevaRaiz->der = nuevaRaiz->izq;
						A->dato = nuevaRaiz->dato;
						delete aBorrar;
					}
					else {
						A->dato = nuevaRaiz->dato;
						A->izq = NULL;
						delete aBorrar;
					}
				}
			}
		}
	}
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	if (a == NULL)return -1;
	else {
		if (a->dato == n) {
			if (a->der != NULL) {
				if (a->der->izq == NULL) {
					return a->der->dato;
				}
				else {
					return sucesor(a->der->izq, n);;
				}
			}
			else {
				return -1;
			}
		}
		else {
			if (a->dato > n) {
				int ret= sucesor(a->izq,n);
				if (ret == -1) {
					return a->dato;
				}
				else {
					return ret;
				}
			}
			else {
				return sucesor(a->der, n);
			}
		}
	}
}

//PRE: Recibe un arbol binario, un array, y dos enteros (nivel maximo y nivel en el que estamos parados)
//POS: Rellena un array con la cantidad de nodos por nivel, coincidiendo los indices del array con los niveles
void contarNivel(NodoAB* a, int* & array, int nivelHasta, int nivelActual) {
	if (a == NULL)return;
	else {
		if (nivelActual <= nivelHasta ) {
			array[nivelActual] = array[nivelActual] + 1;
		}
		contarNivel(a->izq, array, nivelHasta, nivelActual+1);
		contarNivel(a->der, array, nivelHasta, nivelActual + 1);
	}
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	if (raiz == NULL)return 0;
	else {
		int* arrayNiveles = new int[nivelHasta + 1];
		for (int i = 0; i <= nivelHasta; i++) {
			arrayNiveles[i] = 0;
		}
		contarNivel(raiz, arrayNiveles, nivelHasta, 1);
		int max = 0;
		int nivelMax=1;
		for (int i = 1; i <= nivelHasta; i++) {
			if (arrayNiveles[i] > max) {
				max = arrayNiveles[i];
				nivelMax = i;
			}
		}
		return nivelMax;
	}
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	if (raiz == NULL)return 0;
	else return max(1 + alturaAG(raiz->ph), alturaAG(raiz->sh));
}

int sumaPorNiveles(NodoAG* raiz){
	int suma = 0;
	if (raiz == NULL)return 0;
	else {
		suma = suma - raiz->dato;
		return suma = suma + sumaPorNiveles(raiz->sh) - sumaPorNiveles(raiz->ph);
	}
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	if (a == NULL && l == NULL)return true;
	else {
		if (a != NULL && l == NULL)return true;
		else {
			if (a == NULL && l != NULL)return false;
			else {
				if (a->dato == l->dato) {
					return esPrefijo(a->ph, l->sig);
				}
				else {
					return esPrefijo(a->sh, l);
				}
			}
		}
	}
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	NodoLista* ret = NULL;
	if (arbolGeneral == NULL)return ret;
	else {
		if (arbolGeneral->dato == dato) {
			NodoLista* nodo = new NodoLista;
			nodo->dato = arbolGeneral->dato;
			nodo->sig = ret;
			ret = nodo;
		}
		else {
			ret = caminoAG(arbolGeneral->ph, dato);
			if (ret == NULL) {
				ret = caminoAG(arbolGeneral->sh, dato);
			}
			else {
					NodoLista* nodo = new NodoLista;
					nodo->dato = arbolGeneral->dato;
					nodo->sig = ret;
					ret = nodo;
				
			}
		}
	}
	return ret;
}

//PRE: Recibe un arbol general, un array, y dos enteros (nivel maximo y nivel en el que estamos parados)
//POS: Rellena un array con la cantidad de nodos por nivel, coincidiendo los indices del array con los niveles
void arrayAuxMasNodosAG(NodoAG* a, int* & array, int nivelHasta, int nivelActual) {
	if (a == NULL)return;
	else {
		if (nivelActual <= nivelHasta ) {
			array[nivelActual] = array[nivelActual] + 1;
		}
		arrayAuxMasNodosAG(a->ph, array, nivelHasta, nivelActual+1);
		arrayAuxMasNodosAG(a->sh, array, nivelHasta, nivelActual);
	}
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	if (arbolGeneral == NULL)return 0;
	else{
		int altura = alturaAG(arbolGeneral);
		int* arrayAux = new int[altura + 1];
		for (int i = 0; i <= altura; i++) {
			arrayAux[i] = 0;
		}
		arrayAuxMasNodosAG(arbolGeneral, arrayAux, altura, 1);
		int max = 0;
		int nivelMax = 1;
		for (int i = 1; i <= altura; i++) {
			if (arrayAux[i] > max) {
				max = arrayAux[i];
				nivelMax = i;
			}
		}
		return nivelMax;
	}
}

