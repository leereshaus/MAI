import numpy as np
import matplotlib.pyplot as plt

points_array = []

x1y1 = input("Введите координаты 1 точки в виде \"x y\": ")
x2y2 = input("Введите координаты 2 точки в виде \"x y\": ")
x3y3 = input("Введите координаты 3 точки в виде \"x y\": ")
x4y4 = input("Введите координаты 4 точки в виде \"x y\": ")
x5y5 = input("Введите координаты 5 точки в виде \"x y\": ")
x6y6 = input("Введите координаты 6 точки в виде \"x y\": ")
points_array.append(int(x1y1.split()[0]))
points_array.append(int(x1y1.split()[1]))
points_array.append(int(x2y2.split()[0]))
points_array.append(int(x2y2.split()[1]))
points_array.append(int(x3y3.split()[0]))
points_array.append(int(x3y3.split()[1]))
points_array.append(int(x4y4.split()[0]))
points_array.append(int(x4y4.split()[1]))
points_array.append(int(x5y5.split()[0]))
points_array.append(int(x5y5.split()[1]))
points_array.append(int(x6y6.split()[0]))
points_array.append(int(x6y6.split()[1]))

min = min(points_array[::2]) - 1
max = max(points_array[::2]) + 1
x = np.arange(min, max, 0.01)

def lagrange(points_array, x):
    y = points_array[1] * (x - points_array[2]) * (x - points_array[4]) * (x - points_array[6]) * (x - points_array[
        8]) * (x - points_array[10]) /\
        ((points_array[0] - points_array[2]) * (points_array[0] - points_array[4]) *\
        (points_array[0] - points_array[6]) * (points_array[0] - points_array[8]) * (points_array[0] - points_array[
                    10])) + \
        points_array[3] * (x - points_array[0]) * (x - points_array[4]) * (x - points_array[6]) * (x - points_array[
        8]) * (x - points_array[10]) /\
        ((points_array[2] - points_array[0]) * (points_array[2] - points_array[4]) *\
        (points_array[2] - points_array[6]) * (points_array[2] - points_array[8]) * (points_array[2] - points_array[
                    10])) + \
        points_array[5] * (x - points_array[0]) * (x - points_array[2]) * (x - points_array[6]) * (x - points_array[
        8]) * (x - points_array[10]) /\
        ((points_array[4] - points_array[0]) * (points_array[4] - points_array[2]) *\
        (points_array[4] - points_array[6]) * (points_array[4] - points_array[8]) * (points_array[4] - points_array[
                    10])) + \
        points_array[7] * (x - points_array[0]) * (x - points_array[2]) * (x - points_array[4]) * (x - points_array[
        8]) * (x - points_array[10]) /\
        ((points_array[6] - points_array[0]) * (points_array[6] - points_array[2]) *\
        (points_array[6] - points_array[4]) * (points_array[6] - points_array[8]) * (points_array[6] - points_array[
                    10])) + \
        points_array[9] * (x - points_array[0]) * (x - points_array[2]) * (x - points_array[4]) * (x - points_array[
        6]) * (x - points_array[10]) /\
        ((points_array[8] - points_array[0]) * (points_array[8] - points_array[2]) *\
         (points_array[8] - points_array[4]) * (points_array[8] - points_array[6]) * (points_array[8] - points_array[
                    10])) + \
        points_array[11] * (x - points_array[0]) * (x - points_array[2]) * (x - points_array[4]) * (x - points_array[
        6]) * (x - points_array[8]) /\
        ((points_array[10] - points_array[0]) * (points_array[10] - points_array[2]) *\
         (points_array[10] - points_array[4]) * (points_array[10] - points_array[6]) * (points_array[10] - points_array[
                    8]))
    return y

plt.plot(x, lagrange(points_array, x))
plt.plot(points_array[0], points_array[1], marker="o", color="red")
plt.plot(points_array[2], points_array[3], marker="o", color="red")
plt.plot(points_array[4], points_array[5], marker="o", color="red")
plt.plot(points_array[6], points_array[7], marker="o", color="red")
plt.plot(points_array[8], points_array[9], marker="o", color="red")
plt.plot(points_array[10], points_array[11], marker="o", color="red")
plt.show()