//#include <iostream>
//#include <GL/gl.h>
//#include <GL/glut.h>
//#include "glutil.h"
//float _move = 0.0f;
//Texture bx("E:\\Desktop\\OneDrive\\Documents\\Docs Files\\ab\\resources\\img55.bmp");
//Texture bx("E:\\Desktop\\OneDrive\\Documents\\Docs Files\\pls\\image1.bmp");
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include<cstdio>
#include <cmath>
#include "glutil.h"


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glColor3d(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();


    // Draw the rectangle with the applied texture
    glColor3d(1.0, 1.0, 1.0);
    glPushMatrix();
    glTranslatef(-0.2f, -0.2f, 0.0f);  // Adjust the translation to match the texture coordinates
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, 0.4f);
    glVertex2f(0.0f, 0.4f);
    glEnd();

    ApplyTexture(0.0f, 0.0f, 0.4f,0.0f,  0.40f, 0.40f, 0.0f, 0.40f, textures[0].textureID); // Adjusted texture coordinates

    glPopMatrix();


    glutSwapBuffers();
}




int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Modified Box Movement");
    loadImageAndStore("E:\\Desktop\\OneDrive\\Documents\\Docs Files\\ab\\resources\\ggg.bmp");
    PlayMusic("C:/Users/abha/Downloads/sample-6s.wav");
    glutDisplayFunc(display);
    gluOrtho2D(-1, 1, -1, 1);
    glutMainLoop();

    return 0;
}
