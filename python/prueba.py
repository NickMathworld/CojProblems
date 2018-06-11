import numpy as np;
tablero = np.zeros((8,8))
tablero[1::2,::2] = 1
tablero[::2,1::2] = 1
print(tablero);