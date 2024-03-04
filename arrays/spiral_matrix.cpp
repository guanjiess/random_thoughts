#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void print_matrix(int row, int col, vector<vector<int>> matrix){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> ans(n, vector<int>(n,0));
        int loops = n / 2;
        int count = 1;
        int offset = 1;
        int start_x = 0, start_y = 0;    
        for (int round = 0; round < loops; round++) {
            start_x = round;
            start_y = round;
            int cur_round_len = n - offset;
            for (int i = 0; i < cur_round_len; i++) {
                ans[start_x][start_y+i] = count;
                count ++;
            }
            for (int i = 0; i < cur_round_len; i++) {
                ans[start_x+i][n-round-1] = count;
                count ++;
            }
            for (int j = 0; j < cur_round_len; j++) {
                ans[n-1-round][n-1-round-j] = count;
                count ++;
            }
            for (int i = 0; i < cur_round_len; i++) {
                ans[n-round-i-1][start_y] = count;
                count ++;
            }
            offset += 2;
        }
        int mid = n / 2;
        if(n == 1){
            ans[0][0] = 1;
            return ans;
        }
        if(n % 2){
            ans[mid][mid] = count;
        }
        return ans;   
    }
    
};


int main()
{
    Solution solution;
    //vector<vector<int>> three = solution.generateMatrix(3);
    //vector<vector<int>> fout = solution.generateMatrix(4);
    vector<vector<int>> five = solution.generateMatrix(5);
    //vector<vector<int>> six = solution.generateMatrix(6);
    //vector<vector<int>> one = solution.generateMatrix(1);
    //print_matrix(1, 1, one);
    //print_matrix(3, 3, three);
    //print_matrix(4, 4, fout);
    print_matrix(5, 5, five);
    //print_matrix(6, 6, six);
}