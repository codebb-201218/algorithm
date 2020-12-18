#include <cmath>
using namespace std;

int treble(int n, int plusCnt)
{
    int result=0;
    
    // log(n)/log(3) = *의 개수
    if(n < 1 || 2 * log(n) / log(3) < plusCnt){
         return 0; 
    }
    
    // 마지막은 음높이3이고 ++이어야함
    if(n == 3 && plusCnt == 2){
         return 1; 
    }
    
    // *++ 충족되면 바로바로 없애
    if(n % 3 == 0 && plusCnt >= 2){
         result += treble(n / 3, plusCnt - 2); 
    }
    
    result += treble(n - 1, plusCnt + 1);
    
    return result;
}

int solution(int n) {
    return treble(n-2,2);
}