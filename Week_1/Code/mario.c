#include <stdio.h>

// create code that roughly represents these four horizontal blocks
/* int main(void) {
    for (int i = 0; i < 4; i++) {
        printf("?");
    }
    printf("\n");
} */

// create three vertical blocks
/* int main(void) {
    for (int i = 0; i < 3; i++) {
        printf("#\n");
    }
} */

// create a three-by-three group of blocks
/* int main(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("#");
        }
        printf("\n");
    }
} */

// ensure that the number of blocks to be constant, that is, unchangeable
/* int main(void) {
    const int n = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }
} */

// we can make our code prompt the user for the size of the grid
/* int main(void) {
    int n = get_int("Size: ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }
} */

// A general piece of advice within programming is that you should never fully trust your user. 
// They will likely misbehave, typing incorrect values where they should not. 
// We can protect our program from bad behavior by checking to make sure the user’s input satisfies our needs.
/* int main(void) {
    // Get size of grid
    int n;
    do {
        n = get_int("Size: ");
    }
    while (n < 1);

    // Print grid of bricks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
} */

// Abstraction the problem
int get_size(void);
void print_grid(int n);

int main(void) {
    int n = get_size();
    print_grid(n);
}

int get_size(void) {
    int n;
    do {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_grid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("#");
        }
        printf("\n");
    }
}