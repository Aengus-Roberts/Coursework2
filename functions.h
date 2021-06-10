#ifndef COURSEWORK_FUNCTIONS_H
#define COURSEWORK_FUNCTIONS_H

typedef struct particle {
    int location;
    int type; /* 1 = conductor, 2 = superconductors */
    int tag; /* allows for temporary attaching of a indexing tag for cluster finding */
} particle;

int randomInt(int max) {
    return (random() % max);
}

int checkUnique(const int *list, int i, int current) {
    int j;
    int check = 0;
    for (j = 0; j < i; j++) {
        if (list[j] == current) {
            check++;
        }
    }
    return check;
}

void listgen(int *list, int N, int max) {
    int check;
    int current;
    for (int i = 0; i < N; i++) {
        list[i] = -1;
    }
    for (int i = 0; i < N; i++) {
        check = 1;
        while (check != 0) {
            current = randomInt(max);
            check = checkUnique(list, i, current);
        }
        list[i] = current;
    }
}

void particleQuicksort(particle *array, int first, int last) {
    int i, j, pivot;
    particle temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while ((array[i].location <= array[pivot].location) && i < last)
                i++;
            while (array[j].location > array[pivot].location)
                j--;
            if (i < j) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        temp = array[pivot];
        array[pivot] = array[j];
        array[j] = temp;
        particleQuicksort(array, first, j - 1);
        particleQuicksort(array, j + 1, last);
    }
}

void listSubtract(particle *superSet, particle *subSet, int superSize, int subSize) {
    int k = superSize - subSize;
    particle dummy;
    dummy.location = -1;
    dummy.type = -1;
    dummy.tag = -1;
    int subPointer = 0;
    for (int i = 0; i < superSize; i++) {
        if (superSet[i].location == subSet[subPointer].location) {
            superSet[i] = dummy;
            subPointer++;
        }
    }
    particleQuicksort(superSet, 0, superSize - 1);
    for (int i = 0; i < k; i++) {
        superSet[i] = superSet[i + subSize];
        superSet[i].tag = i;
    }
    for (int i = k; i < superSize; i++) {
        superSet[i] = dummy;
    }
}

#endif //COURSEWORK_FUNCTIONS_H