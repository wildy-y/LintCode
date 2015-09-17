#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

using namespace std;
class Solution {
public:
    /**
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer 
     */
    vector<int> r;
    vector<vector<int>> res;
    
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        // write your code here
        vector<vector<int>> ret;
        int len=A.size();
        if(k>len){return res;}
        vector<pair<int,int>> num;
        for(int i=0;i<len;i++){
            num.push_back(make_pair(A[i],i));
        }
        sort(A.begin(), A.end());
        solve(A,k,target,r,0);
        ret =res;
        return ret;
       
    }
    void solve(vector<int> A,int k,int target,vector<int> &r,int begin){
        if(k==0&&target==0){
            res.push_back(r);
            return ;
        }
        if(k==0&&target!=0){
            return;
        }
        for(int i=begin;i<A.size();++i){
            int a=A[i];
            r.push_back(a);
			//cout<<a<<endl;
            solve(A,k-1,target-a,r,i+1);
			r.pop_back();
        }
    }
};
int main(){
	Solution  test;
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	vector<vector<int> > res;
	res=test.kSumII(a,2,5);
	for(int i=0;i<res.size();i++){
	   vector<int> tmp=res[i];
	   for(int j=0;j<tmp.size();j++){
	       cout<<tmp[j]<<" ";
	   }
	   cout<<endl;
	}
	Sleep(1000000);
}