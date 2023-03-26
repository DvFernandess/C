#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int Num;
        Num = get_int ("Digite um número: \n");
    
    while( Num > 1 ){
        Num = get_int ("Digite novamente: \n");
    }
    
}