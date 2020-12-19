#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int ALPABET_COUNT = 26;

struct Trie
{
    bool finish;
    int count;
    Trie* next[ALPABET_COUNT];

    Trie() : finish(false), count(1) {
        memset(next, 0, sizeof(next));
    }

    ~Trie()
    {
        for(int index = 0; index <ALPABET_COUNT; index++) {
            if(next[index]) {
                delete next[index];
            }
        }
    }

    void insert(const char* key) {
        if(*key == '\0') {
             finish=true; 
        } else {
            int cur = *key - 'a';

            if(next[cur] == NULL) {
                next[cur] = new Trie();
            } else {
                next[cur] -> count++;
            }

            next[cur] -> insert(key + 1);
        }
    }

    int find(const char* key)
    {
        int cur = *key - 'a';
        if(*key == '?') {
            int temp = 0;

            for(int index = 0; index < ALPABET_COUNT; index++) {
                if(next[index] != NULL) { 
                    temp += next[index] -> count;
                }
            }

            return temp;
        }

        if(next[cur] == NULL) {
            return 0; 
        }

        if(*(key+1) == '?') {
            return next[cur] -> count; 
        }

        return next[cur] -> find(key + 1);
    }
};

Trie* root[10001];
Trie* reverseRoot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    int queriesSize=queries.size();
    vector<int> answer(queriesSize, 0);
    
    for(auto word : words) {
        int wordSize = word.size();
        
        const char* wordChar = word.c_str();
        if(root[wordSize] == NULL) {
            root[wordSize] = new Trie(); 
        }

        root[wordSize]->insert(wordChar);
        
        string reverseWord = word;
        reverse(reverseWord.begin(),reverseWord.end());
        
        const char* reverseWordChar = reverseWord.c_str();
        if(reverseRoot[wordSize] == NULL) {
            reverseRoot[wordSize] = new Trie(); 
        }

        reverseRoot[wordSize]->insert(reverseWordChar);
    }
    
    int index = 0;

    for(auto query : queries) {
        int querySize = query.size();

        if(query[querySize-1] == '?') {
            const char* queryChar = query.c_str();

            if(root[querySize]==NULL) {
                index++; 
                continue;
            }

            answer[index] = root[querySize] -> find(queryChar);
        } else {
            string reverseQuery = query;
            reverse(reverseQuery.begin(),reverseQuery.end());

            const char* reverseQueryChar = reverseQuery.c_str();

            if(reverseRoot[querySize] == NULL) {
                index++; 
                continue; 
            }

            answer[index] = reverseRoot[querySize] -> find(reverseQueryChar);
        }

        index++;
    }

    return answer;
}