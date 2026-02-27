import java.util.*;

class Solution {
    public int minOperations(String s, int k) {
        int n = s.length();
        int initialZeros = 0;
        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '0') initialZeros++;
        }

        if (initialZeros == 0) return 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(initialZeros);
        
        int[] dist = new int[n + 1];
        Arrays.fill(dist, -1);
        dist[initialZeros] = 0;

        // To avoid TLE: Maintain two pointers for the 'unvisited' ranges
        // One for even indices, one for odd indices (since step is 2)
        int[] nextUnvisited = new int[n + 3];
        for (int i = 0; i <= n + 2; i++) nextUnvisited[i] = i;

        while (!queue.isEmpty()) {
            int Z = queue.poll();

            // Calculate the range of possible nextZ
            int min_z = Math.max(0, k - (n - Z));
            int max_z = Math.min(Z, k);
            
            int startZ = Z + k - 2 * max_z;
            int endZ = Z + k - 2 * min_z;

            // Jump through unvisited nodes in steps of 2
            for (int curr = findNext(nextUnvisited, startZ); curr <= endZ; curr = findNext(nextUnvisited, curr)) {
                if (dist[curr] == -1) {
                    dist[curr] = dist[Z] + 1;
                    if (curr == 0) return dist[curr];
                    queue.add(curr);
                }
                // Mark as visited by pointing to the next possible index (curr + 2)
                nextUnvisited[curr] = findNext(nextUnvisited, curr + 2);
            }
        }

        return -1;
    }

    // Helper to skip already visited nodes (Union-Find style path compression)
    private int findNext(int[] nextUnvisited, int i) {
        if (i >= nextUnvisited.length) return nextUnvisited.length - 1;
        if (nextUnvisited[i] == i) return i;
        return nextUnvisited[i] = findNext(nextUnvisited, nextUnvisited[i]);
    }
}