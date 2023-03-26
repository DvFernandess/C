#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv [])
{
    // O argumento (argc) precisa ser 2, por aceitar só 1 comando além da exec ./caesar
    if (argc != 2 || argv[1] == 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Começo criando algumas variaveis que serão úteis
    int n = 0;
    int key = 0, teste = 0;
    n = strlen(argv[1]);

    //Nesse laço, vamos descobrir se o argv é 100% númerico, como deve ser
    for (int i = 0; i < n; i++)
    {
    // Se a função isdigit for false, ela retorna 0, então o char não é númerico, então o if roda
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
//Chegando aqui, temos certeza que o argv é uma string de número, vamos converter em int
    key = atoi(argv[1]);
   // Caso queira conferir se o valor armazenado está correto ->printf("%i\n", key);

    //Requisito o plaintext(palavra a ser codificada) via terminal
    string text = get_string("Plaintext: ");
    //Armazeno o comprimento do text na variavel t
    int t = strlen(text);
    printf("ciphertext:");
    //Utilizo um laço para iterar cada letra do text, usando o tamanho do text (t) como condição
    for (int i = 0; i < t; i++)
    {
        //Como o algoritmo césar utiliza a númeração do alfabeto como 'index', devemos converter o nosso char para números de 0 a 25
        if (isalpha(text[i]) && islower(text[i]))
        {
            // Para transpor letras mínusculas para o indíce do alfabeto, diminuimos 97, valor de 'a' na tabela ASCII,
            // que representa o index 97 das letras minusculas (97-122) e agora index 0 do alfabeto (0-25)
            text[i] = text[i] - 97;
            //Após transpor o index ao alfabeto, utilizamos o algoritmo de cesar
            text[i] = (text[i] + key) % 26;
            //Agora, para devolver a letra correta, devolvemos o número 97 ao char para que represente a letra correta da tabela ASCII
            printf("%c", text[i] + 97);
        }
        else if (isalpha(text[i]) && isupper(text[i]))
        {
            //Mesma lógica das minusculas, mas na tabela ASCII as letras maiusculas começam no 65 ('A') e vão até 90 ('Z')
            //Assim, diminuindo 65 transportaremos ao índice do alfabeto 0-25, necessário ao algoritmo césar
            text[i]= text[i] - 65;
            text[i]= (text[i] + key) % 26;
            printf("%c", text[i] + 65);
        }
        else
        {
            // Como cerquei letras maisculas e minusculas anteriorment (caracteres que serão codificados), o restante somente será impresso do jeito que está
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
