#include <vector>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if (r < 3 || c < 3) {
            return 0;
        }
        
        int ans = 0;

        // Function to check if a 3x3 grid is a magic square
        auto isMagicSquare = [](vector<vector<int>>& mt) -> bool {
            vector<int> count(10, 0);
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int num = mt[i][j];
                    if (num < 1 || num > 9) return false;
                    count[num]++;
                }
            }
            for (int i = 1; i <= 9; ++i) {
                if (count[i] != 1) return false;
            }
            
            int sum1 = mt[0][0] + mt[0][1] + mt[0][2];
            int sum2 = mt[1][0] + mt[1][1] + mt[1][2];
            int sum3 = mt[2][0] + mt[2][1] + mt[2][2];
            int sum4 = mt[0][0] + mt[1][0] + mt[2][0];
            int sum5 = mt[0][1] + mt[1][1] + mt[2][1];
            int sum6 = mt[0][2] + mt[1][2] + mt[2][2];
            int sum7 = mt[0][0] + mt[1][1] + mt[2][2];
            int sum8 = mt[0][2] + mt[1][1] + mt[2][0];

            return (sum1 == 15 && sum2 == 15 && sum3 == 15 &&
                    sum4 == 15 && sum5 == 15 && sum6 == 15 &&
                    sum7 == 15 && sum8 == 15);
        };
        
        // Iterate over all possible 3x3 subgrids
        for (int i = 0; i <= r - 3; ++i) {
            for (int j = 0; j <= c - 3; ++j) {
                vector<vector<int>> mt(3, vector<int>(3));
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        mt[x][y] = grid[i + x][j + y];
                    }
                }
                if (isMagicSquare(mt)) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};
