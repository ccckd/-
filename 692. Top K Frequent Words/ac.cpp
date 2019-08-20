#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        vector<string> res;
        for(auto s : words){
            if(m.count(s) == 0)
                m[s] = 1;
            else
                m[s] += 1;
        }
        while(k > 0){
            int max = 0;
            string max_s;
            for(auto s : m){
                if(s.second > max){
                    max = s.second;
                    max_s = s.first;
                }else if(s.second == max){
                    int min;
                    string min_s;
                    if(max_s.size() > s.first.size()){
                        min = s.first.size();
                        min_s = s.first;
                    }else{
                        min = max_s.size();
                        min_s = max_s;
                    }
                    int i = 0;
                    while(i < min){
                        if(s.first[i] < max_s[i]){
                            max_s = s.first;
                            break;
                        }else if(s.first[i] > max_s[i]){
                            break;
                        }else{
                            i++;
                        }
                    }
                    if(i == min){
                        max_s = min_s;
                        max = min;
                    }
                }
            }
            m.erase(max_s);
            res.push_back(max_s);
            k--;
        }

        return res;
    }
};

int main(){
    Solution s;
    vector<string> wd = {"i", "love", "leetcode", "i", "love", "coding"};
    s.topKFrequent(wd, 2);
}