#include <iostream>
#include <vector>
#include <cstdarg>
#include <algorithm>
using namespace std;
vector<int> sym(int count, ...){
    vector<int> result;
    va_list args;
    va_start(args, count);
    for(int i = 0; i < count; i++){
        int* arg = va_arg(args, int*);
        cout << arg[0] << endl;
    }
    va_end(args);
    return result;
}
vector<int> sym_difference(vector<int> arr1, vector<int> arr2){
    vector<int> merged_result;

    return merged_result;
}
class Tool{
public:
    static bool includes(vector<int> arr1, vector<int> arr2){
        for(int item: arr1){
            auto from_arr2 = find(arr2.begin(), arr1.end(), item);
            if(from_arr2 == arr2.end()) return true;
        }
        return false;
    }
    static void print(vector<int> result){
        string output = "[";
        for(int i = 0; i < result.size() - 1; i++){
            output += to_string(result[i]) + ", ";
        }
        output += to_string(result[result.size() - 1]);
        output += "]";
        cout << output << endl;
    }

};


int main(){
    cout << "Hello World!" << endl;
    int array1[] = {1, 2, 3};
    int array2[] = {5, 2, 1, 4};
    sym(4, array1, array2);
    return 0;
}