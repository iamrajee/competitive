#include <bits/stdc++.h> 
#define N 4 
using namespace std; 
void displayMatrix(int mat[N][N]); 
void rotateMatrix(int mat[][N]) { 
    for (int x = 0; x < N / 2; x++) { 
        for (int y = x; y < N-x-1; y++) { 
            int temp = mat[x][y]; 
            mat[x][y] = mat[y][N-1-x]; // move values from right to top 
            mat[y][N-1-x] = mat[N-1-x][N-1-y]; // move values from bottom to right 
            mat[N-1-x][N-1-y] = mat[N-1-y][x]; // move values from left to bottom 
            mat[N-1-y][x] = temp;  // assign temp to left 
        } 
    } 
} 
  
void displayMatrix(int mat[N][N]) { 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            printf("%2d ", mat[i][j]); 
  
        printf("\n"); 
    } 
    printf("\n"); 
} 
  
  
/* Driver program to test above functions */
int main() 
{ 
    int mat[N][N] = // Test Case 1 
    { 
        {1, 2, 3, 4}, 
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}, 
        {13, 14, 15, 16} 
    }; 
    rotateMatrix(mat); 
    displayMatrix(mat);// Print rotated matrix  
    return 0; 
} 