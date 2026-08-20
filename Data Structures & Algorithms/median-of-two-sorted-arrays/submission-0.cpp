class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size())
            swap(nums1, nums2);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {

            int cutA = (low + high) / 2;
            int cutB = (m + n + 1) / 2 - cutA;

            int leftA = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
            int rightA = (cutA == m) ? INT_MAX : nums1[cutA];

            int leftB = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            int rightB = (cutB == n) ? INT_MAX : nums2[cutB];

            // Correct partition
            if (leftA <= rightB && leftB <= rightA) {

                // Odd
                if ((m + n) % 2)
                    return max(leftA, leftB);

                // Even
                return (max(leftA, leftB) +
                        min(rightA, rightB)) / 2.0;
            }

            if (leftA > rightB)
                high = cutA - 1;
            else
                low = cutA + 1;
        }

        return 0;
    }
};
