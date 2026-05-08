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

    int partition1_start = 1, partition2_start, partition3_start;
    int partition1_end, partition2_end, partition3_end;
    int swaps;
    char tmp;

    if (r < c)
    {
        // traverse 1 and 2 by column starting from th left, 
        // then 3 by row starting from the bottom
        partition1_end = r - 1;
        partition2_start = r;
        partition2_end = c;
        partition3_start = r - 1;
        partition3_end = c - r + 1;

        // traverse partition 1
        for (int i = partition1_start; i < partition1_end; i++) {
            swaps = i / 2;
            for (int j = 0; j < swaps; j++) {
                ret[i][j] = grid[j][i];
                ret[j][i] = grid[i][j];
            }
        }
    }

    return ret;
}

// 1    2    3   4
// 5    6    7   8
// 9    10   11  12

// 1    2   3
// 4    5   6
// 7    8   9
// 10   11  12