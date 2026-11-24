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
void BubbleSort(CentroPesquisa *Pokecenter, int n);
void SelectionSort(CentroPesquisa *Pokecenter, int n);
void ShellSort(CentroPesquisa *Pokecenter, int n,clock_t* TempoTotal);
void QuickSort(CentroPesquisa *Pokecenter, int n);
void Particao(int esq, int dir, int *i, int *j, CentroPesquisa *Pokecenter);
void Ordena(int esq, int dir, CentroPesquisa *Pokecenter);



#endif