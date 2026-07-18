import concurrent.futures
#import threading
import time

start_time = time.perf_counter()

def do_something(second):
    print(f'Sleeping {second} second...')
    time.sleep(second)
    res = f"{second} second thread awoke"
    return res

#t1 = threading.Thread(target=do_something)
#t2 = threading.Thread(target=do_something)

#t1.start()
#t2.start()
#
#t1.join()
#t2.join()

seconds = [5,3,4,1,6]

with concurrent.futures.ThreadPoolExecutor() as executor:
    threads = executor.map(do_something,seconds)

    for _ in threads:
        print(_)

finish = time.perf_counter()

print(f'Slept for {round(finish-start_time,2)} second(s)')