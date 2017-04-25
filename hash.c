#include "hash.h"
#include <string.h>
//Array de numeros primos uteis para se calcular tamanho da tabela Hash
const int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547};
void initHash(Table *t,int M){
	t->sz = M;
	t->itens = (Item *)malloc(sizeof(Item) * M);
	for (int i = 0; i < M; i++) {
		t->itens[i].prox = NULL;
		t->itens[i].val = "";
	}
	t->pesos = (unsigned int *)malloc(sizeof(unsigned int));		//Primeira posicao vetor possui o tamanho do vetor
}
void add(Table *t, Chave *c, int tam){
	int i;
	for (i = 0; i < tam; i++) {
		transf(t,c[i]);
	}
}
void print(Table *t){
	Item *ptr;
	for (int i = 0; i < t->sz; i++) {
		ptr = &t->itens[i];
		printf("%s",ptr->val);
		while(ptr->prox != NULL){
			ptr = ptr->prox;
			printf(", %s",ptr->val);
		}
		printf("\n");
	}
}
unsigned int peso(unsigned int i, Table *t){	//realocar vetor para o maior tamanho de i passado
	if (i > t->pesos[0]){
		realloc(t->pesos,sizeof(unsigned int)*i);
	}
}
void transf(Table *t, Chave c){
	int sum = 0;
	for (int i = 0; c[i] != '\0'; i++) {
		sum += c[i]*peso(i,t);
	}
	if(strcmp(t->itens[sum % t->sz].val,"")){
		antiColisoes(&t->itens[sum % t->sz],c);	//Campo possui item
		return;
	}
	t->itens[sum % t->sz].val = c;	//Se Campo estiver vazio
}
void antiColisoes(Item *i,Chave c){
	if(i->prox == NULL){
		i->prox = (Item *)malloc(sizeof(Item));
		i->prox->prox = NULL;
		i->prox->val = c;
		return;
	}
	antiColisoes(i->prox, c);
}
int calcM(int n){
	int i = 0;
	while(primos[i++] <= n){}
	return primos[i-1];
}
