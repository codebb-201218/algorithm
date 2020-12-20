#include <string>
#include <vector>
#include <string.h>

using namespace std;

int cache[1000000][2];
vector<int> MONEY;

int MONEY_COUNT;
int FIRST_HOME;
int LAST_HOME;

int dp(int index, bool stolenfirstHome) {
    if(index >= MONEY_COUNT) {
        return 0;
    }
    
    int& returnValue = cache[index][stolenfirstHome];

    if(returnValue != -1) {
        return returnValue;
    }
    
    if(index == FIRST_HOME) {
        returnValue = MONEY[index] + max(returnValue, dp(index + 2, true));
    } else if(index == LAST_HOME) {
        if(!stolenfirstHome) {
             returnValue = MONEY[index] + max(returnValue, dp(index + 2, stolenfirstHome));
        }
    } else {
        returnValue = MONEY[index] + max(returnValue, dp(index + 2, stolenfirstHome));
    }

    returnValue = max(returnValue, dp(index + 1,stolenfirstHome));

    return returnValue;
}

int solution(vector<int> money) {
    MONEY = money;

    MONEY_COUNT = money.size();
    FIRST_HOME = 0;
    LAST_HOME = MONEY_COUNT - 1;

    memset(cache, -1 , sizeof(cache));

    return dp(0, false);
}