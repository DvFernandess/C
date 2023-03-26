#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void)
{
    //variaveis 
    float moeda;
    int m25 = 0;
    int m10 = 0;
    int m5 = 0;
    int m1 = 0;
    
    //condição para digitar o valor
    do
    {
      moeda = get_float("Digite o valor desejado: ");
    }
    while (moeda <= 0);
    int cents = round (moeda * 100);
    
    while (cents > 25 || cents == 25)
    {
        cents = cents - 25;
        m25++;
    }
    
    while (cents > 10 || cents == 10)
    {
        cents = cents - 10;
        m10++;
    }
    
    while (cents > 5 || cents == 5)
    {
        cents = cents - 5;
        m5++;
    }
    
    while (cents > 1 || cents == 1)
    {
        cents = cents - 1;
        m1++;
    }
    
    printf("%i moedas de 0,1\n", m1);
    printf("%i moedas de 0,5\n", m5);
    printf("%i moedas de 0,10\n", m10);
    printf("%i moedas de 0,25\n", m25);
    printf("%i moedas necessarias\n", m1 + m5 + m10 + m25);

//corpo main
}

