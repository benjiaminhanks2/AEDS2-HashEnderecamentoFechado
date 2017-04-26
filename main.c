#include "hash.h"
#include "hashComArquivo.h"
#include <time.h>
#define TAMHASH 23
int main(void)
{
	srand(time(NULL));
	ClosedAdressingHashTable *t;
	initClosedAdressingHash(&t,TAMHASH);
	leArquivo(&t);
	
	print(t->table);
	return 0;
}
