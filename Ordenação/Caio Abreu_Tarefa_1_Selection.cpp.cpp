#include <stdio.h>
#include <stdlib.h>

int main(){
    int var[] = { };
    int i, j, aux, n,troca;
    n = 5;
    for (i = 0; i <= n-1; i++)
    {
        aux = i;
        for (j = i+1; j<=n ; j++){
            if(var[j]<var[aux])
            	aux=j;
			}
        if(i!= aux){
        	troca=var[i];
        	var[i]=var[aux];
        	var[aux]=troca;
		}

    }
    for (i = 0; i <= n; i++)
    {
        printf("%d \n", var[i]);
    }
    system("pause");
    return 0;
}
