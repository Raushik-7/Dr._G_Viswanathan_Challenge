class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();

        // If the conversion of the matrix is NOT possible, return original
        if (row * col != r * c) {
            return mat;
        }

        // Corrected initialization syntax
        vector<vector<int>> result(r, vector<int>(c));

        int new_row = 0;
        int new_col = 0;

        // Loop through the original matrix
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Assign value to the reshaped matrix
                result[new_row][new_col] = mat[i][j];
                
                new_col++; // Move to the next column in the new matrix
                
                // If the current row in the new matrix is full, move to the next row
                if (new_col == c) {
                    new_col = 0;
                    new_row++;
                }
            }
        }

        return result;
    }
};
