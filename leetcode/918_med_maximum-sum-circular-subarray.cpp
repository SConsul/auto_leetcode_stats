class Solution {
public:
    int normalMax(vector<int>& arr){
        int res = arr[0];
        int maxEnding = arr[0];
        for(int i = 1; i< arr.size(); i++){
            maxEnding = max(maxEnding+arr[i], arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& arr) {
        int normal = normalMax(arr);
        // cout<<normal<<endl;
        if(normal < 0)
            return normal;
        int sum = 0;
        for(int i=0; i< arr.size(); i++){
            sum+= arr[i];
            arr[i] = -arr[i];
        }
        // cout<<sum<<endl;
        int circular = sum + normalMax(arr);
        // cout<<circular<<endl;
        return max(normal, circular);
        
    }
};