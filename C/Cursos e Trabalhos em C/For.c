#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int valor = 0;
do{
    valor = get_int("Digite um valor entre 1 e 10: \n"); 
  
}while(valor < 1 || valor > 10);

    for(int i = 1; i <= 10; i++){
        printf("%i x %i = %i\n", i, valor, i * valor);
    }
    
//Final
}