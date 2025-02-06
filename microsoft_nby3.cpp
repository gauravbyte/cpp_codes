/* YouaregivenanarrayAconsistingofNintegers(Nisdivisibleby3)anda n integerK.Inonemove,youcanincreaseordecreaseanyelementofAby1.The taskistomodifyarrayAusingsuchmovesinordertomaximizethedifference betweenthe(N/3)thlargestelementandthe(N/3)thsmallestelementofthe
resultingarray.YoucanperformatmostKmoves.
For example, array A=[9, 12, 15, 5, 7, 13] consists of N=6elements, so t h e (N/3)th(thatis,the2nd)largestelementi s1 3andt h eN/3)th(2nd)smallest
elementis7 . Write a function:
i n tsolution(vector<int>&A,i n tK);
that, given an array Aand an integer K, returns the maximum possible difference between the (N/3)th largest element and the N/3)th smallest element of Aafter
performing a t most Kmoves, a s described above.
Example:
1. Given A=[8, 8, 8, 7, 7, 7, 7, 7, 7, 7, -8, -8] and K=1, the function should return 1. We can increase one 7once. The resulting array is [8, 8, 8, 8, 7, 7, 7, 7, 7, 7, -8,
-8].The4thbiggestnumberis8 andthe4thsmallestis7.
2. Given A=[-5, 1, 1, 4, 4, 4, 7, 4, 6] and K= 6, the function should return 7. We can increase one 4 three times, increase the 6 once and decrease both 1 s once. The resulting array is I-5, 0, 0, 4, 4, 7, 7, 4, 7]. The 3rd biggest number is 7and the 3rd
smallesti s0 .
3. Given A=[-7, -6, -3, -2, -2, -2, -2, -2, -2, -2, -2, -1] and K=5, the function shouldreturn3.Wecandecreaseone-2threetimesanddecreasethe-3twice.
The resulting array is I-7, -6, -5, -5, -2, -2, -2, -2, -2, -2, -2, -1]. The 4th biggest numberis- 2andthe4thsmallestis- */

#include <bits/stdc++.h>
using namespace std;
int solution(vector<int> &A, int k) {
    sort(A.begin(),A.end());
    int n=A.size();

    int f=n/3-1, l=2*n/3;
    int x1=1,x2=1;
  
   long long num1=A[n/3-1], num2=A[2*n/3];
    while(k>0)
    {
        while(f>0 && num1==A[f-1])
          {
              x1++;
              f--;
          }
          while(l<n-1 && num2==A[l+1])
          {
              x2++;
              l++;
          }
          if(x1<=x2)
          {
              if(k>=x1)
              {
                  k-=x1;
                  num1--;
              } 
              else 
                break;
          }
          else
          {
               if(k>=x2)
               {
                   k-=x2;
                   num2++;
               }

               else
                 break; 
          }
  
    }
    return num2-num1;
}
int main(){
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    int k;
    cin>>k;
    cout<<solution(A,k)<<endl;

}