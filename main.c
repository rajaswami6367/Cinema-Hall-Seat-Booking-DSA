#include <stdio.h>

int main()
{
    int seats[5][5] = {0};
    int i, j, row, seat, choice;

    printf("\n====== CINEMAX ======\n");
    printf("       SCREEN\n\n");

    // Display seats
    for(i = 0; i < 5; i++)
    {
        printf("Row %d: ", i + 1);

        for(j = 0; j < 5; j++)
        {
            printf("[%d] ", seats[i][j]);
        }

        printf("\n");
    }

    // Seat booking
    do
    {
    
    printf("\nEnter Row Number (1-5): ");
    scanf("%d", &row);

    printf("Enter Seat Number (1-5): ");
    scanf("%d", &seat);

    // Input validation
if(row < 1 || row > 5 || seat < 1 || seat > 5)
{
    printf("\nInvalid Seat Selection!\n");
}
else if(seats[row - 1][seat - 1] == 1)
{
    printf("\nSeat Already Booked!\n");
}
else
{
    seats[row - 1][seat - 1] = 1;
    printf("\nSeat Booked Successfully!\n");
}
printf("\nBook another seat? (1 = Yes, 0 = No): ");
scanf("%d", &choice);

} while(choice == 1);

    // Updated seat layout
    printf("\n====== UPDATED SEAT LAYOUT ======\n");

    for(i = 0; i < 5; i++)
    {
        printf("Row %d: ", i + 1);

        for(j = 0; j < 5; j++)
        {
            printf("[%d] ", seats[i][j]);
        }

        printf("\n");
    }
// Search first available seat
    int found = 0;

    printf("\n===== FIRST AVAILABLE SEAT =====\n");

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(seats[i][j] == 0)
            {
                printf("Available Seat: Row %d, Seat %d\n",
                       i + 1, j + 1);

                found = 1;
                break;
            }
        }

        if(found == 1)
        {
            break;
        }
    }

    if(found == 0)
    {
        printf("No Seats Available!\n");
    }
    // Address Calculation
if(row >= 1 && row <= 5 && seat >= 1 && seat <= 5)
{
    int offset = ((row - 1) * 5 + (seat - 1)) * sizeof(int);

    printf("\n===== ADDRESS CALCULATION =====\n");
    printf("Base Address: %p\n", (void*)seats);
    printf("Offset: %d bytes\n", offset);
    printf("Element Address: %p\n",
           (void*)((char*)seats + offset));
}
    return 0;
}