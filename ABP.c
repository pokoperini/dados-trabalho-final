#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.c"

#include "ABP.h"

nodo *InsereArvoreABP(nodo *a, char palavra[max_palavra], char traducao[max_palavra])
{
    strlwr(palavra); // coloca a palavra como minuscula
    
    if (a == NULL)
    {
        a = (nodo *)malloc(sizeof(nodo));
        strcpy(a->palavra, palavra);
        strcpy(a->traducao, traducao);
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (strcmp(palavra, a->palavra) < 0) // compara a palavra a ser inserida com a palavra do nodo
    {
        a->esq = InsereArvoreABP(a->esq, palavra, traducao);
    }
    else
    {
        a->dir = InsereArvoreABP(a->dir, palavra, traducao);
    }
    return a;
}