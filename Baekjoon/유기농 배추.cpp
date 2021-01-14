#include <iostream>
#include <string.h>
using namespace std;

int map[51][51];
bool visit[51][51];

int M, N;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool isRange(int x, int y) {
	return 0 <= x && x < M && 0 <= y && y < N;
}

void dfs(int x, int y) {
	visit[x][y] = true;
	
	for(int dir = 0; dir < 4; dir++) {
		int newX = x + dx[dir];
		int newY = y + dy[dir];
		
		if(isRange(newX, newY) && map[newX][newY] && !visit[newX][newY]) {
			dfs(newX, newY);
		}
	}
}

int main() {
	int count;
	cin >> count;

	
	for(int testCase = 0 ; testCase < count; testCase++) {
		int answer = 0;
		int cabbage;
		
		cin >> M >> N >> cabbage;
		
		memset(map, 0, sizeof(map));
		memset(visit, false, sizeof(visit));
		
		for(int index = 0; index < cabbage; index++) {
			int x, y;
			cin >> x >> y;
			
			map[x][y] = 1;
		}
		
		for(int xPos = 0; xPos < M; xPos++) {
			for(int yPos = 0; yPos < N; yPos++) {
				if(map[xPos][yPos] == 1 && !visit[xPos][yPos]) {
					answer++;
					dfs(xPos, yPos);
				}
			}
		}
		
		cout << answer << endl;
	}
}