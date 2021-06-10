#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

void checkNeighbours(int startIndex, particle start, particle *pList, particle *bList, int x, int y, int z, int n,
                     char DIAG) {
    /* 1 */
    if (start.location >= (x * y)) {
        /* 1a */
        if (start.location % (x * y) >= x) {
            /* 1ai */
            if (start.location % x != 0) {
                for (int i = 0; i < startIndex; i++) {
                    if (pList[i].location == (start.location - (x * y) - x - 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[0] = pList[i];
                            break;
                        }
                    }
                }
            }
            /* 1aii */
            for (int i = 0; i < startIndex; i++) {
                if (pList[i].location == (start.location - (x * y) - x)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[1] = pList[i];
                        break;
                    }
                }
            }
            /* 1aiii */
            if (start.location % x != (x - 1)) {
                for (int i = 0; i < startIndex; i++) {
                    if (pList[i].location == (start.location - x * y - x + 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[2] = pList[i];
                            break;
                        }
                    }
                }
            }
        }
        /* 1b */
        /* 1bi */
        if (start.location % x != 0) {
            for (int i = 0; i < startIndex; i++) {
                if (pList[i].location == (start.location - (x * y) - 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[3] = pList[i];
                        break;
                    }
                }
            }
        }
        /* 1bii */
        for (int i = 0; i < startIndex; i++) {
            if (pList[i].location == (start.location - x * y)) {
                bList[4] = pList[i];
                break;
            }
        }
        /* 1biii */
        if (start.location % x != (x - 1)) {
            for (int i = 0; i < startIndex; i++) {
                if (pList[i].location == (start.location - (x * y) + 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[5] = pList[i];
                        break;
                    }
                }
            }
        }
        /* 1c */
        if ((start.location % (x * y)) < x*(y-1)) {
            /* 1ci */
            if (start.location % x != 0) {
                for (int i = 0; i < startIndex; i++) {
                    if (pList[i].location == (start.location - (x * y) + x - 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[6] = pList[i];
                            break;
                        }
                    }
                }
            }
            /* 1cii */
            for (int i = 0; i < startIndex; i++) {
                if (pList[i].location == (start.location - (x * y) + x)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[7] = pList[i];
                        break;
                    }
                }
            }
            /* 1ciii */
            if (start.location % x != (x - 1)) {
                for (int i = 0; i < startIndex; i++) {
                    if (pList[i].location == (start.location - x * y + x + 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[8] = pList[i];
                            break;
                        }
                    }
                }
            }
        }
    }
    /* 2 */
    /* 2a */
    if (start.location % (x * y) >= x) {
        /* 2ai */
        if (start.location % x != 0) {
            for (int i = 0; i < startIndex; i++) {
                if (pList[i].location == (start.location - x - 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[9] = pList[i];
                        break;
                    }
                }
            }
        }
        /* 2aii */
        for (int i = 0; i < startIndex; i++) {
            if (pList[i].location == (start.location - x)) {
                bList[10] = pList[i];
                break;
            }
        }
        /* 2aiii */
        if (start.location % x != (x - 1)) {
            for (int i = 0; i < startIndex; i++) {
                if (pList[i].location == (start.location - x + 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[11] = pList[i];
                        break;
                    }
                }
            }
        }
    }
    /* 2b */
    /* 2bi */
    if (start.location % x != 0) {
        for (int i = 0; i < startIndex; i++) {
            if (pList[i].location == (start.location - 1)) {
                bList[12] = pList[i];
                break;
            }
        }
    }
    /* 2biii */
    if (start.location % x != (x - 1)) {
        for (int i = startIndex; i < n; i++) {
            if (pList[i].location == (start.location + 1)) {
                bList[13] = pList[i];
                break;
            }
        }
    }
    /* 2c */
    if ((start.location % (x * y)) < x*(y-1)) {
        /* 2ci */
        if (start.location % x != 0) {
            for (int i = startIndex; i < n; i++) {
                if (pList[i].location == (start.location + x - 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[14] = pList[i];
                        break;
                    }
                }
            }
        }
        /* 2cii */
        for (int i = startIndex; i < n; i++) {
            if (pList[i].location == (start.location + x)) {
                bList[15] = pList[i];
                break;
            }
        }
        /* 2ciii */
        if (start.location % x != (x - 1)) {
            for (int i = startIndex; i < n; i++) {
                if (pList[i].location == (start.location + x + 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[16] = pList[i];
                        break;
                    }
                }
            }
        }
    }
    /* 3 */
    if (start.location < (x * y * (z-1))) {
        /* 3a */
        if (start.location % (x * y) >= x) {
            /* 3ai */
            if (start.location % x != 0) {
                for (int i = startIndex; i < n; i++) {
                    if (pList[i].location == (start.location + (x * y) - x - 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[17] = pList[i];
                            break;
                        }
                    }
                }
            }
            /* 3aii */
            for (int i = startIndex; i < n; i++) {
                if (pList[i].location == (start.location + (x * y) - x)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[18] = pList[i];
                        break;
                    }
                }
            }
            /* 3aiii */
            if (start.location % x != (x - 1)) {
                for (int i = startIndex; i < n; i++) {
                    if (pList[i].location == (start.location + (x * y) - x + 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[19] = pList[i];
                            break;
                        }
                    }
                }
            }
        }
        /* 3b */
        /* 3bi */
        if (start.location % x != 0) {
            for (int i = startIndex; i < n; i++) {
                if (pList[i].location == (start.location + (x * y) - 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[20] = pList[i];
                        break;
                    }
                }
            }
        }
        /* 3bii */
        for (int i = startIndex; i < n; i++) {
            if (pList[i].location == (start.location + (x * y))) {
                bList[21] = pList[i];
                break;
            }
        }
        /* 3biii */
        if (start.location % x != (x - 1)) {
            for (int i = startIndex; i < n; i++) {
                if (pList[i].location == (start.location + (x * y) + 1)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[22] = pList[i];
                        break;
                    }
                }
            }
        }
        /* 3c */
        if ((start.location % (x * y)) < x*(y-1)) {
            /* 3ci */
            if (start.location % x != 0) {
                for (int i = startIndex; i < n; i++) {
                    if (pList[i].location == (start.location + (x * y) + x - 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[23] = pList[i];
                            break;
                        }
                    }
                }
            }
            /* 3cii */
            for (int i = startIndex; i < n; i++) {
                if (pList[i].location == (start.location + (x * y) + x)) {
                    if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                        bList[24] = pList[i];
                        break;
                    }
                }
            }
            /* 3ciii */
            if (start.location % x != (x - 1)) {
                for (int i = startIndex; i < n; i++) {
                    if (pList[i].location == (start.location + (x * y) + x + 1)) {
                        if (start.type == 2 || (pList[i].type == 2 && DIAG == 'y')) {
                            bList[25] = pList[i];
                            break;
                        }
                    }
                }
            }
        }
    }

}

void cluster_finder(particle start, particle *cList, particle *pList, int x, int y, int z, int n, const char DIAG) {
    int location = 0;
    int appendLocation = 1;
    cList[0] = start;
    while (cList[location].location != -1 && location != n) {
        particle tempList[26];
        for (int i = 0; i < 26; i++) {
            tempList[i].location = -1;
            tempList[i].type = 0;
        }
        checkNeighbours(cList[location].tag, cList[location], pList, tempList, x, y, z, n, DIAG);
        for (int i = 0; i < 26; i++) {
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

int newGridGen(int X, int Y, int Z, int N, int fsc, const char DIAG) {
    /* Creates Particles List */
    particle *particles;
    int *locations;
    int i, pointer = 0, clusterPointer = 0, isConnected = 0;
    int NSC = round((double) (N * fsc) / 100);
    particles = (particle *) malloc(N*sizeof(particle));
    locations = (int *)malloc(N * sizeof(int));
    listgen(locations, N, X * Y * Z);
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
    particle *clusterList;
    clusterList = (particle *) malloc(N * sizeof(particle));
    /* runs cluster_finder until no clusters are left or one is found that connects the electrodes */
    int particlesLeft = N;
    while (particlesLeft != 0) {
        for (i = 0; i < N; i++) {
            clusterList[i].location = -1;
            clusterList[i].type = -1;
            clusterList[i].tag = -1;
        }
        /* creates list of particles in cluster */
        cluster_finder(particles[0], clusterList, particles, X, Y, Z, N, DIAG);
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
        if ((clusterList[0].location < (X*Y)) && ((X * Y * Z) - clusterList[count - 1].location < (X*Y))) {
            isConnected = 1;
            break;
        } else {
            listSubtract(particles, clusterList, particlesLeft, count);
            particlesLeft -= count;
        }
    }
    free(particles);
    free(clusterList);
    free(locations);
    return isConnected;
}

void questionThree(const char DIAG){
    int x = 10, y = 10, z=10, N = 10, fsc, total = 0, k = 100;
    /* Rough Runthrough */
    for (fsc=0;fsc<101;fsc+=5) {
        for (int j = 3; j > 0; j--) {
            while (((float) total / k) < 0.5) {
                total = 0;
                for (int i = 0; i < k; i++) {
                    total += newGridGen(x, y, z, N, fsc, DIAG);
                }
                N += (int) (pow(10, j - 1) + 0.5);
                if (N >= x * y * z) {
                    break;
                }
            }
            N -= 2 * (int) (pow(10, j - 1) + 0.5);
            total = 0;
        }
        N += 2;
        printf("%d particles provided over 50%% of electrode connections in %d simulations with fsc = %d\n", N, k, fsc);
    }
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
    questionThree(DIAG);
}