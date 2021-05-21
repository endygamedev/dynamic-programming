#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//others
int min(int x, int y);
int max(int x, int y);

//12
int levenshtein_disance(char * x_string, char * y_string);
int levenshtein_disance_rec(char * x_string, int m, char * y_string, int n);
int levenshtein_disance_arr(char * x_string, int m, char * y_string, int n);

//14
int matrix_chain_multiplication(int* dims, int n);

//15
int min_matrix_path(int x[5][5]); //!problem with defining the function argument

//16
int const_cost_matrix_path(int costs[5][5], int rest_cost);
int const_cost_matrix_path_rec(int costs[5][5], int m, int n, int rest_cost); //!problem with defining the function argument

//23
int binary_strings_without_ones(int n);

//24
int rod_cut(int costs[], int n);


int min(int x, int y)
{
 if (x > y){
     return y;
 }
 else{
    return x;
 }
}

int max(int x, int y)
{
 if (x < y){
     return y;
 }
 else{
    return x;
 }
}

int levenshtein_disance(char * x_string, char * y_string) //function entry. task 12
{
    //entering a recursive (?) function
    int m = strlen(x_string), n = strlen(y_string);
    return levenshtein_disance_arr(x_string, m, y_string, n);
    //return levenshtein_disance_rec(x_string, m, y_string, n);
}

int levenshtein_disance_rec(char * x_string, int m, char * y_string, int n) //recursive option (not cool). task 12
{

    //edge cases when lines are empty
    if (m == 0){
        return n;
    }
    if (n == 0){
        return m;
    }
    int cost;
    //if the last elements do not differ, then the cost is 0
    if (x_string[m - 1] == y_string[n - 1]){
        cost = 0;
    }
    else{
        cost = 1;
    }
    //determine the optimal move - replace, insert or delete a character
    return min(min(levenshtein_disance_rec(x_string, m - 1, y_string, n) + 1,
                   levenshtein_disance_rec(x_string, m, y_string, n - 1)),
               levenshtein_disance_rec(x_string, m - 1, y_string, n - 1) + cost);
}

int levenshtein_disance_arr(char * x_string, int m, char * y_string, int n) //option with memoization (cool). task 12
{
    //array for memoization, where d[i][j] is the distance for strings x[1 ... i], y[1 ... j]
    char D[m + 1][n + 1];
    memset(D, 0, sizeof(D));

    //initialization
    for (int i = 1; i <= m; i++) {
        D[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
        D[0][i] = i;
    }

    int sub_cost;

    //the same calculations as in the recursive version
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (x_string[i - 1] == y_string[j - 1]){
                sub_cost = 0;
            }
            else{
                sub_cost = 1;
            }
            D[i][j] = min(min(D[i - 1][j] + 1, D[i][j - 1] + 1),
                          D[i - 1][j - 1] + sub_cost);
        }
    }
    return D[m][n];
}

int matrix_chain_multiplication(int* dims, int n) //!problem with the length of the array, does not want to be calculated inside the function !!! task 14
{
    //array for memoization, where c[i][j] is the minimum cost of multiplying a sequence of matrices Mi*...*Mj, 0 <= i <j <= n
    int C[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        C[i][i] = 0;
    }

    //check subsequences of all lengths and fill in matrix C
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            C[i][j] = INT_MAX;

            for (int k = i; j < n && k <= j - 1; k++)
            {
                int cost = C[i][k] + C[k + 1][j] + dims[i - 1] * dims[k] * dims[j];
                if (cost < C[i][j]) {
                    C[i][j] = cost;
                }
            }
        }
    }
    //element Ñ[1][n - 1] - the minimum cost of multiplying a sequence of matrices from the first to the last
    return C[1][n - 1];
}

int min_matrix_path(int costs[5][5]) //!problem with function arguments. task 15
{
    //determination of the cost matrix, where c[i][j] is the minimum distance to the element with c[i][j]
    int C[5][5];
    memset(C, 0, sizeof(C));
    C[0][0] = costs[0][0];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            //if the element is at the right or top border
            if (i == 0 && j > 0){
                C[0][j] = C[0][j - 1] + costs[0][j];
            }
            else if (j == 0 && i > 0){
                C[i][0] += C[i - 1][0] + costs[i][0];
            }
            //choose the best way to get from neighboring elements
            else if (i > 0 && j > 0){
                C[i][j] += min(C[i - 1][j], C[i][j - 1]) + costs[i][j];
            }
        }
    }

    return C[4][4];
}

int const_cost_matrix_path(int costs[5][5], int rest_cost) //function entry. task 17
{
    return const_cost_matrix_path_rec(costs, 4, 4, rest_cost);
}
int const_cost_matrix_path_rec(int costs[5][5], int m, int n, int rest_cost)  //!problem with function arguments. task 17.
//!maybe it is necessary use single linked list for dictionary
//moving in the opposite direction, from the last element to the first
{
    //if there are no paths with incalculable cost
    if (rest_cost < 0){
        return 0;
    }
    //if the first cell is reached
    if (m == 0 && n == 0){
        if (costs[0][0] - rest_cost == 0)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    //if movement along the edge/
    if (n == 0){
        return const_cost_matrix_path_rec(costs, m - 1, 0, rest_cost - costs[m][n]);
    }
    else if (m == 0){
        return const_cost_matrix_path_rec(costs, 0, n - 1, rest_cost - costs[m][n]);
    }
    else{
        return const_cost_matrix_path_rec(costs, m - 1, n, rest_cost - costs[m][n]) +
                const_cost_matrix_path_rec(costs, m, n - 1, rest_cost - costs[m][n]);
    }
}

int binary_strings_without_ones(int n) //task 23
{
    int counts[n][2];
    counts[0][0] = 1;
    counts[0][1] = 1;

    for (int i = 1; i < n; i++){
        counts[i][0] = counts[i - 1][0] + counts[i - 1][1];
        counts[i][1] = counts[i - 1][0];
    }
    return counts[n - 1][0] + counts[n - 1][1];
}

int rod_cut(int costs[], int n) //task 24
{
    int C[n + 1];
    memset(C, 0, sizeof(C));

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){

            C[i] = max(C[i], costs[j - 1] + C[i - j]);
        }
    }

    return C[n];
}
