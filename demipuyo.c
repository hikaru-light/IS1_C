#include <stdio.h>

int main() {
    int l;

    scanf("%d", &l);

    int array[l][5];

    int m, n;

    for (m = 0; m < l; m++) {
        for (n = 0; n < 5; n++) {
            scanf("%d", &array[m][n]);
        }
    }

    int z = 0;

    int q;

    for (q = 0; q < l; q++) {
        for (m = 0; m < l; m++) {

            int a;

            for (n = 0; n < 1; n++) {
                if (array[m][n] == array[m][n + 1] && array[m][n + 1] == array[m][n + 2] &&
                    array[m][n + 2] == array[m][n + 3] && array[m][n + 3] == array[m][n + 4]) {
                    for (a = 0; a < 5; a++) {
                        z = array[m][n + a] + z;
                        array[m][n + a] = 0;
                    }
                }
            }

            for (n = 0; n < 2; n++) {
                if (array[m][n] == array[m][n + 1] && array[m][n + 1] == array[m][n + 2] &&
                    array[m][n + 2] == array[m][n + 3]) {
                    for (a = 0; a < 4; a++) {
                        z = array[m][n + a] + z;
                        array[m][n + a] = 0;
                    }
                }
            }

            for (n = 0; n < 3; n++) {
                if (array[m][n] == array[m][n + 1] && array[m][n + 1] == array[m][n + 2]) {
                    for (a = 0; a < 3; a++) {
                        z = array[m][n + a] + z;
                        array[m][n + a] = 0;
                    }
                }
            }
        }

        int r;

        for (r = 0; r < l; r++) {
            for (m = l - 1; 0 < m; m--) {
                for (n = 0; n < 5; n++) {
                    if (array[m][n] == 0) {
                        array[m][n] = array[m - 1][n];
                        array[m - 1][n] = 0;
                        if (m == 1) {
                            array[0][n] = 0;
                        }
                    }
                }
            }
        }
    }

    printf("RESULT\n");

    for (m = 0; m < l; m++) {
        for (n = 0; n < 5; n++) {
            printf("%d ", array[m][n]);
        }
        printf("\n");
    }

    printf("TOTAL SCORE %d\n", z);
}
