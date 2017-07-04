#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//CAMPO MINADO!!!

//Variaveis do Jogo:
//Tamanho da matriz;
int size = 9;
//Quantidade de Bombas;
int quant_bombas = size-1;
//Matriz 9x9 com todas as informações;
int campo_minado[9][9];
//Matriz 9x9 sem informações iniciais. Sera a exibida para o usuario;
int mtz_Impressa[9][9];
bool achouBomba = false;

//Metodos de Design do jogo;
void texto_Inicial();
void texto_Final();
void texto_Perdeu();
void texto_Ganhou();

//Metodos do Jogo;
bool ganhou();
void prencherCamposVazio();
void gerandoBomba();
void minasAdjacentes();
void somaAdjacentes(int x, int y);
void verificaESoma(int x, int y);
void imprime(int matriz[9][9]);

int main(){

    texto_Inicial();
    puts(" ");

    prencherCamposVazio();
    gerandoBomba();
    minasAdjacentes();
    imprime(mtz_Impressa);

    //Variaveis das coordenadas da matriz que serao informadas pelo usuario;
    int x;
    int y;

    while(!achouBomba && !ganhou()){
        printf("Digite o eixo x: ");
        scanf("%d", &x);
        printf("Digite o eixo y: ");
        scanf("%d", &y);

        if(x >= 0 && x <= size && y >= 0 && y <= size){

            mtz_Impressa[x-1][y-1] = campo_minado[x-1][y-1];

            if(mtz_Impressa[x-1][y-1] == -1){
                achouBomba = true;
            }

            imprime(mtz_Impressa);
            ganhou();
        }
        else{
            printf("Digite as coordenadas no intervalo de 1 a %d.\n", size);
        }
    }
     //Caso ache uma bomba, o jogo acaba, se não se
    //O usuario desbloqueou todos os espaços da matriz e so restar os com bomba ele ganha;
    if (achouBomba == true){
        texto_Perdeu();

    }else if(ganhou()){
        texto_Ganhou();

    }
    imprime(campo_minado);
    texto_Final();

    return 0;
}


void texto_Inicial() {
puts("|-----------------------------------------------------------------------------|");
puts("|     .--.                               .-..-. _                 .-.         |");
puts("|    : .--'                              : `' ::_;                : :         |");
puts("|    : :    .--.  ,-.,-.,-..---.  .--.   : .. :.-.,-.,-. .--.   .-' : .--.    |");
puts("|    : :__ ' .; ; : ,. ,. :: .; `' .; :  : :; :: :: ,. :' .; ; ' .; :' .; :   |");
puts("|    `.__.'`.__,_;:_;:_;:_;: ._.'`.__.'  :_;:_;:_;:_;:_;`.__,_;`.__.'`.__.'   |");
puts("|                          : :                                                |");
puts("|                          :_;                                                |");
puts("|-----------------------------------------------------------------------------|");
}

void texto_Ganhou(){
puts("");
puts("|-----------------------------------------------------------------------------|");
puts("| .--.   .--.             _       .----.               ,-.                    |");
puts("| :  :._.:  : .--. .---..---.    :  :  __  .--.  ,-.,-.: :,-. .--.  _   _     |");
puts("|  :        :' .; :: :: : :-'    :  :__:: ' .; ; : ,. :: :  :' .; :' '.; '    |");
puts("|   :..__..: `.__.'`.__,`.__;    `.____.' `.__,_;:_;:_;:_;:_;`.__.'`.___.'    |");
puts("|                                                                             |");
puts("|                                                                             |");
puts("|-----------------------------------------------------------------------------|");

}

void texto_Perdeu(){
puts("");
puts("|-----------------------------------------------------------------------------|");
puts("| .--.   .--.             _       ,----.              .-.                     |");
puts("| :  :   :  :            / \\     :      :             : :                     |");
puts("| :  :._.:  : .--. .---..---.    :  ,__:.---.,----, .-' :.---.  _   _         |");
puts("|  :        :' .; :: ::': :-'    :  :   : :-': ;-; ' .; :: :-''' .;  '        |");
puts("|   :..__..: `.__.'`.__,`.__;    :__:   `.__;:_:   `.__.'`.__; `.___.'        |");
puts("|                                                                             |");
puts("|                                                                             |");
puts("|-----------------------------------------------------------------------------|");

}

void texto_Final(){
puts("");
puts("|-----------------------------------------------------------------------------|");
puts("|                                 GRUPO                                       |");
puts("|                           SHEILLA DA SILVA                                  |");
puts("|                           CAMILA CARVALHO                                   |");
puts("|                            SAMARA SAMPAIO                                   |");
puts("|                             GLAUBER BRAZ                                    |");
puts("|-----------------------------------------------------------------------------|");
}

//As demais posições da matriz impressa sera completadas com -2;
//Os valores na matriz que possuem -2, são os que o usuario ainda não desbloqueou;
//Isso apenas para a matriz que sera exibida ao usuario;
void prencherCamposVazio(){

    for(int j = 0; j < size; j ++){
         for(int k = 0; k < size; k ++){
            mtz_Impressa[j][k] = -2;
         }
    }

}

//Gerando as bombas na matriz(obs: bombas possuem  valor -1);
void gerandoBomba(){
    //Posicoes x e y da matriz;
    int posicao_x_tabela;
    int posicao_y_tabela;
    srand(time(NULL));

    for(int i = 0; i <= quant_bombas; i++){

        posicao_x_tabela = rand() % size;
        posicao_y_tabela = rand() % size;

        campo_minado[posicao_x_tabela][posicao_y_tabela] = -1;
    }

}

//Verifica os quadrados que contem bomba e passa a posicao do quadrado, na matriz principal,
//como parametro do metodo somaAdjacentes();
void minasAdjacentes(){

    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            if(campo_minado[x][y] == -1){
                somaAdjacentes(x, y);
            }
        }
    }
}

//Soma +1 a cada bomba proxima ao quadrado da matriz principal, passado como parametro;
//Matriz principal eh a Campo_Minado, pois ela que contem todas as informações;
void somaAdjacentes(int x, int y){

    if(x > 0 && x < size-1){

        if(y > 0 && y < size-1){
            //Linha da Bomba
            verificaESoma(x, y-1);
            verificaESoma(x, y+1);

            //Linha acima da Bomba
            verificaESoma(x-1, y);
            verificaESoma(x-1, y-1);
            verificaESoma(x-1, y+1);

            //Linha abaixo da Bomba
            verificaESoma(x+1, y);
            verificaESoma(x+1, y-1);
            verificaESoma(x+1, y+1);

        }

        else if(y == 0){
            //Linha da Bomba
            verificaESoma(x, y+1);

            //Linha acima da Bomba
            verificaESoma(x-1, y);
            verificaESoma(x-1, y+1);

             //Linha abaixo da Bomba
            verificaESoma(x+1, y);
            verificaESoma(x+1, y+1);
        }


        else{
            //Linha da Bomba
            verificaESoma(x, y-1);

            //Linha acima da Bomba
            verificaESoma(x-1, y);
            verificaESoma(x-1, y-1);

             //Linha abaixo da Bomba
            verificaESoma(x+1, y);
            verificaESoma(x+1, y-1);
        }

    }
    else if(x == 0){
        if(y > 0 && y < size-1){
            //Linha da Bomba
            verificaESoma(x, y-1);
            verificaESoma(x, y+1);

            //Linha abaixo da Bomba
            verificaESoma(x+1, y);
            verificaESoma(x+1, y-1);
            verificaESoma(x+1, y+1);

        }

        else if(y == 0){
            //Linha da Bomba
            verificaESoma(x, y+1);

            //Linha abaixo da Bomba
            verificaESoma(x+1, y);
            verificaESoma(x+1, y+1);
        }


        else{
            //Linha da Bomba
            verificaESoma(x, y-1);
            campo_minado[x][y - 1] +=1;

            //Linha abaixo da Bomba
            verificaESoma(x+1, y);
            verificaESoma(x+1, y-1);

        }
    }

    else{
        if(y > 0 && y < size-1){
            //Linha da Bomba
            verificaESoma(x, y-1);
            verificaESoma(x, y+1);

            //Linha abaixo da Bomba
            verificaESoma(x-1, y);
            verificaESoma(x-1, y-1);
            verificaESoma(x-1, y+1);

        }

        else if(y == 0){
            //Linha da Bomba
            verificaESoma(x, y+1);

            //Linha abaixo da Bomba
            verificaESoma(x-1, y);
            verificaESoma(x-1, y+1);

        }


        else{
            //Linha da Bomba
            verificaESoma(x, y-1);

            //Linha abaixo da Bomba
            verificaESoma(x-1, y);
            verificaESoma(x-1, y-1);

        }

    }

}

//Verifica se a posição não eh uma bomba, se não for, soma mais 1;
void verificaESoma(int x, int y){
    if(campo_minado[x][y] != -1){
        campo_minado[x][y] += 1;
    }
}

//Verifica se o usuraio ganhou o jogo;
bool ganhou(){

    for(int j = 0; j < size; j ++){
        for(int k = 0; k < size; k ++){
            if( mtz_Impressa[j][k] == -2){
                if(campo_minado[j][k] != -1){
                    return false;
                }
            }
        }
    }
    return true;
}

//Imprime o tabuleiro do jogo de acordo com as informações da matriz passada como parametro;
void imprime(int matriz[9][9]){
    printf("\n");

    for(int x = 0; x < size; x++){
        printf("                    ");
        printf("|");
        for(int y = 0; y < size; y++){
            if(matriz[x][y] == -2){
                printf(" x |");
            }
            //Bomba!!!
            else if(matriz[x][y] == -1){
                printf(" * |");
            }
            //Espaço em branco!!!
            else if(matriz[x][y] == 0){
                printf("   |");
            }
            //umeros Adjacentes!!!
            else{
                printf(" %d |",  matriz[x][y]);

            }
        }
        printf("\n                    ");
        puts("-------------------------------------");

    }

}
