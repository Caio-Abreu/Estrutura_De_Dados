#include <stdio.h>
#include <stdlib.h>

int main(){
    int var[] = { 22, 78, 49, 13, 55, 67 };
    int i, j, aux, n;
    n = 5;
    for (i = 1; i <= n; i++)
    {
        aux = var[i];
        for (j = i; (j > 0) && (aux < var[j - 1]); j--){
            var[j] = var[j - 1];
			}
        var[j]=aux;

    }
    for (i = 0; i <= n; i++)
    {
        printf("%d \n", var[i]);
    }
    system("pause");
    return 0;
}
