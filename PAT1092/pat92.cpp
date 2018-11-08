/*Hash Table*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main(){

    string str;
    bool flag = false;
    int num = 0;
    
    int *hashTable = new int[100];
    fill_n(hashTable,100,0);

    cin >> str;
    for(auto iter : str) {
        hashTable[iter-'0']++;
    }

    cin >> str;
    for(auto iter : str) {
        hashTable[iter-'0']--;
        if(hashTable[iter-'0'] < 0) {
            flag = true;
        }
    }

    if(flag) {
        for(int i=0; i<100; i++) {
            if(hashTable[i]<0) {
                num -= hashTable[i];
            }
        }
        printf("No %d\n", num);
    } else {
        for(int i=0; i<100; i++) {
            num += hashTable[i];
        }
        printf("Yes %d\n", num);
    }

    return 0;
}