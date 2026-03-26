int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize,
                                  int* returnSize) {
// O(n)
    int n = gridSize;

    int *ans = (int*)malloc(2 * sizeof(int));  
    int hash[n*n + 1];

    for (int i = 0; i <= n*n; i++) {
        hash[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            hash[grid[i][j]]++;

            if (hash[grid[i][j]] == 2) {
                ans[0] = grid[i][j]; 
            }
        }
    }

    for (int i = 1; i <= n*n; i++) {
        if (hash[i] == 0) {
            ans[1] = i;
            break;  
        }
    }

    *returnSize = 2;
    return ans;
}