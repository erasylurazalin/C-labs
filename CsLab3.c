#include <stdio.h>
int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("==========================================\n");
    printf("==               TASK 1:                ==\n");
    printf("==========================================\n");

    int N;
    int temp;
    int sum;
    printf("Enter N:");
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        temp = i;
        sum = 0;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        if (sum == 2 || sum == 3 || sum == 5 || sum == 7 || sum == 11 || sum == 13 || sum == 17 || sum == 19 || sum == 23)
            printf(" %d: Sum of digits = %d, which is a prime number.\n", i, sum);
    }
    printf("\n==========================================\n");
    printf("==               TASK 2:                ==\n");
    printf("==========================================\n");



    printf("=========================================\n");
    printf("Welcome to the Treasure Hunt Adventure!\n");
    printf("=========================================\n");
    printf("Rules:\n");
    printf("- You are an adventurer on a 3x3 grid. Each position on the grid may contain a treasure, a trap, a\n");
    printf("  potion, or be empty.\n");
    printf("- Your goal is to navigate through the grid, collect treasures, avoid traps, and reach the exit at the\n");
    printf("  bottom-right corner.\n");
    printf("- You start with 100 Health Points (HP) and 0 points. Treasures increase your score, traps reduce your\n");
    printf("  HP, and potions restore your HP.\n");
    printf("- You can move in four directions: Up (W), Down (S), Left (A), or Right (D).\n");
    printf("- The game ends when you reach the exit (or user presses E for quitting the game) or if your HP drops to 0.\n");
    printf("Let's begin! Your adventure starts now.\n\n");

    int x = 2;
    int y = 2;
    char move;
    int score = 0;
    int hp = 100;

    while (1)
    {
        printf("Your move: ");
        scanf(" %c", &move);

        if (move == 'w') 
        {
            if (y == 1)
			{
				printf("Invalid move! There is a bound!\n");
                continue;
			}
            else
            {
                y--;
            }
            

        }
        else if (move == 's') 
        {
            if (y == 3)
            {
                printf("Invalid move! There is a bound!\n");
                continue;
            }
            else
            {
                y++;
            }

        }
        else if (move == 'a') 
        {
            if (x == 1)
            {
                printf("Invalid move! There is a bound!\n");
                continue;
            }
            else
            {
                x--;
            }

        }
        else if (move == 'd') 
        {
            if (x == 3)
            {
                printf("Invalid move! There is a bound!\n");
                continue;
            }
            else
            {
                x++;
            }

        }
        else if (move == 'e') 
        {
            break;
        }
        else 
        {
            printf("Invalid move!\n");
            continue;
        }

        printf("Location: (%d, %d)  ", y, x);

        if (x == 1 && y == 1)
        {
            printf("It's empty. Nothing happens.\n");
        }
        else if (x == 2 && y == 1)
        {
            printf("Oh no! You stepped on a trap! -20 HP.\n");
            hp -= 20;

        }
        else if (x == 3 && y == 1)
        {
            printf("It's empty. Nothing happens.\n");

        }
        else if (x == 1 && y == 2)
        {
            printf("You found a potion! +20 HP\n");
            hp += 20;
        }
        else if (x == 2 && y == 2)
        {
            printf("It's empty. Nothing happens.\n");

        }
        else if (x == 3 && y == 2)
        {
            printf("Oh no! You stepped on a trap! -30 HP.\n");
            hp -= 30;
        }
        else if (x == 1 && y == 3)
        {
            printf("Congratulations! You found a treasure! +20 points.\n");
            score += 20;
        }
        else if (x == 2 && y == 3)
        {
            printf("It's empty. Nothing happens.\n");

        }
        else if (x == 3 && y == 3)
        {
            printf("You've found the exit! The game ends.\n");
            break;
        }
        printf("HP: %d\n", hp);
        printf("Score: %d\n", score);
        if (hp <= 0)
		{
			printf("Game over! You are dead.\n");
            hp = 0;
			break;
		}   
    }
    printf(" Congratulations! You've completed the game. Final Score: %d, Final HP: %d.", score, hp);
    return 0;
}