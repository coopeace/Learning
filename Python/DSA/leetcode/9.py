class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x<0 or (x>0 and x%10==0):
            return False
        m = x
        a = 0
        while (m!=0):
            a=a*10+m%10
            m//=10
        return x==a

if __name__ == "__main__":
    x = 121
    print(Solution().isPalindrome(x))
