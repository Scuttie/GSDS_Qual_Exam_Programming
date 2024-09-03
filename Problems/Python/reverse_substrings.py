class Solution(object):
    def reverseParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        stack = []  # 스택을 사용하여 괄호 내부의 문자열을 처리
        
        for char in s:
            if char == ')':  # 닫는 괄호를 만나면
                temp = []
                # 스택에서 여는 괄호 '('까지 모든 문자를 꺼내서 temp에 저장
                while stack and stack[-1] != '(':
                    temp.append(stack.pop())
                stack.pop()  # 여는 괄호 '(' 제거
                stack.extend(temp)  # 반전된 문자열을 다시 스택에 추가
            else:
                # 닫는 괄호가 아닌 문자는 스택에 추가
                stack.append(char)
        
        # 스택에 남아있는 문자들을 이어붙여 결과 반환
        return ''.join(stack)
