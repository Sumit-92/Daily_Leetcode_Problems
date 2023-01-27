void  check( string &w , unordered_map< string , int >&mp , string t , int i , int count  , bool &f )
    {
        // if already our f is true avoid unnecessary calls and return 
        if(f) return ;
        if( i < w.size() )
        {
            t += w[i] ;   
        }
       
        // if reached end of string 
        if( i >= w.size() )
        {
          // if t is null and count is more than 1 means can be broken into more than one part and all are there in dictionary so f = true and return 
           if( t == "" && count > 1 )
            {
                
              f = true ;
             
            }
             return ;
        }
    
        check( w , mp , t , i+1 , count , f ) ;
    
        // if this words is present in map break it count++ and t = "" try creating new word from this point 
        if( mp.find(t) != mp.end())
            {
                t = "" ;
                check( w , mp , t , i+1 , count+1 , f ) ;
              
            }
        
    
           
    

    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
       
        // Store all words in a map 
        unordered_map< string , int >mp;
        
        for( auto i : words )
        {
            mp[i]++ ;
        }
        
        vector<string>ans ;
        
        for( auto i : words )
        {
            string t = "" ;
            
            bool f = false ;
            // make dfs call to check for each word 
            check( i , mp , t , 0 , 0 , f ) ;
            if(f)
            {
                ans.push_back(i) ;
            }
        }
        
        return ans ;
    }
