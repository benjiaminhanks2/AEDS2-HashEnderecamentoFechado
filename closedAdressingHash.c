#include "closedAdressingHash.h"
#include "ListaEncadeada.h"
void initClosedAdressingHash(ClosedAdressingHashTable** t,int M){
	*t = (ClosedAdressingHashTable *)malloc(sizeof(ClosedAdressingHashTable));
	initHash(&(*t)->table,M);
	(*t)->pesos = (unsigned int *)malloc(sizeof(unsigned int));		//Primeira posicao vetor possui o tamanho do vetor
	(*t)->pesos[0] = 0;
}
void addItem(ClosedAdressingHashTable *t, Item item){
	int sum = 0;
	for (unsigned int i = 0; item.nome[i] != '\0'; i++) {
		sum += item.nome[i]*peso(i,t);
	}
	if(strcmp(t->table->itens[sum % t->table->sz].dados.nome,"")){
		antiColisoes(&t->table->itens[sum % t->table->sz],item);	//Campo possui item
		return;
	}
	t->table->itens[sum % t->table->sz].dados = item;	//Se Campo estiver vazio
	t->table->itens[sum % t->table->sz].prox = NULL;
}
unsigned int peso(unsigned int i, ClosedAdressingHashTable *t){	//realocar vetor para o maior tamanho de i passado
	if (++i > t->pesos[0]){	//indice 0 possui como valor o tamanho do vetor - 1 ou, em outras palavras, o índice do último peso. i é incrementado para pular posicao 0
		if((t->pesos =(unsigned int*) realloc((void*)t->pesos,(i+1)*sizeof(unsigned int)))==NULL) printf("FAIL\n");
		else t->pesos[0] = i;
		return ( t->pesos[i] = i*(rand()/10000) );
	}else{
		return (t->pesos[i]);
	}
}
void antiColisoes(ListaEncadeada *i,Item item){
	if(i->prox == NULL){
		ListaEncadeada_Insere(&(i->prox), item);
		return;
	}
	antiColisoes(i->prox, item);
}
