#include "hash.h"
#include <string.h>
int primos[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547};
void initHash(Table *t,int M){
	t->sz = M;
	t->itens = (Item *)malloc(sizeof(Item) * M);
	for (int i = 0; i < M; i++) {
		t->itens[i].prox = NULL;
		t->itens[i].val = "";
	}
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
int peso(int i){
	return 	i*13;
}
void transf(Table *t, Chave c){
	int sum = 0;
	for (int i = 0; c[i] != '\0'; i++) {
		sum += c[i]*peso(i);
	}
	if(strcmp(t->itens[sum % t->sz].val,"")){
		antiColisoes(&t->itens[sum % t->sz],c);
		return;
	}
	t->itens[sum % t->sz].val = c;
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
	while(primos[i++] < n){}
	return primos[i-1];
}
