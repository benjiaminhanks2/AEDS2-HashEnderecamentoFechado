#include "hash.h"
#include <string.h>
//Array de numeros primos uteis para se calcular tamanho da tabela Hash
void initHash(HashTable** t,int M){
	*t = (HashTable*)malloc(sizeof(HashTable));
	(*t)->sz = M;
	initListaEncadeada(&(*t)->itens,M);
	for (int i = 0; i < M; i++) {
		(*t)->itens[i].prox = NULL;
		(*t)->itens[i].dados.nome = "";
	}
}
void printTabela(HashTable* t){
	ListaEncadeada *ptr;
	for (int i = 0; i < t->sz; i++){
		ptr = &t->itens[i];
		printf("%s",ptr->dados.nome);
		while(ptr->prox != NULL){
			ptr = ptr->prox;
			printf(", %s",ptr->dados.nome);
		}
		printf("\n");
	}
}
void print(HashTable* t){
	ListaEncadeada *ptr;
	int char_index = 0, printed_counter = 0;
	for (int i = 0; i < t->sz; i++){
		ptr = &t->itens[i];

		while(ptr->dados.nome[char_index] != '\n' && ptr->dados.nome[char_index] != '\0'){
			printf("%c", ptr->dados.nome[char_index]);
			char_index++;
		}
		if(char_index > 0){
			printed_counter++;
		}

		while(ptr->prox != NULL){
			ptr = ptr->prox;
			printf(", %s",ptr->dados.nome);
		}
		if(printed_counter > 0){
			printf("\n");
		}
		printed_counter = 0;
		char_index = 0;
	}
}

int searchMatricula(HashTable* t, unsigned int matricula){ //Retorna 1 caso matricula seja encontrada, 0 caso nao esteja na lista
	int hash_index = 0, hash_tam = t->sz;        //e retorna -1 caso haja erro.
	ListaEncadeada* ptr;
	for(hash_index=0; hash_index<hash_tam; hash_index++){
		ptr = &t->itens[hash_index];
		if(ptr == NULL){
			return -1;
		}
		do{
			if(ptr->dados.matricula == matricula){
				return 1;
			}
			ptr = ptr->prox;
		}while(ptr != NULL);
	}
	return 0;
}

int searchNome(HashTable* t, Chave nome){
	int hash_index = 0, hash_tam = t->sz;        //e retorna -1 caso haja erro.
	ListaEncadeada* ptr;
	for(hash_index=0; hash_index<hash_tam; hash_index++){
		ptr = &t->itens[hash_index];
		if(ptr == NULL){
			return -1;
		}
		do{
			if(!strcmp(ptr->dados.nome, nome)){
				return 1;
			}
			ptr = ptr->prox;
		}while(ptr != NULL);
	}
	return 0;
}
