#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <bits/stdc++.h>
#include <math.h>
#include <GL/glut.h>
#endif
#include <stdlib.h>
using namespace std;
int xc , yc,r ;

void plot_point(int x, int y) {
glBegin(GL_POINTS);
glVertex2i(xc+x, yc+y);
glVertex2i(xc+x, yc
-y);
glVertex2i(xc+y, yc+x);
glVertex2i(xc+y, yc
-x);
glVertex2i(xc
-x, yc
-y);
glVertex2i(xc
-y, yc
-x);
glVertex2i(xc
-x, yc+y);
glVertex2i(xc
-y, yc+x);

glEnd(); }

void bresenham_circle(int r) {

int x=0,y=r;
float pk=(5.0/4.0)
-r;
plot_point(x,y);

while(x < y)
{
x = x + 1;
if(pk < 0)
pk = pk + 2*x+1;
else {
y = y
- 1;
pk = pk + 2*(x
- y) + 1;

}
plot_point(x,y); }
glFlush(); }
void concentric_circles(void) {
glClear(GL_COLOR_BUFFER_BIT);
bresenham_circle(r); }

void Init() {
glClearColor(0.5,0.1,1,0);
glColor3f(0.0,0.0,0.0);
gluOrtho2D(0 , 640 , 0 , 480);


}

int main(int argc, char **argv)
{
cout << "Enter the coordinates of the center:\n\n" << endl;
cout << "x-coordinate : "; cin>>xc;
cout << "\ny-coordinate : "; cin>>yc;
cout << "\nradius : "; cin>>r;
concentric_circles();
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(640,480);
glutCreateWindow("bresenham_circle");
Init();
glutDisplayFunc(concentric_circles);
glutMainLoop();
}
