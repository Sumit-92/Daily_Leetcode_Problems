class Solution {
public:
vector<int>ans ;
// unordered_map< int , pair< int , char > >mp ;
    vector<pair< int , char > >mp ;
    
pair< int , char > dfs( int node , int prnt , string &labels , vector<vector<int>>&adj , vector<bool>&visited , int &ans )
{
    if(visited[node])  return mp[node] ;
    
    pair< int , char >p , t ;
    
    int temp =  1 ;
     
    
     vector<pair< int , char >>v ;
    for( auto c : adj[node] )
    {
       
        
        if( c != prnt )
        {
            t = dfs( c , node , labels , adj , visited , ans ) ;
            v.push_back(t) ;
        }
        
    }
    
         priority_queue<int>pq ;
             
         for( int i = 0 ; i < v.size() ; i++  )
            {
          
            if( labels[node] != v[i].second )
            {
                temp = max( temp , 1 + v[i].first ) ;
                ans =  max( ans , temp ) ;
                
                pq.push(v[i].first) ;
                
            }
             
            }
    
             int cnt = 2 ;
             int v1 = 0 , v2 = 0 ;
             while(cnt-- && !pq.empty())
             {
                 if(v1==0)
                 {
                     v1 = pq.top() ;
                     pq.pop() ;
                 }
                 else{
                     v2 = pq.top() ;
                     pq.pop() ; 
                 }
             }
         
    ans = max( ans , 1 + v1 + v2 ) ;
    p.first = temp ;
    p.second = labels[node] ;
    visited[node] = true ;
    
   
    return mp[node] = p  ;
    
}
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size() ;
        
        vector<vector<int>>adj(n) ;
        mp.resize(n) ;
        for( int i = 1 ; i < n ; i++ )
        {
            adj[i].push_back(parent[i]) ;
            adj[parent[i]].push_back(i) ;
        }
        
        vector<bool>visited( n , false ) ;
        int ans =  1 ;
        dfs( 0 , 0 , s , adj , visited , ans ) ;
        
        return ans ;
    }
};
