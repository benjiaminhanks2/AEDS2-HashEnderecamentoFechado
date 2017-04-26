#include "hashComArquivo.h"
void leArquivo(ClosedAdressingHashTable **table){
	FILE* arquivo;
	if ((arquivo = fopen(NOMEARQUIVO,"r")) == NULL){
		printf("Leitura falhou\n");
		return;
	}
	char temp_nome[40];
	Item itemTemp;
	int chave_sz;

	while (!feof(arquivo)) {
		fscanf(arquivo,"%u - %s\n",
				&itemTemp.matricula,
				temp_nome
				);
		for(chave_sz = 0; temp_nome[chave_sz] != '\0'; chave_sz++){} 	//Capturando tamanho do nome
		if((itemTemp.nome = (Chave)malloc((chave_sz+1)*sizeof(char))) == NULL) printf("FAIL\n");				//Alocando espaço para o nome
		itemTemp.nome[chave_sz] = '\0';							//Determinando fim da string
		for(chave_sz = 0; temp_nome[chave_sz] != '\0'; chave_sz++){
			itemTemp.nome[chave_sz] = temp_nome[chave_sz];			//copiando valor da string
		}
		 									//criando No e inserindo à arvore
		addItem(*table,itemTemp);
											//add item AGORA
	}

	fclose(arquivo);
}
