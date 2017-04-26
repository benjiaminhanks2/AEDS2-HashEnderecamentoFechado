#ifndef HASHCOMARQUIVO_H_INCLUDED
#define HASHCOMARQUIVO_H_INCLUDED
#define NOMEARQUIVO "arq.dat"
#include "closedAdressingHash.h"
//Funcao responsavel por ler arquivo e gerar tabela hash de endereçamento fechado
void leArquivo(ClosedAdressingHashTable **table);
#endif
