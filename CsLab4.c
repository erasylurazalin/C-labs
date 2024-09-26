#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE* inputFile = fopen("input.csv", "r");

    int productCount = 0;
    double totalValue = 0.0;
    double totalPrice = 0.0;
    char mostExpensiveName[50] = "";
    char leastExpensiveName[50] = "";
    double mostExpensivePrice = 0.0;
    double leastExpensivePrice = 0.0;
    char lineSize[1024];

    fgets(lineSize, sizeof(lineSize), inputFile);

    while (fgets(lineSize, sizeof(lineSize), inputFile)) 
    {
        char name[50];
        double price;
        int quantity;

        if (sscanf(lineSize, "%50[^,],%lf,%d", name, &price, &quantity) == 3) 
        {
         
            totalValue += price * quantity;
            totalPrice += price;
            productCount++;

            
            if (productCount == 1 || price > mostExpensivePrice) 
            {
                strcpy(mostExpensiveName, name);
                mostExpensivePrice = price;
            }
            if (productCount == 1 || price < leastExpensivePrice) 
            {
                strcpy(leastExpensiveName, name);
                leastExpensivePrice = price;
            }
        }
    }
    fclose(inputFile);

    
    if (productCount > 0) 
    {
        double averagePrice = totalPrice / productCount;

        FILE* outputFile = fopen("summary.txt", "w");


        // Write the results to the output file
        fprintf(outputFile, "Total number of products: %d\n", productCount);
        fprintf(outputFile, "Total value of all products: %.2f\n", totalValue);
        fprintf(outputFile, "Most expensive product: %s ($%.2f)\n", mostExpensiveName, mostExpensivePrice);
        fprintf(outputFile, "Least expensive product: %s ($%.2f)\n", leastExpensiveName, leastExpensivePrice);
        fprintf(outputFile, "Average price of products: $%.2f\n", averagePrice);

        fclose(outputFile);
    }




    

    printf("\n==========================================\n");
    printf("==               TASK 2:                ==\n");
    printf("==========================================\n");

    
    FILE* input2 = fopen("text.txt", "r");
    FILE* output2 = fopen("text_summary.txt", "w");


    char line[1024];
    int lineCounter = 0;
    int wordCounter = 0;
    int longestLineLength = 0;
    int longestLine = 0;
    int mostWordsLine = 0;
    int mostWordsCount = 0;

    while (fgets(line, sizeof(line), input2)) 
    {
        lineCounter++;  

        int currentLineLength = 0;
        int currentLineWord = 0;
        for (int i = 0; line[i] != '\0'; i++) 
        {
            currentLineLength++; 

           
            if (!isspace(line[i]) && (i == 0 || isspace(line[i - 1]))) 
            {
                currentLineWord++; 
            }
        }

        wordCounter += currentLineWord;

        if (currentLineLength > longestLineLength) 
        {
            longestLineLength = currentLineLength;  
            longestLine = lineCounter;  
        }

        if (currentLineWord > mostWordsCount) 
        {
            mostWordsCount = currentLineWord; 
            mostWordsLine = lineCounter;  
        }
    }

    fprintf(output2, "Total number of lines: %d\n", lineCounter);
    fprintf(output2, "Total number of words: %d\n", wordCounter);
    fprintf(output2, "The longest line (by characters): Line %d (%d characters).\n", longestLine, longestLineLength);
    fprintf(output2, "The line with the most words: Line %d (%d words)\n", mostWordsLine, mostWordsCount);

    fclose(input2);
    fclose(output2);

    printf("Summary written to text_summary.txt\n");

    return 0;

}