# -*- coding: utf-8 -*-

# ������Ʈ ���� 1��
input = [10, 40, 30, 60, 30]

def problem1(input):
    # �̰��� �ڵ带 �ۼ��ϼ���.
    mean = sum(input) // len(input)          # ��� 
    median = sorted(input)[len(input)//2]    # �߾Ӱ� 
    
    result = [0, 0]
    result[0] = mean
    result[1] = median
    return result

result = problem1(input)

assert result == [34, 30]
print("correct.")
