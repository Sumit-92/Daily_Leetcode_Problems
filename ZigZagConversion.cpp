string convert(string s, int numRows) {
        
  
        if( numRows == 1 ) return s ;
        string ans = "" ;
        
        bool f = true ;
        int c = 0 ;
        
        vector<vector<char>>v(numRows) ;
        
        for( int i = 0 ; i < s.size() ; i++ )
        {
            v[c].push_back(s[i]) ;
            
            // if flag is true go in the down direction 
            if(f)  c++ ;
          
            // if flag is false go in up direction 
            if(!f) c-- ;
            
          // if you reach down at the end change direction of flag = false and c to second last characters position 
            if(c==numRows)
            {
                c = numRows-2 ;
                f = false ;
            }
            
          // if you reach 0 change direction flag = true  
            if(c==0)
            {
                f = true ;
            }
        }
        
        for( int i = 0 ; i < numRows ; i++ )
        {
            for( int j = 0 ; j < v[i].size() ; j++ )
            {
                ans += v[i][j] ;
            }
        }
        
        return ans ;
    }
