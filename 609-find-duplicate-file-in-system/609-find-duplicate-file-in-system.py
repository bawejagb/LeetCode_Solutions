class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        result = []
        hmap = {}
        for files in paths:
            fileList = files.split(" ")
            if len(fileList)>1:
                for i in range(1,len(fileList)):
                    file = fileList[i].split("(")[0]
                    data = fileList[i].split("(")[1][:-1]
                    if(data not in hmap.keys()):
                        hmap[data] = []
                    hmap[data].append(fileList[0]+'/'+file)
        for key in hmap.keys():
            if len(hmap[key])>1:
                result.append(hmap[key])
        return result