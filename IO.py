import time

# constant
RANGE_LOOP = 200000
def calculate_eiei(index):
    eiei = index * 2
    return eiei

def someFunc():
    start_time = time.time()
    for i in range(RANGE_LOOP):
        eiei = calculate_eiei(i)
    end_time = time.time()
    return end_time - start_time

def someFuncHasIO():
    start_time = time.time()
    for i in range(RANGE_LOOP):
        eiei = calculate_eiei(i)
        print(f"eiei : ", eiei)
    end_time = time.time()
    return end_time - start_time

def someFuncHasMoreIO():
    start_time = time.time()
    for i in range(RANGE_LOOP):
        eiei = calculate_eiei(i)
        print(f"eiei : ", eiei)
        print(f"repeat eiei : ", eiei)
    end_time = time.time()
    return end_time - start_time


def someFuncHasMoreMoreIO():
    start_time = time.time()
    for i in range(RANGE_LOOP):
        eiei = calculate_eiei(i)
        print(f"eiei : ", eiei)
        print(f"repeat eiei : ", eiei)
        print(f"repeat eiei again : ", eiei)
    end_time = time.time()
    return end_time - start_time

show_times = []
time_func1 = someFunc()
time_func2 = someFuncHasIO()
time_func3 = someFuncHasMoreIO()
time_func4 = someFuncHasMoreMoreIO()
show_times.append(time_func1)
show_times.append(time_func2)
show_times.append(time_func3)
show_times.append(time_func4)

print("-------RESULT--------")
for i in range(len(show_times)):

    print(f"Runtime func ",i+1, " is : ", show_times[i], "sec")
