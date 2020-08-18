#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include "planet.h"
#include "labels.h"
bool labelsActive = true;
bool solarSystemSimulation = true;
void display(){

    // if the solar system simulation is currently active
	if(solarSystemSimulation){

        // sets the bit plane area of the window to values previously selected by glClearColor
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);             // switch to the drawing perspective
        glLoadIdentity();                       // reset the drawing perspective
        glRotatef(10.0, 1.0f, 0.0f, 0.0f);      // rotate the camera

        //glColor3f(1.0,0.0,0.0);/set color
        glTranslatef(0.0f, -3.0f, -22.0f);

        glPushMatrix();                         // save the transformations performed thus far
        glRotatef(-60.0, 1.0f, 0.0f,0.0f);

        // rendering the sun
        glPushMatrix();
        glBegin(GL_LINES);
        glutSolidSphere(0.8f, 45, 45);          // rendering the sun
        glEnd();

        // if planet labels are active
        if(labelsActive){

            glPushMatrix();
            glRasterPos3f(-0.2, -1.75, 0.0);                 // setting string rendering position
            drawString(GLUT_BITMAP_HELVETICA_12, "Sun");    // drawing sun string
            glPopMatrix();
        }

        glPopMatrix();

        // rendering all the planets
        glPushMatrix();
        renderPlanet(mercury);
        renderPlanet(venus);
        glPopMatrix();

        glPushMatrix();
        renderPlanet(earth);
        if(labelsActive){

            glRasterPos3f(earth.xPos - 0.25, earth.yPos - 0.95, 0.0);        // setting string rendering position
            drawString(GLUT_BITMAP_HELVETICA_12, "Earth");                  // drawing earth string
        }
        glPopMatrix();

        glPushMatrix();
        renderPlanet(mars);
        if(labelsActive){

            glRasterPos3f(mars.xPos - 0.2, mars.yPos - 0.95, 0.0);           // setting string rendering position
            drawString(GLUT_BITMAP_HELVETICA_12, "Mars");                   // drawing mars string
        }
        glPopMatrix();

        glPushMatrix();

        renderPlanet(jupiter);
        renderPlanet(saturn);
        renderPlanet(urenus);
        renderPlanet(neptune);
        renderPlanet(pluto);
        glPopMatrix();
	}
	glutSwapBuffers();      // swaps the buffers of the current window if double buffered
}
#endif // DISPLAY_H_INCLUDED
