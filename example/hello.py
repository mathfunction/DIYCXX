import numpy as np
import timeit

t1 = timeit.default_timer()
_mat = np.ones([1000,1000,1000])
t2 = timeit.default_timer()
print((t2-t1)*1000)