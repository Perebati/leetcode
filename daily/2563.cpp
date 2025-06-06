class Solution {
    public:
        long long countFairPairs(std::vector<int>& nums,
                                 int lower, int upper)
        {
            std::sort(nums.begin(), nums.end());             
            return solve(nums, 0, (int)nums.size() - 1,
                         (long long)lower, (long long)upper);
        }
    
    private:
        static long long solve(const std::vector<int>& a,
                               int l, int r,
                               long long low, long long up)
        {
            if (r - l < 1) return 0;            
    
            int mid = (l + r) >> 1;
            long long ans = 0;
    
            int  i   = mid;        
            int  jLo = mid + 1;    
            int  jHi = mid + 1;    
    
            while (i >= l) {
                while (jLo <= r && 1LL * a[i] + a[jLo] <  low) ++jLo;
                while (jHi <= r && 1LL * a[i] + a[jHi] <= up) ++jHi;
    
                if (jHi > jLo) ans += (jHi - jLo);  
                --i;                               
            }
     
            ans += solve(a, l,     mid,     low, up); 
            ans += solve(a, mid+1, r,       low, up);  
            return ans;
        }
    };