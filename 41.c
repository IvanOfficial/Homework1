#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i,j;
    scanf("%d", &n);
    int mas[100000][2];
    for (i = 1; i <= n; i +=1)
    {
        scanf("%d %d", &mas[i-1][0], &mas[i-1][1]);

    }

    for(i = 0 ; i < n - 1; i++)
    {
   // сравниваем два соседних элемента.
        for(j = 0 ; j < n - i - 1 ; j++)
        {
            if(mas[j][1] > mas[j+1][1])
            {
          // если они идут в неправильном порядке, то
          //  меняем их местами.
                int tmp = mas[j][1];
                mas[j][1] = mas[j+1][1];
                mas[j+1][1] = tmp;
                int tmp1 = mas[j][0];
                mas[j][0] = mas[j+1][0];
                mas[j+1][0] = tmp1;
            }
        }
    }
    /*for ( i = 0; i < n; i ++)
    {
        printf("|massa: %d strong: %d|\n", mas[i][0], mas[i][1]);
    }*/

    int massa_pir;
    int piramid[100000][2];
    piramid[0][0] = mas[0][0];
    piramid[0][1] = mas[0][1];
    massa_pir = piramid[0][0];
    int k;
    k = 1;
    for (i = 1; i <= n-1; i +=1)
    {
        if (mas[i][1] >= massa_pir)
        {
            piramid[k][0] = mas[i][0];
            piramid[k][1] = mas[i][1];
            massa_pir += piramid[k][0];
            k += 1;
        }
    }

    printf("Ответ : \n");


    for (i = 1; i <= k; i +=1)
    {
        printf("%d %d\n", piramid[i-1][0], piramid[i-1][1]);

    }

    return 0;

}
