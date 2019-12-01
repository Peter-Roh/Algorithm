#include "mst.h"

void Kruskal(int (*graph)[10], int (*mst)[10], int connected[]) {
    int min;
    int a, b, i, j, k;

    for(i = 0; i < 9; i++) {
        min = 20;

        for(j = 0; j < 10; j++) {
            for(k = 0; k < 10; k++) {
                if((connected[j] == 1 && connected[k] == 0) && (graph[j][k] < min && graph[j][k] != 0)) {
                    min = graph[j][k];
                    a = j;
                    b = k;
                }
            }
        }

        connected[b] = 1;
        mst[a][b] = graph[a][b];
    }
}
