
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>

uint32_t surface_area(uint16_t l, uint16_t w, uint16_t h) {
    uint16_t side1 = l * w;
    uint16_t small_side = side1;
    uint16_t side2 = w * h;
    small_side = small_side > side2 ? side2 : small_side;
    uint16_t side3 = h * l;
    small_side = small_side > side3 ? side3 : small_side;

    return 2 * (side1 + side2 + side3) + small_side;
}

uint32_t ribbon_length(uint16_t l, uint16_t w, uint16_t h) {
    uint32_t bow = l * w * h;

    uint32_t ribbon = l + w;
    ribbon = ribbon > w + h ? w + h : ribbon;
    ribbon = ribbon > h + l ? h + l : ribbon;

    return bow + 2 * ribbon;
}

void problem_1(FILE *input) {
    uint16_t l, w, h;
    uint64_t total_wrapping = 0;

    while (fscanf(input, "%hdx%hdx%hd", &l, &w, &h) == 3) {
        total_wrapping += surface_area(l, w, h);
    }

    printf("Total wrapping: %lu\n", total_wrapping);
}

void problem_2(FILE *input) {
    uint16_t l, w, h;
    uint64_t total_wrapping = 0;
    uint64_t total_ribbon = 0;

    while (fscanf(input, "%hdx%hdx%hd", &l, &w, &h) == 3) {
        total_wrapping += surface_area(l, w, h);
        total_ribbon += ribbon_length(l, w, h);
    }

    printf("Total wrapping: %lu\n", total_wrapping);
    printf("Total ribbon: %lu\n", total_ribbon);
}

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

    /*problem_1(input);*/
    problem_2(input);

    fclose(input);
    return 0;
}
