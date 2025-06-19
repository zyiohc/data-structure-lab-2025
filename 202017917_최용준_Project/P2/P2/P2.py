# -*- coding: utf-8 -*-

def problem2(input):
    open_count = 0  # ���� ��ȣ�� ��
    need_to_add = 0  # �߰� ��ȣ ��

    for char in input:
        print(char) 

    for char in input:
        if char == '(':
            open_count += 1
        elif char == ')':
            if open_count > 0:  
                open_count -= 1  # ()ä���� ��ȣ
            else:
                need_to_add += 1  # ¦ ���� ')' �� '('�� �ϳ� �ʿ���

    result = need_to_add + open_count
    return result

# �Է°�
input = ")))()"

# �Լ� ����
result = problem2(input)

# ��� Ȯ��
assert result == 3
print("correct")