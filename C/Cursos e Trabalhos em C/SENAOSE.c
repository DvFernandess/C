#include <cs50.h>
#include <stdio.h>

int main (void)
{
    
    int valor1 = get_int ("Digite o valor 1: \n");
    int valor2 = get_int ("Digite o valor 2: \n");
    
    if(valor1 == valor2){
        printf("O seus valores são iguais. \n");
    }
    else if(valor1 > valor2){
        printf("Seu valor 1 e maior que seu valor 2. \n");
    }
    else {
        printf ("Valor 2 e maior que valor 1. \n");
    }
    
    
//Final    
}
