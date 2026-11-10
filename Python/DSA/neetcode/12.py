from typing import List

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack=list()
        first=False
        for ch in tokens:
            match ch :
                case "+" :
                    y = stack.pop()
                    x = stack.pop()
                    stack.append(x+y)
                    print("Sum",stack[-1])
                case "-" :
                    y = stack.pop()
                    x = stack.pop()
                    stack.append(x-y)
                    print("Differ",stack[-1])
                case "*" :
                    y = stack.pop()
                    x = stack.pop()
                    stack.append(x*y)
                    print("Mul",stack[-1])
                case "/" :
                    y = stack.pop()
                    print("divided by",y)
                    x = stack.pop()
                    print("dividing",x)
                    stack.append(int(x/y))
                    print("Div",stack[-1])
                case _ :
                    stack.append(int(ch))
                    print("append",stack[-1])
        return stack[0]

if __name__ == "__main__":
    tokens=["1","2","+","3","*","4","-"]
    tokens1=["2","1","+","3","*"]
    tokens2=["4","13","5","/","+"]
    tokens3=["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    print(Solution().evalRPN(tokens3))
