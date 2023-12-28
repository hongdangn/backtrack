import numpy as np

number_bits = int(input("The number of bits is: "))
list = np.random.randint(0, 2, number_bits)
bits = [0, 1]
def print_string(list):
    string = ""
    for index in range(number_bits):
        string += str(list[index])
    print(string)

def print_solution(count_bits):
    if count_bits == number_bits:
        print_string(list)
        return  

    for bit in bits:
        list[count_bits] = bit
        print_solution(count_bits + 1)

print_solution(count_bits = 0)