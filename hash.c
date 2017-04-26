#include "hash.h"
#include <string.h>
//Array de numeros primos uteis para se calcular tamanho da tabela Hash
void initHash(HashTable** t,int M){
	*t = (HashTable *)malloc(sizeof(HashTable));
	(*t)->sz = M;
	initListaEncadeada(&(*t)->itens,M);
	for (int i = 0; i < M; i++) {
		(*t)->itens[i].prox = NULL;
		(*t)->itens[i].dados.nome = "";
	}
}
void print(HashTable *t){
	ListaEncadeada *ptr;
	for (int i = 0; i < t->sz; i++) {
		ptr = &t->itens[i];
		printf("%s",ptr->dados.nome);
		while(ptr->prox != NULL){
			ptr = ptr->prox;
			printf(", %s",ptr->dados.nome);
		}
		printf("\n");
	}
}
void searchMatricula(HashTable *t, unsigned int matricula){

}
void searchNome(HashTable *t, Chave nome){

}
