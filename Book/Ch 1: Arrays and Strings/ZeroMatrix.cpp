/*
 Problem:
  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
  column are set to 0.

 Implementation:
  Store the row, column in set and nullify all row and column to zero.

 Time Complexity: O(MN)
 Space Complexity: O(N).

*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

void find_zeros(set<size_t>& rows, set<size_t>& cols,
        const vector<vector<int>>& m)
{
    size_t R = m.size();
    size_t C = m[0].size();

    for (size_t i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            if (m[i][j] == 0)
            {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
}

void zero_matrix(vector<vector<int>>& m)
{
    set<size_t> rows, cols;
    find_zeros(rows, cols, m);
    size_t R = m.size();
    size_t C = m[0].size();

    for (const size_t& r : rows)
    {
        m[r].assign(C, 0);
    }

    for (const size_t& c : cols)
    {
        for (size_t i = 0; i < R; i++)
        {
            m[i][c] = 0;
        }
    }
}

void print_matrix(const vector<vector<int>>& m)
{
    for (const vector<int>& row : m)
    {
        for (const int& cell : row)
        {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main(int argc, char** argv)
{
    vector<vector<int>> m = { { 1, 2, 3 }, { 4, 5, 0 }, { 0, 8, 9 } };
    print_matrix(m);
    zero_matrix(m);
    print_matrix(m);
 return 0;
}
