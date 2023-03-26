#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int x = get_int ("Digite um número: \n");
    int contador = 0;
    float y = (float) x;
    
    while(contador < 9){
        x = get_int ("Digite um número: \n");
        y = y + (float) x;
        contador++;
    }
    printf ("A média é: %.2f\n", y / 10);
    
    
}