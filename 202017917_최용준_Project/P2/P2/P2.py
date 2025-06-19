# -*- coding: utf-8 -*-

def problem2(input):
    open_count = 0  # 열린 괄호의 수
    need_to_add = 0  # 추가 괄호 수

    for char in input:
        print(char) 

    for char in input:
        if char == '(':
            open_count += 1
        elif char == ')':
            if open_count > 0:  
                open_count -= 1  # ()채워진 괄호
            else:
                need_to_add += 1  # 짝 없는 ')' → '('가 하나 필요함

    result = need_to_add + open_count
    return result

# 입력값
input = ")))()"

# 함수 실행
result = problem2(input)

# 결과 확인
assert result == 3
print("correct")