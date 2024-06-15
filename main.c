#include "pilhaa.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_VETOR 100


Pilha cria_multipilha(int tamvet) {
    Pilha P = malloc(sizeof(struct pilha));
    if (P == NULL) {
        puts("Erro ao alocar memória para a multipilha.");
        exit(EXIT_FAILURE);
    }
    P->max = tamvet;
    P->topo1 = -1;
    P->topo2 = tamvet;
    P->item = malloc(tamvet * sizeof(Itemp));
    if (P->item == NULL) {
        puts("Erro ao alocar memória para o vetor de itens.");
        exit(EXIT_FAILURE);
    }
    return P;
}

void destroi_multipilha(Pilha *MP) {
    destroip(MP);
}

void reinicializa_pilha_alvo(int pilha_alvo, Pilha MP, int tamvet) {
    if (pilha_alvo == 1)
        MP->topo1 = -1;
    else if (pilha_alvo == 2)
        MP->topo2 = tamvet;
    else {
        puts("Pilha-alvo inválida.");
        exit(EXIT_FAILURE);
    }
}

void empilha_pilha_alvo(Itemp x, int pilha_alvo, Pilha MP) {
    if (pilha_alvo == 1)
        empilha1(x, MP);
    else if (pilha_alvo == 2)
        empilha2(x, MP);
    else {
        puts("Pilha-alvo inválida.");
        exit(EXIT_FAILURE);
    }
}

Itemp desempilha_pilha_alvo(int pilha_alvo, Pilha MP) {
    if (pilha_alvo == 1)
        return desempilha1(MP);
    else if (pilha_alvo == 2)
        return desempilha2(MP);
    else {
        puts("Pilha-alvo inválida.");
        exit(EXIT_FAILURE);
    }
}

int pilha_alvo_cheia(int pilha_alvo, Pilha MP) {
    if (pilha_alvo == 1)
        return cheiap1(MP);
    else if (pilha_alvo == 2)
        return cheiap2(MP);
    else {
        puts("Pilha-alvo inválida.");
        exit(EXIT_FAILURE);
    }
}

int pilha_alvo_vazia(int pilha_alvo, Pilha MP) {
    if (pilha_alvo == 1)
        return vaziap1(MP);
    else if (pilha_alvo == 2)
        return vaziap2(MP);
    else {
        puts("Pilha-alvo inválida.");
        exit(EXIT_FAILURE);
    }
}

Itemp busca_topo_pilha_alvo(int pilha_alvo, Pilha MP) {
    if (pilha_alvo == 1)
        return topo1(MP);
    else if (pilha_alvo == 2)
        return topo2(MP);
    else {
        puts("Pilha-alvo inválida.");
        exit(EXIT_FAILURE);
    }
}

int num_elementos_pilha_alvo(int pilha_alvo, Pilha MP, int tamvet) {
    if (pilha_alvo == 1)
        return MP->topo1 + 1;
    else if (pilha_alvo == 2)
        return tamvet - MP->topo2;
    else {
        puts("Pilha-alvo inválida.");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Pilha MP = NULL;
    int escolha, confirma;
    int pilha_alvo;
    Itemp x;
    int tamvet = TAM_VETOR;

    do {
        printf("\nMenu de Ações\n");
        printf("1- Criar Pilha\n");
        printf("2- Empilhamento em Pilha Alvo\n");
        printf("3- Desempilha em Pilha Alvo\n");
        printf("4- Reinicia Pilha Alvo\n");
        printf("5- Destruir Pilha\n");
        printf("6- Buscar Topo Alvo\n");
        printf("7- Contar Pilha Alvo\n");
        printf("0- Sair\n");

        printf("\nDigite o número da ação: ");
        scanf("%i", &escolha);

        switch (escolha) {
            case 1:
                printf("Informe tamanho total das Pilhas: ");
                scanf("%i", &tamvet);
                MP = cria_multipilha(tamvet);
                printf("Pilha criada com sucesso.\n");
                break;
            case 2:
                printf("Informe a Pilha que deseja alterar: ");
                scanf("%i", &pilha_alvo);
                printf("O que deseja empilhar: ");
                scanf(" %c", &x);
                empilha_pilha_alvo(x, pilha_alvo, MP);
                printf("\nEmpilhado com Sucesso\n");
                break;
            case 3:
                printf("Informe a Pilha que deseja alterar: ");
                scanf("%i", &pilha_alvo);
                desempilha_pilha_alvo(pilha_alvo, MP);
                printf("\nDesempilhado com Sucesso\n");
                break;
            case 4: 
                printf("Informe a Pilha que deseja reiniciar: ");
                scanf("%i", &pilha_alvo);
                reinicializa_pilha_alvo(pilha_alvo, MP, tamvet);
                printf("\nPilha reiniciada com sucesso.\n");
                break;
            case 5:
                printf("A ação de Destruir as pilhas é irreversível, tem certeza que deseja continuar?\nDigite 1 para Sim\t0 para Não\n");
                scanf("%i", &confirma);
                if (confirma == 1) {
                    destroi_multipilha(&MP);
                    printf("Pilhas destruídas com sucesso.\n");
                } else {
                    printf("Ação de destruição cancelada.\n");
                }
                break;
            case 6:
                printf("Informe a Pilha que deseja Buscar: ");
                scanf("%i", &pilha_alvo);
                printf("\nEncontrado no Topo %i : %c\n", pilha_alvo, busca_topo_pilha_alvo(pilha_alvo, MP));
                break;
            case 7:
                printf("Informe a Pilha que deseja contar: ");
                scanf("%i", &pilha_alvo);
                printf("Tamanho da pilha de Topo %i : %d\n", pilha_alvo, num_elementos_pilha_alvo(pilha_alvo, MP, tamvet));
                break;
            case 0:
                printf("\nPrograma Encerrado\n");
                if (MP != NULL) {
                    destroi_multipilha(&MP);
                }
                break;
            default:
                printf("\nAção Inexistente, digite novamente\n");
                break;
        }
    } while (escolha != 0);

    return 0;  
}
