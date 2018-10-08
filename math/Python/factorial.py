#Atieve Wadhwa
#Finding factorial of a number without recursion

n = int(raw_input("Enter number to find factorial of: "))

ans = 1

while(n>1):
	ans = ans * n
	n = n-1

print("Factorial of given number is:")
print(ans)