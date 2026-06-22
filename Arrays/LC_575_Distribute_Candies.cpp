class Solution {
public:
    int distributeCandies(vector<int>& candyType) {

    ////Method : 1
    
        // unordered_set<int> unique_candies(candyType.begin(), candyType.end());

        // return min(candyType.size() / 2, unique_candies.size());
    
    ////Method : 2

        // 1. Sort to group identical types together
        sort(candyType.begin(), candyType.end());
        
        int n = candyType.size();
        int unique_types = 1; // Start at 1 because the array is non-empty
        
        // 2. Count the unique types
        for (int i = 0; i < n - 1; i++) {
            if (candyType[i+1] != candyType[i]) {
                unique_types++;
            }
        }
        
        // 3. Alice can eat at most n / 2 candies, or all unique types available
        return min(n / 2, unique_types);

    }
};
