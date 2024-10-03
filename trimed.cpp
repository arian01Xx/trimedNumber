#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class SolutionTwenty{
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto x: queries){
            priority_queue<pair<string,int>> v;

            for(int i=0; i<nums.size(); i++){
                int t=nums[i].length()-x[1]; //define el nuevo tamaño segun queries[1]
                string p=nums[i].substr(t,x[1]); //corta el string al nuevo tamaño
                if(v.size() < x[0]) v.push({p,i});
                else{
                    if(v.top().first > p){
                        v.pop();
                        v.push({p,i});
                    }
                }
            }

            int val=v.top().second;
            res.push_back(val);
        }
        return res;
    }
};

int main(){
    return 0;
}