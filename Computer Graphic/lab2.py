import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
from matplotlib.widgets import Button

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

r = 6

# Основание пирамиды
x = [r, np.sqrt(2) * r / 2, 0, -np.sqrt(2) * r / 2, -r, -np.sqrt(2) * r / 2, 0, np.sqrt(2) * r / 2]
y = [0, -np.sqrt(2) * r / 2, -r, -np.sqrt(2) * r / 2, 0, np.sqrt(2) * r / 2, r, np.sqrt(2) * r / 2]
z = [0, 0, 0, 0, 0, 0, 0, 0]
sides = [list(zip(x, y, z))]

# Первая боковая грань
x = [r, np.sqrt(2) * r / 2, 0]
y = [0, -np.sqrt(2) * r / 2, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

# Вторая боковая грань
x = [np.sqrt(2) * r / 2, 0, 0]
y = [-np.sqrt(2) * r / 2, -r, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

# Третья боковая грань
x = [0, -np.sqrt(2) * r / 2, 0]
y = [-r, -np.sqrt(2) * r / 2, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

# Четвертая боковая грань
x = [-np.sqrt(2) * r / 2, -r, 0]
y = [-np.sqrt(2) * r / 2, 0, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

# Пятая боковая грань
x = [-r, -np.sqrt(2) * r / 2, 0]
y = [0, np.sqrt(2) * r / 2, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

# Шестая боковая грань
x = [-np.sqrt(2) * r / 2, 0, 0]
y = [np.sqrt(2) * r / 2, r, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

# Седьмая боковая грань
x = [0, np.sqrt(2) * r / 2, 0]
y = [r, np.sqrt(2) * r / 2, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

# Восьмая боковая грань
x = [np.sqrt(2) * r / 2, r, 0]
y = [np.sqrt(2) * r / 2, 0, 0]
z = [0, 0, r]
sides.append(list(zip(x, y, z)))

poly = Poly3DCollection(sides, alpha=0.5, edgecolors='black')

ax.add_collection3d(poly)

ax.set_xlim(-6, 6)
ax.set_ylim(-6, 6)
ax.set_zlim(-6, 6)


def button_callback_remove(event):
    ax.add_collection3d(Poly3DCollection(sides, alpha=1, edgecolors='black'))
    plt.draw()


button_ax_remove = fig.add_axes([0.5, 0.05, 0.31, 0.06])
button_remove = Button(button_ax_remove, "Remove invisible lines")
button_remove.on_clicked(button_callback_remove)


def button_callback_show(event):
    ax.add_collection3d(Poly3DCollection(sides, alpha=0.5, edgecolors='black'))
    plt.draw()


button_ax_show = fig.add_axes([0.5, 0.15, 0.31, 0.06])
button_show = Button(button_ax_show, "Show invisible lines")
button_show.on_clicked(button_callback_show)


def button_callback_isometric(event):
    ax.view_init(10, 30)
    plt.draw()


button_ax_isometric = fig.add_axes([0.1, 0.05, 0.31, 0.06])
button_isometric = Button(button_ax_isometric, "Isometric projection")
button_isometric.on_clicked(button_callback_isometric)


def button_callback_orthographic_top(event):
    ax.view_init(90)
    plt.draw()


button_ax_orthographic_top = fig.add_axes([0.1, 0.15, 0.31, 0.06])
button_orthographic_top = Button(button_ax_orthographic_top, "Top orthographic projection")
button_orthographic_top.on_clicked(button_callback_orthographic_top)


def button_callback_orthographic_hip(event):
    ax.view_init(0, 90)
    plt.draw()


button_ax_orthographic_front = fig.add_axes([0.1, 0.85, 0.31, 0.06])
button_orthographic_front = Button(button_ax_orthographic_front, "Side orthographic projection")
button_orthographic_front.on_clicked(button_callback_orthographic_hip)

ax.grid(None)
ax.axis('off')
plt.show()