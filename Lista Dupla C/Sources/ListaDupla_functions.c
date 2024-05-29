#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listadupla.h"

// Função para criar uma nova lista
ListaDupla* criar_lista() {
    ListaDupla* lista = (ListaDupla*)malloc(sizeof(ListaDupla));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}

// Função para destruir a lista e liberar memória
void destruir_lista(ListaDupla* lista) {
    No* atual = lista->primeiro;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        if (atual->tipo == TIPO_STRING) {
            free(atual->dado.dadoString);
        }
        free(atual);
        atual = proximo;
    }
    free(lista);
    printf("\nLista destruida com sucesso.\n");
}

int tamanho_atual(ListaDupla *lista)
{
    return lista->tamanho;
}

// Função auxiliar para criar um novo nó
No* criar_no(TipoDado tipo, void* valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->tipo = tipo;
    novoNo->proximo = NULL;
    novoNo->anterior = NULL;

    switch (tipo) {
        case TIPO_INT:
            novoNo->dado.dadoInt = *((int*)valor);
            break;
        case TIPO_FLOAT:
            novoNo->dado.dadoFloat = *((float*)valor);
            break;
        case TIPO_CHAR:
            novoNo->dado.dadoChar = *((char*)valor);
            break;
        case TIPO_STRING:
            novoNo->dado.dadoString = (char*)malloc(strlen((char*)valor) + 1);
            strcpy(novoNo->dado.dadoString, (char*)valor);
            break;
    }

    return novoNo;
}

// Função para adicionar um elemento no fim da lista
void adicionar_no_fim(ListaDupla* lista, TipoDado tipo, void* valor) {
    No* novoNo = criar_no(tipo, valor);
    novoNo->anterior = lista->ultimo;

    if (lista->ultimo != NULL) {
        lista->ultimo->proximo = novoNo;
    } else {
        lista->primeiro = novoNo;
    }

    lista->ultimo = novoNo;
    lista->tamanho++;
}

// Função para adicionar um elemento no começo da lista
void adicionar_no_comeco(ListaDupla* lista, TipoDado tipo, void* valor) {
    No* novoNo = criar_no(tipo, valor);
    novoNo->proximo = lista->primeiro;

    if (lista->primeiro != NULL) {
        lista->primeiro->anterior = novoNo;
    } else {
        lista->ultimo = novoNo;
    }

    lista->primeiro = novoNo;
    lista->tamanho++;
}

// Função para adicionar um elemento em uma posição específica da lista
void adicionar_na_posicao(ListaDupla* lista, int posicao, TipoDado tipo, void* valor) {
    if (posicao < 0 || posicao > lista->tamanho) {
        printf("Posicao invalida\n");
        return;
    }

    if (posicao == 0) {
        adicionar_no_comeco(lista, tipo, valor);
        return;
    }

    if (posicao == lista->tamanho) {
        adicionar_no_fim(lista, tipo, valor);
        return;
    }

    No* novoNo = criar_no(tipo, valor);
    No* atual = lista->primeiro;
    for (int i = 0; i < posicao - 1; i++) {
        atual = atual->proximo;
    }

    novoNo->proximo = atual->proximo;
    novoNo->anterior = atual;
    if (atual->proximo != NULL) {
        atual->proximo->anterior = novoNo;
    }
    atual->proximo = novoNo;
    lista->tamanho++;
}

// Função para remover um elemento do começo da lista
void remover_do_comeco(ListaDupla* lista) {
    if (lista->primeiro == NULL) {
        printf("A lista esta vazia\n");
        return;
    }

    No* removido = lista->primeiro;
    lista->primeiro = removido->proximo;

    if (lista->primeiro != NULL) {
        lista->primeiro->anterior = NULL;
    } else {
        lista->ultimo = NULL;
    }

    if (removido->tipo == TIPO_STRING) {
        free(removido->dado.dadoString);
    }
    free(removido);
    lista->tamanho--;
}

// Função para remover um elemento do fim da lista
void remover_do_fim(ListaDupla* lista) {
    if (lista->ultimo == NULL) {
        printf("A lista esta vazia\n");
        return;
    }

    No* removido = lista->ultimo;
    lista->ultimo = removido->anterior;

    if (lista->ultimo != NULL) {
        lista->ultimo->proximo = NULL;
    } else {
        lista->primeiro = NULL;
    }

    if (removido->tipo == TIPO_STRING) {
        free(removido->dado.dadoString);
    }
    free(removido);
    lista->tamanho--;
}

// Função para remover um elemento em uma posição específica da lista
void remover_na_posicao(ListaDupla* lista, int posicao) {
    if (posicao < 0 || posicao >= lista->tamanho) {
        printf("Posicao invalida\n");
        return;
    }

    if (posicao == 0) {
        remover_do_comeco(lista);
        return;
    }

    if (posicao == lista->tamanho - 1) {
        remover_do_fim(lista);
        return;
    }

    No* atual = lista->primeiro;
    for (int i = 0; i < posicao; i++) {
        atual = atual->proximo;
    }

    atual->anterior->proximo = atual->proximo;
    atual->proximo->anterior = atual->anterior;

    if (atual->tipo == TIPO_STRING) {
        free(atual->dado.dadoString);
    }
    free(atual);
    lista->tamanho--;
}

// Função para imprimir a lista
void imprimir_lista(const ListaDupla* lista) {
    No* atual = lista->primeiro;
    while (atual != NULL) {
        switch (atual->tipo) {
            case TIPO_INT:
                printf("%d ", atual->dado.dadoInt);
                break;
            case TIPO_FLOAT:
                printf("%f ", atual->dado.dadoFloat);
                break;
            case TIPO_CHAR:
                printf("%c ", atual->dado.dadoChar);
                break;
            case TIPO_STRING:
                printf("%s ", atual->dado.dadoString);
                break;
        }
        atual = atual->proximo;
    }
    printf("\n");
}


