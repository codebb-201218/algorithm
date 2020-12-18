#include <string>
#include <vector>
#include <string.h>
using namespace std;

long long cache[5001];
const int MOD_NUMBER = 1000000007;

long long tiling(int num)
{
    long long& returnValue = cache[num];

    if(returnValue != 0){ return returnValue; }
    
    // 가로 길이가 2 늘어날때 마다 경우의 수가 3배 생기고
    returnValue += 3 * tiling(num - 2);

    // 짝수 지점마다 위쪽, 아래쪽 두가지 경우가 생김
    for(int index = 4; index <= num; index += 2)
    {
        returnValue += 2 * tiling(num - index);
    }

    returnValue %= MOD_NUMBER;

    return returnValue;
}

int solution(int n) {
    memset(cache, 0, sizeof(cache));
    cache[0] = 1; cache[2] = 3;
    int answer = tiling(n);
    return answer;
}