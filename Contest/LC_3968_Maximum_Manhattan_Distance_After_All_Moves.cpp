class Solution {
public:
    int maxDistance(string moves) {
        long long x = 0, y = 0;
        long long wild = 0;

        for (char c : moves) {
            if (c == 'U') y++;
            else if (c == 'D') y--;
            else if (c == 'R') x++;
            else if (c == 'L') x--;
            else wild++; // '_'
        }

        return (int)(llabs(x) + llabs(y) + wild);
    }
};
