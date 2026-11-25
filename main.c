#include <stdio.h>

int main()
{
    int seats[5][5] = {0};
    int i, j;

    printf("\n====== CINEMAX ======\n");
    printf("       SCREEN\n\n");

    for(i = 0; i < 5; i++)
    {
        printf("Row %d: ", i + 1);

        for(j = 0; j < 5; j++)
        {
            printf("[%d] ", seats[i][j]);
        }

        printf("\n");
    }

    return 0;
}