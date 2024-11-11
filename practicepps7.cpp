/*A positive integer n can be partitioned into a sequence of distinct positive
 integers a1,a2,...,an such that n = a1+a2+...+ak. We call a1+a2+...+ak
 as k−size distinct partition of n. Here, none of the positive integers ai,i =
 1, 2..., n are same. Distinct partitions of 3 are 2+1 and 3. We consider the
 partition 2 +1 and the partition 1+2, as the same partition. Maximum
size distinct parttion of 3 is 2 + 1. Similarly, distinct partitions of 6 are
 1+5,2+4,3+2+1,6. Maximum-size distinct partition of 6 is 3+2+1.
 Given a positive integer n, design a back-tracking algorithm to compute
 a maximum-size distinct partition of n. Analyse the algorithm with the
 running-time and the time-complexity*/

 #include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
  cout << endl;
}

int partition(int n, vector<int> &v) {
    if (n == 0) {
        printVector(v);
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (find(v.begin(), v.end(), i) == v.end()) {
        v.push_back(i);
        count += partition(n - i, v);
        v.pop_back();
        }
    }
    return count;
}

int main() {
  int n;
  cout << "Enter the number: ";
  cin >> n;
  vector<int> v;
  int n1 = partition(n, v);
  cout <<"paths:"<< n1 << endl;

  return 0;
}