class Solution {
public:
    int fib(int n) {
//         vector<int> v(n+1);
//         return recurse(n,v);
        
        if (n <=1)
            return n;
        else
            return fib(n-1) + fib(n-2);
    }
};

// int fib(int n) {
//         vector<int>v(n+1,-1);
//         return findp(n,v);
//     }
//     int findp(int n, vector<int>&v){
//         if(n==0)
//             return 0;
//         if(n==2 || n==1)
//             return 1;
//         if(v[n]!=-1)
//             return v[n];
//         v[n] = findp(n-1,v)+findp(n-2,v);
//         return v[n];
//     } 