#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int Num1, Num2;
    int Menu;
    double Resultado;
    do
    {
        Menu = get_int ("Escolha um número: \n");
    
        switch(Menu)
        {
            case 1:
                Num1 = get_int ("Digite o primeiro número \n");
                Num2 = get_int ("Digite o segunda número \n");
                printf("A soma é: %i\n", Num1 + Num2);
                break;
    
            case 2:
                Num1 = get_int ("Digite o primeiro número \n");
                Num2 = get_int ("Digite o segundo número \n");
                printf("A soma é: %i\n", Num1 - Num2);
                break;
            case 3:
                Num1 = get_int ("Digite o primeiro número \n");
                Num2 = get_int ("Digite o segundo número \n");
                printf("A soma é: %i\n", Num1 * Num2);
                break;
            case 4:
                Num1 = get_int ("Digite o primeiro número \n");
                Num2 = get_int ("Digite o segundo número \n");
                Resultado = (float) Num1 /(float) Num2;
                printf("A soma é: %.2f\n", Resultado);
                break;
            default:
                printf("Número invalido, digite novamente. \n");
                break;
        }
    }
    while(Menu < 1 || Menu > 4);

//Final    
}