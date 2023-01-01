class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
        if (len(pattern) != len(words)) or (len(set(pattern)) != len(set(words))):
            return False
        d = {} 
        i=0
        for c in pattern: 
            w = words[i] 
            if (c in d) and (d[c] != w):
                return False
            else:
                d[c] = w
            i += 1
        return True
            