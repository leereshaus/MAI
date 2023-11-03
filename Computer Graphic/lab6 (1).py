import numpy as np
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *


material = GL_LINE

alpha_channel = 1
time = 0
x_rot = 0
y_rot = 0
z_rot = 0

approximation = int(input("Введите количество образующих (не меньше трех): "))
R = 2
size = 1

def cylinder():
    global approximation, R
    alpha_default = np.pi * (360 / approximation) / 180
    alpha = alpha_default
    vertices = [[0, 0, 0], [0, 2, 0]]

    for i in range(approximation - 1):
        x_i = R * np.sin(alpha)
        y_i = R * np.sin((np.pi / 2) - alpha)
        vertices.append([x_i, y_i, 0])
        alpha += alpha_default
    for i in range(approximation):
        glBegin(GL_TRIANGLE_STRIP)
        if i < (approximation - 1):
            glColor4f(0, 1, 0, alpha_channel)
            glVertex3fv(vertices[0])
            glVertex3fv(vertices[i + 1])
            glVertex3fv(vertices[i + 2])
        else:
            glColor4f(0, 1, 0, alpha_channel)
            glVertex3fv(vertices[0])
            glVertex3fv(vertices[i + 1])
            glVertex3fv(vertices[1])
        glEnd()

    vertices.append([0, 0, 4])
    vertices.append([0, 2, 3])
    alpha = alpha_default

    for i in range(approximation - 1):
        x_i = vertices[i+2][0]
        y_i = vertices[i+2][1]
        vertices.append([x_i, y_i, (8 - y_i) / 2])
        alpha += alpha_default
    for i in range(approximation):
        glBegin(GL_TRIANGLE_STRIP)
        if i < (approximation - 1):
            glColor4f(0, 1, 1, alpha_channel)
            glVertex3fv(vertices[approximation + 1])
            glVertex3fv(vertices[approximation + 2 + i])
            glVertex3fv(vertices[approximation + 3 + i])
        else:
            glColor4f(0, 1, 1, alpha_channel)
            glVertex3fv(vertices[approximation + 1])
            glVertex3fv(vertices[approximation + 2 + i])
            glVertex3fv(vertices[approximation + 2])
        glEnd()

    for i in range(approximation):
        if i < (approximation - 1):
            glBegin(GL_TRIANGLE_STRIP)
            glColor4f(1, 1, 0, alpha_channel)
            glVertex3fv(vertices[i + 1])
            glVertex3fv(vertices[i + 2])
            glVertex3fv(vertices[i + approximation + 2])
            glEnd()
            glBegin(GL_TRIANGLE_STRIP)
            glColor4f(1, 1, 0, alpha_channel)
            glVertex3fv(vertices[i + 2])
            glVertex3fv(vertices[i + approximation + 3])
            glVertex3fv(vertices[i + approximation + 2])
            glEnd()
        else:
            glBegin(GL_TRIANGLE_STRIP)
            glColor4f(1, 1, 0, alpha_channel)
            glVertex3fv(vertices[approximation])
            glVertex3fv(vertices[1])
            glVertex3fv(vertices[i + approximation + 2])
            glEnd()
            glBegin(GL_TRIANGLE_STRIP)
            glColor4f(1, 1, 0, alpha_channel)
            glVertex3fv(vertices[1])
            glVertex3fv(vertices[approximation + 2])
            glVertex3fv(vertices[i + approximation + 2])
            glEnd()


def init():
    glEnable(GL_DEPTH_TEST)
    glEnable(GL_BLEND)
    glDepthFunc(GL_LEQUAL)

    glBlendFunc(GL_SRC_ALPHA, GL_ONE)

    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST)  # сглаженные полигоны, больше пикселей для отрисовки
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)  # хорошее качество текстур, цветов
    glEnable(GL_NORMALIZE)


def display():
    global time, x_rot, y_rot, z_rot, size, material, alpha_channel

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    gluLookAt(10, 10, 10, 0, 0, 0, 0, 0, 2)
    glPolygonMode(GL_FRONT_AND_BACK, material)
    glTranslatef(size, size, size)
    glRotatef(x_rot, 1, 0, 0)
    glRotatef(y_rot, 0, 0, 1)
    glRotatef(z_rot, 0, 1, 0)

    glPushMatrix()  # сохраняем текущее положение "камеры"

    time += 0.01
    alpha_channel = np.sin(time)

    cylinder()
    glPopMatrix()  # возвращаем сохраненное положение "камеры"
    glutSwapBuffers()  # выводим все нарисованное в памяти на экран
    glutPostRedisplay()


def reshape(width, height):
    glViewport(0, 0, width, height)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(60, float(width) / float(height), 1.0, 60.0)
    # 1) угол, под которым пользователь видит фигуру, по y;
    # 2) отношение x/y, которое задаёт положение по x; 3) расстояние до ближней плоскости; 4) до дальней плоскости
    glMatrixMode(GL_MODELVIEW)
    glLoadIdentity()
    gluLookAt(0, 0.0, 0.0, 1.0, 1.0, 1.0, 0.0, 1, 0)


def specialkeys(key, x, y):
    global x_rot, y_rot, z_rot, size, approximation, light_intensity, material
    if key == b'w':
        x_rot += 5  # вращаем на 5 градусов по оси X
    if key == b's':
        x_rot -= 5  # вращаем на -5 градусов по оси X
    if key == b'a':
        y_rot += 5  # вращаем на 5 градусов по оси Y
    if key == b'd':
        y_rot -= 5  # вращаем на -5 градусов по оси Y
    if key == b'q':
        z_rot += 5  # вращаем на 5 градусов по оси Z
    if key == b'e':
        z_rot -= 5  # вращаем на -5 градусов по оси Z
    if key == b'=':
        size += 1  # увеличиваем размер на 1
    if key == b'-':
        size -= 1  # уменьшаем размер на 1
    if key == b'p':
        approximation += 1  # увеличиваем число образующих на 1
    if key == b'o':
        approximation -= 1  # уменьшаем число образующих на 1
        approximation = max(3, approximation)
    if key == b'z':
        if material == GL_FILL:
            material = GL_LINE
        else:
            material = GL_FILL

    glutPostRedisplay()  # вызываем процедуру перерисовки


def main():
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH)  # используем двойную буферизацию и формат RGBA
    glutInitWindowSize(500, 500)
    glutInitWindowPosition(0, 0)
    glutInit(sys.argv)  # инициализируем opengl
    glutCreateWindow("lab 6")
    glutDisplayFunc(display)  # определяем функцию для отрисовки
    glutReshapeFunc(reshape)  # определяем функцию для масштабирования
    glutKeyboardFunc(specialkeys)  # определяем функцию для обработки нажатия клавиш
    init()
    glutMainLoop()


if __name__ == "__main__":
    main()