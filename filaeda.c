#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char Itemf; //tipo dos itens

#define avanca(i) (i = (i+1) % F->max)

typedef struct fila {
    int max;
    int topo;
    int inicio;
    int final;
    Itemf *item;
    
}*Fila;

Fila fila(int m){ //criação de fila
    Fila F = malloc(sizeof(struct fila));
    F -> max = m;
    F -> topo = 0;
    F -> inicio = 0;
    F -> final = 0;
    F -> item = malloc(m*sizeof(Itemf));
}

int vaziaf(Fila F){ //teste de fila vazia
    return(F->topo == 0);
}

int cheiaf(Fila f){ //teste de fila cheia
    return(F->topo == F->max);
}

void enfileira(Itemf x, Fila F){ //função para inserção em fila
    if(cheiaf){
        puts("Fila cheia!");
        abort();
    }
    
    F->item[F->final] = x;
    avanca(F->final);
    F->topo++;
}

Itemf desenfileira(Fila F){ //função para remoção em fila
    if(vaziaf){
        puts("Fila vazia!");
        abort();
    }
    Itemf x = F->item[F->inicio];
    avanca(F->inicio);
    F->topo--;
    return x;
    
}

int main()
{
    int max;
    printf("Digite o tamanho maximo da fila: ");
    scanf("%d", &max);
    
    Fila F = fila(max);
    int opcao;
    Itemf item;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir na fila\n");
        printf("2. Remover da fila\n");
        printf("3. Imprimir fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido (char): ");
                scanf(" %c", &item);
                enfileira(item, F);
                break;
            case 2:
                item = desenfileira(F);
                printf("Removido: %c\n", item);
                break;
            case 3:
                imprimeFila(F);
                break;
            case 4:
                free(F->item);
                free(F);
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }
    return 0;

}
