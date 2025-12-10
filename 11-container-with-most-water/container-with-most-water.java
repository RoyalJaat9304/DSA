class Solution {
    public int maxArea(int[] height) {
        int i=0,j=height.length-1;
        int maxx=0;
        while(i<j){
            if(height[i] < height[j]){
                maxx=Math.max(maxx,height[i] * (j-i));
                i++;
            }else{
                maxx=Math.max(maxx,height[j] * (j-i));
                j--;
            }
        }
        return maxx;
    }
}