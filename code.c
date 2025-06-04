#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void scoreboard(int *rs, int *ps, char *pname) {
    int width = strlen(pname) > 8 ? strlen(pname) : 8;
    int table_width = width + 13;
    for (int i = 0; i < table_width; i++) printf("-");
    printf("\n");
    printf("| %-*s | %-6s |\n", width, "Player", "Score");
    for (int i = 0; i < table_width; i++) printf("-");
    printf("\n");
    printf("| %-*s | %-6d |\n", width, pname, *ps);
    printf("| %-*s | %-6d |\n", width, "Computer", *rs);
    for (int i = 0; i < table_width; i++) printf("-");
    printf("\n");
}

void single_game(int *rs, int *ps, char *pname) {
    int pc, rc;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n");
        printf("Please enter your choice (1-3): ");
        if (scanf("%d", &pc) != 1) {
            while (getchar() != '\n'); // clear input buffer
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (pc < 1 || pc > 3) {
            printf("Invalid choice. Please choose again.\n");
            continue;
        } else {
            break;
        }
    }

    rc = rand() % 3 + 1;
    const char *choices[3] = {"Rock", "Paper", "Scissors"};
    printf("\n%s chose: %s\n", pname, choices[pc - 1]);
    printf("Computer chose: %s\n", choices[rc - 1]);

    if (pc == rc) {
        printf("It's a tie!\n");
    } else if ((pc == 1 && rc == 3) || (pc == 2 && rc == 1) || (pc == 3 && rc == 2)) {
        printf("%s wins!\n", pname);
        (*ps)++;
    } else {
        printf("%s loses!\n", pname);
        (*rs)++;
    }
}

void best_of_3(int *rs, int *ps, char *pname) {
    while (1) {
        single_game(rs, ps, pname);
        scoreboard(rs, ps, pname);
        if (*rs == 2 || *ps == 2) {
            printf("%s wins the best of 3!\n", (*ps > *rs) ? pname : "Computer");
            break;
        }
    }
}

void infinite_game(int *rs, int *ps, char *pname) {
    while (1) {
        single_game(rs, ps, pname);
        scoreboard(rs, ps, pname);
        int s;
        while (1) {
            printf("\nDo you want to continue? (1 for Yes, 0 for No): ");
            if (scanf("%d", &s) != 1) {
                while (getchar() != '\n'); 
                printf("Invalid input. Please enter 1 or 0.\n");
                continue;
            }
            if (s == 1 || s == 0) break;
            printf("Invalid input. Please enter 1 or 0.\n");
        }
        if (s == 0) {
            printf("\nFinal Score:\n");
            scoreboard(rs, ps, pname);
            printf("%s wins the game!\n", (*ps > *rs) ? pname : "C]omputer");
            break;
        }
    }
}

int main() {
    int rs = 0, ps = 0, ch;
    char pname[30];

    srand(time(NULL));

    printf("===== Rock Paper Scissors Game =====\n");
    while (1) {
        printf("\nEnter Player Name: ");
        fgets(pname, sizeof(pname), stdin);
        pname[strcspn(pname, "\n")] = 0; // remove newline
        if (strlen(pname) == 0) {
            printf("\nPlayer name cannot be empty.\n");
        } else {
            break;
        }
    }

    printf("Welcome %s\n", pname);

    while (1) {
        printf("\nChoose your option:\n");
        printf("1. Single game\n");
        printf("2. Best of 3\n");
        printf("3. Infinite game\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &ch) != 1) {
            while (getchar() != '\n'); // clear input buffer
            printf("\nInvalid input. Please enter a number.\n");
            continue;
        }

        switch (ch) {
            case 1:
                printf("\nYou chose Single game.\n");
                single_game(&rs, &ps, pname);
                printf("\n===============================================\n");
                rs = ps = 0;
                break;

            case 2:
                printf("\nYou chose Best of 3.\n");
                best_of_3(&rs, &ps, pname);
                printf("\n===============================================\n");
                rs = ps = 0;
                break;

            case 3:
                printf("\nYou chose Infinite game.\n");
                infinite_game(&rs, &ps, pname);
                rs = ps = 0;
                printf("\n===============================================\n");
                break;

            case 4:
                printf("\nExiting the game.\n");
                printf("\n===============================================\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please choose again.\n");
                printf("\n===============================================\n");
                break;
        }
    }
    return 0;
}
