# include <stdio.h>
# include <math.h>
int verifica(int);


int main(){

    int number, number2;
    scanf("%d", &number);

    number2 = number + 2;

    if(verifica(number2) == 1 && verifica(number) == 1){
        printf("PRIMO CASADO!");
    }
    else if(verifica(number) == 1){
        printf("PRIMO!");
    }
    else printf("NAO PRIMO!");

    return 0;

}

int verifica(int number){
    int i = 2;
    while (i*i <= number){
        if(number%i == 0) return 0;

        i++;
    }

    return 1;


    }
