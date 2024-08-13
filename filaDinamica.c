#include "filaDinamica.h" //inclui os Prot�tipos
#include <stdio.h>
#include <stdlib.h>

// manipulacao da celula
typedef struct celula {
  struct canal dados;
  struct celula *prox;
} Cel;

struct fila {
  struct celula *inicio;
  struct celula *final;
  int qtd;
};

Fila *cria_Fila() {
  Fila *fi = (Fila *)malloc(sizeof(Fila));
  if (fi != NULL) {   // verifica se foi criado
    fi->final = NULL; // inicializa inicio/final/contador
    fi->inicio = NULL;
    fi->qtd = 0;
  }
  return fi;
}

void libera_Fila(Fila *fi) {
  if (fi != NULL) {
    Cel *aux;
    while (fi->inicio != NULL) {
      aux = fi->inicio;
      fi->inicio = fi->inicio->prox;
      free(aux);
    }
    free(fi);
  }
}

int consulta_Fila(Fila *fi, struct canal *comp) {
  if (fi == NULL)
    return 0;
  if (fi->inicio == NULL) // fila vazia
    return 0;
  *comp = fi->inicio->dados;
  return 1;
}

int insere_Fila(Fila *fi, struct canal comp) {
  if (fi == NULL)
    return 0;
  Cel *aux = (Cel *)malloc(sizeof(Cel));
  if (aux == NULL)
    return 0;

  aux->dados = comp;
  aux->prox = NULL;
  if (fi->final == NULL) { // fila vazia
    fi->inicio = aux;
  } else {
    fi->final->prox = aux;
  }
  fi->final = aux;
  fi->qtd++;
  return 1;
}

int remove_Fila(Fila *fi) {
  if (fi == NULL)
    return 0;
  if (fi->inicio == NULL) // fila vazia
    return 0;
  Cel *no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  if (fi->inicio == NULL) // fila ficou vazia
    fi->final = NULL;
  free(no);
  fi->qtd--;
  return 1;
}

int tamanho_Fila(Fila *fi) {
  if (fi == NULL)
    return 0;
  return fi->qtd;
}

int Fila_vazia(Fila *fi) {
  if (fi == NULL)
    return 1;
  if (fi->inicio == NULL)
    return 1;
  return 0;
}

int Fila_cheia(Fila *fi) { return 0; }

void imprime_Fila(Fila *fi) {
  if (fi == NULL)
    return;

  Cel *aux = fi->inicio;
  while (aux != NULL) {
    printf("|(%d - %d)|\n", aux->dados.indentificador, aux->dados.valor);
    aux = aux->prox;
  }
}

void separa_Fila(Fila *fi, Fila *fluxo1, Fila *fluxo2, Fila *fluxo3) {
  Cel *aux = fi->inicio;
  while (aux != NULL) { // condicional para separar os canais
    if (aux->dados.indentificador == 1) {
      insere_Fila(fluxo1, aux->dados);
    } else if (aux->dados.indentificador == 2) {
      insere_Fila(fluxo2, aux->dados);
    } else if (aux->dados.indentificador == 3) {
      insere_Fila(fluxo3, aux->dados);
    }
    aux = aux->prox;
  }
  int tam = tamanho_Fila(fi);
  for (int i = 0; i < tam; i++) {
    remove_Fila(fi);
  }
}

void dadosCanal(struct canal *comp) {

  printf("Digite o Identificador(1, 2, 3): ");
  scanf("%d", &comp->indentificador);
  printf("Digite o Valor: ");
  scanf("%d", &comp->valor);
}