"""
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
"""
class Solution:
    # @param tokens, a list of string
    # @return an integer
	def evalRPN(self, tokens):
		n=len(tokens)
		if(n==1):return tokens[0]
		setS=[int(tokens[0]),int(tokens[1])]
		dictS={"+":self.plus,"-":self.minus,"*":self.multiply,"/":self.divide}
		for i in range(2,n):
			if(tokens[i] in dictS):
				num2=setS.pop()
				num1=setS.pop()
				r=dictS[tokens[i]](num1,num2)
				setS.append(r)
			else:
				setS.append(int(tokens[i]))
		return setS[0]

	def plus(self,a,b):return a+b

	def minus(selt,a,b):return a-b

	def multiply(self,a,b):return a*b

	def divide(self,a,b):
		if(a*b>0):return a/b
		else:return -(abs(a)/abs(b))
    

s=Solution()
token=["2", "1", "+", "3", "*"]
print token,s.evalRPN(token)
token=["4", "13", "5", "/", "+"]
print token,s.evalRPN(token)
token=["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
print token,s.evalRPN(token)
