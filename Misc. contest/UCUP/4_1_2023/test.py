import subprocess
import random

# Define the two executable programs to run
program1 = './hard_problem.exe'
program2 = './hard_problem_brute_force.exe'

while True:
    input_range = (0, 3)
    input_value = [str(random.randint(*input_range)) for i in range(6)]
    print(input_value)
    s = ("1 5 " + " ".join(input_value) + "\n").encode()
    print(s)
    # Run program 1 with the random input and capture the stdout
    p1 = subprocess.Popen([program1], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    p1_output = p1.communicate(input=s)[0].decode('utf-8')
    
    # Run program 2 with the same random input and capture the stdout
    p2 = subprocess.Popen([program2], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
    p2_output = p2.communicate(input=s)[0].decode('utf-8')
    
    # # Compare the stdout of program 1 and program 2
    if p1_output != p2_output:
        print(f"Inputs: {input_value}\nProgram 1 output: {p1_output}\nProgram 2 output: {p2_output}\n")
        break