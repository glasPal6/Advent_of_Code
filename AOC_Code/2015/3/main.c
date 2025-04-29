
#include <stdint.h>
#include <stdio.h>

typedef struct {
    int32_t x;
    int32_t y;
} house_position;

// TODO: Datastructure for searching this. Maybe a tree of some kind
// Hash map will be quicker

void problem_1(FILE *input) {
    uint64_t houses = 1; // Initial house count
    house_position current_house = {0, 0};

    char c = ' ';
    do {
        c = (char)fgetc(input);
        if (c == EOF)
            break;

        switch (c) {
        case '>':
            current_house.x++;
            break;
        case '<':
            current_house.x--;
            break;
        case '^':
            current_house.y++;
            break;
        case 'v':
            current_house.y--;
            break;
        default:
            break;
        }
    } while (c != EOF);
}

/*void problem_2(FILE *input) {}*/

int main(int argc, char *argv[]) {
    char *filename = "input.txt";
    if (argc == 2) {
        filename = argv[1];
    }

    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("The input file cannot be opened!\n");
        return 1;
    }

    problem_1(input);
    /*problem_2(input);*/

    fclose(input);
    return 0;
}
