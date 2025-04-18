class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int> subvector(nums1.begin(), nums1.begin() + m);
    
            subvector.insert(subvector.end(), nums2.begin(), nums2.end());
    
            sort(subvector.begin(), subvector.end());
    
            for (int i = 0; i < subvector.size(); ++i) {
                nums1[i] = subvector[i];
            }
    
            cout << "nums1: ";
            for (int val : nums1) {
                cout << val << " ";
            }
            cout << endl;
        }
    };