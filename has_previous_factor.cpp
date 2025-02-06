
#include<bits/stdc++.h>
using namespace std;
std::vector<bool> hasPreviousFactor(std::vector<int> inputs) {
    int inputsSize = inputs.size();
    std::vector<bool> hasFactor(inputsSize, false); // Initialize the vector with 'inputsSize' number of false values

    for (int i = 0; i < inputsSize; ++i) {
        if (i == 0) {
            continue;
        } else {
            for (int j = 0; j < inputsSize; ++j) {
                if (i != j && inputs[i] % inputs[j] == 0) {
                    hasFactor[i] = true;
                }
            }
        }
    }
    for(int i=0; i<hasFactor.size(); i++){
        cout<<hasFactor[i]<<endl;
    }
    return hasFactor;

}

int main(){
    vector<int> v={3,9,14,2};
    hasPreviousFactor(v);


    
}


<= 0 ayega may be