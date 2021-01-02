#include <string>
#include <vector>

using namespace std;

int sum[2001];

int solution(vector<int> cookie) {
    int answer = 0;
    int cookieSize = cookie.size();

    for(int index = 0; index < cookieSize; index++) {
        sum[index + 1] = sum[index] + cookie[index];
    }
    
    for(int i = 1; i < n; i++) {
        int firstSon = sum[i];

        for(int j = i + 1; j <= cookieSize; j++) {
            int secondSon = sum[j] - firstSon;

            if(answer >= secondSon || secondSon > firstSon) {
                continue; 
            }

            for(int k = 0; k  < i; k++) {
                if(secondSon == firstSon - sum[k]) {
                    answer = max(answer, secondSon);
                    break;
                }
            }
        }
    }
    return answer;
}