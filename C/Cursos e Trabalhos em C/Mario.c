#include <cs50.h>
#include <stdio.h>

// Função Responsável por fazer a rampa
void get_ramp(int andar);

int main(void) 

{
   //Variável que vai receber o tamanho da rampa informado pelo usuario
   int andar; 
   
   //Pergunte o tamanho enquanto a variável andar for menor que 1 ou maior que 8
   do
{
   andar = get_int("Digite um numero de 1 a 8: ");
}
 //While vai ficar em loop enquanto for verdadeira, quando for falso vai seguir.
   while (andar < 1 || andar > 8);
   
   //Gera a rampa a partir do tamanho infromado pelo usuario
   get_ramp(andar);
} 

   void get_ramp(int andar)
{
   //gera a linha (andar)
   for (int a = andar; a > 0; a --)//3
{
   //gera rampa 1
   for (int b = 1; b <= andar; b ++)
   {
      if (a > b)
      {
      printf(" "); 
      }
      else
      {
         printf("#");
      }
   }
   //gera espaço entre as rampas
   printf("  ");
   
   //gera rampa 2
   for (int c = andar; c > 0; c--)
   {
      if(a < c || a == c)
   {
      printf("#");
   }
}
printf("\n");
}
//salta para a próxima linha

}//chaves do main