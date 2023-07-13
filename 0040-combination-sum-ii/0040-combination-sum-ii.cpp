

class Solution {
public:
    void find(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
            if(target==0){
                ans.push_back(ds);
                return;
        }
        //Pick Up the element
        for(int i=ind;i<arr.size();i++){
            
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            find(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        find(0,target,candidates,ans,temp);
        return ans;
    }
};