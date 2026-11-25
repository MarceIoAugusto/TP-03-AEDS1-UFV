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
void BubbleSort(CentroPesquisa *Pokecenter, int n, int*movdef, int*compdef, int*movdes, int*compdes, clock_t *tempototal);
void SelectionSort(CentroPesquisa *Pokecenter, int n, int*movdef, int*compdef, int*movdes, int*compdes, clock_t *tempototal);
void ShellSort(CentroPesquisa *Pokecenter, int n, int*movdef, int*compdef, int*movdes, int*compdes, clock_t *tempototal);
void QuickSort(CentroPesquisa *Pokecenter, int n, int*movdef, int*compdef, int*movdes, int*compdes, clock_t *tempototal);
void Particao(int esq, int dir, int *i, int *j, CentroPesquisa *Pokecenter, int*movdef, int*compdef, int*movdes, int*compdes);
void Ordena(int esq, int dir, CentroPesquisa *Pokecenter, int*movdef, int*compdef, int*movdes, int*compdes);



#endif