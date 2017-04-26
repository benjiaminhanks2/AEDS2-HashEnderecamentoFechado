#include "hash.h"
#include "hashComArquivo.h"
#include <time.h>
#define TAMHASH 23
int main(void)
{
	srand(time(NULL));
	Table *t;
	initHash(&t,TAMHASH);
	leArquivo(&t);
	
	print(t);
	return 0;
}
