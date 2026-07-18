import time

start_time = time.time()
print(f'Start time {start_time}')

def do_something():
    print('Sleeping 4 second...')
    time.sleep(4)
    print('Awake')

do_something()

finish = time.time()
print(f'Finish time {finish}')

print(f'Slept for {round(finish-start_time,2)} second(s)')