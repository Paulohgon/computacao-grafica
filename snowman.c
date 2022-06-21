// gcc snowman_sample.c -lglut -lGL -lGLU -lm -o snowman && ./snowman

#include <GL/glut.h>

// Rotation
static GLfloat yRot = 0.0f;
static GLfloat xRot = 0.0f;
static GLfloat zRot = 0.0f;


// Change viewing volume and viewport. Called when window is resized
void ChangeSize(int w, int h)
{
GLfloat fAspect;

// Prevent a divide by zero
if(h == 0)
h = 1;

// Set Viewport to window dimensions
glViewport(0, 0, w, h);

fAspect = (GLfloat)w/(GLfloat)h;

// Reset coordinate system
glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// Produce the perspective projection
gluPerspective(35.0f, fAspect, 1.0, 40.0);

glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}


// This function does any needed initialization on the rendering context. Here it sets up and initializes the lighting for the scene.
void SetupRC(){

// Light values and coordinates
GLfloat whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
GLfloat sourceLight[] = { 0.20f, 0.25f, 0.25f, 1.0f };
GLfloat lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

glEnable(GL_DEPTH_TEST); // Hidden surface removal
glFrontFace(GL_CCW); // Counter clock-wise polygons face out
glEnable(GL_CULL_FACE); // Do not calculate inside

// Enable lighting


// Set Material properties to follow glColor values
glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

// Black blue background
glClearColor(0.7f, 1.0f, 1.0f, 1.0f);
}

// Respond to arrow keys (rotate snowman)
void SpecialKeys(int key, int x, int y){

if(key == GLUT_KEY_LEFT)
yRot -= 5.0f;
xRot -= 5.0f;

if(key == GLUT_KEY_RIGHT)
yRot += 5.0f;
xRot += 5.0f;



yRot = (GLfloat)((const int)yRot % 360);
xRot = (GLfloat)((const int)xRot % 360);
// Refresh the Window
glutPostRedisplay();
}

// Called to draw scene
void RenderScene(void){

GLUquadricObj *pObj; // Quadric Object

// Clear the window with current clearing color
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

// Save the matrix state and do the rotations
glPushMatrix();

// Move object back and do in place rotation
glTranslatef(0.0f, -1.0f, -5.0f);
glRotatef(yRot, 0.0f, 1.0f, 0.0f);
glRotatef(xRot, 0.0f, 1.0f, 0.0f);

// Draw something
pObj = gluNewQuadric();
gluQuadricNormals(pObj, GLU_SMOOTH);

// white
glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

// Main Body
gluSphere(pObj, 0.47f, 26, 13); // Bottom

// Mid section
glPushMatrix();
glTranslatef(0.0f, 0.55f, 0.0f);
gluSphere(pObj, 0.35f, 26, 13);
glPopMatrix();

// Head
glPushMatrix(); // save transform matrix state
glTranslatef(0.0f, 1.0f, 0.0f);
gluSphere(pObj, 0.25f, 26, 13);
glPopMatrix(); // restore transform matrix state

// Nose (orange)
glColor3f(1.0f, 0.4f, 0.51f);
glPushMatrix();
glTranslatef(0.0f, 1.0f, 0.2f);
gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
glPopMatrix();

// Eyes (black)
glColor3f(0.0f,0.0f,0.0f);
glPushMatrix();
glTranslatef(-0.08f,1.1f,0.2f);
gluSphere(pObj, 0.04f, 26, 13);
glPopMatrix();

glPushMatrix();
glTranslatef(0.08f,1.1f,0.2f);
gluSphere(pObj, 0.04f, 26, 13);
glPopMatrix();

//mouth
glPushMatrix();//right
glTranslatef(0.09f,0.92f,0.21f);
gluSphere(pObj, 0.02f, 26, 13);
glPopMatrix();
glPushMatrix();// middle
glTranslatef(0.0f,0.9f,0.22f);
gluSphere(pObj, 0.02f, 26, 13);
glPopMatrix();
glPushMatrix();// left
glTranslatef(-0.09f,0.92f,0.21f);
gluSphere(pObj, 0.02f, 26, 13);
glPopMatrix();

// Buttons
glPushMatrix();// up
glTranslatef(0.0f,0.7f, 0.3f);
gluSphere(pObj, 0.045f, 26, 13);
glPopMatrix();
glPushMatrix();// middle
glTranslatef(0.0f,0.48f, 0.325f);
gluSphere(pObj, 0.045f, 26, 13);
glPopMatrix();
glPushMatrix();// down
glTranslatef(0.0f,0.23f, 0.385f);
gluSphere(pObj, 0.048f, 26, 13);
glPopMatrix();

//Arms1
glPushMatrix();
glTranslatef(0.30f,0.60f,0.0f);
glRotatef(90,0,1,0);
glRotatef(50,1,0,0);
gluCylinder(pObj, 0.02f, 0.02f, 0.60f, 200, 200);
glPopMatrix();
//arm2
glPushMatrix();
glTranslatef(-0.30f,0.60f,0.0f);
glRotatef(270,0,1,0);
glRotatef(50,1,0,0);
gluCylinder(pObj, 0.02f, 0.02f, 0.6f, 200, 200);
glPopMatrix();
//glPopMatrix();

// Hat
glPushMatrix();
glTranslatef(0.0f,1.21f,0.01f);
glRotatef(90,0,0,1);
glRotatef(80,0,1,0);
gluDisk(pObj, 0.0f, 0.40f, 200, 200);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0f,1.20f,0.01f);
glRotatef(90,0,0,1);
glRotatef(80,0,1,0);
gluCylinder(pObj, 0.2f, 0.02f, 0.9f, 200, 200);
glPopMatrix();
// Hat brim

// Restore the matrix state
glPopMatrix();

// Buffer swap
glutSwapBuffers();

}

int main(int argc, char *argv[]){

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize(800, 600);
glutCreateWindow("Snowman");
glutReshapeFunc(ChangeSize);
glutSpecialFunc(SpecialKeys);
glutDisplayFunc(RenderScene);
SetupRC();
glutMainLoop();

return 0;
}