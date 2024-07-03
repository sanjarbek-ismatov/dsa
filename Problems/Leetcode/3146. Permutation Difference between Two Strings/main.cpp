#include<string>
#include<iostream>
#include<cmath>
using namespace std;
class Solution {
private:
    int total = 0;
    int add(int s = 0, int t = 0){
        return total += fabs(s - t);
    }
public:
    int findPermutationDifference(string s, string t) {
        for(int i = 0; i < s.length(); i++){
            this->add(i, t.find(s[i]));
        }
        return add();
    }
};
int main(){
    Solution solution;
    const int result = solution.findPermutationDifference("abc", "bac");
    cout << result << endl;
    return 0;
}