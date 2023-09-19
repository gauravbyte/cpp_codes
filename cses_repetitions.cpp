// you are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest repetition in the sequence. This is a maximum-length substring containing only one type of character.

// Input

// The only input line contains a string of n
//  characters.

// Output

// Print one integer: the length of the longest repetition.

// Constraints
// 1≤n≤106

// Example

// Input:
// ATTCGGGA

// Output:
// 3

#include<bits/stdc++.h> 

using namespace std;

int main(){
    string s;
    cin>> s;
    char prev='$';
    int maxcount=0;
    int count=1;
    for(auto c: s){
        if(prev==c) 
            count++;
        else
            count=1;
        prev=c;
        maxcount=max(count,maxcount);
    }
    
    cout<<maxcount<<endl;;
    return 0;
}


