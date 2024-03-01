#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& image, int row, int col, int newColor, int initColor, vector<vector<int>>& ans, int delRow[], int delCol[]){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();

        for(int i =  0; i < 4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
               image[nrow][ncol] == initColor && ans[nrow][ncol] != newColor){
                dfs(image, nrow, ncol, newColor, initColor, ans, delRow, delCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int initColor = image[sr][sc];
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        dfs(image, sr, sc, color, initColor, ans, delRow, delCol);

        return ans;
    }
};

vector<vector<int>> createInput(vector<vector<int>>& imageValues) {
    vector<vector<int>> image;
    for (const auto& row : imageValues) {
        image.push_back(row);
    }
    return image;
}

int main() {
    Solution sol;

    // Example usage:
    vector<vector<int>> imageValues = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> image = createInput(imageValues);

    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);

    cout << "Updated image after flood fill:\n";
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
