class Solution {
public:
   bool isScramble(string s1, string s2) {
    if(s1==s2)
        return true;
    int n = s1.length();
    vector<vector<vector<bool> > > scrambled(n,vector<vector<bool> >(n,vector<bool>(n,false) )); 
    for(int i = 0; i < s1.length(); i++)
        for(int j = 0; j < s2.length(); j++){
            scrambled[i][j][0] = true; 
            scrambled[i][j][1] = s1[i] == s2[j];
        }

    for(int i = s1.length() - 1; i >= 0 ; i--)
        for(int j = s2.length() - 1; j >= 0; j--)
            for(int n = 2; n <= min(s1.length() - i, s2.length() - j); n ++)
                for(int m = 1; m < n; m++){
                    scrambled[i][j][n] = scrambled[i][j][m] && scrambled[i + m][j + m][n - m] ||
                            scrambled[i][j + n - m][m] && scrambled[i + m][j][n - m];
                    if(scrambled[i][j][n])  break;
                }
    return scrambled[0][0][s1.length()]; 
}
};
