int longestUniqueSubsttr(string a){
    int n = a.length();
    int curr_len = 1;
    int max_len = 1;
    
    int last_occ[256];
    for(int i=0;i<256;i++){
        last_occ[i] = -1;
    }
    
    last_occ[a[0]]=0;
    
    for(int i=1;i<n;i++){
        
        if(last_occ[a[i]]== -1){ 
            curr_len+=1; //expansion: include
        }
        else{
            if((i-curr_len) > last_occ[a[i]]){   
                curr_len++; //expansion: include
            }
            else{
                curr_len= i-last_occ[a[i]]; //a[i] occurs in the current window so shrink window from left
            }
        }
        
        max_len = max(curr_len,max_len);
        last_occ[a[i]]=i;
        
    }
    
    
    
    return max_len;
}