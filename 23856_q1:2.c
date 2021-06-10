#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

void checkNeighbours(int startIndex, particle start, particle *pList, particle *bList, int x, int y, int n, char DIAG) {
    /* CHECK ABOVE LEFT */
    /* **************** */
    if (start.location >= x && start.location % x != 0) {
        for (int i = 0; i < startIndex; i++) {
            if (pList[i].location == (start.location - x - 1)) {
                if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                    bList[0] = pList[i];
                    break;
                }
            }
        }
    }
    /* CHECK ABOVE */
    /* *********** */
    if (start.location >= x) {
        for (int i = 0; i < startIndex; i++) {
            if (pList[i].location == (start.location - x)) {
                bList[1] = pList[i];
                break;
            }
        }
    }
    /* CHECK ABOVE RIGHT */
    /* ***************** */
    if (start.location >= x && start.location % x != x - 1) {
        for (int i = 0; i < startIndex; i++) {
            if (pList[i].location == (start.location - x + 1)) {
                if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                    bList[2] = pList[i];
                    break;
                }
            }
        }
    }
    /* CHECK  LEFT */
    /* *********** */
    if (start.location % x != 0) {
        for (int i = 0; i < startIndex; i++) {
            if (pList[i].location == (start.location - 1)) {
                bList[3] = pList[i];
                break;
            }
        }
    }
    /* CHECK RIGHT */
    /* *********** */
    if (start.location % x != x - 1) {
        for (int i = startIndex; i < n; i++) {
            if (pList[i].location == (start.location + 1)) {
                bList[4] = pList[i];
                break;
            }
        }
    }
    /* CHECK DOWN LEFT */
    /* **************** */
    if (x * y - start.location > x && start.location % x != 0) {
        for (int i = startIndex; i < n; i++) {
            if (pList[i].location == (start.location + x - 1)) {
                if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                    bList[5] = pList[i];
                    break;
                }
            }
        }
    }
    /* CHECK DOWN */
    /* *********** */
    if ((x * y - start.location) > x) {
        for (int i = startIndex; i < n; i++) {
            if (pList[i].location == (start.location + x)) {
                bList[6] = pList[i];
                break;
            }
        }
    }
    /* CHECK DOWN RIGHT */
    /* ***************** */
    if (x * y - start.location > x && start.location % x != x - 1) {
        for (int i = startIndex; i < n; i++) {
            if (pList[i].location == (start.location + x + 1)) {
                if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                    bList[7] = pList[i];
                    break;
                }
            }
        }
    }
}

void cluster_finder(particle start, particle *cList, particle *pList, int x, int y, int n, const char DIAG) {
    int location = 0;
    int appendLocation = 1;
    cList[0] = start;
    while (cList[location].location != -1 && location != n) {
        particle tempList[8];
        for (int i = 0; i < 8; i++) {
            tempList[i].location = -1;
            tempList[i].type = 0;
        }
        checkNeighbours(cList[location].tag, cList[location], pList, tempList, x, y, n, DIAG);
        for (int i = 0; i < 8; i++) {
            int check = 0;
            if (tempList[i].location != -1) {
                for (int j = 0; j < n; j++) {
                    if (tempList[i].location == cList[j].location) {
                        check++;
                        break;
                    }
                }
            }
            if (tempList[i].location == -1) {
                check = 1;
            }
            if (check == 0) {
                cList[appendLocation] = tempList[i];
                appendLocation++;
            }
        }
        location++;
    }
}

int newGridGen(int X, int Y, int N, int fsc, int question, const char DIAG) {
    /* Creates Particles List */
    particle *particles;
    int *locations;
    int i, pointer = 0, clusterPointer = 0, isConnected = 0;
    int NSC = round((double) (N * fsc) / 100);
    particles = (particle *) calloc(N, sizeof(particle));
    locations = (int *) calloc(N, sizeof(int));
    listgen(locations, N, X * Y);
    for (i = 0; i < N; i++) {
        particles[i].location = locations[i];
        if (i < NSC) {
            particles[i].type = 2;
        } else {
            particles[i].type = 1;
        }
    }
    particleQuicksort(particles, 0, N - 1);
    for (i = 0; i < N; i++) {
        particles[i].tag = i;
    }
    /*Question1 Subsection*/
    if (question == 1) {
        i = 0;
        for (int y = 0; y < Y; y++) {
            for (int x = 0; x < X; x++) {
                if (i == particles[pointer].location) {
                    if (particles[pointer].type == 1) {
                        printf("+   ");
                    } else if (particles[pointer].type == 2) {
                        printf("x   ");
                    }
                    pointer++;
                    i++;
                } else {
                    printf(".   ");
                    i++;
                }
            }
            printf("\n");
        }
    }
        /* Question2 Subsection */
    else {
        particle *clusterList;
        clusterList = (particle *) calloc(N, sizeof(particle));
        /* Question2A Subsection */
        if (question == 2) {
            /* Creates Cluster List */
            int randPos = randomInt(N);
            for (i = 0; i < N; i++) {
                clusterList[i].location = -1;
                clusterList[i].type = -1;
                clusterList[i].tag = -1;
            }
            /* creates list of particles in cluster */
            cluster_finder(particles[randPos], clusterList, particles, X, Y, N, DIAG);
            /* find number of particles in cluster */
            int count = 0;
            while (clusterList[count].location != -1) {
                count++;
                if (count == N) {
                    break;
                }
            }
            /* sorts clusterList for present particles (ignoring dummy (-1) particles */
            particleQuicksort(clusterList, 0, count - 1);
            /* Creates Grid */
            i = 0;
            for (int y = 0; y < Y; y++) {
                for (int x = 0; x < X; x++) {
                    if (i == particles[pointer].location) {
                        if (particles[pointer].location == clusterList[clusterPointer].location) {
                            if (i == particles[randPos].location) {
                                printf(" 0   ");
                            } else {
                                printf(" 1   ");
                            }
                            clusterPointer++;
                        } else {
                            printf("-1   ");
                        }
                        pointer++;
                        i++;
                    } else {
                        printf(" .   ");
                        i++;
                    }
                }
                printf("\n");
            }
        }
        /* Question2B Subsection */
        if (question == 3) {
            /* runs cluster_finder until no clusters are left or one is found that connects the electrodes */
            int particlesLeft = N;
            while (particlesLeft != 0) {
                for (i = 0; i < N; i++) {
                    clusterList[i].location = -1;
                    clusterList[i].type = -1;
                    clusterList[i].tag = -1;
                }
                /* creates list of particles in cluster */
                cluster_finder(particles[0], clusterList, particles, X, Y, N, DIAG);
                /* find number of particles in cluster */
                int count = 0;
                while (clusterList[count].location != -1) {
                    count++;
                    if (count == particlesLeft) {
                        break;
                    }
                }
                /* sorts clusterList for present particles (ignoring dummy (-1) particles */
                particleQuicksort(clusterList, 0, count - 1);
                if ((clusterList[0].location < X) && (X * Y - clusterList[count - 1].location < X)) {
                    isConnected = 1;
                    break;
                } else {
                    listSubtract(particles, clusterList, particlesLeft, count);
                    particlesLeft -= count;
                }
            }
        }
    }
    return isConnected;
}

void questionOne(const char DIAG) {
    int x = -1, y = -1;
    while (x<1) {
        printf("x input please: ");
        scanf("%d", &x);
    }
    while (y<1) {
        printf("y input please: ");
        scanf("%d", &y);
    }
    int N = x * y + 1;
    int fsc = 101;
    while (N > x * y || N < 0) {
        printf("How many particles would you like?: ");
        scanf("%d", &N);
    }
    while (fsc > 100 || fsc < 0) {
        printf("What percentage of superconductors would you like?: ");
        scanf("%d", &fsc);
    }
    for (int i = 0; i < 3; i++) {
        printf("grid %d\n", i + 1);
        newGridGen(x, y, N, fsc, 1, DIAG);
    }
}

void questionTwoA(const char DIAG) {
    int x = -1, y = -1;
    while (x<1) {
        printf("x input please: ");
        scanf("%d", &x);
    }
    while (y<1) {
        printf("y input please: ");
        scanf("%d", &y);
    }
    int N = x * y + 1; /* sets N outside while range to trigger while loop */
    int fsc = 10;
    while (N > x * y || N < 0) {
        printf("How many particles would you like?: ");
        scanf("%d", &N);
    }
    for (int i = 0; i < 3; i++) {
        printf("grid %d\n", i + 1);
        newGridGen(x, y, N, fsc, 2, DIAG);
    }
}

void questionTwoB(const char DIAG) {
    int x = 6, y = 4, N = 10, fsc = 10, total = 0, k = 100;
    for (int i = 0; i < k; i++) {
        total += newGridGen(x, y, N, fsc, 3, DIAG);
    }
    printf("%d out of %d grids generated had a connection between the two electrodes! \n", total, k);
}

void questionTwoC(const char DIAG) {
    int x = 25, y = 25, N = 0, fsc = 10, total = 0, k = 50;
    FILE *fp = fopen("GridPercentage.csv", "w");
    if (fp == NULL) {
        fprintf(stderr, "failed to open");
        exit(-1);
    }
    fprintf(fp, "N,total\n");
    for (N=200;N<450;N+=1){
        for (int i = 0; i < k; i++) {
            total += newGridGen(x, y, N, fsc, 3, DIAG);
        }
        printf("%d out of %d grids generated had a connection between the two electrodes! when N = %d\n", total, k, N);
        fprintf(fp,"%d,%d\n",N,total);
        total = 0;
    }
    fclose(fp);
    x = 100, y = 100, N = 6000;
    for (int i = 0; i < k; i++) {
        total += newGridGen(x, y, N, fsc, 3, DIAG);
    }
    printf("%d out of %d grids generated had a connection between the two electrodes! when N = %d\n", total, k, N);
}

int main() {
    char DIAG = 'z';
    printf("+ . \n. x\n\n");
    while (DIAG != 'y' && DIAG != 'n') {
        printf("Does the above position conduct both ways y/n?");
        scanf("%s", &DIAG);
    }
    int seed;
    printf("seed input please: ");
    scanf("%d", &seed);
    srandom(seed);
    printf("\n**********\nQUESTION 1\n********** \n ");
    questionOne(DIAG);
    printf("\n**********\nQUESTION 2A\n********** \n");
    questionTwoA(DIAG);
    printf("\n**********\nQUESTION 2B\n********** \n");
    questionTwoB(DIAG);
    printf("\n**********\nQUESTION 2C\n********** \n");
    questionTwoC(DIAG);
    return 0;
}