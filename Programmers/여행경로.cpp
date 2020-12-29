#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

void dfs(string here, vector<int>& visited, vector<vector<string>> tickets, vector<string>& answer) {
    if(tickets.empty()) {
        return;
    }

	answer.push_back(here);

    for(vector<vector<string>>::iterator iter = tickets.begin(); iter != tickets.end(); iter++) {
        int idx = iter - tickets.begin();
        if((*iter)[0] == (*(answer.end() - 1))) {
            string next = (*iter)[1];
            tickets.erase(tickets.begin() + idx);
            cout<<next;
            dfs(next, visited, tickets, answer);
                if(tickets.empty()) {
        return;
    }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    vector<int> visited(tickets.size());
	sort(tickets.begin(), tickets.end());

	dfs("ICN", visited, tickets, answer);

	return answer;
}
