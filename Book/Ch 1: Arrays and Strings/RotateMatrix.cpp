/*
 Problem:
  Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
  write a method to rotate the image by 90 degrees. Can you do this in place?

 Implementation:
  We can just swap top -> left -> bottom -> right -> top in place going inwards.

 Time Complexity: O(n^2)
 Space Complexity: O(1).

*/

#include <iostream>
#include <vector>

using namespace std;

bool rotate_matrix(vector<vector<int> >& m)
{
    if (m.size() == 0 || (m.size() != m[0].size()))
        return false;

    size_t len = m.size();
    for (size_t layer = 0; layer < len / 2; layer++)
    {
        size_t first = layer;
        size_t last = len - 1 - layer;
        for (size_t i = first; i < last; i++)
        {
            size_t offset = i - first;
            int top = m[first][i];

            // move left to top
            m[first][i] = m[last - offset][first];

            // move bottom to left
            m[last - offset][first] = m[last][last - offset];

            // move right to bottom
            m[last][last - offset] = m[i][last];

            // move top to right
            m[i][last] = top;
        }
    }
    return true;
}

void print_matrix(const vector<vector<int> >& m)
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
    vector<vector<int> > m = { { 1, 2, 3}, {10, 11, 12}, {20, 21, 22} };
    print_matrix(m);
    if (rotate_matrix(m))
    {
        print_matrix(m);
    }
 return 0;
}

