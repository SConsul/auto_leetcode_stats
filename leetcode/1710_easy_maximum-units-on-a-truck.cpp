class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
         int n = boxTypes.size();
         vector<int>count(1000,0);
         for(int i=0; i<n;i++){
             //cout<<boxTypes[i][1]<<endl;
             count[boxTypes[i][1]-1] += boxTypes[i][0];
         }
        int max_units = 0;
        int boxes = 0;
        for(int i =999; i>=0; i--){
            if(boxes> truckSize)
                break;
            if (boxes + count[i] > truckSize){
                max_units += (truckSize - boxes) * (i+1);
                    break;
            }
            else{
                max_units += count[i] * (i+1);
                boxes += count[i];
            }
        }
        return max_units;
    }
    
   
};