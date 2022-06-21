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
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };  
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };  
    GLfloat  lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };  
  
    glEnable(GL_DEPTH_TEST);    // Hidden surface removal  
    glFrontFace(GL_CCW);        // Counter clock-wise polygons face out  
    glEnable(GL_CULL_FACE);     // Do not calculate inside  
  
    // Enable lighting  
    glEnable(GL_LIGHTING);  
  
    // Setup and enable light 0  
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);  
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);  
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);  
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);  
    glEnable(GL_LIGHT0);  
  
    // Enable color tracking  
    glEnable(GL_COLOR_MATERIAL);  
      
    // Set Material properties to follow glColor values  
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);  
  
    // Black blue background  
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f);  
}

// Respond to arrow keys (rotate snowman)
void SpecialKeys(int key, int x){

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
glColor4f(2.50f, 0.40f, 1.0f, 0.0f);//white

// parede
glPushMatrix();
glTranslatef(0.0f,1.0f, 0.0f);
glScaled(1,0.5,0.03);
glutSolidCube(1.0);
glPopMatrix();
//tower
glPushMatrix();
glTranslatef(0.70f,0.75f,0.0f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.2f, 0.2f, 0.80f, 200, 200);
glPopMatrix();
//TOWER2
glPushMatrix();
glTranslatef(-0.70f,0.75f,0.0f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.2f, 0.2f, 0.80f, 200, 200);
glPopMatrix();
//detailtower
glPushMatrix();
glTranslatef(-0.70f,1.35f,0.0f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.22f, 0.22f, 0.25f, 200, 200);
glPopMatrix();
//topTower2
glPushMatrix();
glTranslatef(-0.70f,1.55f,0.0f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.25f, 0.0f, 0.50f, 200, 200);
glPopMatrix();
//topTower
glPushMatrix();
glTranslatef(0.70f,1.55f,0.0f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.25f, 0.0f, 0.50f, 200, 200);
glPopMatrix();
//detail Tower2
glPushMatrix();
glTranslatef(0.70f,1.35f,0.0f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.22f, 0.22f, 0.25f, 200, 200);
glPopMatrix();
//parede
glPushMatrix();
glTranslatef(0.70f,1.0f, 0.70f);
glRotatef(270,0.0f,1.0f,0.0f);
glScaled(1,0.5,0.03);
glutSolidCube(1.0);
glPopMatrix();
//mureta

void mureta1 (float x,float y,float z){
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(270,0.0f,1.0f,0.0f);
    glScaled(0.5,0.4,0.04);
    glutSolidCube(0.2);
    glPopMatrix();

}
mureta1(0.70f,1.29f, 0.30f);
mureta1(0.70f,1.29f, 0.50f);
mureta1(0.70f,1.29f, 0.70f);
mureta1(0.70f,1.29f, 0.90f);
mureta1(0.70f,1.29f, 1.10f);

void mureta2 (float x,float y,float z){
    glPushMatrix();
    glTranslatef(x,y,z);
    glScaled(0.5,0.4,0.04);
    glutSolidCube(0.2);
    glPopMatrix();
}
mureta2(0.0f,1.29f, 0.0f);
mureta2(0.20f,1.29f, 0.0f);
mureta2(0.40f,1.29f, 0.0f);
mureta2(-0.20f,1.29f, 0.0f);
mureta2(-0.40f,1.29f, 0.0f);

void mureta3 (float x,float y,float z){
    glPushMatrix();
    glTranslatef(x,y,z);
    glRotatef(270,0.0f,1.0f,0.0f);
    glScaled(0.5,0.4,0.04);
    glutSolidCube(0.2);
    glPopMatrix();
}
mureta3(-0.70f,1.29f, 0.70f);
mureta3(-0.70f,1.29f, 0.50f);
mureta3(-0.70f,1.29f, 0.30f);
mureta3(-0.70f,1.29f, 0.90f);
mureta3(-0.70f,1.29f, 1.10f);
void mureta4 (float x,float y,float z){
    glPushMatrix();
    glTranslatef(x,y,z);
    glScaled(0.5,0.4,0.04);
    glutSolidCube(0.2);
    glPopMatrix();
}

mureta4(0.0f,1.29f, 1.40f);
mureta4(0.20f,1.29f, 1.40f);
mureta4(0.40f,1.29f, 1.40f);
mureta4(-0.20f,1.29f, 1.40f);
mureta4(-0.40f,1.29f, 1.40f);
//tower3
glPushMatrix();
glTranslatef(0.70f,0.75f,1.40f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.2f, 0.2f, 0.80f, 200, 200);
glPopMatrix();
//toptower3
glPushMatrix();
glTranslatef(0.70f,1.55f,1.40f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.25f, 0.0f, 0.50f, 200, 200);
glPopMatrix();
//detailTower3
glPushMatrix();
glTranslatef(0.70f,1.35f,1.40f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.22f, 0.22f, 0.25f, 200, 200);
glPopMatrix();
//tower4
glPushMatrix();
glTranslatef(-0.70f,0.75f,1.40f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.2f, 0.2f, 0.80f, 200, 200);
glPopMatrix();
//toptower4
glPushMatrix();
glTranslatef(-0.70f,1.55f,1.40f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.25f, 0.0f, 0.50f, 200, 200);
glPopMatrix();

//detailTower4
glPushMatrix();
glTranslatef(-0.70f,1.35f,1.40f);
glRotatef(270,1,0,0);
gluCylinder(pObj, 0.22f, 0.22f, 0.25f, 200, 200);
glPopMatrix();

//parede3
glPushMatrix();
glTranslatef(-0.70f,1.0f, 0.70f);
glRotatef(270,0.0f,1.0f,0.0f);
glScaled(1,0.5,0.03);
glutSolidCube(1.0);
glPopMatrix();
// parede4
glPushMatrix();
glTranslatef(0.35f,1.0f, 1.40f);
glScaled(0.5,0.5,0.03);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.35f,1.0f, 1.40f);
glScaled(0.5,0.5,0.03);
glutSolidCube(1.0);
glPopMatrix();
glPushMatrix();

glTranslatef(0.0f,1.2f, 1.40f);
glScaled(0.2,0.1,0.03);
glutSolidCube(1.0);
glPopMatrix();
//

glPushMatrix();
glTranslatef(-0.75f,1.55f,1.40f);
glScaled(1,1.0,1.5);
gluDisk(pObj, 2.0f, 2.0f, 200,200);
glPopMatrix();
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