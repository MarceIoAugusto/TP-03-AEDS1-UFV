#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemon.h"


typedef struct {
    TipoPokemon *Arranjo;
    int Ultimo, MaxTam;
} PokeLista;

void InicializaLista(PokeLista *Lista, int n);// Inicializa a celula cabeça da lista encadeada
void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon);// Insere o Pokemon ao final da lista
TipoPokemon *BuscaPokemon(PokeLista *Lista, int x); // Recebe uma PokeLista e retorna o endereco do pokemon no indice x
void ImprimeLista(PokeLista *Lista); // Imprime a lista de pokemons na tela
void ImprimeListaFile(FILE *saida, PokeLista *Lista);// Imprime a lista de pokemons no arquivo de saida
int ListaEVazia(PokeLista *Lista);// Retorna 1 se a lista estiver vazia, 0 caso contrário
void LiberaLista(PokeLista *Lista);// Libera a memória alocada para a lista de pokemons

#endif
