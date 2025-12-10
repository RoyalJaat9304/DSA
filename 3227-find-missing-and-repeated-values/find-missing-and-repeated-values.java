class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int[] ans=new int[2];
        int n = grid.length;
        int[] hash= new int[(n*n)+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[grid[i][j]]++;
            }
        }
        for(int i=0;i<hash.length;i++){
            if(hash[i] == 0)
            ans[1] = i;
            if(hash[i] == 2)
            ans[0] = i;
        }
        return ans;
    }
}