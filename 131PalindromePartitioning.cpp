class Solution {
public:
    // Function to check for palindrome 
    bool isPalindrome( string s )
    {
        string t = s ;
        reverse( t.begin() , t.end() ) ;
        
        return t == s ;
    }
    void solve( string&s , int i  , vector<string>&v , vector<vector<string>>&ans )
    {
        // Base case if index crosses size 
        if(i >= s.size() )
        {
            ans.push_back(v) ;
            return ;
        }
        
        string t = "" ;
        for( int j = i ; j < s.size() ; j++ )
        {
            t += s[j] ;
            // if our current string is palindrome push it into container and call function with next index 
            if(isPalindrome(t))
            {
                v.push_back(t) ;
                solve( s , j+1 , v , ans ) ;
              
                // backtrack 
                v.pop_back() ;
            }
        }
    }
    vector<vector<string>> partition(string s) {
       
        vector<vector<string>>ans ;
        
        vector<string>v ;
        solve( s , 0 , v , ans ) ;
        return ans ;
    }
};
