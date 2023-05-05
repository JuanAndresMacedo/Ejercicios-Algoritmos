#include "EjerciciosListas.h"

//PRE: Recibe una lista y un entero
//POS: Inserta un nodo con dicho entero al inicio de una lista
void insertarPrincipio(NodoLista*& nuevaLista, int dato) {
	NodoLista* nuevoNodo = new NodoLista;
	nuevoNodo->dato = dato;
	nuevoNodo->sig = nuevaLista;
	nuevaLista = nuevoNodo;
}

NodoLista* invertirParcial(NodoLista* l)
{
	NodoLista* nuevaLista = NULL;
	if (l != NULL) {
		while (l->sig != NULL) {
			insertarPrincipio(nuevaLista, l->dato);
			l = l->sig;
		}
	}
	return nuevaLista;
}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int& n)
{
	if (n >= 1) {
		if (lista != NULL) {
			eliminarNesimoDesdeElFinal(lista->sig, n);
			n--;
			if (n == 0) {
				NodoLista* borrar = lista;
				lista = lista->sig;
				delete borrar;
			}
		}
	}
}

//PRE: Recibe un entero y una lista
//POS: Inserta un nodo con dicho dato de manera ordenada en una lista
void insertarOrdenado(int dato, NodoLista*& ret) {
	if (ret == NULL) {
		insertarPrincipio(ret, dato);
	}
	else {
		if (dato <= ret->dato) {
			insertarPrincipio(ret, dato);
		}
		else {
			insertarOrdenado(dato, ret->sig);
		}
	}
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l)
{
	NodoLista* ret = NULL;
	while (l != NULL) {
		insertarOrdenado(l->dato, ret);
		l = l->sig;
	}
	return ret;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	if (l != NULL) {
		NodoLista* i = l;
		NodoLista* j = l;
		NodoLista* min = l;
		while (i != NULL) {
			j = i;
			min = j;
			while (j != NULL) {
				if (j->dato < min->dato) {
					min = j;
				}
				j = j->sig;
			}
			if (min->dato < i->dato) {
				int aux = i->dato;
				i->dato = min->dato;
				min->dato = aux;
			}
			i = i->sig;
		}
	}
}

//PRE: Recibe un puntero a la posicion final de una lista, un puntero a la posicion inicial de la lista y un entero
//POS: Inserta un elemento al final de una lista 
void insertarFinal(NodoLista*& fin, NodoLista*& l, int dato) {
	if (fin == l) {
		if (fin == NULL) {
			insertarPrincipio(l, dato);
			fin = l;
		}
		else {
			NodoLista* nuevoNodo = new NodoLista;
			nuevoNodo->dato = dato;
			fin = nuevoNodo;
			l->sig = nuevoNodo;
		}
	}
	else {
		NodoLista* nuevoNodo = new NodoLista;
		nuevoNodo->dato = dato;
		fin->sig = nuevoNodo;
		fin = nuevoNodo;
	}
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* ret = NULL;
	NodoLista* fin = ret;
	while (l1 != NULL && l2 != NULL) {
		if (l1->dato <= l2->dato) {
			insertarFinal(fin, ret, l1->dato);
			l1 = l1->sig;
		}
		else {
			insertarFinal(fin, ret, l2->dato);
			l2 = l2->sig;
		}
	}

	while (l1 != NULL) {
		insertarFinal(fin, ret, l1->dato);
		l1 = l1->sig;
	}

	while (l2 != NULL) {
		insertarFinal(fin, ret, l2->dato);
		l2 = l2->sig;
	}
	return ret;
}

//PRE: Recibe un nodo apuntando a NULL y un entero
//POS: Crea un nuevo nodo con el entero recibido
void crearNodo(NodoLista*& ret, int dato) {
	ret = new NodoLista;
	ret->dato = dato;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	NodoLista* ret = NULL;
	if (l1 == NULL && l2 == NULL) {
		return NULL;
	}
	else {
		if (l1 == NULL && l2 != NULL) {
			crearNodo(ret, l2->dato);
			ret->sig = intercalarRec(l1, l2->sig);
		}
		else {
			if (l1 != NULL && l2 == NULL) {
				crearNodo(ret, l1->dato);
				ret->sig = intercalarRec(l1->sig, l2);
			}
			else {
				if (l1->dato <= l2->dato) {
					crearNodo(ret, l1->dato);
					ret->sig = intercalarRec(l1->sig, l2);
				}
				else {
					crearNodo(ret, l2->dato);
					ret->sig = intercalarRec(l1, l2->sig);
				}
			}
		}
	}
	return ret;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	NodoLista* ret = NULL;
	if (l1==NULL && l2==NULL) {
		return NULL;
	}
	else {
		if (l1 != NULL && l2 == NULL) {//Si hay algo en l1 y no en l2
			if (l1->sig!=NULL) {
				if (l1->dato == l1->sig->dato) {
					return exor(l1->sig, l2);//Si el elemento esta repetido avanza en l1
				}
				else {//Si no esta repetido lo agrega
					crearNodo(ret,l1->dato);
					ret->sig = exor(l1->sig, l2);
				}
			}
			else {
				crearNodo(ret, l1->dato);
				ret->sig = exor(l1->sig, l2);
			}
		}
		else {
			if (l1 == NULL && l2 != NULL) {//Si hay algo en l2 y no en l1
				if (l2->sig != NULL) {
					if (l2->dato == l2->sig->dato) {
						return exor(l1, l2->sig);//Si el elemento esta repetido avanza en l2
					}
					else {
						crearNodo(ret, l2->dato);
						ret->sig = exor(l1, l2->sig);//Si no esta repetido lo agrega
					}
				}
				else {
					crearNodo(ret, l2->dato);
					ret->sig = exor(l1, l2->sig);//Si no esta repetido lo agrega
				}
			}
			else {
				if (l1->dato==l2->dato) {
					if (l1->sig != NULL) {
						if (l1->dato == l1->sig->dato) {
							return exor(l1->sig, l2);//Si el elemento esta repetido avanza en l1
						}
						else {
							if (l2->sig != NULL) {
								if (l2->dato == l2->sig->dato) {
									return exor(l1, l2->sig);//Si el elemento esta repetido avanza en l2
								}
								else {
									return exor(l1->sig, l2->sig);
								}
							}
						}
					}
					else {
						if (l2->sig != NULL) {
							if (l2->dato == l2->sig->dato) {
								return exor(l1, l2->sig);//Si el elemento esta repetido avanza en l2
							}
							else {
								return exor(l1->sig, l2->sig);
							}
						}
					}
				}
				else {
					if (l1->dato < l2->dato) {
						if (l1->sig != NULL) {
							if (l1->dato == l1->sig->dato) {
								return exor(l1->sig, l2);//Si el elemento esta repetido avanza en l1
							}
							else {
								crearNodo(ret, l1->dato);
								ret->sig = exor(l1->sig, l2);
							}
						}
						else {
							crearNodo(ret, l1->dato);
							ret->sig = exor(l1->sig, l2);
						}
					}
					else {
						if (l2->sig != NULL) {
							if (l2->dato == l2->sig->dato) {
								return exor(l1, l2->sig);//Si el elemento esta repetido avanza en l2
							}else{
								crearNodo(ret, l2->dato);
								ret->sig = exor(l1, l2->sig);
							}
						}
						else {
							crearNodo(ret, l2->dato);
							ret->sig = exor(l1, l2->sig);
						}
					}
				}
			}
		}
	}
	return ret;
}

//PRE: Recibe una lista
//POS: Elimina los primeros dos elementos de una lista
void eliminarDuplicadosPar(NodoLista * &l) {
		NodoLista* borrar1 = l;
		NodoLista* borrar2 = l->sig;
		l = l->sig->sig;
		delete borrar1;
		delete borrar2;
}

//PRE: Recibe una lista
//POS: Elimina el primer elemento de una lista
void eliminarDuplicadosImpar(NodoLista*& l) {
	NodoLista* borrar = l;
	l = l->sig;
	delete borrar;
}

	void eliminarDuplicadosListaOrdenadaDos(NodoLista * &l)
	{
		if (l!=NULL) {
			if (l->sig != NULL) {
				if (l->sig->sig != NULL) {
					if ((l->dato == l->sig->dato) && (l->dato == l->sig->sig->dato)) {//si el num de duplicados es impar
						eliminarDuplicadosImpar(l);
						eliminarDuplicadosListaOrdenadaDos(l);
					}
					else {
						if (l->dato == l->sig->dato) {//si el num de duplicados es par
							eliminarDuplicadosPar(l);
							eliminarDuplicadosListaOrdenadaDos(l);
						}
						else {//si no esta duplicado
							eliminarDuplicadosListaOrdenadaDos(l->sig);
						}
					}
				}
				else {
					if (l->dato == l->sig->dato) {
						eliminarDuplicadosPar(l);
						eliminarDuplicadosListaOrdenadaDos(l);
					}
					else {
						eliminarDuplicadosListaOrdenadaDos(l->sig);
					}
				}
			}
		}
	}

	bool palindromo(NodoLista * l)
	{
		// IMPLEMENTAR SOLUCION
		return false;
	}

	//PRE: Recibe una lista y una secuencia(lista)
	//POS: Retorna si la secuencia existe en dicha lista
	bool existeSecuencia(NodoLista* l, NodoLista* secuencia) {
		bool existe = true;
		while (l!=NULL && secuencia !=NULL && existe) {
			if (l->dato != secuencia->dato) {
				existe = false;
			}
			l = l->sig;
			secuencia = secuencia->sig;
		}
		if(l==NULL&&secuencia!=NULL){
			existe = false;
		}
		return existe;
	}

	void eliminarSecuencia(NodoLista * &l, NodoLista * secuencia)
	{
		if (l != NULL && secuencia != NULL) {
			if (l->dato==secuencia->dato) {
				if (existeSecuencia(l,secuencia)) {
					NodoLista* aBorrar = l;
					l = l->sig;
					delete aBorrar;
					eliminarSecuencia(l, secuencia->sig);
				}
				else {
					eliminarSecuencia(l->sig, secuencia);
				}
			}
			else {
				eliminarSecuencia(l->sig, secuencia);
			}
		}
	}

	void moverNodo(NodoLista * &lista, unsigned int inicial, unsigned int final)
	{
		// IMPLEMENTAR SOLUCION
	}
