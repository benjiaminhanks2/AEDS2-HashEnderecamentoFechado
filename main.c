#include "hash.c"
#include "hashComArquivo.c"
#define TAMHASH 23
int main(void)
{
	Table *t;
	initHash(&t,TAMHASH);
	leArquivo(&t);
	
	print(t);
	return 0;
}
