#ifndef CENTROPESQUISA_H
#define CENTROPESQUISA_H

#include <time.h>
#include "pokelista.h"
#include "pokemon.h"

typedef struct {
    PokeLista Simples;
    PokeLista Sofisticado;
} CentroPesquisa;

//getters

// inicializacao e insersao
void InicializaCP(CentroPesquisa *Pokecenter, int n);
void LiberaListaCP(CentroPesquisa *Pokecenter);
void InserePokemonCP(CentroPesquisa *Pokecenter, TipoPokemon *pokemon);

//algoritmos de ordenacao
void BubbleSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal);
void SelectionSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal);
void ShellSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal);
void QuickSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal);
void Particao(int esq, int dir, int *i, int *j, CentroPesquisa *Pokecenter, long int*movdef, long int*compdef, long int*movdes, long int*compdes);
void Ordena(int esq, int dir, CentroPesquisa *Pokecenter, long int*movdef, long int*compdef, long int*movdes, long int*compdes);

//impressao
void ImprimeCPSimples(CentroPesquisa *Pokecenter, int n);
void ImprimeCPSofisticado(CentroPesquisa *Pokecenter, int n);


#endif