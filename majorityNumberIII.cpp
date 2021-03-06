class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        // write your code here
        int len=nums.size();
        if(len<k){
            return -1;
        }
        map<int,int> m;
        for(int i=0;i<len;++i){
            if(m.find(nums[i])!= m.end()){
                m[nums[i]]++;
            }
            else if(m.size()<k){
                m[nums[i]]=1;
            }
            else{
                //需要把键存起来然后做删除操作，因为如果在map的遍历过程中删除，这个遍历就不是原来的方式
                vector<int> keys;
                for(auto &kv:m){
                    keys.push_back(kv.first);
                }

                for(auto &it:keys){
                    m[it]--;
                    if(m[it]==0){
                        m.erase(it);
                    }
                }
            }
        }
        
        int res=0;
        int num=0;
        for(auto &kv:m){
            if(kv.second>num){
                num=kv.second;
                res=kv.first;
            }
        }
        return res;
    }
};
