#include "pokelista.h"

void InicializaLista(PokeLista *Lista, int n) { /* Inicializa a lista com tamanho n*/
    Lista->Arranjo=(TipoPokemon*)malloc(n * sizeof(TipoPokemon));
    Lista->Ultimo=0;
    Lista->MaxTam=n;
}

void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon) { /* Insere o Pokemon ao Final da Lista*/
    if(Lista->Ultimo == Lista->MaxTam){
        printf("Erro, tentativa de insersão com arranjo cheio, pokemon não adicionado.");
        return;
    }
    Lista->Arranjo[Lista->Ultimo] = *pokemon;
    Lista->Ultimo++;
}

//Percorre a lista e Imprime todos os pokemons na tela
void ImprimeLista(PokeLista *Lista) {
    int curr=0;

    while (curr < Lista->Ultimo) { // Ultimo define a ultima posicao livre, deve-se imprimir até o indice anterior
        ImprimePokemon(&Lista->Arranjo[curr]);
        curr ++;
    }
}

//Percorre a lista e Imprime todos os pokemons no arquivo de saida.txt
void ImprimeListaFile(FILE *saida, PokeLista *Lista) {
    int curr=0;

    while (curr < Lista->Ultimo) { // Ultimo define a ultima posicao livre, deve-se imprimir até o indice anterior
        ImprimePokemonSaida(saida , &Lista->Arranjo[curr]);
        curr ++;
    }
}

//Verifica se a lista esta vazia
int ListaEVazia(PokeLista *Lista) {
    if (Lista->Ultimo==0) {
        return 1;
    } else
        return 0;
}

// Libera o arranjo 
void LiberaLista(PokeLista *Lista) {
    free(Lista->Arranjo);
}

TipoPokemon *BuscaPokemon(PokeLista *Lista, int x){
    return &Lista->Arranjo[x];
}