#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
// Algoritma DDA

using namespace std; //standar input c++

//identifier fungsi
void init();
void display(void);
void dda(void);

//  posisi window di layar
int window_x,window_y;

//  ukuran window
int window_width = 520;
int window_height = 520;

int x1,y1,x2,y2;

//  judul window
char* judul_window = "Algoritma DDA";

void input(){

}

int main(int argc, char **argv)
{
	//  inisialisasi GLUT (OpenGL Utility Toolkit)
    cout<<"Masukkan nilai x1 : ";cin>>x1;
    cout<<"Masukkan nilai y1 : ";cin>>y1;
    cout<<"\nMasukkan nilai x2 : ";cin>>x2;
    cout<<"Masukkan nilai y2 : ";cin>>y2;
    cout<<endl;
    glutInit(&argc,argv);

    // set posisi window supaya berada di tengah
	window_x = (glutGet(GLUT_SCREEN_WIDTH) - window_width) / 2;
	window_y = (glutGet(GLUT_SCREEN_HEIGHT) - window_height) / 2;
	glutInitWindowSize(window_width, window_height); //set ukuran window
	glutInitWindowPosition(window_x, window_y); //set posisi window

	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE); // set display RGB dan double buffer
	glutCreateWindow(judul_window);

	init();

	glutDisplayFunc(display); // fungsi display
	glutMainLoop(); // loop pemrosesan GLUT
    }


void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0); //set warna background
	glColor3f(0.0, 1.0, 0.0); //set warna titik
	glPointSize(2.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan
	glLoadIdentity(); // load matriks identitas
	gluOrtho2D(0.0, 800.0, 0.0, 800.0); // set ukuran viewing window
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	dda(); //panggil fungsi dda
	glutSwapBuffers(); //swap buffer
}
int round(double x){ ///5.7
    int a;
    double c;
    a=x; ///a = 5
    c=(x-a); ///c = 5,7 - 5 = 0,7
    if (c>=0.5){
        return a+1;} ///a=6
    else{
        return a;  }
    }

void dda(void) {

	float x,y,dx, dy, steps, x_inc, y_inc;
	//tentukan titik awal dan akhir

	x = x1;
	y = y1;

	//hitung dx dan dy
	dx = (x2 - x1);
	dy = (y2 - y1);

	cout<<"dx : "<<dx;
	cout<<"\ndy : "<<dy;

	//hitung steps
	if (abs(dx) > abs(dy)) { ///step mengikuti nilai dx/dy yang absolut terbesar
		steps = abs(dx); ///step di absolut agar nilai selalu positif
	}else
        steps = abs(dy);

	//hitung perubahan nilai x (x_inc) dan y (y_inc)
	x_inc = dx / steps;
	y_inc = dy / steps;

    cout<<"\n xinc : "<<x_inc;
	cout<<"\n yinc : "<<y_inc;
	cout<<"\n steps : "<<steps;

	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y); // gambar titik awal
    cout<<"\n("<<round(x)<<","<<round(y)<<")";
	//perulangan untuk menggambar titik-titik
	do {
		x += x_inc; // x = x + x_inc
		y += y_inc; // y = y + y_inc
		glVertex2i(round(x),round(y)); //gambar titik
		cout<<"\n("<<round(x)<<","<<round(y)<<")";
            steps--; ///iterasi negatif
	} while (steps != 0); ///looping kondisi

	glEnd();
	glFlush();
}

