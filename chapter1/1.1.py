# Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

# parse each character from string and put it new array. Check if the character is present in the new array already. If so, exit.
my_string = raw_input("Enter the string: ")
char_arr = list(my_string)
new_arr = []
for c in char_arr:
	if c in new_arr:
		print "Non unique string"
		quit()
	else:
		new_arr.append(c)
print "Unique string"
	
	
