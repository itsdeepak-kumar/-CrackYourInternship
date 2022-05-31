
// Problem 1 : valid square 

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
         unordered_set<int> s({dist(p1,p2), dist(p1,p3), dist(p1,p4), dist(p2,p3),                                dist(p2,p4), dist(p3,p4)});
        return !s.count(0) && s.size()==2;
    }
    
    int dist(vector<int>& x1, vector<int>& x2){
        return (x2[1]-x1[1])* (x2[1]-x1[1]) + (x2[0]-x1[0])* (x2[0]-x1[0]);
    }

};

// Problem 2 : The kth factor of n 

class Solution {
public:
    int kthFactor(int n, int k) {
        for(int i=1;i<=n/2;i++){
            if(n%i==0 && --k==0) return i;
        }        
        return k==1 ? n : -1;
    }
};

// Problem 3 : spiral matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        int rbegin=0,rend=n-1, cbegin=0,cend=m-1;
        
        if(n==0 || m==0) return res;
        
        while(rbegin<=rend && cbegin<=cend){
            for(int i=cbegin;i<=cend;i++) res.push_back(matrix[rbegin][i]);
            rbegin++;
            
            for(int i=rbegin;i<=rend;i++) res.push_back(matrix[i][cend]);
            cend--;
            
            if(rbegin<=rend){
                for(int i=cend;i>=cbegin;i--) res.push_back(matrix[rend][i]);
            }
            rend--; 
            
            if(cbegin<=cend){
                for(int i=rend;i>=rbegin;i--) res.push_back(matrix[i][cbegin]);
            }
            cbegin++;  
        }
        return res;
    }
};


// Problem 4 : Rotate Image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverse(matrix);
    }
    
    void transpose(vector<vector<int>>& mat){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp = mat[j][i];
                mat[j][i]=mat[i][j];
                mat[i][j]=temp;
            }
        }
    }
    
    void reverse(vector<vector<int>>& mat){
        int n=mat.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                int temp = mat[i][j];
                mat[i][j]=mat[i][n-j-1];
                mat[i][n-j-1]=temp;
            }
        }
    }
};



