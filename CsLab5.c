#include <stdio.h>
#include <stdlib.h>

int main()
{
    setvbuf(stdout, NULL, _IONBF, 0); 

    int length;
    int sum = 0;  
    int max, min;

    int uniqueCounter = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &length);

    int arr[length];

    printf("Enter the elements: ");
    for (int i = 0; i < length; i++) 
    {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];

    for (int i = 0; i < length; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
        if (arr[i] < min) 
        {
            min = arr[i];
        }
    }

    for (int i = 0; i < length; i++) 
    {
        sum += arr[i];
    }

    float average = (float)sum / length;

    for (int i = 0; i < length / 2; i++) 
    {
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }

    for (int i = 0; i < length; i++)
    { 
        int currentNumber = arr[i];
        while (currentNumber > 0) 
        {
            int digit = currentNumber % 10;  
            if (digit == 1 || digit == 3) 
            {
                uniqueCounter++;
            }
            currentNumber /= 10;  
        }
     
    }
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", max);   
    printf("Minimum: %d\n", min);
    printf("Reversed Array: ");
    for (int i = 0; i < length; i++) 
    {
		printf("%d ", arr[i]);
	}
    printf("\n");
    printf("The number of unique elements: %d\n", uniqueCounter);

    printf("\n==========================================\n");
    printf("==               Task 2:               ==\n");
    printf("==========================================\n");

    int items;
    int size = 100;
    int itemID[size];
    int itemQuantity[size];
    double itemWeight[size];
    double totalWeight = 0;  

    printf("Enter the number of different items: ");
    scanf("%d", &items);

    printf("Enter item ID, quantity and weight per unit (separated by spaces): ");
    for (int i = 0; i < items; i++)
    {
        int id, quantity;
        double weight;
        scanf("%d %d %lf", &id, &quantity, &weight);

        int found = 0;
        for (int j = 0; j < i; j++) 
        {
            if (itemID[j] == id) 
            {
                itemQuantity[j] += quantity;
                found = 1;
                printf("Item ID %d was already entered. Quantities combined.\n", id);
                break;
            }
        }

        if (!found) 
        {
            itemID[i] = id;
            itemQuantity[i] = quantity;
            itemWeight[i] = weight;
        }
    }

    for (int i = 0; i < items; i++) 
    {
        totalWeight += itemWeight[i] * itemQuantity[i];
    }

    printf("Printing items:\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < items; i++) 
    {
        if (itemQuantity[i] > 0) 
        {
            double itemTotalWeight = itemWeight[i] * itemQuantity[i];
            printf("Item ID: %d, Total Quantity: %d, Total Weight: %.2lf\n", itemID[i], itemQuantity[i], itemTotalWeight);
        }
    }
    printf("-------------------------------------------------------------\n");
    printf("Total Weight of All Items: %.2lf\n", totalWeight);

    return 0;
}