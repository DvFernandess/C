#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int inicial;
    int final;
    int anos;
    
    // Solicite o valor inicial ao usuário
    do 
    {
       inicial = get_int ("Digite o valor inicial: \n");
    }
    while (inicial < 9);
    
     // Solicite o valor final ao usuário
    do {
        final = get_int ("Digite o valor Final: \n");
    }
    while (final <= inicial );
    
    // Calcule o número de anos até o limite
    for (anos = 0; inicial < final; anos++)
    {
     inicial = inicial + (inicial / 3) - (inicial / 4);   
    }
    
    // Imprima o número de anos
    printf("anos: %i\n", anos);
    
}//final
 