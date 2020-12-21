using namespace std;

long long getGCD(long long a, long long b)
{
    if(a % b == 0) {
        return b; 
    }

    return getGCD(b, a%b);
}

long long solution(int w,int h) {
    long long W = w, H = h;

    // (w/g+h/g-1)g=w+h-g
    long long answer = W * H - (W + H - getGCD(W, H));
    
    return answer;
}