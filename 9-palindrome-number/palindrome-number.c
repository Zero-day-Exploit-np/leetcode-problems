bool isPalindrome(int x){
  if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    long reversedNum = 0;
    int original = x;

    while (x > 0) {
        int remainder = x % 10;
        reversedNum = reversedNum * 10 + remainder;
        x /= 10;
    }
    return reversedNum == (long)original;
}