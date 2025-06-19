# -*- coding: utf-8 -*-

# 프로젝트 문제 1번
input = [10, 40, 30, 60, 30]

def problem1(input):
    # 이곳에 코드를 작성하세요.
    mean = sum(input) // len(input)          # 평균 
    median = sorted(input)[len(input)//2]    # 중앙값 
    
    result = [0, 0]
    result[0] = mean
    result[1] = median
    return result

result = problem1(input)

assert result == [34, 30]
print("correct.")
