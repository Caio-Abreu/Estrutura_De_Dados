 #include <stdio.h>

int busca_binaria(int vetor[],int ob, int inicio,int fim){
    int meio = (inicio + fim)/2;
    if (inicio > fim) {  
        return printf("Nao achamos o valor");
    } 
    if(ob == vetor[meio]){
            return printf("o valor esta na posicao %d do vetor",meio);
        }
    if(vetor[meio] < ob){
            busca_binaria(vetor,ob,meio+1,fim);
        } else{
            busca_binaria(vetor,ob,inicio,meio-1);
        }
}

int main(){
    int vetor[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int ob;
    int t= 19;
    printf("Digite o valor que deseja procurar no vetor:");
    scanf("%d",&ob);

    busca_binaria(vetor,ob,0,t);
 }
