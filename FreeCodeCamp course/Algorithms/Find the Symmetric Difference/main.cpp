#include <iostream>
#include <vector>
#include <cstdarg>
#include <algorithm>
using namespace std;
vector<int> sym_difference(vector<int> arr1, vector<int> arr2);
class Tool{
public:
    static bool includes(vector<int> arr, int item){
        auto from_arr2 = find(arr.begin(), arr.end(), item);
        return from_arr2 != arr.end();
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
    static void iterator(vector<int> &arr1, vector<int> &arr2, vector<int> &merged_result) {
        for(int item1: arr1){
            if(!(Tool::includes(arr2, item1) && Tool::includes(merged_result, item1))){
                merged_result.push_back(item1);
            }
        }
    }
};
template<typename... Args>
vector<int> sym(const Args... args){
    vector<int> result;
    result = sym_difference(result, vector<int> {});
//    va_list args;
//    va_start(args, numArgs);
//    for(int i = 0; i < numArgs; i++){
//        int* arg = va_arg(args, int*);
//        int size_of_arg = sizeof(arg) / sizeof(int);
//        vector<int> arg_as_vector(arg, arg + size_of_arg);
//        if(result.size() == 0){
//            result = arg_as_vector;
//        }
//        result = sym_difference(result, arg_as_vector);
//    }
//    va_end(args);
    return result;
}
vector<int> sym_difference(vector<int> arr1, vector<int> arr2){
    vector<int> merged_result;
    Tool tools;
    tools.iterator(arr1, arr2, merged_result);
    tools.iterator(arr2, arr1, merged_result);
    return merged_result;
}
int main(){
    int array1[] = {1, 2, 3};
    int array2[] = {5, 2, 1, 4};
    vector<int> result = sym(array1, array2);
    Tool::print(result);
    return 0;
}