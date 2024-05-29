#ifndef listadupla_h
#define listadupla_h

typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_CHAR,
    TIPO_STRING
} TipoDado;

typedef union {
    int dadoInt;
    float dadoFloat;
    char dadoChar;
    char* dadoString;
}Dado;

typedef struct No {
    Dado dado;
    TipoDado tipo;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct ListaDupla {
    No* primeiro;
    No* ultimo;
    int tamanho;
} ListaDupla;

ListaDupla* criar_lista();

void destruir_lista(ListaDupla* lista);
int tamanho_atual(ListaDupla* lista);
void adicionar_no_fim(ListaDupla* lista, TipoDado, void* valor);
void adicionar_no_comeco(ListaDupla* lista, TipoDado tipo, void* valor);
void adicionar_na_posicao(ListaDupla* lista, int posicao, TipoDado tipo, void* valor);
void remover_do_comeco(ListaDupla* lista);
void remover_do_fim(ListaDupla* lista);
void remover_na_posicao(ListaDupla* lista, int posicao);
void imprimir_lista(const ListaDupla* lista);

#endif /* listadupla_h */




