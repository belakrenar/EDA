#include "pilhaa.h"
#include <stdio.h>
#include <stdlib.h>

Pilha pilha(int m) {
    Pilha P = malloc(sizeof(struct pilha));
    P->max = m;
    P->topo1 = -1;
    P->topo2 = m; // O topo da segunda pilha começa logo após o fim da primeira
    P->item = malloc(m * sizeof(Itemp));
    return P;
}

int vaziap1(Pilha P) {
    if (P->topo1 == -1)
        return 1;
    else
        return 0;
}

int vaziap2(Pilha P) {
    if (P->topo2 == P->max)
        return 1;
    else
        return 0;
}

int cheiap1(Pilha P) {
    if (P->topo1 == P->topo2 - 1)
        return 1;
    else
        return 0;
}

int cheiap2(Pilha P) {
    if (P->topo2 == P->topo1 + 1)
        return 1;
    else
        return 0;
}

void empilha1(Itemp x, Pilha P) {
    if (cheiap1(P)) {
        puts("pilha 1 cheia!");
        abort();
    }
    P->topo1++;
    P->item[P->topo1] = x;
}

void empilha2(Itemp x, Pilha P) {
    if (cheiap2(P)) {
        puts("pilha 2 cheia!");
        abort();
    }
    P->topo2--;
    P->item[P->topo2] = x;
}

Itemp desempilha1(Pilha P) {
    if (vaziap1(P)) {
        puts("pilha 1 vazia!");
        abort();
    }
    Itemp x = P->item[P->topo1];
    P->topo1--;
    return x;
}

Itemp desempilha2(Pilha P) {
    if (vaziap2(P)) {
        puts("pilha 2 vazia!");
        abort();
    }
    Itemp x = P->item[P->topo2];
    P->topo2++;
    return x;
}

Itemp topo1(Pilha P) {
    if (vaziap1(P)) {
        puts("pilha 1 vazia!");
        abort();
    }
    return P->item[P->topo1];
}

Itemp topo2(Pilha P) {
    if (vaziap2(P)) {
        puts("pilha 2 vazia!");
        abort();
    }
    return P->item[P->topo2];
}

void destroip(Pilha *Q) {
    free((*Q)->item);
    free(*Q);
    *Q = NULL;
}

