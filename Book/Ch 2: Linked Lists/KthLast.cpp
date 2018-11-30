/*
 Problem:
  Implement an algorithm to find the kth to last element of a singly linked list.

 Implementation:
  Iterate the list with two pointers one starting from 0 and one from (0+k) when
  second pointer reaches to last first pointer reaches at the kth to last.

 Time Complexity: O(N)
 Space Complexity: O(1)
 */

#include <forward_list>
#include <iostream>

using namespace std;

int kth_to_last(const forward_list<int>& l, size_t k)
{
    auto second = l.begin();
    for (int i = 0;i < k; i++){
        second++;
    }

    auto answer = l.begin();
    for (;second != l.end(); second++)
        ++answer;

    return *answer;
}

int main()
{
    forward_list<int> l = { 1, 10, 3, 4, 100 };
    cout << kth_to_last(l, 4) << endl;
    return 0;
}
