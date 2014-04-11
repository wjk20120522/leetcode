public class Solution {
    public int minDistance(String word1, String word2) {
        int len1 = word1.length(), len2 = word2.length();
        if(len1 == 0) return len2;    //if word1 is empty
        if(len2 == 0) return len1;    //if word2 is empty
        char str1[] = word1.toCharArray();
        char str2[] = word2.toCharArray();
        
        int res[][] = new int[len1+1][len2+1];
        
        int i,j;
        for(i=0; i<=len1; i++) res[i][0] = i;
        for(j=1; j<=len2; j++) res[0][j] = j;
        
        for(i=1; i<=len1; i++){
        	for(j=1; j<=len2; j++) {
        		if(str1[i-1] == str2[j-1]) {
        			res[i][j] = min(res[i-1][j]+1, res[i][j-1]+1, res[i-1][j-1]);
        		} else {
        			res[i][j] = min(res[i-1][j]+1, res[i][j-1]+1, res[i-1][j-1]+1);
        		}
        	}
        }
        return res[len1][len2];
    }
    
     public int min(int i, int j, int k){
    	int min = i;
    	if(j<min) min = j;
    	if(k<min) min = k;
    	return min;
    }
}