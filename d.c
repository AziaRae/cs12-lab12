#include "gollums_columns.h"
#include <stdlib.h>

char **transpose(int r, int c, const char **grid)
{
    char **ret = malloc(c * sizeof(char));

    for (int i = 0; i < c; i++)
    {
        char *row = malloc((r + 1) * sizeof(char));
        row[r] = '\0';
        ret[i] = row;
    }

    int swaps;
    char tmp;

    if (r < c)
    {
        // traverse partition 1
        for (int i = 0; i < r - 1; i++) {
            swaps = i / 2;
            for (int j = 0; j < swaps; j++) {
                ret[i][j] = grid[j][i];
                ret[j][i] = grid[i][j];
            }
        }

        // traverse partition 2
        swaps = c / 2;
        for (int j = r - 1; j < c - 1; j++) {
            for (int i = 0; i < swaps; i++) {
                ret[i][j] = grid[j][i];
                ret[j][i] = grid[i][j];
            }
        }

        // traverse partition 3
        int numOfElementsInDiagonal = r - 1;
        for (int j = c - r + 1; j < c - 1; j++) {
            swaps = numOfElementsInDiagonal / 2;

            for (int i = r - 1; ;i++) {
                if (swaps == 0) {
                    break;
                }

                ret[i][j] = grid[j][i];
                ret[j][i] = grid[i][j];

                swaps--;
            }

            numOfElementsInDiagonal--;
        }
    }

    return ret;
}

// 1    2    3   4  13  16
// 5    6    7   8  14  17 
// 9    10   11  12 15  18

// 1    2   3
// 4    5   6
// 7    8   9
// 10   11  12