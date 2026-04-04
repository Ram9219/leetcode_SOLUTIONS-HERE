class Solution {
    public String decodeCiphertext(String encodedText, int rows) {
        if (rows == 0) return "";
        
        int cols = encodedText.length() / rows;
        StringBuilder result = new StringBuilder();
        
        for (int start = 0; start < cols; start++) {
            int i = 0, j = start;
            
            while (i < rows && j < cols) {
                result.append(encodedText.charAt(i * cols + j));
                i++;
                j++;
            }
        }
        
        return result.toString().replaceAll("\\s+$", "");
    }
}