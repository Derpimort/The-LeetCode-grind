#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int diff=0;
        multiset <int, greater <int>> m(stones.begin(),stones.end());
        
        while(m.size()>1){
            diff=*m.begin();
            m.erase(m.begin());
            diff-=*m.begin();
            m.erase(m.begin());
            if(diff!=0)
                m.insert(abs(diff));
        }
        return m.empty()?0:*m.begin();
    }
};

int main(){
    return 1;
}
