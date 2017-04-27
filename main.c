#include "hash.h"
#include "hashComArquivo.c"
#include <time.h>
#define TAMHASH 23
int main(void)
{
	srand(time(NULL));
	ClosedAdressingHashTable *t;
	initClosedAdressingHash(&t,TAMHASH);
	leArquivo(&t);
	searchMatricula(t->table, 4)? printf("- Matricula Presente\n") : printf("Matricula Ausente\n");
	searchNome(t->table, "Camila")? printf("- Nome Encontrado\n") : printf("Nome Ausente\n");
	putchar('\n');
	printf("Itens na tabela (Sem quebra de linha):\n");
	print(t->table);
	printf("\nItens na tabela:\n");
	printf("Tabela Hash com listas vazias:\n");
	printTabela(t->table);
	return 0;
}
