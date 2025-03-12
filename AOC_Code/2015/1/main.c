
#include <stdbool.h>
#include <stdio.h>

void problem_1(FILE *input) {
    int floor = 0;
    char c = ' ';

    do {
        c = (char)fgetc(input);
        if (c == EOF)
            break;

        switch (c) {
        case '(':
            floor++;
            break;
        case ')':
            floor--;
            break;
        default:
            break;
        }

    } while (c != EOF);

    printf("Floor: %d\n", floor);
}

void problem_2(FILE *input) {
    int floor = 0;
    int count = 1;
    int basement_pos = -1;
    char c = ' ';

    do {
        c = (char)fgetc(input);
        if (c == EOF)
            break;

        switch (c) {
        case '(':
            floor++;
            break;
        case ')':
            floor--;
            break;
        default:
            break;
        }

        // Flag it so that it does not go again
        if (basement_pos == -1 && floor == -1)
            basement_pos = count;
        count++;

    } while (c != EOF);

    printf("Floor: %d\n", floor);
    printf("Basement Position: %d\n", basement_pos);
}

int main(int argc, char *argv[]) {
    char *filename = "input.txt";
    if (argc == 2) {
        filename = argv[1];
    }

    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("The input file cannot be opened!");
        return 1;
    }

    /*problem_1(input);*/
    problem_2(input);

    fclose(input);
    return 0;
}
