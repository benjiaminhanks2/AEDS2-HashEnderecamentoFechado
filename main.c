#include "hash.h"
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
	initHash(&t,calcM(5));
	add(&t,palavras,5);
	print(&t);
	return 0;
}
