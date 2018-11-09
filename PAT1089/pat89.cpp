#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
int *seqBefor;
int *seqAfter;

//find merge sorting partition length(need modify)
//Note: merge sorting per iteration has 2^n of length
int partitionLengthMerge() {
    int index = 1;
    int start;
    int minLen = N;
    while(index < N) {
        start = index - 1;
        while(index<N && seqAfter[index]>=seqAfter[index-1]) {
            index++;
        }
        if(index<N && (index-start)<minLen) {
            minLen = index - start;
        }
        index++;
    }
    return minLen;
}

void insertSortIter(int index) {
    if(index==N) {
        return;
    }
    int i = index-1;
    int tmp = seqAfter[index];
    while(i>=0 && seqAfter[i]>tmp) {
        seqAfter[i+1] = seqAfter[i];
        i--;
    }
    i++;
    seqAfter[i] = tmp;
}

void MergeSortingIter(int len) {
    int end1 = len - 1;
    int end2 = 2*len-1;
    int index1 = 0;
    int index2 = len;
    int index = 0;
    int *res = new int[N];
    while(index < N) {
        while(index1<N && index1<=end1 && index2<N && index2<=end2) {
            if(seqAfter[index1]<seqAfter[index2]) {
                res[index]=seqAfter[index1];
                index1++;
            } else {
                res[index]=seqAfter[index2];
                index2++;
            }
            index++;
        }
        while(index1<N && index1<=end1) {
            res[index]=seqAfter[index1];
            index++;
            index1++;
        }
        while(index2<N && index2<=end2) {
            res[index]=seqAfter[index2];
            index++;
            index2++;
        }
        index1 = end2+1;
        index2 = end2+len+1;
        end1 = end2+len;
        end2 = end2+2*len;
    }
    seqAfter = res;
}

int main() {

    scanf("%d",&N);
    seqBefor = new int[N];
    seqAfter = new int[N];
    for(int i=0; i<N; i++) {
        scanf("%d",seqBefor+i);
    }
    for(int i=0; i<N; i++) {
        scanf("%d",seqAfter+i);
    }

    bool flag = false;
    int index = 1;
    int partLen;

    //test insertion sort, if it is then flag denotes false
    while(index<N && seqAfter[index]>=seqAfter[index-1]) {
        index++;
    }
    partLen = index; //partition sorting length denotes insertion sorting

    while(index < N) {
        if(seqBefor[index]!=seqAfter[index]) {
            flag = true;
            break;
        }
        index++;
    }
    
    if(flag) {
        printf("Merge Sort\n");
        partLen = partitionLengthMerge();
        MergeSortingIter(partLen);
    } else {
        printf("Insertion Sort\n");
        insertSortIter(partLen);
    }

    printf("%d", seqAfter[0]);
    for(int i=1; i<N; i++) {
        printf(" %d", seqAfter[i]);
    }
    printf("\n");

    return 0;
}