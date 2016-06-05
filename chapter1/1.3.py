# Given two strings, write a method to decide if one is a permutation of another

first_str = raw_input("Enter the first string: ")
second_str = raw_input("Enter the second string: ")

if len(first_str) != len(second_str):
	print "NOT A Permutation!!"
else:
	# use XOR - ord method gives the ascii value of character
	first_str_arr = list(first_str)
	second_str_arr = list(second_str)
	result = 0
	for i in range(0,len(first_str_arr)):
		result = result ^ ord(first_str_arr[i]) ^ ord(second_str_arr[i])
	if result == 0:
		print "Permutation!!"
	else:
		print "NOT A Permutation!!"
		
