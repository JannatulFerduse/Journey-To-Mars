#include<windows.h>
#include<GL/glut.h>
#include<iostream>
#include<math.h>
#define RADIAN 180.0/3.141592

void drawInstructions();

#include "updates.h"
#include "display.h"
#include "earth.h"
using namespace std;
void keyboardInput(unsigned char key, int x, int y){
    if(key == 'E' || key == 'e'){

            glutCreateWindow ("NASA");
            glutDisplayFunc(myDisplay);
            glutKeyboardFunc(keyboard);
            glutMouseFunc(mouse);
            myInit ();
            glutMainLoop();
        glutPostRedisplay();
    }
}
int main(int argc, char** argv){
    createPlanets();
    glutInit(&argc, argv);                                          // initializes the GLUT library
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);       // determines the OpenGL display mode
    glutInitWindowSize(1200, 600);                              // defines window size
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-600)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-1200)/2); // setting the window at the middle of the screen
    glutCreateWindow("Solar System");                                      // creates the window
    glutDisplayFunc(display);           // sets the display callback for the current window
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboardInput);
	glutTimerFunc(25, simulationUpdate, 0);
    glutMainLoop();                        // enters the GLUT event processing loop
	return 0;
}
