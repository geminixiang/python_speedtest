import gemini
import time
from numba import jit, int32
from functools import wraps


def timer(func):
    @wraps(func)
    def wrap(*args, **kwargs):
        start = time.time()
        value = func(*args, **kwargs)
        using_time = time.time() - start
        print(func.__qualname__ + " using time: " + str(using_time))
        return using_time
    return wrap


##########################################

start = time.time()
result = gemini.add(1,2)
t1 = time.time() - start
print('cpp using time: ' + str(t1))

##########################################
@timer
def by_python(a, b):
    for i in range(500_000):
        c = a + b
    return c

t2 = by_python(1, 2)

###########################################

@timer
@jit(int32(int32, int32), 
           nopython=True, 
           nogil=True,
           cache=True)
def by_numba(a, b):
    for i in range(500_000):
        c = a + b
    return c

t3 = by_numba(1, 2)

###########################################
print('-----------------------------------------')
print('cpp faster python: ' + str(t2 / t1) + '%')
print('cpp faster numba: ' + str(t3 / t1) + '%')