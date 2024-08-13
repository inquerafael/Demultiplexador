#include "filaDinamica.h"
#include <stdio.h>
#include <stdlib.h>

int menu() {
  int op;
  // menu do sistema
  printf("\t===  Menu  ===\n\n");
  printf("\t1 - Inserir\n");
  printf("\t2 - Imprime\n");
  printf("\t3 - Demultiplexador\n");
  printf("\t0 - Sair\n");
  printf("\n\t==============\n");
  printf("Digite a opcao: ");
  scanf("%d", &op);
  return op;
}

int main() {

  Fila *CanalComp = cria_Fila();
  Fila *fluxo1 = cria_Fila();
  Fila *fluxo2 = cria_Fila();
  Fila *fluxo3 = cria_Fila();
  struct canal comp;

  int opcao;

  struct canal aux[11] = {{1, 15}, {2, 89}, {3, 48}, {2, 23}, {1, 13}, {3, 32},
                          {2, 45}, {1, 17}, {3, 30}, {2, 47}, {1, 27}};

  for (int i = 0; i < 11; i++) {
    insere_Fila(CanalComp, aux[i]);
  }
  imprime_Fila(CanalComp);

  do {
    opcao = menu();
    switch (opcao) {
    case 1:
      dadosCanal(&comp);
      insere_Fila(CanalComp, comp);
      break;
    case 2:
      imprime_Fila(CanalComp);
      break;
    case 3:
      separa_Fila(CanalComp, fluxo1, fluxo2, fluxo3);
      printf("\n\tFluxo 1\n");
      imprime_Fila(fluxo1);
      printf("\n\tFluxo 2\n");
      imprime_Fila(fluxo2);
      printf("\n\tFluxo 3\n");
      imprime_Fila(fluxo3);

      break;
    case 0:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
      break;
    }
  } while (opcao != 0);

  return 0;
}