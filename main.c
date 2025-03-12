
#include <stdio.h>

void problem_1(FILE *input) {}
void problem_2(FILE *input) {}

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

    problem_1(input);
    problem_2(input);

    fclose(input);
    return 0;
}
