import string

expression = "E1<(2-6)E2%87|E3>E4"

if expression[0] == '(' :
	isAnchor = False
else :
	isAnchor = True

anchor = ''
for i in range(len(expression)) :
	if isAnchor :
		anchor += expression
		if expression[i] == '<' :
			isAnchor = False
			isComplexGen = True
		elif expression[i] == '(' :
			isAnchor = False
			isComplexGen = False
	else :
		