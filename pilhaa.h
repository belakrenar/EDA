typedef char Itemp;

typedef struct pilha {
    int max;
    int topo1;
    int topo2;
    Itemp *item;
} *Pilha;

Pilha pilha(int m);
int vaziap1(Pilha P);
int vaziap2(Pilha P);
int cheiap1(Pilha P);
int cheiap2(Pilha P);
void empilha1(Itemp x, Pilha P);
void empilha2(Itemp x, Pilha P);
Itemp desempilha1(Pilha P);
Itemp desempilha2(Pilha P);
Itemp topo1(Pilha P);
Itemp topo2(Pilha P);
void destroip(Pilha *Q);