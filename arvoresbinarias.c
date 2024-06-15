#include <stdlib.h>
#include <stdio.h>

typedef int Item;
typedef struct arv{
    struct arv *esq; // sub arvore esquerda
    Item item;
    struct arv *dir; // sub arvore direita
} *Arv;

Arv arv(Arv e, Item x, Arv d){ // função para criar arvore binaria
   Arv n = malloc(sizeof(struct arv));
   n->esq = e;
   n->item = x;
   n->dir = d;
   
   return n;
}

void destroi(Arv *A){ // A função de destruição emprega um percurso pós-ordem: primeiro destrói a subárvore esquerda, depois destrói a subárvore direita e, por fim, desaloca a raiz da árvore.
    if (*A == NULL)
        return;
    destroi(&(*A)->esq);
    destroi(&(*A)->dir);
    free(*A);
    *A = NULL;
}

void insABB(Item x, Arv *A){ //// inserir valor em árvore de busca binária
    if (*A == NULL)
        *A = arv(NULL, x, NULL);
    else if (x <= (*A)->item)
        insABB(x, &(*A)->esq);
    else
        insABB(x, &(*A)->dir);
}

void em_ordem(Arv A){
    if (A == NULL)
        return;
    em_ordem(A->esq); // esquerda
    printf("%i ", A->item); // raiz
    em_ordem(A->dir); // direita
}

void pre_ordem(Arv A){
    if (A == NULL)
        return;
    printf("%i ", A->item); // raiz
    pre_ordem(A->esq); // esquerda
    pre_ordem(A->dir); // direita
}

void pos_ordem(Arv A){
    if (A == NULL)
        return;
    pos_ordem(A->esq); // esquerda
    pos_ordem(A->dir); // direita
    printf("%i ", A->item); // raiz
}

int main(){
    Arv a = NULL;    
    a = arv(NULL, 1, NULL);
    if (a != NULL){
       printf("\nRaiz %i\n", a->item);
    }
    
    int opcao, numero;
    
    while(1){
        printf("\nMenu:\n");
        printf("1. Inserir valor\n");
        printf("2. Imprimir em ordem\n");
        printf("3. Imprimir em pre-ordem\n");
        printf("4. Imprimir em pos-ordem\n");
        printf("5. Destruir Arvore\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &numero);
                insABB(numero, &a);
                break;
            case 2:
                printf("Arvore em ordem: ");
                em_ordem(a);
                printf("\n");
                break;
            case 3:
                printf("Arvore em pre-ordem: ");
                pre_ordem(a);
                printf("\n");
                break;
            case 4:
                printf("Arvore em pos-ordem: ");
                pos_ordem(a);
                printf("\n");
                break;
            case 5:
                printf("Arvore destruída.")
                destroi(&a);
                return 0;
            default:
                printf("Opcao invalida\n"); 
        }
    }

    return 0;
}
