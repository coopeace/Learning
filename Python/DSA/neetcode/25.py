class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(s)<len(t) : return ""

        t_counter = dict()
        for ch in t:
            t_counter[ch]=1+t_counter.get(ch,0)
        
        window = dict()
        left = 0
        min_window = float("inf")
        l_r = [0,0]
        have,need = 0,len(t_counter)
        for right in range(len(s)):
            window[s[right]] = 1 + window.get(s[right],0) # adding ch to window

            if s[right] in t_counter and window[s[right]]==t_counter[s[right]]:
                have+=1   

            while have == need :
                if right - left + 1 < min_window:
                    min_window = right - left + 1
                    l_r = [left,right]

                window[s[left]]-=1
                if s[left] in t_counter and window[s[left]] < t_counter[s[left]]:
                    have -= 1
                left += 1

        return s[l_r[0]:l_r[1]+1] if min_window != float("inf") else "" 

if __name__ == "__main__":
    # s = "OUZODYXAZV"
    # t = "XYZ"
    s = "ab"
    t = "a"
    s = "ADOBECODEBANC"
    t = "ABC"
    print(Solution().minWindow(s,t))
