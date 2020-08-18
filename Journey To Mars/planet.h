#ifndef PLANET_H_INCLUDED
#define PLANET_H_INCLUDED
struct PLANET{
	float radius;
	float speed;
	float xPos;
	float yPos;
	float zPos;
	float orbitRadius;
	float orbitPos;
};

struct PLANET mercury, venus, earth, mars, jupiter, saturn, urenus, neptune, pluto;
void createPlanets(){
    mercury.radius = 0.11+.3;
	mercury.speed = 0.00028;
	mercury.xPos = 0.0;
	mercury.yPos = 0.0;
	mercury.zPos = 0.0;
	mercury.orbitRadius = 1.08+.3;
	mercury.orbitPos = 180.0;

	// planet venus
	venus.radius = 0.15+.3;
	venus.speed = 0.00022;
	venus.xPos = 0.0;
	venus.yPos = 0.0;
	venus.zPos = 0.0;
	venus.orbitRadius = 1.30+.3;
	venus.orbitPos = 15.0;

	// planet earth
	earth.radius = 0.16+.3;
	earth.speed = 0.00020;
	earth.xPos = 0.0;
	earth.yPos = 0.0;
	earth.zPos = 0.0;
	earth.orbitRadius = 1.52+.3;
	earth.orbitPos = 90.0;

	// planet mars
	mars.radius = 0.12+.3;
	mars.speed = 0.00017;
	mars.xPos = 0.0;
	mars.yPos = 0.0;
	mars.zPos = 0.0;
	mars.orbitRadius = 1.74+.3;
	mars.orbitPos = 120.0;

	// planet jupiter
	jupiter.radius = 0.29+.3;
	jupiter.speed = 0.00012;
	jupiter.xPos = 0.0;
	jupiter.yPos = 0.0;
	jupiter.zPos = 0.0;
	jupiter.orbitRadius = 1.96+.3;
	jupiter.orbitPos = 290.0;

	// planet saturn
	saturn.radius = 0.28+.3;
	saturn.speed = 0.00009;
	saturn.xPos = 0.0;
	saturn.yPos = 0.0;
	saturn.zPos = 0.0;
	saturn.orbitRadius = 2.18+.3;
	saturn.orbitPos = 60.0;

	// planet uranus
	urenus.radius = 0.22+.3;
	urenus.speed = 0.00007;
	urenus.xPos = 0.0;
	urenus.yPos = 0.0;
	urenus.zPos = 0.0;
	urenus.orbitRadius = 2.40+.3;
	urenus.orbitPos = 15.0;

	//planet neptune
	neptune.radius = 0.21+.3;
	neptune.speed = 0.00005;
	neptune.xPos = 0.0;
	neptune.yPos = 0.0;
	neptune.zPos = 0.0;
	neptune.orbitRadius = 2.62+.3;
	neptune.orbitPos = 350.0;

	// planet pluto
	pluto.radius = 0.09+.3;
	pluto.speed = 0.00002;
	pluto.xPos = 0.0;
	pluto.yPos = 0.0;
	pluto.zPos = 0.0;
	pluto.orbitRadius = 2.84+.3;
	pluto.orbitPos = 200.0;
}

/*
This function draws all the planets according to their given inputs
*/
void renderPlanet(struct PLANET &planet){

    // setting planet's position along with orbit radius
    planet.xPos = planet.orbitRadius * planet.orbitRadius * cos(planet.orbitPos * RADIAN);
    planet.yPos = planet.orbitRadius * planet.orbitRadius * sin(planet.orbitPos * RADIAN);

    glPushMatrix();         // pushes the current matrix stack down by one, duplicating the current matrix
//    changeColor(planet.color[0], planet.color[1], planet.color[2], 1.0);

    // produces a translation of planets by x y z co-ordinate by multiplying between this matrix and current matrix
    glTranslatef(planet.xPos, planet.yPos, planet.zPos);
    glBegin(GL_LINES);
    glutSolidSphere(planet.radius, 30, 30);     // renders a sphere centered at the modeling coordinates origin of the specified radius
    glEnd();

    glPopMatrix();          // pops the current matrix stack, replacing the current matrix with the one below it on the stack

    planet.orbitPos += planet.speed;            // planet's position changing along with it's speed
    // if the planet's position reaches to 360 it will start from 0 again
    if(planet.orbitPos >= 360.0){

        planet.orbitPos = 0.0;
    }
}
#endif // PLANET_H_INCLUDED
