#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
  return 0;
}
int main() {
  vector < int > arr;
  int size;
  cin>>size;
  //push 1000 elements in the vector arr randomly
  for (int i = 0; i < size; i++) {
    arr.push_back(rand() % 1000);
  }
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}
