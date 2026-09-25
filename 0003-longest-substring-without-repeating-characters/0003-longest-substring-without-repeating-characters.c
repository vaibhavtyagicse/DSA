int lengthOfLongestSubstring(char* s) {
    int last[256];
    
    // Initialize last occurrence of every character to -1
    for (int i = 0; i < 256; i++) {
        last[i] = -1;
    }

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {
        unsigned char c = s[right];

        // Character is already inside the current window
        if (last[c] >= left) {
            left = last[c] + 1;
        }

        last[c] = right;

        int len = right - left + 1;

        if (len > maxLen) {
            maxLen = len;
        }
    }

    return maxLen;
}
