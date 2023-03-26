#include <cs50.h>
#include <stdio.h>

int main (void)
{
 int Num1, Num2, Menu;
 string nome;

do 
{
    Menu = get_int ("Digite a opção de menu \n1 - Soma \n2 - Multiplicação \n3 - Verificação de idade \n");
    switch (Menu){
        case 1:
        Num1 = get_int ("Digite o número 1: \n");
        Num2 = get_int ("Digite o número 2: \n");
        printf("Seu resultado é: %i\n", Num1 + Num2);
        break;
        case 2:
        Num1 = get_int ("Digite o número 1: \n");
        Num2 = get_int ("Digite o número 2: \n");
        printf("Seu resultado é: %i\n", Num1 * Num2);
        break;
        case 3:
        nome = get_string ("Digite o seu nome: \n");
        Num1 = get_int ("Digite sua idade: \n");
        if(Num1 >= 18){
            printf("Você é maior de idade. \n");
        }else{
            printf("Você é menor de idade. \n");
        }
        break;
        default:
        printf("Opção invalida \n");
        }
}
    while( Menu < 1 || Menu > 3);

//Final
}