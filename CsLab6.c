#include <stdio.h>
#include <stdlib.h>

struct Book {
    int book_id;
    float price;
    int num_pages;
    int year_published;
};

struct Attraction {
    int attraction_id;
    char name[30];
    char location[30];
    float rating;
};

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    int choice, bookCount = 0;
    struct Book books[10]; 

    FILE* file = fopen("books.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read books from file
    while (bookCount < 10 && fscanf(file, "%d %f %d %d", &books[bookCount].book_id, &books[bookCount].price, &books[bookCount].num_pages, &books[bookCount].year_published) == 4) 
    {
        bookCount++;
    }
    fclose(file);

    while (1) {
        if (bookCount == 0) {
            printf("No books.\n");
            break;
        }
        printf("\nMenu\n");
        printf("1. Display all books\n");
        printf("2. Search for a book by ID\n");
        printf("3. Find the most expensive book\n");
        printf("4. Find the least expensive book\n");
        printf("5. Display total number of books\n");
        printf("6. Display average book price\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
        {
            for (int i = 0; i < bookCount; i++) {
                printf("\nID: %d\n", books[i].book_id);
                printf("Price: %.2f\n", books[i].price);
                printf("Pages: %d\n", books[i].num_pages);
                printf("Year: %d\n", books[i].year_published);
            }
            break;
        }

        case 2: 
        { 
            int searchID;
            printf("Enter the book ID to search for: ");
            scanf("%d", &searchID);
            int found = 0;
            for (int i = 0; i < bookCount; i++) {
                if (books[i].book_id == searchID) {
                    printf("Book found:\n");
                    printf("\nID: %d\n", books[i].book_id);
                    printf("Price: %.2f\n", books[i].price);
                    printf("Pages: %d\n", books[i].num_pages);
                    printf("Year: %d\n", books[i].year_published);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Book not found.\n");
            }
            break;
        }

        case 3: 
        { 

            int expensiveID = 0;
            for (int i = 1; i < bookCount; i++) {
                if (books[i].price > books[expensiveID].price) {
                    expensiveID = i;
                }
            }
            printf("Most expensive book:\n");
            printf("\nID: %d\n", books[expensiveID].book_id);
            printf("Price: %.2f\n", books[expensiveID].price);
            printf("Pages: %d\n", books[expensiveID].num_pages);
            printf("Year: %d\n", books[expensiveID].year_published);
            break;
        }

        case 4: 
        { 
     
            int cheapID = 0;
            for (int i = 1; i < bookCount; i++) {
                if (books[i].price < books[cheapID].price) {
                    cheapID = i;
                }
            }
            printf("Least expensive book:\n");
            printf("\nID: %d\n", books[cheapID].book_id);
            printf("Price: %.2f\n", books[cheapID].price);
            printf("Pages: %d\n", books[cheapID].num_pages);
            printf("Year: %d\n", books[cheapID].year_published);    
            break;
        }

        case 5:
        {
            printf("Total number of books: %d\n", bookCount);
            break;
        }
        case 6: 
        { 
            
            float totalPrice = 0;
            for (int i = 0; i < bookCount; i++) {
                totalPrice += books[i].price;
            }
            printf("Average book price: %.2f\n", totalPrice / bookCount);
            break;
        }

        case 7:
        {
            printf("Exiting program\n");
            return 0;
        }

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    printf("\n==========================================\n");
    printf("==               TASK 2:                ==\n");
    printf("==========================================\n");


    int attractionCount;
    printf("How many attractions?");
    scanf("%d", &attractionCount);

    struct Attraction attractions[attractionCount];


    for (int i = 0; i < attractionCount; i++)
    {
        printf("Enter attraction ID: ");
        scanf("%d", &attractions[i].attraction_id);
        printf("Enter attraction name: ");
        scanf("%s", &attractions[i].name);
        printf("Enter location: ");
        scanf("%s", &attractions[i].location);
        printf("Enter rating: ");
        scanf("%f", &attractions[i].rating);
        printf("\n");
    }
    double sumRating = 0;
    int highestID = 0;
    double highestRating = 0;
    for (int i = 0; i < attractionCount; i++)
    {
        if (attractions[i].rating > highestRating)
        {
            highestRating = attractions[i].rating;
            highestID = i;
        }
        sumRating += attractions[i].rating;
    }
    double averageRating = sumRating / attractionCount;
    printf("Average rating: %.2f", averageRating); 
    printf("\nHighest-rated attraction: %s %.2f", attractions[highestID].name, highestRating);

    return 0;
}
