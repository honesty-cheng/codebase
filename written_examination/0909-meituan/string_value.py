def min_value(s, n, k):
    # same = 0
    # diff = 0
    # i = 0
    for i in range(100):
        s = s.replace("11", "")
        s = s.replace("00", "")
    ans = len(s)
    
    # while i < n:
    #     j = i
    #     while j < len(s) and s[i] == s[j]:
    #         j += 1
    #     same += (j - i) // 2
    #     diff += 1
    #     i = j

    # ans = n- (same*2)
    
    print(s)
    print("ans", ans)
    # print("ans", ans, "same", same, "diff", diff)
    if ans >= k*2:
        return ans - k*2
    elif ans % 2 == 0: #  偶数
        if (k - ans/2) % 2 == 0: # k 余偶数
            return 0
        else:
            return 2
    else:   # ans 奇数
        return 1    
    
print(min_value('1010', 4, 2))
print(min_value('1010', 4, 3))
print(min_value('1010', 4, 4))

print(min_value('10101', 5, 2))
print(min_value('10101', 5, 3))
print(min_value('10101', 5, 4))

print(min_value('0000', 4, 1))
print(min_value('0000', 4, 2))
print(min_value('0000', 4, 3))
print(min_value('0000', 4, 4))

print(min_value('100100', 6, 1))
print(min_value('100100', 6, 2))
print(min_value('100100', 6, 3))
print(min_value('100100', 6, 4))
print(min_value('100100', 6, 5))

# print(min_value('00', 2, 1))
# print(min_value('101', 3, 1))
