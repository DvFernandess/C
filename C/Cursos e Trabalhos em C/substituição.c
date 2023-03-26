#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv [])
{
    int vetor[26];
    int key;
    
    if (argc != 2){
        printf("Use ./substituição chave \n");
        return 1;
    }
    if (strlen (argv[1]) != 26){
        printf("A chave deve conter 26 caracteres \n");
        return 1;
    }
    for(int i = 0, n = 26; i < n; i++){
        if(!isalpha(argv[1][i])){
            printf("A chave deve conter somente caracteres alfabeticos. \n");
            return 1;
        }
        else if (islower(argv[1][i])){
            key = argv[1][i] - 97;
        }
        else {
            key = argv[1][i] - 65;
        }
        for (int j = 0; j < i; j++){
            if(argv[1][i] == argv [1][j]){
                printf("A chave não pode conter caracteres repetidos. \n");
                return 1;
            }
        }
        vetor[i] = key;
    }
    string texto = get_string ("Digite o texto: ");
    printf("texto criptografado: ");
    for(int i = 0, n = strlen(texto); i < n; i++){
        if (isalpha(texto[i]) && islower(texto[i])){
            key = texto[i] - 97;
            printf("%c", vetor[key] + 97);
        }
        else if(isupper(texto[i]) && isalpha(texto[i])){
            key = texto[i] - 65;
            printf("%c", vetor[key] + 65);
        }
        else {
            printf("%c", texto[i]);
        }
    }
printf("\n");
}