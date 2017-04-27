#include "hash.c"
#include "hashComArquivo.c"
#include <time.h>
#define TAMHASH 23
int main(void)
{
	srand(time(NULL));
	ClosedAdressingHashTable *t;
	initClosedAdressingHash(&t,TAMHASH);
	leArquivo(&t);

	searchMatricula(t->table, 4)? printf("Matricula Presente\n") : printf("Matricula Ausente\n");
	searchNome(t->table, "Camila")? printf("Nome Encontrado\n") : printf("Nome Ausente\n");

	print(t->table);
	return 0;
}
