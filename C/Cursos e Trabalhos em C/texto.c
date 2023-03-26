#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int main (void)
{

int L = 0;//Valor de letras
int S = 0;//Valor de sentenças 
int P = 1;//Valor de palavras
float ML= 0;//Media de letras 
float MS = 0;//Media de sentenças
double indice;//grade
string texto = get_string("Digite seu texto aqui: \n");
     
//Verificação de quantidade de palavras
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (isspace (texto[i]))
    {
        P++;
    }
    
}
//Verificação de quantidade de letras 
    for (int i = 0, n = strlen(texto); i < n; i++)
    {
        if (isalpha (texto[i]))
    {
        L++;
    }
}   
//Verifica de quantidade de sentenças 
    for (int i = 0, n = strlen(texto); i < n; i++)
     
    {
    if (texto[i] == '.' || texto[i] == '!' || texto[i] == '?')
    {
       S++;
    }
}
//Media de letras por 100 palavras
ML = ((float) L / (float) P) * 100;
MS = ((float) S / (float) P) * 100;
indice = round ((0.0588 * ML) - (0.296 * MS) - 15.8);

printf ("Quantidade de letras: %i\n", L);//Imprime a quantidade de letras
printf ("Quantidade de sentenças: %i\n", P);// Imprime a quantidade de palavras
printf ("Quantidade de palavras: %i\n", S); // Imprime a quantidade de sentenças 

if(indice < 1)
{
    printf ("Antes da 1 série.\n");
}
else if (indice >= 16)
{
    printf ("Serie: 16+\n");
}
else 
{
    printf ("Serie: %i\n", (int)indice);
}
// final
}