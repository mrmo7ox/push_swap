import os
import random

MIN = 0
MAX = 500

def get_Numbers():
    global MIN, MAX
    MIN += 100
    MAX += 100
    numbers = []
    
    while len(numbers) < 100:
        x = random.randint(MIN, MAX)
        if x not in numbers:
            numbers.append(x)
    
    return numbers

while True:
    numbers = get_Numbers()
    commandnumbers = " ".join(str(i) for i in numbers)
    
    command = f'ARG="{commandnumbers}"; ./push_swap $ARG | wc -l'
    output = os.popen(command).read()

    command_c = f'ARG="{commandnumbers}"; ./push_swap $ARG | ./checker $ARG'
    output_c = os.popen(command_c).read()
    
    if int(output) >= 700:
        print(commandnumbers, output_c)
        print(numbers)
    else:
        print(int(output), output_c)
