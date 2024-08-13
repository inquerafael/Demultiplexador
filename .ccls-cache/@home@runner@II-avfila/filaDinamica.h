// Arquivo filaDinamica.h

// celula da fila
struct canal {
  int indentificador;
  int valor;
};
/*struct fluxo{
  int valor;
};*/

// para manipular a fila, cria um tipo fila e da um apelido
typedef struct fila Fila;

Fila *cria_Fila();
void libera_Fila(Fila *fi);
int consulta_Fila(Fila *fi, struct canal *comp);
int insere_Fila(Fila *fi, struct canal comp);
int remove_Fila(Fila *fi);
int tamanho_Fila(Fila *fi);
int Fila_vazia(Fila *fi);
int Fila_cheia(Fila *fi);
void imprime_Fila(Fila *fi);
void separa_Fila(Fila *fi, Fila *fluxo1, Fila *fluxo2, Fila *fluxo3);
void dadosCanal(struct canal *comp);