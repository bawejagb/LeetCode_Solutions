class Solution:
    def reverseWords(self, s: str) -> str:
        res=""
        for word in s.split():
            res += ' '+word[::-1]
        return res[1:]