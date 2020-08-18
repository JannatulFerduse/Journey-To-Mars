#ifndef UPDATES_H_INCLUDED
#define UPDATES_H_INCLUDED
#include "display.h"

void simulationUpdate(int value){

    glutPostRedisplay();                        // display has changed
    glutTimerFunc(25, simulationUpdate, 0);     // calling update() again and again in every 25 milliseconds
}


void handleResize(int width, int height){

    glViewport(0, 0, width, height);        // sets the view port
    glMatrixMode(GL_PROJECTION);            // applies subsequent matrix operations to the projection matrix stack
    glLoadIdentity();                       // reset the drawing perspective
    gluPerspective(45.0, (double)width / (double)height, 1.0, 200.0);
}
#endif // UPDATES_H_INCLUDED
