from pprint import pprint
import numpy as np

board = [[1, 1, 1, 1, 1, ],
         [1, 1, 1, 1, 1, ],
         [1, 1, 1, 1, 1, ],
         [1, 1, 1, 1, 1, ],
         [1, 1, 0, 1, 1, ]]
store = [[1, 1, 1, 1, 1, ],
         [1, 1, 1, 1, 1, ],
         [1, 1, 1, 1, 1, ],
         [1, 1, 1, 1, 1, ],
         [1, 1, 1, 1, 1, ]]

# 计算行方向上的最小值
cum_sum = np.cumsum(board, axis=1)
store = np.minimum(store, cum_sum)

print(store)
# 计算列方向上的最小值
cum_sum = np.cumsum(board, axis=0)
store = np.minimum(store, cum_sum[::-1])[::-1]
