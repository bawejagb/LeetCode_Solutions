class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split();
        if len(pattern) != len(words):
            return False
        dic1={}
        dic2={}
        i=0
        for ch in pattern:
            if ch not in dic1.keys():
                dic1[ch] = words[i]
            elif dic1[ch] != words[i]:
                return False
            if words[i] not in dic2.keys():
                dic2[words[i]] = ch
            elif dic2[words[i]] != ch:
                return False;
            i += 1
        return True
            