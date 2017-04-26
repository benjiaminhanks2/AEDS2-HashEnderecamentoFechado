#include "listaEncadeada.h"
void initListaEncadeada(ListaEncadeada **lista, int M){
	*lista = (ListaEncadeada *)malloc(sizeof(ListaEncadeada) * M);
}
