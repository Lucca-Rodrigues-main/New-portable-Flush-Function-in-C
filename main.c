#include <stdio.h>

int Flush(void); // Consome todos os dados restantes na stdin depois de uma leitura

int main()
{
    int n;
    char c;

    printf("Numero: ");
    scanf("%d", &n);

    Flush();

    printf("Caractere: ");
    scanf("%c", &c);

    printf("\nVoce digitou:\nNumero: %d\nCaractere: %c\n", n, c);

    return 0;
}

int Flush(void) // Consome todos os dados restantes na stdin depois de uma leitura
{
    /* Com ungetc(), um caractere é virtualmente colocado
    de volta em um fluxo de entrada */
    int c = ungetc(' ', stdin);

    /* fgetc() lê o caractere presente na posição atual do fluxo
    interno. Após a leitura, a posição atual é avançada para o
    próximo caractere, como resultado, vão ser lidos todos os
    caracteres até encontrar '\n' ou EOF */
    for(int ch = 0; ((ch = fgetc(stdin)) != '\n' && ch != EOF););

    return c;
}
