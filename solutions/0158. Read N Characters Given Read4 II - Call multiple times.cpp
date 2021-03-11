/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char myBuf[4];
    int index = 0;
    int charLeft = 0;
    
    int read(char *buf, int n) {
        if (charLeft == 0) {
            charLeft = read4(myBuf);
            index = 0;
        }
        
        int cnt = 0;
        while (cnt < n && charLeft) {
            buf[cnt++] = myBuf[index++];
            charLeft--;
            if (charLeft == 0) {
                charLeft = read4(myBuf);
                index = 0;
            }
        }
        
        return cnt;
    }
};
