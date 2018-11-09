/*利用有限状态机+DP即可解决
 其中状态机有四种状态，分别代表null,末尾匹配T，末两位匹配AT，三位都匹配
 DP:动态规划从最后一位开始，当前位代表所对应的状态向后能匹配的最大数量
 递推公式：s[i]=s[i]+s[i-1]，i是当前位的状态*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

int main() {

    string str;

    ll *s = new ll[4];
    fill_n(s,4,0);

    cin >> str;

    int len = str.length();
    ll *dp = new ll[len];

    //initialization
    s[0] = 1;

    //Dynamic programming
    for(int i=len-1; i>=0; i--) {
        if(str[i]=='T') {
            s[1] += s[0];
        } else if(str[i] == 'A') {
            s[2] += s[1];
        } else {
            s[3] += s[2];
        }
    }

    printf("%lld\n", s[3]%1000000007);

    return 0;
}