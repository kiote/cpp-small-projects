class Solution(object):
    OPEN_BRACKETS = ["(", "{", "["]
    CLOSED_BRACKETS = [")", "}", "]"]
    
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if (s == ""):
            return True
        
        bracketsList = list(s)
        checkList = []
        for i in range(0, len(bracketsList)):
            if (bracketsList[i] in self.OPEN_BRACKETS):
                checkList.append(bracketsList[i])
            else:
                if (len(checkList) == 0):
                    return False
                elem = checkList.pop()
                if not self.isMatching(elem, bracketsList[i]):
                    return False
        if (len(checkList) != 0):
            return False
        return True
    
    def isMatching(self, elem1, elem2):
        index1 = self.OPEN_BRACKETS.index(elem1)
        index2 = self.CLOSED_BRACKETS.index(elem2)
        return index1 == index2
