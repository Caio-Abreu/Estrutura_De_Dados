#include <stdio.h>
#include <malloc.h>

struct no{
    int info;
    struct no *prox;
};

typedef struct no *noPtr;
noPtr topo = NULL;

void push(){
    noPtr p;
    int valor;

    p = (noPtr)malloc(sizeof(struct no));
    printf("Qual o valor do elemento ?\n");
    scanf("%d",&valor);
    p->info=valor;
    p->prox = topo;
    topo = p;
}

void pop(){
    noPtr p = topo;
    if(!listaVazia()){
        topo = topo->prox;
        printf("\nO elemento %d foi retirado da pilha\n\n",p->info);
        free(p);
    } else
    {
        printf("\n==================\n");
        printf("A pilha esta vazia");
        printf("\n==================\n");
    }
    
}
int listaVazia(){
    if(topo == NULL){
        return 1;
    } else
    {
        return 0;
    }
}

void listar(){
    noPtr p = topo;
    int c=0;
    if(!listaVazia()){
        // Estava usando o while e ele estava encerrando o programa
        for (int i = 0; i == c;)
            {
                printf("\n %d \n",p->info);
                printf("==================");
                if(p->prox == NULL){
                    c++;
                }
                p = p->prox;
            }
            
        // while (p->info != NULL){
        //     printf("\n %d \n",p->info);
        //     printf("==================");
        //     p = p->prox;
        // }
    } else{
        printf("\n==================\n");
        printf("A pilha esta vazia");
        printf("\n==================\n");
    }
}
void menu(){
    int op;

    do{
        // printf("============================================================================================");
        printf("\nEscolha oq ira fazer 1-adicionar elemento, 2-excluir o elemento do topo ou 3-listar a pilha:\n");
        printf("============================================================================================\n");
        scanf("%d", &op);
        switch (op){
            case 1: push();
            break;
            case 2:pop();
            break;
            case 3:listar();
            break;
            default: printf("Escolha 1- para adicionar, 2- para excluir o item no topo ou 3- para listar a pilha\n");
            break;
        }
    } while (op !=0);

}

int main(){
    menu();

    return 0;
}