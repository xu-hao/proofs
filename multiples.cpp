#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int i=100000; i < 100999; i+=1) {
        //9127 divisible;
        if(i % 9127 == 0) {
            cout << i << '\n';
        }
    }
}
