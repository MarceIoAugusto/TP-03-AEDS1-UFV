 #include "pokelista.h"
 #include "pokemon.h"
 #include "saida.h"

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

// <<<<modificar para o TP3<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
 void CarregaDados(FILE* fptr, TipoTreinador *treinadores,TipoPokemon **listaarranjo,int *energia, int *quantidade){
    int cont=0;
    TipoPokemon temp; //variavel temporaria para armazenar o pokemon lido do arquivo
    for(int i=0; i<NUM_TREINADORES; i++){
        leTreinador(fptr,&treinadores[i]);
    }
    fscanf(fptr,"%d",quantidade);
    fscanf(fptr,"%d",energia);
    *listaarranjo = (TipoPokemon*)malloc(*quantidade * sizeof(TipoPokemon)); //o ponteiro agora aponta para um vetor de tipo TipoPokemon.
    if(*listaarranjo == NULL) {
        printf("Erro ao alocar memoria para a lista de pokemons.\n");
        exit(EXIT_FAILURE);
    }
    
    while( (cont<*quantidade) && LePokemon(fptr,&temp)){ // cont<*quantidade impede estourar o vetor caso tenha mais pokemons que o informado
        (*listaarranjo)[cont]=temp;
        cont++;
    }
    if(*quantidade != cont){
        printf("\x1b[31mFLAG:ERRO AO LER POKEMONS.\nQUANTIDADE INFORMADA (%d) DIVERGE DA QUANTIDADE DE POKEMONS DISPONIVEIS PARA LEITURA.\x1b[0m\n", *quantidade);
        printf("\x1b[31mO programa ira continuar, mas a quantidade de pokemons lidos sera %d. \x1b[0m\n",cont);
        *quantidade = cont;
    }
}



int main(){

    clock_t inicio,fim,tempo;// Variaveis para medir o tempo de execução da operacao chave
    TipoTreinador treinadores[NUM_TREINADORES]; // Lista de treinadores
    TipoPokemon *ListaArranjo; // Lista de pokemons do arquivo
    ListaArranjo = NULL; // Inicializa o ponteiro como NULL
    int QuantidadePokemons = 0;
    int EnergiaDisponivel = 0;
    
    char nomearquivo[TAM_ARQUIVO]; // Nome do arquivo de entrada
    Menu();
    scanf("%s", nomearquivo);
    LimparTela();

    // Leitura dos dados do arquivo de entrada

    // <<<<modificar para o TP3<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
    FILE *fptr = fopen(nomearquivo,"r");
    while(fptr == NULL){
        printf("Erro ao abrir o arquivo de entrada\nPossivel nome invalido, tente novamente.\n");
        printf("\nDigite o nome do arquivo de entrada (ex: teste1.txt): ");
        scanf("%s", nomearquivo);
        fptr = fopen(nomearquivo,"r");
        LimparTela();
    }
    CarregaDados(fptr,treinadores,&ListaArranjo,&EnergiaDisponivel,&QuantidadePokemons);
    fclose(fptr);
    
    
    
    
    
    
    
    ImprimeSaida(ListaArranjo, treinadores, melhorequipe, maiorpoder, energiaconsumida,
                    EnergiaDisponivel, tempo, QuantidadePokemons, tamanho_melhor_equipe); 

    return 0; 
}
