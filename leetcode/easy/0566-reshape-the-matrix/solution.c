/**
 * Return an array of arrays.
 */
int** matrixReshape(int** mat, int matSize,
                    int* matColSize, int r, int c,
                    int* returnSize, int** returnColumnSizes)
{
    int m = matSize;
    int n = matColSize[0];

    if (m * n != r * c)
    {
        *returnSize = m;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int **result = malloc(r * sizeof(int *));

    *returnSize = r;
    *returnColumnSizes = malloc(r * sizeof(int));

    int k = 0;

    for (int i = 0; i < r; i++)
    {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;

        for (int j = 0; j < c; j++)
        {
            result[i][j] = mat[k / n][k % n];
            k++;
        }
    }

    return result;
}