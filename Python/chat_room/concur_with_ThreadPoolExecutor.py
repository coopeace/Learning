from concurrent.futures import ThreadPoolExecutor
import time
import random

def waiting(worker):
    print(f"{worker} task is running")
    sleep_limit = random.randint(1,10)
    # print(f"{worker} task will work for {sleep_limit}")
    time.sleep(sleep_limit)
    print(f"{worker} task is done")

def main():
    with ThreadPoolExecutor(max_workers=2) as executor :
        executor.submit(waiting,"worker-1")
        executor.submit(waiting,"worker-2")

if __name__ == "__main__":
    main()
