#include <stdio.h>
#include <malloc.h>

struct no{
    int info;
    struct no *ant;
    struct no *prox;
};

typedef struct no *noPtr;

int listaVazia(noPtr a){
    if(a == NULL){
        return 1;
    } else
    {
        return 0;
    }
}
void push(noPtr * a){
    noPtr p = (noPtr)malloc(sizeof(struct no));
    int valor;

    printf("Qual o valor do elemento ?\n");
    scanf("%d",&valor);
    p->ant = NULL;

    if(listaVazia(*a)){
        p->prox = NULL;
    } else
    {
        p->prox = *a;
        (*a)->ant=p;
    }
    *a = p;
}

void pop(noPtr *a){
    noPtr p = *a;
    if(!listaVazia(*a)){
        if(p->prox == NULL){
            *a = NULL;
        }else
        {
            *a = p->prox;
            (*a)->ant = NULL;
        }
        printf("\nO elemento %d foi retirado da pilha\n\n",p->info);
        free(p);
    } else
    {
        printf("\n==================\n");
        printf("A pilha esta vazia");
        printf("\n==================\n");
    }
    
}

void listar(noPtr a){
    
    if(!listaVazia(a)){
        printf("\nElementos da lista\n");
        while (a != NULL){
            printf("%d",a->info);
            a = a->prox;
        }
        printf("\n-->NULL");
    } else{
        printf("\n==================\n");
        printf("A pilha esta vazia");
        printf("\n==================\n");
    }
}
void menu(){
        printf("\nEscolha oq ira fazer:\n");
        printf("1-adicionar elemento\n");   
        printf("2-excluir o elemento\n");    
        printf("3-listar\n");                
        printf("0-sair\n");                  
        printf("============================================================================================\n");
}

int main(){
    noPtr topo = NULL;
    int op;
    do{
        menu();
        scanf("%d", &op);
        switch (op){
            case 1: push(&topo);
            break;
            case 2:pop(&topo);
            break;
            case 3:listar(topo);
            break;
            default: printf("Escolha 1- para adicionar, 2- para excluir o item no topo ou 3- para listar a pilha\n");
            break;
        }
    } while (op !=0);

    return 0;
}


