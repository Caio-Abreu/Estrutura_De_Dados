#include <stdio.h>
#include <malloc.h>

struct no{
    int info;
    struct no *prox;
};

typedef struct no *noPtr;
noPtr topo = NULL;
noPtr ult = NULL;

void enqueue (){
    noPtr p;  
    int valor;

    p = (noPtr)malloc(sizeof(struct no));
    printf("Digite o valor do elemento: ");
    scanf("%d",&valor);

    p->info = valor;
    p->prox = NULL;

    if(listaVazia()){
      topo = p; 
      ult = topo;
      
    } else{
      ult->prox = p; 
      ult = p;
    }
    printf("\n----------------------------------");
    printf("\nO elemento %d foi adicionado a Fila\n",valor);
    printf("----------------------------------\n");
}

void dequeue(){
    noPtr p = topo;
    if(listaVazia()){
        printf("\n==================\n");
        printf("A Fila esta vazia");
        printf("\n==================\n");

    } else{
        topo = topo->prox;
        printf("\n----------------------------------");
        printf("\nO elemento %d foi retirado da Fila\n",p->info);
        printf("------------------------------------\n");
        free(p); 
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
    int c = 0;
    if(!listaVazia()){
        for (int i = 0; i == c;)
            {
                printf("\n %d \n",p->info);
                printf("==================");
                if(p->prox == NULL){
                    c++;
                }
                p = p->prox;
            }    
        // Estava usando o while e ele estava encerrando o programa
        // while (p->info != NULL){
        //     printf("\n %d \n",p->info);
        //     printf("==================");
        //     p = p->prox;
        // }
    } else{
        printf("\n==================\n");
        printf("A Fila esta vazia");
        printf("\n==================\n");
    }
}

void menu(){
    int op;

    do{
        // printf("============================================================================================");
        printf("\nEscolha oq ira fazer(1-adicionar elemento, 2-excluir o elemento do topo, 3-listar a Fila ou 0-Sair:)\n");
        printf("=====================================================================================================\n");
        scanf("%d", &op);
        switch (op){
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: listar();
            break;
            
            default: printf("\nEscolha 1- para adicionar, 2- para excluir o item no topo ou 3- para listar a Fila\n");
            break;
        }
    } while (op !=0);

}

int main(){
    menu();
    return 0;
}