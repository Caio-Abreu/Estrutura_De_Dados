#include <stdio.h>
#include <malloc.h>

struct no{
    int info;
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
void push(noPtr * a,int *n){
    noPtr p = (noPtr)malloc(sizeof(struct no));
    int valor;

    printf("Qual o valor do elemento ?\n\n");
    scanf("%d",&valor);

    if(listaVazia(*a)){ // quando entrar pela primeira vez o primeiro nó criado ira apontar para o topo
        p->info = valor;
        *a = p;
        p->prox = *a;
    } else // quando entrar de novo nao estara vazia logo sera criado um novo nó apontando para o antigo e ele sera o novo topo
    {
        p->prox = *a;
        p->info = valor;
        *a = p;
        for (int i = 0; i <= *n; i++) // vai pecorrer a lista para atualizar o ultimo nó com o topo 
        {
            if(i == *n){
                p->prox = *a;
            }
            p = p->prox;
        }
        
    }
    printf("\n----------------------------------");
    printf("\nO endereco de memoria esta em %p \n", *a);
    printf("----------------------------------\n");
    *n = *n+1;
}

void pop(noPtr *a, int *n){
    noPtr p = *a, ant = *a,aux;
    int num,i,j=0;
    printf("Digite o numero que quer retirar:\n");
    scanf("%d", &num);
    if(listaVazia(*a)){
        printf("\n==================\n");
        printf("A Lista esta vazia");
        printf("\n==================\n");

    } else{
        for (i = 0; i < *n; i++){ 
                if(num == p->info){
                    if(i > 0){
                    ant->prox = p->prox;
                    }
                    if(i == 0){ // ele ira entrar aqui quando se for o primeiro nó
                     *a = p->prox; // fará a substituição 

                     for (int l = 0; l < *n-1; l++) // ira pecorrer o nó até o ultimo
                     {
                        ant = ant->prox; 
                        // aux = ant;
                     }
                     ant->prox = *a; // depois de ter chego no ultimo ira colocar o endereço do primeiro novo nó 
                    }
                    free(p);
                    *n = *n-1;
                    j++;
                }
                ant = p;
                p = p->prox;
            }     
            if(j == 0){
                printf("\n==================\n");
                printf("Nao foi achado o numero");
                printf("\n==================\n");
            }
            if (*n == 0) // se nao tiver elementos o topo sera NULL
            {
                *a = NULL;
            }
            
    }
}

void listar(noPtr *a, int *n){
    noPtr p = *a;
    int num;
    if(!listaVazia(*a)){
        printf("\n==================\n");
        printf("\nElementos da lista\n");
        printf("\n==================\n");
        for (int i = 0; i < *n; i++)
        {
            if(i == 0){
                printf("\nO endereco do primeiro elemento eh %p\n", *a);
            }
            num = p->info;
            printf("\nValor do %d no eh %d\n",i+1,num);
            if(i == *n-1){
                printf("\nO endereco do ultimo (endereco->prox) eh %p\n",p->prox);
            }
            p = p->prox;
        }
        
    } else{
        printf("\n==================\n");
        printf("A lista esta vazia");
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
    int op, qtde = 0;
    do{
        menu();
        scanf("%d", &op);
        switch (op){
            case 1: push(&topo,&qtde);
            break;
            case 2:pop(&topo,&qtde);
            break;
            case 3:listar(&topo,&qtde);
            break;
            default: printf("Escolha 1- para adicionar, 2- para excluir o elemento ou 3- para listar\n");
            break;
        }
    } while (op !=0);

    return 0;
}