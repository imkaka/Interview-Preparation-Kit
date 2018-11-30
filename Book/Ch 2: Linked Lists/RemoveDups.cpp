/*
 Problem:
  Write code to remove duplicates from an unsorted linked list.

 Implementation:
  Store and look up to map for any duplicates.

 Time Complexity: O(N)
 Space Complexity: O(N)
 */

#include <map>
#include <forward_list>  // Singly Link list
#include <iostream>

using namespace std;

void dedup(forward_list<int>& l)
{
    map<int, bool> seen;
    auto runner = ++(l.begin());
    auto first = l.begin();
    while (runner != l.end())
    {
        seen[*first] = true;
        if (seen[*runner])
        {
            runner = first;
            l.erase_after(first);
        }
        else
        {
            ++first;
        }
        ++runner;
    }
}

int main()
{
    forward_list<int> test = { 1, 1, 2, 3, 4, 4 };
    dedup(test);
    for (const int& i : test)
        cout << i << " ";
    cout << endl;

    return 0;
}

// Follow Up : using O(1) space itrate the list O(N^2) to delete all nodes same as current node.
