/ * ====================================
File name: exerc_2_5.c (or cpp)
Date: 2016-01-27
Group Number: 33
Members that contributed:
Darja Linkova
Pooria Balavi
Andreas Aronsson
Demonstration code: [<Ass code 1-4> <abc>]
Important , No code no bonus !
====================================== * /

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAXNUMBER 20

// ------ Function declaration ---------- Updated 2014 after wp2

void create_random(int *tab);

void count_frequency(int *tab, int *freq);

void draw_histogram(int *freq);

int main(void) {

    int table[MAX], n;
    int frequency[MAXNUMBER];

    create_random(table);
    for (int i = 0; i < MAXNUMBER; ++i) {
        frequency[i] = 0;

    }
    count_frequency(table, frequency);
    draw_histogram(frequency);

}

void create_random(int *table) {
    srand(time(NULL));

    for (int i = 0; i < MAX; i++) {
        int ran = rand() % MAXNUMBER;
        table[i] = ran;
    }
}

void count_frequency(int *table, int *frequency) {
    for (int i = 0; i < MAX; ++i) {
        int counter = table[i];
        frequency[counter]++;

    }
}

void draw_histogram(int *frequency) {
    int i = 0;
    for (; i < MAXNUMBER; i++) {
        if (frequency[i] != 0) {
            printf("\t%d\t", i);
            int j = 0;
            for (; j < frequency[i]; j++) {
                printf("X");
            }
            printf("%s", "\n");
        }
    }
}