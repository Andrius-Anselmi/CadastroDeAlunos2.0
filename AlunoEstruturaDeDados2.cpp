#include <stdio.h>
#include <stdlib.h>

struct Aluno {
    int matricula;
    double g1, g2, media;
    struct Aluno *prox; // Ponteiro para o próximo nó
};

void maiorMedia(struct Aluno *lista);
void ordenar(struct Aluno **lista);
void imprimir(struct Aluno *lista);
void recuperacao(struct Aluno *lista);
void liberarLista(struct Aluno *lista);

int main() {
    int tam;
    struct Aluno *lista = NULL; // Inicializa a lista vazia
    struct Aluno *ultimo = NULL;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &tam);

    for (int i = 0; i < tam; i++) {
        struct Aluno *novo = (struct Aluno *)malloc(sizeof(struct Aluno));
        if (novo == NULL) {
            printf("Falha em alocar memória\n");
            liberarLista(lista);
            return 1;
        }

        printf("Digite a matricula aluno %d: ", i + 1);
        scanf("%d", &novo->matricula);
        printf("Digite Nota G1 aluno %d: ", i + 1);
        scanf("%lf", &novo->g1);
        printf("Digite Nota G2 aluno %d: ", i + 1);
        scanf("%lf", &novo->g2);
        novo->media = (novo->g1 + novo->g2) / 2.0;
        novo->prox = NULL;

        if (lista == NULL) {
            lista = novo;
            ultimo = novo;
        } else {
            ultimo->prox = novo;
            ultimo = novo;
        }
    }

    printf("\nLista de alunos:\n");
    struct Aluno *atual = lista;
    while (atual != NULL) {
        printf("Matricula - %d, g1 = %.2lf, g2 = %.2lf, Media = %.2lf\n",
               atual->matricula, atual->g1, atual->g2, atual->media);
        atual = atual->prox;
    }

    printf("\nExibindo maior media:\n");
    maiorMedia(lista);

    printf("\nExibindo as notas de forma ordenada:\n");
    ordenar(&lista);
    imprimir(lista);

    printf("\nExibindo alunos de recuperacao:\n");
    recuperacao(lista);

    liberarLista(lista); // Libera a memória da lista
    return 0;
}

void maiorMedia(struct Aluno *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    struct Aluno *maior = lista;
    struct Aluno *atual = lista->prox;

    while (atual != NULL) {
        if (atual->media > maior->media) {
            maior = atual;
        }
        atual = atual->prox;
    }

    printf("Matricula: %d, Media: %.2lf\n", maior->matricula, maior->media);
}

void ordenar(struct Aluno **lista) {
    if (*lista == NULL || (*lista)->prox == NULL) {
        return; // Lista vazia ou com apenas um elemento
    }

    struct Aluno *novaLista = NULL;
    struct Aluno *atual = *lista;

    while (atual != NULL) {
        struct Aluno *prox = atual->prox;
        
        if (novaLista == NULL || atual->media < novaLista->media) {
            atual->prox = novaLista;
            novaLista = atual;
        } else {
            struct Aluno *temp = novaLista;
            while (temp->prox != NULL && temp->prox->media < atual->media) {
                temp = temp->prox;
            }
            atual->prox = temp->prox;
            temp->prox = atual;
        }
        
        atual = prox;
    }

    *lista = novaLista;
}

void imprimir(struct Aluno *lista) {
    struct Aluno *atual = lista;
    while (atual != NULL) {
        printf("Matricula - %d, Media: %.2lf\n", atual->matricula, atual->media);
        atual = atual->prox;
    }
}

void recuperacao(struct Aluno *lista) {
    struct Aluno *atual = lista;
    while (atual != NULL) {
        if (atual->media < 6.0) {
            printf("Matricula %d, media: %.2lf\n", atual->matricula, atual->media);
        }
        atual = atual->prox;
    }
}

void liberarLista(struct Aluno *lista) {
    struct Aluno *atual = lista;
    while (atual != NULL) {
        struct Aluno *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}
