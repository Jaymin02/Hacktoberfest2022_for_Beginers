class Solution {
public:
    
    void dfs(int i,int j,vector<vector<int>>&h,int n,int m,vector<vector<int>>&mat,int val){
        
        if(i>=n || i<0 || j<0 || j>=m)return;
        if(h[i][j]<val)return;
        if(mat[i][j]!=0)return;
        mat[i][j]=1;
        
        
        dfs(i-1,j,h,n,m,mat,h[i][j]);
        dfs(i+1,j,h,n,m,mat,h[i][j]);
        dfs(i,j-1,h,n,m,mat,h[i][j]);
        dfs(i,j+1,h,n,m,mat,h[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        
        vector<vector<int>>p(n,vector<int>(m,0));
        vector<vector<int>>a(n,vector<int>(m,0));
        
        
        for(int j=0;j<m;j++){
            dfs(0,j,h,n,m,p,INT_MIN);
            dfs(n-1,j,h,n,m,a,INT_MIN);
        }
        
        for(int i=0;i<n;i++){
            dfs(i,0,h,n,m,p,INT_MIN);
            dfs(i,m-1,h,n,m,a,INT_MIN);
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<p[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"AD"<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(p[i][j]==1 && a[i][j]==1){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
