import sys

#   多行输入输出 1
for line in sys.stdin:
	words = line.split()
	print(int(words[0]) + int(words[1]))


#  单行输入输出 2    
t = int(input())
for i in range(t):
    words = list(map(int, input().split(" ")))  # 换成 逗号 则是逗号分隔

# 0 0  结束的两个正整数
while True:
    try:
        words = list(map(int,input().split(" ")))
        if words[0] ==  words[1] == 0:
            break
        print(sum(words))
    except:
        break
    



# 字符串

t = int(input())
num = list(input().split(" "))
