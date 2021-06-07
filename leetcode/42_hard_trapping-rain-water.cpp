class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>L(n);
        vector<int>R(n);
        for(int i=1; i<n;i++){
            L[i] = max(L[i-1], height[i-1]);
            R[n-i-1] = max(R[n-i], height[n-i]);
        }
                  
        int vol = 0;
        for(int i=0; i<n;i++){
            vol += max(min(L[i], R[i])-height[i], 0);
        }
        return vol;
        
    }
};