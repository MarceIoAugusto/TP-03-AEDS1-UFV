#include "centropesquisa.h"

//Inicializacao
void InicializaCP(CentroPesquisa *Pokecenter, int n) {
    InicializaLista(&Pokecenter->Simples, n);
    InicializaLista(&Pokecenter->Sofisticado, n);
    return;
}

//Insersão ao final
void InserePokemonCP(CentroPesquisa *Pokecenter, TipoPokemon *pokemon){
    InserePokemon(&Pokecenter->Simples, pokemon);
    InserePokemon(&Pokecenter->Sofisticado, pokemon);
}

//Libera memoria alocada
void LiberaListaCP(CentroPesquisa *Pokecenter){
    LiberaLista(&Pokecenter->Simples);
    LiberaLista(&Pokecenter->Sofisticado);
}

//OBS.: Seria possivel simplificar a logica de comparacao para :
//      se ((poder a > poder b) ou (poder a == poder b E numero a > numero b)) entao faz a troca.
//      Mas atrapalharia a contagem exata de movimentacoes e comparacoes. (Algoritmos de ordenação)

void BubbleSort(CentroPesquisa *Pokecenter, int n){
    int i,j; 
    int compdes=0; //COMPARACAO CAUSADA PELO CRITERIO DE DESEMPATE
    int movdes=0; //MOVIMENTACAO CAUSADA PELO CRITERIO DE DESEMPATE
    int compdef=0; //CONTA APENAS A COMPARACAO PADRAO DO BOLHA
    int movdef=0; //CONTA APENAS A MOVIMENTACAO PAREAO DO BOLHA
    TipoPokemon aux;

    for(i=0;i<n-1;i++){ //n-1 passadas no array
        for(j=1;j<n-i;j++){ //diminui a cada passada
            compdef++;
            if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j-1))) >= (getPokePoder(BuscaPokemon(&Pokecenter->Simples, j)))) //verifica se o poder anterior é maior ou igual ao proximo
                compdes++;
                if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j-1))) == (getPokePoder(BuscaPokemon(&Pokecenter->Simples, j)))){  //se as chaves são iguais, aplicamos o desempate no numero da pokedex
                    compdes++;
                    if((getPokeNumero(BuscaPokemon(&Pokecenter->Simples, j-1))) > (getPokeNumero(BuscaPokemon(&Pokecenter->Simples, j)))){
                        aux= *BuscaPokemon(&Pokecenter->Simples, j);
                        *BuscaPokemon(&Pokecenter->Simples, j) = *BuscaPokemon(&Pokecenter->Simples, j-1);
                        *BuscaPokemon(&Pokecenter->Simples, j-1)= aux;
                        movdes+=3;
                    }
                }
                else{
                    aux=*BuscaPokemon(&Pokecenter->Simples, j);
                    *BuscaPokemon(&Pokecenter->Simples, j) = *BuscaPokemon(&Pokecenter->Simples, j-1);
                    *BuscaPokemon(&Pokecenter->Simples, j-1)= aux;
                    movdef+=3;
                }
        }
    }
    
}

void SelectionSort(CentroPesquisa *Pokecenter, int n){
    int i,j;
    int compdes=0; //CONTA APENAS A COMPARACAO DE DESEMPATE
    //MESMO COM DESEMPATE, A MOVIMENTACAO EH FEITA NO FINAL DA PASSADA
    int compdef=0; //CONTA APENAS A COMPARACAO PADRAO DO SELECAO
    int movdef=0; //CONTA APENAS A MOVIMENTACAO PADRAO DO SELECAO
    TipoPokemon aux;
    int MAX;

    

    for(i=0;i<n-1;i++){
        MAX=0;
        for(j=1;j<n-i;j++){
            compdef++;
            if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j))) >= (getPokePoder(BuscaPokemon(&Pokecenter->Simples, MAX)))){
                compdes++;
                if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j))) == (getPokePoder(BuscaPokemon(&Pokecenter->Simples, MAX)))){
                    compdes++;
                    if((getPokeNumero(BuscaPokemon(&Pokecenter->Simples, j-1))) > (getPokeNumero(BuscaPokemon(&Pokecenter->Simples, MAX)))){
                        MAX=j;
                    }
                }
                else{
                    MAX=j;
                }
            }
        }

        aux = *BuscaPokemon(&Pokecenter->Simples, MAX);
        *BuscaPokemon(&Pokecenter->Simples, MAX) = *BuscaPokemon(&Pokecenter->Simples, n-1-i);
        *BuscaPokemon(&Pokecenter->Simples, n-1-i) = aux;
        movdef++;
    }
}

void ShellSort(CentroPesquisa *Pokecenter, int n, clock_t* TempoTotal){
    int i,j;
    int h=1;
    TipoPokemon aux;
    clock_t inicial;

    int compdef=0; //Comparações que o Shellsort faria considerando somente o Poder.
    int movdef=0; //Movimentações que o Shellsort faria considerando somente o Poder.

    int compdes=0; //Comparações adicionais necessárias para aplicar o desempate pelo Número.
    int movdes=0; //Movimentações adicionais provocadas pelo desempate.

    inicial = clock();
    while(h<n){
        h= h*3+1;  // h de Knuth
    }
    do{
        h=h/3;
        for (i=h;i<n;i++){
            movdef++;// atribuicao do atual novo item ao aux
            aux = *BuscaPokemon(&Pokecenter->Sofisticado, i);
            j=i;
            while (getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, j-h)) >= getPokePoder(&aux)){
                compdef++;//por conta do while acima (o padrao seria while a > b)
                compdes++;//por conta do if abaixo
                if(getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, j-h)) == getPokePoder(&aux)){
                    compdes++;//por conta do if abaixo
                    if((getPokeNumero(BuscaPokemon(&Pokecenter->Sofisticado, j-h))) > (getPokeNumero(&aux))){
                        movdes++;
                        *BuscaPokemon(&Pokecenter->Sofisticado, j) = *BuscaPokemon(&Pokecenter->Sofisticado, j-h);
                        j-=h;
                        if (j<h){
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    movdef++;
                    *BuscaPokemon(&Pokecenter->Simples, j) = *BuscaPokemon(&Pokecenter->Simples, j-h);
                    j-=h;
                    if (j<h){
                        break;
                    }
                }
            }
        movdef++;//colocar o item em seu lugar
        *BuscaPokemon(&Pokecenter->Simples, j) = aux;
        }
    }
    while (h!=1);  
    *TempoTotal = clock() - inicial; // tempo final - inicial = total
}

// funcoes do QuickSort
void Particao(int esq, int dir, int *i, int *j, CentroPesquisa *Pokecenter){
    TipoPokemon pivo, aux;
    *i=esq;
    *j=dir;
    pivo = *BuscaPokemon(&Pokecenter->Sofisticado, (*i + *j) /2); // utilizando o item do meio como pivo
    do{
        //percorre da esq pra dir em busca de uma chave maior que a chave do pivo
        while(getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, i)) > getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, i))){
            (*i)++;
        }
        //percorre da dir pra esq em busca de uma chave menor que a chave do pivo
        while(getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, j)) < getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, j))){
            (*j)--;
        }
        if(*i <= *j){ //se eles nao se cruzaram, faz a troca
            aux = *BuscaPokemon(&Pokecenter->Sofisticado, i);
            *BuscaPokemon(&Pokecenter->Sofisticado, i) = *BuscaPokemon(&Pokecenter->Sofisticado, j);
            *BuscaPokemon(&Pokecenter->Sofisticado, j) = aux;
            (*i)++;
            (*j)++;
        }
    }
    while(*i <= *j);

}

void Ordena(int esq, int dir, CentroPesquisa *Pokecenter){
    int i,j;
    Particao(esq, dir, &i, &j, Pokecenter);
    if (esq < j) ordena(esq, j, Pokecenter);
    if (i < dir) ordena(i, dir, Pokecenter);
}

void QuickSort(CentroPesquisa *Pokecenter, int n){
    Ordena(0, n-1, Pokecenter);
}