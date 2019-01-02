def cons(a, b):
	def pair(f):
		return f(a, b)
	return pair

def pairExtractor (a,b):
	return (a,b)

#Returns first element of a pair
def car (pair):
	return pair (pairExtractor)[0]

#Refurns second element of a pair
def cdr(pair):
	return pair (pairExtractor)[1]

print(car(cons(3,4)))
print(cdr(cons(3,4)))
