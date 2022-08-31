class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        res1,res2=[],[]
        for s in logs:
            if s.split()[1].isdigit():
                res2.append(s.split())
            else:
                res1.append(s.split())
        res1.sort(key = lambda x: x[0])
        res1.sort(key = lambda x: x[1:])
        res1.extend(res2)
        for i in range(len(res1)):
            res1[i] = ' '.join(res1[i])
        return res1
        