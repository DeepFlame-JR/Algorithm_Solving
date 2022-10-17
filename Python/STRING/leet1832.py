
# https://leetcode.com/problems/check-if-the-sentence-is-pangram/
import collections

class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return len(collections.Counter(sentence).keys()) == 26

    def checkIfPangram2(self, sentence: str) -> bool:
        return len(set(sentence)) == 26

    def checkIfPangram3(self, sentence: str) -> bool:
        Visit = [0] * 26
        for char in sentence:
            Visit[ord(char)-ord('a')] = 1
            if sum(Visit) == 26:
                return True
        return False

    print(checkIfPangram(None, "thequickbrownfoxjumpsoverthelazydog"))

