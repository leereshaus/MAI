import numpy as np
import matplotlib.pyplot as plt

a = float(input("Введите параметр a: "))
phi = np.arange(0, 2*np.pi, 0.01)
r = a * (1 - np.sin(phi))

x = r * np.cos(phi)
y = r * np.sin(phi)

ax = plt.subplot()
ax.plot(x, y, color = 'r')

ax.grid(True)

plt.show()