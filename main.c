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

	add(&t,palavras,5);
	print(&t);
	return 0;
}
