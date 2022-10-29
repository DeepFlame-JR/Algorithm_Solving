# https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

class Solution:
    def maxLength(self, arr: List[str]) -> int:
        set_list = [set()]

        for item in arr:
            if len(set(item)) < len(item):  # 중복이다
                continue

            set1 = set(item)
            for set2 in set_list[:]:
                if set1 & set2:  # 교집합이 존재하는가
                    continue

                set_list.append(set1 | set2)

        return max(len(concat) for concat in set_list)
