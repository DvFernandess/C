#include <cs50.h>
#include <stdio.h>

int main (void)

{
   
   int Num1 = get_int ("Digite seu número aqui: \n");
   int Num2 = get_int ("Digite seu outro número aqui: \n");
   
   int Soma = Num1 + Num2;
   
   if (Soma == 50){
       printf ("Seu valor é igual a 50. \n");
       
   }else {
       printf ("O resultado do calculo foi menor que 50. \n");
   }
   
//Final    
}
