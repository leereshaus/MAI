import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from scipy.integrate import odeint


def odesys(y, t, m1, m2, c, c1, R, g):
    dy = np.zeros(4)
    dy[0] = y[2]
    dy[1] = y[3]

    a11 = -m2 * R * np.cos(y[1])
    a12 = ((2 * m1 + m2) * R**2 + m2 * y[0] + 2 * R * m2 * y[0] * np.sin(y[1]))
    a21 = 1
    a22 = -R * np.cos(y[1])

    b1 = -m2 * R * y[0] * y[3]**2 * np.cos(y[1]) - 2 * m2 * (y[0] + R * np.sin(y[1])) * y[2] * y[3] - c1 * R**2 * y[1] - m2 * g * y[0] * np.cos(y[1])
    b2 = y[0] * y[3]**2 - 2 * (c/m2) * y[0] - g * np.sin(y[1])

    dy[2] = (b1 * a22 - b2 * a12) / (a11 * a22 - a12 * a21)
    dy[3] = (b2 * a11 - b1 * a21) / (a11 * a22 - a12 * a21)

    return dy


m1 = 1
m2 = 0.5
R = 1
g = 9.81
c = c1 = 5

t_fin = 20

t = np.linspace(0, t_fin, 1001)

s0 = 0
phi0 = np.pi/2
ds0 = 0
dphi0 = 1

y0 = [s0, phi0, ds0, dphi0]

Y = odeint(odesys, y0, t, (m1, m2, c, c1, R,  g))

s = Y[:, 0]
phi = Y[:, 1]
ds = Y[:, 2]
dphi = Y[:, 3]

fig_for_graphs = plt.figure(figsize=[13,7])
ax_for_graphs = fig_for_graphs.add_subplot(2,2,1)
ax_for_graphs.plot(t, s, color='blue')
ax_for_graphs.set_title("s(t)")
ax_for_graphs.set(xlim=[0, t_fin])
ax_for_graphs.grid(True)

ax_for_graphs = fig_for_graphs.add_subplot(2,2,2)
ax_for_graphs.plot(t,phi,color='red')
ax_for_graphs.set_title('phi(t)')
ax_for_graphs.set(xlim=[0,t_fin])
ax_for_graphs.grid(True)

ax_for_graphs = fig_for_graphs.add_subplot(2,2,3)
ax_for_graphs.plot(t,ds,color='green')
ax_for_graphs.set_title("s'(t)")
ax_for_graphs.set(xlim=[0,t_fin])
ax_for_graphs.grid(True)

ax_for_graphs = fig_for_graphs.add_subplot(2,2,4)
ax_for_graphs.plot(t,dphi,color='black')
ax_for_graphs.set_title('phi\'(t)')
ax_for_graphs.set(xlim=[0,t_fin])
ax_for_graphs.grid(True)

plt.show()
