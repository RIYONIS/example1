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


//Mouse
#include <GL/glut.h>
#include <stdio.h>

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    glPointSize(4.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(5, 10);
    glVertex2i(10, 15);
    glEnd();
    glFlush();
}

void myMouse(int button, int state, int x, int y) {
    if ((button == GLUT_RIGHT_BUTTON)||(button == GLUT_LEFT_BUTTON) && state == GLUT_DOWN) {
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple OpenGL Example");
    glutInitWindowPosition(58, 100);
    glutDisplayFunc(display);
    myinit();
    glutMouseFunc(myMouse);
    glutMainLoop();
    
    return 0;
}



//reshape.c

#include <GL/glut.h>
#include <stdio.h>

void myinit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);
    glPointSize(4.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(5, 10);
    glVertex2i(10, 15);
    glEnd();
    glFlush();
}

void myReshape(GLsizei w, GLsizei h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();  // Added missing parentheses
    glViewport(0, 0, w, h);
}

/*void myMouse(int button, int state, int x, int y) {
    if ((button == GLUT_LEFT_BUTTON || button == GLUT_RIGHT_BUTTON) && state == GLUT_DOWN) {
        exit(0);
    }
}*/

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple OpenGL Example");
    glutInitWindowPosition(58, 100);
    glutDisplayFunc(display);
    myinit();
    glutReshapeFunc(myReshape);  // Fixed function name
   // glutMouseFunc(myMouse);
    glutMainLoop();
    
    return 0;
}


