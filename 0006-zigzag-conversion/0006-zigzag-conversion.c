#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    int n = strlen(s);

    // If only one row, no conversion is needed
    if (numRows == 1 || numRows >= n) {
        return strdup(s);
    }

    char* result = malloc((n + 1) * sizeof(char));
    int index = 0;

    int row = 0;
    int direction = 1;  // 1 = down, -1 = up

    // Create an array of strings for each row
    char** rows = malloc(numRows * sizeof(char*));
    int* sizes = calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++) {
        rows[i] = malloc((n + 1) * sizeof(char));
    }

    // Put characters into their respective rows
    for (int i = 0; i < n; i++) {
        rows[row][sizes[row]++] = s[i];

        if (row == numRows - 1) {
            direction = -1;
        } else if (row == 0) {
            direction = 1;
        }

        row += direction;
    }

    // Read rows from top to bottom
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            result[index++] = rows[i][j];
        }
        free(rows[i]);
    }

    result[index] = '\0';

    free(rows);
    free(sizes);

    return result;
}
