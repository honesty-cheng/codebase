# JZ3 数组中重复的数字

class Solution:
    def duplicate(self , numbers: List[int]) -> int:
        mp = dict()
        for num in numbers:
            if num not in mp:
                mp[num] = 1
            else:
                return num
        return -1