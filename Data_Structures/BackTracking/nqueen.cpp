#include <bits/stdc++.h>
using namespace std;

// check if no queens attack each other
bool isPossible(vector<string> &board, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // for every queen
            if (board[i][j] == 'Q') {

                // make sure no queens on row and col
                for (int k = 0; k < N; k++) {
                    if (i != k and board[k][j] == 'Q') return false;
                    if (j != k and board[i][k] == 'Q') return false;
                }

                // make sure no queen on diagonals
                // top left diagonal
                int a = i - 1, b = j - 1;
                while (a >= 0 and b >= 0) {
                    if (board[a][b] == 'Q') return false;
                    a--; b--;
                }

                // bottom right diagonal
                a = i + 1, b = j + 1;
                while (a < N and b < N) {
                    if (board[a][b] == 'Q') return false;
                    a++; b++;
                }

                // top right diagonal
                a = i - 1, b = j + 1;
                while (a >= 0 and b < N) {
                    if (board[a][b] == 'Q') return false;
                    a--; b++;
                }

                // bottom left diagonal
                a = i + 1, b = j - 1;
                while (a < N and b >= 0) {
                    if (board[a][b] == 'Q') return false;
                    a++; b--;
                }
            }
        }
    }
    return true;
}

void getAllPerms(int N, vector<string> &mat, int index) {
    // goal achieved
    if (index == N) {
        // print matrix
        for (auto c : mat) {
            cout << c << endl;
        } cout << endl;
        return;
    }

    // we have N choice for all the rows
    for (int i = 0; i < N; i++) {

        // make choice: set the Q at pos i
        mat[index][i] = 'Q';
        
        // recurse
        // make sure the no queens attack each other
        if (isPossible(mat, N)) {
            getAllPerms(N, mat, index + 1);
        }
        
        // undo choice
        mat[index][i] = '.';
    }
}

void solveNQueens(int N) {

    // creating an NxN matrix mat with '.'
    vector<string> mat(N, string(N, '.'));

    // perform backtracking
    getAllPerms(N, mat, 0);
}

int main() {
    solveNQueens(4);
    return 0;
}