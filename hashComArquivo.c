#include "hashComArquivo.h"
Table* leArquivo(){
	FILE* arquivo;
	if ((arquivo = fopen(NOME_ARQUIVO,"r")) == NULL){
		printf("Leitura falhou\n");
		return NULL;
	}
	Table *table;
	char temp_nome[40];
	Chave chaveTemp;
	int chave_sz;

	while (!feof(arquivo)) {
		fscanf(arquivo,"%u - %s\n",
				&temp_nome,
				temp_nome
				);
		for(chave_sz = 0; temp_nome[chave_sz] != '\0'; chave_sz++){} 	//Capturando tamanho do nome
		chaveTemp = (Chave)malloc((chave_sz+1)*sizeof(char));				//Alocando espaço para o nome
		chaveTemp[chave_sz] = '\0';							//Determinando fim da string
		for(chave_sz = 0; temp_nome[chave_sz] != '\0'; chave_sz++){
			chaveTemp[chave_sz] = temp_nome[chave_sz];			//copiando valor da string
		}
#ifndef TAMHASH
	initHash(&t,calcM(5));
#else
	initHash(&t,TAMHASH);
#endif
		 									//criando No e inserindo à arvore
	}
	fclose(arquivo);
	return arvore;
}
