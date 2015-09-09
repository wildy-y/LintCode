#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int solve(vector<int> nums,int k){
        int size=nums.size();
        if(k>size){
            return -10000;
        }
        int begin=0;
        int end=size-1;
        int ta=nums[0];
        while(begin<end){
            while(nums[end]>=ta&&end>begin){
                end--;
            }
            while(nums[begin]<=ta&&begin<end){
                begin++;
            }
            swap(nums[begin],nums[end]);
        }
        swap(nums[0],nums[end]);
        if(begin==size-k){
            return nums[begin];
        }
        else if(begin>size-k){
            vector<int> tmp;
            for(int i=0;i<begin;++i){
                tmp.push_back(nums[i]);
            }
            return solve(tmp,k+begin-size);
        }
        else{
            vector<int> tmp;
            for(int i=begin+1;i<size;++i){
                tmp.push_back(nums[i]);
            }
            return solve(tmp,k);
        }
    }
    int kthLargestElement(int k, vector<int> nums) {
        // write your code here
        return solve(nums,k);

    }
};

int main() {
    //cout << "Hello, World!" << endl;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(10);
    nums.push_back(7);


    Solution test;
    cout<< test.solve(nums,8);
    return 0;
}