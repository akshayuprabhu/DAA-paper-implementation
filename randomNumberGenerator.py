import random
import sys

n = int(input("enter the number of elements to be generated "))

f = open("input",'w')
sys.stdout = f

print(n)

for i in range(1,n):
	print(random.randint(1,1000) ,end=" ")


