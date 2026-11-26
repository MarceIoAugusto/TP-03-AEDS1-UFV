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

void BubbleSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal){
    clock_t tempo = clock();
    int i,j; 
    TipoPokemon aux;

    for(i=0;i<n-1;i++){ //n-1 passadas no array
        for(j=1;j<n-i;j++){ //diminui a cada passada
            (*compdef)++;
            if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j-1))) > (getPokePoder(BuscaPokemon(&Pokecenter->Simples, j)))){ //verifica se o poder anterior é maior ou igual ao proximo
                aux=*BuscaPokemon(&Pokecenter->Simples, j);
                *BuscaPokemon(&Pokecenter->Simples, j) = *BuscaPokemon(&Pokecenter->Simples, j-1);
                *BuscaPokemon(&Pokecenter->Simples, j-1)= aux;
                (*movdef)+=3;
            }
            else if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j-1))) == (getPokePoder(BuscaPokemon(&Pokecenter->Simples, j)))){  //se as chaves são iguais, aplicamos o desempate no numero da pokedex
                    (*compdes)++;
                    if((getPokeNumero(BuscaPokemon(&Pokecenter->Simples, j-1))) > (getPokeNumero(BuscaPokemon(&Pokecenter->Simples, j)))){
                        aux= *BuscaPokemon(&Pokecenter->Simples, j);
                        *BuscaPokemon(&Pokecenter->Simples, j) = *BuscaPokemon(&Pokecenter->Simples, j-1);
                        *BuscaPokemon(&Pokecenter->Simples, j-1)= aux;
                        (*movdes)+=3;
                    }
                }
        }
    }
    *tempototal = clock() - tempo;
}

void SelectionSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal){
    clock_t tempo = clock();
    int i,j;
    TipoPokemon aux;
    int MAX;

    

    for(i=0;i<n-1;i++){
        MAX=0;
        for(j=1;j<n-i;j++){
            (*compdef)++;
            if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j))) > (getPokePoder(BuscaPokemon(&Pokecenter->Simples, MAX)))){
                MAX=j;
            }
            else if((getPokePoder(BuscaPokemon(&Pokecenter->Simples, j))) == (getPokePoder(BuscaPokemon(&Pokecenter->Simples, MAX)))){
                    (*compdes)++;
                    if((getPokeNumero(BuscaPokemon(&Pokecenter->Simples, j))) > (getPokeNumero(BuscaPokemon(&Pokecenter->Simples, MAX)))){
                        MAX=j;
                    }
                }
            }

        aux = *BuscaPokemon(&Pokecenter->Simples, MAX);
        *BuscaPokemon(&Pokecenter->Simples, MAX) = *BuscaPokemon(&Pokecenter->Simples, n-1-i);
        *BuscaPokemon(&Pokecenter->Simples, n-1-i) = aux;
        (*movdef)+= 3;
    }
    *tempototal = clock() - tempo;
}

void ShellSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal){
    clock_t tempo = clock();
    int i,j;
    int h=1;
    TipoPokemon aux;
    
    if (n <= 1) {
        *tempototal = clock() - tempo;
        return;
    }

    while(h<n){
        h= h*3+1;  // h de Knuth
    }
    do{
        h=h/3;
        for (i=h;i<n;i++){
            (*movdef)++;// atribuicao do atual novo item ao aux
            aux = *BuscaPokemon(&Pokecenter->Sofisticado, i);
            j=i;
            //inclui a contagem dentro do while
            while (((*compdef)++),getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, j-h)) >= getPokePoder(&aux)){
                if(getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, j-h)) == getPokePoder(&aux)){
                    (*compdes)++;//por conta do if abaixo
                    if((getPokeNumero(BuscaPokemon(&Pokecenter->Sofisticado, j-h))) > (getPokeNumero(&aux))){
                        (*movdes)++;
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
                    (*movdef)++;
                    *BuscaPokemon(&Pokecenter->Sofisticado, j) = *BuscaPokemon(&Pokecenter->Sofisticado, j-h);
                    j-=h;
                    if (j<h){
                        break;
                    }
                }
            }
        (*movdef)++;//colocar o item em seu lugar
        *BuscaPokemon(&Pokecenter->Sofisticado, j) = aux;
        }
    }
    while (h!=1);  
    *tempototal = clock() - tempo; // tempo final - inicial = total
}

// funcoes do QuickSort
void Particao(int esq, int dir, int *i, int *j, CentroPesquisa *Pokecenter, long int*movdef, long int*compdef, long int*movdes, long int*compdes){
    TipoPokemon pivo, aux;
    int poder_pivo, numero_pivo;
    *i=esq;
    *j=dir;

    pivo = *BuscaPokemon(&Pokecenter->Sofisticado, ((*i + *j) /2)); // utilizando o item do meio como pivo
    (*movdef)++;
    poder_pivo = getPokePoder(&pivo); // armazena a chave poder do pivo (nao muda durante a exec de particao) (evita getters)
    numero_pivo = getPokeNumero(&pivo); // armazena a chave numero do pivo (tambem nao muda)


    do{

        //percorre da esq pra dir em busca de uma chave maior que a chave do pivo

        while (*i <= dir) {
            TipoPokemon *esquerda = BuscaPokemon(&Pokecenter->Sofisticado, *i);
            int poder_esq   = getPokePoder(esquerda);
            int num_esq = getPokeNumero(esquerda);

            (*compdef)++;                       // comparação de poder (padrão)
            if (poder_esq < poder_pivo) { (*i)++; continue; }
            if (poder_esq > poder_pivo) break;          // A > pivo → para

            // p == poder_pivo → desempate por número
            (*compdes)++;
            if (num_esq < numero_pivo) { (*i)++; continue; }
            break;                              // A >= pivo → para
        }

        while (*j >= esq) {
            TipoPokemon *direita = BuscaPokemon(&Pokecenter->Sofisticado, *j);
            int poder_dir   = getPokePoder(direita);
            int num_dir = getPokeNumero(direita);

            (*compdef)++;                       // comparação de poder (padrão)
            if (poder_dir > poder_pivo) { (*j)--; continue; }
            if (poder_dir < poder_pivo) break;          // A < pivo → para

            // p == poder_pivo → desempate por número
            (*compdes)++;
            if (num_dir > numero_pivo) { (*j)--; continue; }
            break;                              // A <= pivo → para
        }

        if(*i <= *j){ //se eles nao se cruzaram, faz a troca
            if(getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, *i)) == getPokePoder(BuscaPokemon(&Pokecenter->Sofisticado, *j))){
                (*movdes) +=3;
            }
            else{
                (*movdef) +=3;
            }


            // faz a troca
            aux = *BuscaPokemon(&Pokecenter->Sofisticado, *i);
            *BuscaPokemon(&Pokecenter->Sofisticado, *i) = *BuscaPokemon(&Pokecenter->Sofisticado, *j);
            *BuscaPokemon(&Pokecenter->Sofisticado, *j) = aux;
            (*i)++;
            (*j)--;
        }
    }
    while(*i <= *j);

}

void Ordena(int esq, int dir, CentroPesquisa *Pokecenter, long int*movdef, long int*compdef, long int*movdes, long int*compdes){
    int i,j;
    if (esq >= dir) return; // evita chamar particao para subvetores de 1/0 elementos
    Particao(esq, dir, &i, &j, Pokecenter, movdef, compdef, movdes, compdes);
    if (esq < j) Ordena(esq, j, Pokecenter, movdef, compdef, movdes, compdes);
    if (i < dir) Ordena(i, dir, Pokecenter, movdef, compdef, movdes, compdes);
}

void QuickSort(CentroPesquisa *Pokecenter, int n, long int*movdef, long int*compdef, long int*movdes, long int*compdes, clock_t *tempototal){
    clock_t tempo;
    tempo = clock();
    if (n>1){
        Ordena(0, n - 1, Pokecenter, movdef, compdef, movdes, compdes);
    }
    *tempototal = clock() - tempo;
}

// fim funcoes do QuickSort


void ImprimeCPSimples(CentroPesquisa *Pokecenter, FILE *fptr){
    ImprimeLista(&Pokecenter->Simples);
    ImprimeListaFile(fptr, &Pokecenter->Simples);
}
void ImprimeCPSofisticado(CentroPesquisa *Pokecenter, FILE *fptr){
    ImprimeLista(&Pokecenter->Simples);
    ImprimeListaFile(fptr, &Pokecenter->Simples);
}