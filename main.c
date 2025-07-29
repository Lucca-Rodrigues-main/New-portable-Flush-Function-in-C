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
    /* Com ungetc(), um caractere � virtualmente colocado
    de volta em um fluxo de entrada */
    int c = ungetc(' ', stdin);

    /* fgetc() l� o caractere presente na posi��o atual do fluxo
    interno. Ap�s a leitura, a posi��o atual � avan�ada para o
    pr�ximo caractere, como resultado, v�o ser lidos todos os
    caracteres at� encontrar '\n' ou EOF */
    for(int ch = 0; ((ch = fgetc(stdin)) != '\n' && ch != EOF););

    return c;
}
