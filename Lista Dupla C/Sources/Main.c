#include <stdio.h>
#include "listadupla.h"

int main()
{
    ListaDupla* lista1 = criar_lista();
    ListaDupla* lista2 = criar_lista();
    printf("\n Lista criada...\n");
    printf("Adicionando valores de 1 a 10 no começo:\n");

    for(int i=1; i<11; i++)
    {
        adicionar_no_fim(lista1, TIPO_INT, &i);
    }

    imprimir_lista(lista1);
    printf("\n");

    printf("Removendo valores na ordem reversa:\n");
    for(int i=11; i>0; i--)
    {
        remover_do_fim(lista1);
        imprimir_lista(lista1);
    }
    printf("\n");

    printf("Adicionado 1 a 10 no comeco:\n");
    for(int i=1; i<11; i++)
    {
        adicionar_no_comeco(lista1, TIPO_INT, &i);
    }
    imprimir_lista(lista1);
    printf("\n");

    printf("Removendo na esquerda para a direita:\n");
    for(int i=11; i>0; i--)
    {
        remover_do_comeco(lista1);
        imprimir_lista(lista1);
    }
    printf("\n");

    printf("Adicionando letras e texto:\n");
    char letraA = 'A';
    char letraC = 'C';
    char slash = '/';
    char letraD = 'D';
    int pos = 2;

    char texto1[] = "Uma banda que eu gosto muito eh o";
    char texto2[] = "Principalmente o album back in black.";

    adicionar_no_fim(lista1, TIPO_CHAR, &letraA);
    adicionar_no_fim(lista1, TIPO_CHAR, &letraC);
    adicionar_no_fim(lista1, TIPO_CHAR, &letraD);
    adicionar_no_fim(lista1, TIPO_CHAR, &letraC);

    adicionar_na_posicao(lista1, pos, TIPO_CHAR, &slash);

    adicionar_no_comeco(lista1, TIPO_STRING, &texto1);
    adicionar_no_fim(lista1, TIPO_STRING, &texto2);

    imprimir_lista(lista1);
    printf("\n");

    for(int i=6; i>0; i--)
    {
        remover_do_fim(lista1);
    }
    imprimir_lista(lista1);

    char texto3[] = "Metallica";
    char texto4[] = ", Principalmente a musica The Unforgiven parte ";
    char letraI = 'I';
    adicionar_no_fim(lista1, TIPO_STRING, &texto3);
    adicionar_no_fim(lista1, TIPO_STRING, &texto4);
    adicionar_no_fim(lista1, TIPO_CHAR, &letraI);

    printf("\n");
    imprimir_lista(lista1);
    printf("\n");

    int pos2 = 3;
    adicionar_na_posicao(lista1, pos2, TIPO_CHAR, &letraI);
    printf("\n");
    imprimir_lista(lista1);

    printf("\n\nAdicionado floats e texto:\n");
    char texto5[] = "O valor do Pi eh: ";
    char texto6[] = "E o valor do num de Euler eh: ";

    float valorpi = 3.14;
    float valoreuler = 2.71;

    adicionar_no_comeco(lista2, TIPO_STRING, &texto5);
    adicionar_no_fim(lista2, TIPO_FLOAT, &valorpi);
    adicionar_no_fim(lista2, TIPO_STRING, &texto6);
    adicionar_no_fim(lista2, TIPO_FLOAT, &valoreuler);
    imprimir_lista(lista2);

    int tamanho = tamanho_atual(lista2);
    printf("\nTamanho atual: %d", tamanho);

    destruir_lista(lista1);
    destruir_lista(lista2);
    imprimir_lista(lista1);

    int tamanho2 = tamanho_atual(lista2);
    printf("Tamanho atual: %d", tamanho2);

    printf("\n\n");
    system("Pause");
    return 0;
}


