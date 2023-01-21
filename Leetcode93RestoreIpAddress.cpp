void solve( string &s , int i , string ans , string temp , int count , vector<string>&res )
    {
        // Do not contain leading zeros except single zero 
        if( temp.size() > 1 && temp[0] == '0' ) return ;
        
        // base case if 4 parts and end of string put it and return 
        if( i >= s.size() && count == 4 )
        {
            ans = ans + temp  ;
            res.push_back(ans) ;
            return ;
        }
        
        ans = ans + temp + "." ;
        
        temp = "" ;
        
        if( i < s.size() )
        {
           temp = s[i] ;
           solve( s , i+1 , ans , temp , count+1 , res ) ; 
        }
        if( i+1 < s.size() )
        {
           temp += s[i+1] ;
           solve( s , i+2 , ans , temp , count+1 , res ) ;        
        }
        if( i+2 < s.size() )
        {
           temp += s[i+2] ;
           if( stoi(temp) <= 255 )
           {
               solve( s , i+3 , ans , temp , count+1 , res ) ;   
           }
                
        }
        
        
    }
    vector<string> restoreIpAddresses(string s) {
       
        // Base condition that it will only consist of numbers 
        for( auto i : s )
        {
            if( i >= '0' && i <= '9' )
            {
                
            }
            else{
                return {} ;
            }
        }
        
        
        int i = 0 ;
        int count = 0 ;
        
        string ans = ""  ;
        string temp = "" ;
        temp += s[i] ;
        vector<string>res ;
        if( i < s.size() )
        {
           
           solve( s , i+1 , ans , temp , count+1 , res ) ; 
        }
        if( i+1 < s.size() )
        {
           temp += s[i+1] ;
           solve( s , i+2 , ans , temp , count+1 , res ) ;        
        }
        if( i+2 < s.size() )
        {
           temp += s[i+2] ;
           if( stoi(temp) <= 255 )
           {
               solve( s , i+3 , ans , temp , count+1 , res ) ;   
           }
                
        }
        
        return res ;
    }
