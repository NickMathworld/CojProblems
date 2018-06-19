import matplotlib.pyplot as plt
import numpy as np
def f(x):
	return np.exp(-x**2);
x = np.linspace(-1,5);
plt.plot(x,f(x))
plt.xlabel('Eje X')
plt.ylabel('f(x)')
plt.title('Prueba de una gráfica')
plt.grid(True)
plt.savefig("test.png")
plt.show()