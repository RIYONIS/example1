//font1
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float size = 1.0;

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void demo_menu(int id) {
    switch (id) {
        case 1: exit(0); break; 
        case 2: size *= 2; break;
        case 3: if (size > 1) size /= 2; break;
    }
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2i(50, 90);
        glVertex2i(75, 50);
    glEnd();

    glPointSize(size * 2.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
        glVertex2i(75, 50);
    glEnd();

    glPointSize(size * 3.0);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
        glVertex2i(50, 90);
    glEnd();

    glRasterPos2i(10, 10); 
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Program");
    
    myinit();
    
    glutCreateMenu(demo_menu);
    glutAddMenuEntry("Quit", 1);
    glutAddMenuEntry("Increase Size", 2);
    glutAddMenuEntry("Decrease Size", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
