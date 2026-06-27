#include <iostream>
#include <string>
using namespace std;

void merge(string w1, string w2) {
    string result ="";
    for (int i = 0; i < w1.size(); ++i) {
        for (int j = 0; j < w2.size(); ++j) {
            if (j == 0 && i < w1.size()) {
                result += w1[i];
            }
            if (j == 1 && i < w2.size()) {
                result += w2[i];
            }
        }
    }
    cout<<"new word is :"<<result<<endl;
    }
int main() {
    string w1, w2;
    cin>>w1>>w2;
    merge(w1,w2);
}