import numpy as np

number_input = int(input("The input number is: "))

# count the number of permutations
cnt, permutation = 0, [0 for num in range(number_input)]

# marking the number has already existed 
number_marked = [0 for num in range(number_input)]

# init permutation
number_init = [num + 1 for num in range(number_input)]

def backtrack(count_number):        
    global cnt
    if count_number == number_input:
        print(permutation)
        cnt += 1
        return
    
    for num in number_init:
        # if the number isn't chosen (mark = false), assign it to permutation
        if number_marked[num - 1] == 0:
            permutation[count_number] = num
            # marking the chosen number = true
            number_marked[num - 1] = 1
            backtrack(count_number + 1)
            number_marked[num - 1] = 0

backtrack(count_number = 0)
print(cnt)