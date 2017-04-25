#include "hash.h"
#define TAMHASH 23
int main(void)
{
	Table t;
	Chave palavras[] = {
			"Ola",
			"Fadoa",
			"Victor",
			"SuperHomem",
			"Brasil"
			};
#ifndef TAMHASH
	initHash(&t,calcM(5));
#else
	initHash(&t,TAMHASH);
#endif
	add(&t,palavras,5);
	print(&t);
	return 0;
}
