#include <windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void ukuran(int, int);
void tampil(void);
void hilang(void);
void display(void);
void dasar(void);
void keyboard(unsigned char, int x, int y);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void kubus(int ex, int ey, int ez, int p, int l, int t) {
    glBegin(GL_QUADS);
    //Depan
    glVertex3d(ex, ey, ez);  //TITIK KIRI BAWAH
    glVertex3d(ex, ey + t, ez);  //TITIK KIRI ATAS
    glVertex3d(ex + p, ey + t, ez);  //TITIK KANAN ATAS
    glVertex3d(ex + p, ey, ez);  //TITIK KANAN BAWAH

    //Belakang
    glVertex3d(ex, ey, ez + l);  //TITIK KIRI BAWAH
    glVertex3d(ex, ey + t, ez + l);  //TITIK KIRI ATAS
    glVertex3d(ex + p, ey + t, ez + l);  //TITIK KANAN ATAS
    glVertex3d(ex + p, ey, ez + l);  //TITIK KANAN BAWAH

    //Kiri
    glVertex3d(ex, ey, ez);  //TITIK DEPAN BAWAH
    glVertex3d(ex, ey + t, ez);  //TITIK DEPAN ATAS
    glVertex3d(ex, ey + t, ez + l);  //TITIK BELAKANG ATAS
    glVertex3d(ex, ey, ez + l);  //TITIK BELAKANG BAWAH

    //Kanan
    glVertex3d(ex + p, ey, ez);  //TITIK DEPAN BAWAH
    glVertex3d(ex + p, ey + t, ez);  //TITIK DEPAN ATAS
    glVertex3d(ex + p, ey + t, ez + l);  //TITIK BELAKANG ATAS
    glVertex3d(ex + p, ey, ez + l);  //TITIK BELAKANG BAWAH

    //Atas
    glVertex3d(ex, ey + t, ez);  //TITIK DEPAN KIRI
    glVertex3d(ex + p, ey + t, ez);  //TITIK DEPAN KANAN
    glVertex3d(ex + p, ey + t, ez + l);  //TITIK BELAKANG KANAN
    glVertex3d(ex, ey + t, ez + l);  //TITIK BELAKANG KIRI

    //Bawah
    glVertex3d(ex, ey, ez);  //TITIK DEPAN KIRI
    glVertex3d(ex + p, ey, ez);  //TITIK DEPAN KANAN
    glVertex3d(ex + p, ey, ez + l);  //TITIK BELAKANG KANAN
    glVertex3d(ex, ey, ez + l);  //TITIK BELAKANG KIRI
    glEnd();
}

void dasar(void)
{
    //Laut
    /*glBegin(GL_QUADS);
    glColor3ub(0, 0, 255);
    glVertex3f(-150.0, -12.0, 50.0);
    glVertex3f(80.0, -12.0, 50.0);
    glVertex3f(80.0, -12.0, -50.0);
    glVertex3f(-150.0, -12.0, -50.0);
    glEnd();*/

    // tempat lihat pemandangan
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    kubus (-40, 60, 0, 4,4,25);

    glBegin(GL_QUADS);//atas
    glVertex3f(-40.0, 85.0, 4.0);
    glVertex3f(-10.0, 89.0, 4.0);
    glVertex3f(-10.0, 89.0, 0.0);
    glVertex3f(-40.0, 85.0, 0.0);
    glEnd();

    glBegin(GL_QUADS); //bawah
    glVertex3f(-40.0, 80.0, 4.0);
    glVertex3f(-10.0, 84.0, 4.0);
    glVertex3f(-10.0, 84.0, 0.0);
    glVertex3f(-40.0, 80.0, 0.0);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glVertex3f(-40.0, 80.0, 4.0);
    glVertex3f(-10.0, 84.0, 4.0);
    glVertex3f(-10.0, 89.0, 4.0);
    glVertex3f(-40.0, 85.0, 4.0);

    glBegin(GL_QUADS); //kanan
    glVertex3f(-40.0, 80.0, 0);
    glVertex3f(-10.0, 84.0, 0);
    glVertex3f(-10.0, 89.0, 0);
    glVertex3f(-40.0, 85.0, 0);

    glBegin(GL_QUADS);
    glColor3ub(72, 209, 204);
    kubus(-15, 75, -3, 15, 10, 12);

    glColor3f(0, 0, 0);
    kubus(-12, 87, 0, 2,4,1);

    kubus(-10, 80, 7, 5, 1, 2); //kiri
    kubus(-10, 80, -4, 5, 1, 2); //kanan
    //kamar lt.1
    //=================KAMAR 1 KANAN KAPAL LT.1=======================
  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 15, -10, 2, 2, 2);
    kubus(-49, 15, -5, 2, 2, 2);
    kubus(-49, 15, -10, 2, 2, 2);
    kubus(-59, 15, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 17, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 19, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 15, -17, 2, 2, 2);
    kubus(-59, 15, -20, 2, 2, 2);
    kubus(-56, 15, -20, 2, 2, 2);
    kubus(-56, 15, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 17, -20, 5, 5, 2);

    //==================KAMAR 2 KANAN KAPAL LT.1=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 15, -10, 2, 2, 2);
    kubus(-30, 15, -5, 2, 2, 2);
    kubus(-30, 15, -10, 2, 2, 2);
    kubus(-40, 15, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 17, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 19, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 15, -17, 2, 2, 2);
    kubus(-40, 15, -20, 2, 2, 2);
    kubus(-37, 15, -20, 2, 2, 2);
    kubus(-37, 15, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 17, -20, 5, 5, 2);

    //==================KAMAR 3 KANAN KAPAL LT.1=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7, 15, -10, 2, 2, 2);
    kubus(3, 15, -5, 2, 2, 2);
    kubus(3, 15, -10, 2, 2, 2);
    kubus(-7, 15, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 17, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 19, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 15, -17, 2, 2, 2);
    kubus(0, 15, -20, 2, 2, 2);
    kubus(3, 15, -20, 2, 2, 2);
    kubus(3, 15, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 17, -20, 5, 5, 2);

    //==================KAMAR 4 KANAN KAPAL LT.1=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 15, -10, 2, 2, 2);
    kubus(17, 15, -5, 2, 2, 2);
    kubus(17, 15, -10, 2, 2, 2);
    kubus(27, 15, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 17, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 19, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 15, -17, 2, 2, 2);
    kubus(27, 15, -20, 2, 2, 2);
    kubus(24, 15, -20, 2, 2, 2);
    kubus(24, 15, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 17, -20, 5, 5, 2);

    //==================KAMAR 5 KANAN KAPAL LT.1=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 15, -10, 2, 2, 2);
    kubus(46, 15, -5, 2, 2, 2);
    kubus(46, 15, -10, 2, 2, 2);
    kubus(56, 15, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 17, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 19, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 15, -17, 2, 2, 2);
    kubus(56, 15, -20, 2, 2, 2);
    kubus(53, 15, -20, 2, 2, 2);
    kubus(53, 15, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 17, -20, 5, 5, 2);

    //=================KAMAR 1 KIRI KAPAL LT.1=======================
    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 15,  10, 2, 2, 2);
    kubus(-49, 15, 15, 2, 2, 2);
    kubus(-49, 15, 10, 2, 2, 2);
    kubus(-59, 15, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 17, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 19, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 15, 3, 2, 2, 2);
    kubus(-59, 15, 6, 2, 2, 2);
    kubus(-56, 15, 6, 2, 2, 2);
    kubus(-56, 15, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 17, 3, 5, 5, 2);

    //==================KAMAR 2 KIRI KAPAL LT.1=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 15, 10, 2, 2, 2);
    kubus(-30, 15, 15, 2, 2, 2);
    kubus(-30, 15, 10, 2, 2, 2);
    kubus(-40, 15, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 17, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 19, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 15, 3, 2, 2, 2);
    kubus(-40, 15, 6, 2, 2, 2);
    kubus(-37, 15, 6, 2, 2, 2);
    kubus(-37, 15, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 17, 3, 5, 5, 2);

    //==================KAMAR 3 KIRI KAPAL LT.1=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7, 15, 10, 2, 2, 2);
    kubus(3, 15, 15, 2, 2, 2);
    kubus(3, 15, 10, 2, 2, 2);
    kubus(-7, 15, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 17, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 19, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 15, 3, 2, 2, 2);
    kubus(0, 15, 6, 2, 2, 2);
    kubus(3, 15, 6, 2, 2, 2);
    kubus(3, 15, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 17, 3, 5, 5, 2);

    //==================KAMAR 4 KIRI KAPAL LT.1=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 15, 10, 2, 2, 2);
    kubus(17, 15, 15, 2, 2, 2);
    kubus(17, 15, 10, 2, 2, 2);
    kubus(27, 15, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 17, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 19, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 15, 3, 2, 2, 2);
    kubus(27, 15, 6, 2, 2, 2);
    kubus(24, 15, 6, 2, 2, 2);
    kubus(24, 15, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 17, 3, 5, 5, 2);

    //==================KAMAR 5 KIRI KAPAL LT.1=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 15, 10, 2, 2, 2);
    kubus(46, 15, 15, 2, 2, 2);
    kubus(46, 15, 10, 2, 2, 2);
    kubus(56, 15, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 17, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 19, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 15, 3, 2, 2, 2);
    kubus(56, 15, 6, 2, 2, 2);
    kubus(53, 15, 6, 2, 2, 2);
    kubus(53, 15, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 17, 3, 5, 5, 2);

    //kamar lt.2

    //=================KAMAR 1 KANAN KAPAL LT.2=======================
  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 26, -10, 2, 2, 2);
    kubus(-49, 26, -5, 2, 2, 2);
    kubus(-49, 26, -10, 2, 2, 2);
    kubus(-59, 26, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 28, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 30, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 26, -17, 2, 2, 2);
    kubus(-59, 26, -20, 2, 2, 2);
    kubus(-56, 26, -20, 2, 2, 2);
    kubus(-56, 26, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 28, -20, 5, 5, 2);

    //==================KAMAR 2 KANAN KAPAL LT.2=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 26, -10, 2, 2, 2);
    kubus(-30, 26, -5, 2, 2, 2);
    kubus(-30, 26, -10, 2, 2, 2);
    kubus(-40, 26, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 28, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 30, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 26, -17, 2, 2, 2);
    kubus(-40, 26, -20, 2, 2, 2);
    kubus(-37, 26, -20, 2, 2, 2);
    kubus(-37, 26, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 28, -20, 5, 5, 2);

    //==================KAMAR 3 KANAN KAPAL LT.2=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7, 26, -10, 2, 2, 2);
    kubus(3, 26, -5, 2, 2, 2);
    kubus(3, 26, -10, 2, 2, 2);
    kubus(-7, 26, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 28, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 30, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 26, -17, 2, 2, 2);
    kubus(0, 26, -20, 2, 2, 2);
    kubus(3, 26, -20, 2, 2, 2);
    kubus(3, 26, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 28, -20, 5, 5, 2);

    //==================KAMAR 4 KANAN KAPAL LT.2=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 26, -10, 2, 2, 2);
    kubus(17, 26, -5, 2, 2, 2);
    kubus(17, 26, -10, 2, 2, 2);
    kubus(27, 26, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 28, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 30, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 26, -17, 2, 2, 2);
    kubus(27, 26, -20, 2, 2, 2);
    kubus(24, 26, -20, 2, 2, 2);
    kubus(24, 26, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 28, -20, 5, 5, 2);

    //==================KAMAR 5 KANAN KAPAL LT.2=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 26, -10, 2, 2, 2);
    kubus(46, 26, -5, 2, 2, 2);
    kubus(46, 26, -10, 2, 2, 2);
    kubus(56, 26, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 28, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 30, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 26, -17, 2, 2, 2);
    kubus(56, 26, -20, 2, 2, 2);
    kubus(53, 26, -20, 2, 2, 2);
    kubus(53, 26, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 28, -20, 5, 5, 2);

    //=================KAMAR 1 KIRI KAPAL LT.2=======================
    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 26, 10, 2, 2, 2);
    kubus(-49, 26, 15, 2, 2, 2);
    kubus(-49, 26, 10, 2, 2, 2);
    kubus(-59, 26, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 28, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 30, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 26, 3, 2, 2, 2);
    kubus(-59, 26, 6, 2, 2, 2);
    kubus(-56, 26, 6, 2, 2, 2);
    kubus(-56, 26, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 28, 3, 5, 5, 2);

    //==================KAMAR 2 KIRI KAPAL LT.2=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 26, 10, 2, 2, 2);
    kubus(-30, 26, 15, 2, 2, 2);
    kubus(-30, 26, 10, 2, 2, 2);
    kubus(-40, 26, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 28, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 30, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 26, 3, 2, 2, 2);
    kubus(-40, 26, 6, 2, 2, 2);
    kubus(-37, 26, 6, 2, 2, 2);
    kubus(-37, 26, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 28, 3, 5, 5, 2);

    //==================KAMAR 3 KIRI KAPAL LT.2=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7, 26, 10, 2, 2, 2);
    kubus(3, 26, 15, 2, 2, 2);
    kubus(3, 26, 10, 2, 2, 2);
    kubus(-7, 26, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 28, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 30, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 26, 3, 2, 2, 2);
    kubus(0, 26, 6, 2, 2, 2);
    kubus(3, 26, 6, 2, 2, 2);
    kubus(3, 26, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 28, 3, 5, 5, 2);

    //==================KAMAR 4 KIRI KAPAL LT.2=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 26, 10, 2, 2, 2);
    kubus(17, 26, 15, 2, 2, 2);
    kubus(17, 26, 10, 2, 2, 2);
    kubus(27, 26, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 28, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 30, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 26, 3, 2, 2, 2);
    kubus(27, 26, 6, 2, 2, 2);
    kubus(24, 26, 6, 2, 2, 2);
    kubus(24, 26, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 28, 3, 5, 5, 2);

    //==================KAMAR 5 KIRI KAPAL LT.2=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 26, 10, 2, 2, 2);
    kubus(46, 26, 15, 2, 2, 2);
    kubus(46, 26, 10, 2, 2, 2);
    kubus(56, 26, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 28, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 30, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 26, 3, 2, 2, 2);
    kubus(56, 26, 6, 2, 2, 2);
    kubus(53, 26, 6, 2, 2, 2);
    kubus(53, 26, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 28, 3, 5, 5, 2);

    //kamar lt.3

      //=================KAMAR 1 KANAN KAPAL LT.3=======================
  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 36, -10, 2, 2, 2);
    kubus(-49, 36, -5, 2, 2, 2);
    kubus(-49, 36, -10, 2, 2, 2);
    kubus(-59, 36, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 38, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 40, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 36, -17, 2, 2, 2);
    kubus(-59, 36, -20, 2, 2, 2);
    kubus(-56, 36, -20, 2, 2, 2);
    kubus(-56, 36, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 38, -20, 5, 5, 2);

    //==================KAMAR 2 KANAN KAPAL LT.3=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 36, -10, 2, 2, 2);
    kubus(-30, 36, -5, 2, 2, 2);
    kubus(-30, 36, -10, 2, 2, 2);
    kubus(-40, 36, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 38, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 40, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 36, -17, 2, 2, 2);
    kubus(-40, 36, -20, 2, 2, 2);
    kubus(-37, 36, -20, 2, 2, 2);
    kubus(-37, 36, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 38, -20, 5, 5, 2);

    //==================KAMAR 3 KANAN KAPAL LT.3=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7, 36, -10, 2, 2, 2);
    kubus(3, 36, -5, 2, 2, 2);
    kubus(3, 36, -10, 2, 2, 2);
    kubus(-7, 36, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 38, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 40, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 36, -17, 2, 2, 2);
    kubus(0, 36, -20, 2, 2, 2);
    kubus(3, 36, -20, 2, 2, 2);
    kubus(3, 36, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 38, -20, 5, 5, 2);

    //==================KAMAR 4 KANAN KAPAL LT.3=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 36, -10, 2, 2, 2);
    kubus(17, 36, -5, 2, 2, 2);
    kubus(17, 36, -10, 2, 2, 2);
    kubus(27, 36, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 38, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 40, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 36, -17, 2, 2, 2);
    kubus(27, 36, -20, 2, 2, 2);
    kubus(24, 36, -20, 2, 2, 2);
    kubus(24, 36, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 38, -20, 5, 5, 2);

    //==================KAMAR 5 KANAN KAPAL LT.3=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 36, -10, 2, 2, 2);
    kubus(46, 36, -5, 2, 2, 2);
    kubus(46, 36, -10, 2, 2, 2);
    kubus(56, 36, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 38, -10, 12, 7, 2);
    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 40, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 36, -17, 2, 2, 2);
    kubus(56, 36, -20, 2, 2, 2);
    kubus(53, 36, -20, 2, 2, 2);
    kubus(53, 36, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 38, -20, 5, 5, 2);

    //=================KAMAR 1 KIRI KAPAL LT.3=======================
    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 36, 10, 2, 2, 2);
    kubus(-49, 36, 15, 2, 2, 2);
    kubus(-49, 36, 10, 2, 2, 2);
    kubus(-59, 36, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 38, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 40, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 36, 3, 2, 2, 2);
    kubus(-59, 36, 6, 2, 2, 2);
    kubus(-56, 36, 6, 2, 2, 2);
    kubus(-56, 36, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 38, 3, 5, 5, 2);

    //==================KAMAR 2 KIRI KAPAL LT.3=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 36, 10, 2, 2, 2);
    kubus(-30, 36, 15, 2, 2, 2);
    kubus(-30, 36, 10, 2, 2, 2);
    kubus(-40, 36, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 38, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 40, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 36, 3, 2, 2, 2);
    kubus(-40, 36, 6, 2, 2, 2);
    kubus(-37, 36, 6, 2, 2, 2);
    kubus(-37, 36, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 38, 3, 5, 5, 2);

    //==================KAMAR 3 KIRI KAPAL LT.3=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7, 36, 10, 2, 2, 2);
    kubus(3, 36, 15, 2, 2, 2);
    kubus(3, 36, 10, 2, 2, 2);
    kubus(-7, 36, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 38, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 40, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 36, 3, 2, 2, 2);
    kubus(0, 36, 6, 2, 2, 2);
    kubus(3, 36, 6, 2, 2, 2);
    kubus(3, 36, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 38, 3, 5, 5, 2);

    //==================KAMAR 4 KIRI KAPAL LT.3=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 36, 10, 2, 2, 2);
    kubus(17, 36, 15, 2, 2, 2);
    kubus(17, 36, 10, 2, 2, 2);
    kubus(27, 36, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 38, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 40, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 36, 3, 2, 2, 2);
    kubus(27, 36, 6, 2, 2, 2);
    kubus(24, 36, 6, 2, 2, 2);
    kubus(24, 36, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 38, 3, 5, 5, 2);

    //==================KAMAR 5 KIRI KAPAL LT.3=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 36, 10, 2, 2, 2);
    kubus(46, 36, 15, 2, 2, 2);
    kubus(46, 36, 10, 2, 2, 2);
    kubus(56, 36, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 38, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 40, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 36, 3, 2, 2, 2);
    kubus(56, 36, 6, 2, 2, 2);
    kubus(53, 36, 6, 2, 2, 2);
    kubus(53, 36, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 38, 3, 5, 5, 2);

    //kamar lt.4

      //=================KAMAR 1 KANAN KAPAL LT.4=======================
  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 46, -10, 2, 2, 2);
    kubus(-49, 46, -5, 2, 2, 2);
    kubus(-49, 46, -10, 2, 2, 2);
    kubus(-59, 46, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 48, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 50, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 46, -17, 2, 2, 2);
    kubus(-59, 46, -20, 2, 2, 2);
    kubus(-56, 46, -20, 2, 2, 2);
    kubus(-56, 46, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 48, -20, 5, 5, 2);

    //==================KAMAR 2 KANAN KAPAL LT.4=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 46, -10, 2, 2, 2);
    kubus(-30, 46, -5, 2, 2, 2);
    kubus(-30, 46, -10, 2, 2, 2);
    kubus(-40, 46, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 48, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 50, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 46, -17, 2, 2, 2);
    kubus(-40, 46, -20, 2, 2, 2);
    kubus(-37, 46, -20, 2, 2, 2);
    kubus(-37, 46, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 48, -20, 5, 5, 2);

    //==================KAMAR 3 KANAN KAPAL LT.4=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7,46, -10, 2, 2, 2);
    kubus(3, 46, -5, 2, 2, 2);
    kubus(3, 46, -10, 2, 2, 2);
    kubus(-7, 46, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 48, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 50, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 46, -17, 2, 2, 2);
    kubus(0, 46, -20, 2, 2, 2);
    kubus(3, 46, -20, 2, 2, 2);
    kubus(3, 46, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 48, -20, 5, 5, 2);

    //==================KAMAR 4 KANAN KAPAL LT.4=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 46, -10, 2, 2, 2);
    kubus(17, 46, -5, 2, 2, 2);
    kubus(17, 46, -10, 2, 2, 2);
    kubus(27, 46, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 48, -10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 50, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 46, -17, 2, 2, 2);
    kubus(27, 46, -20, 2, 2, 2);
    kubus(24, 46, -20, 2, 2, 2);
    kubus(24, 46, -17, 2, 2, 2);

    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 48, -20, 5, 5, 2);

    //==================KAMAR 5 KANAN KAPAL LT.4=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 46, -10, 2, 2, 2);
    kubus(46, 46, -5, 2, 2, 2);
    kubus(46, 46, -10, 2, 2, 2);
    kubus(56, 46, -5, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 48, -10, 12, 7, 2);
    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 50, -9, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 46, -17, 2, 2, 2);
    kubus(56, 46, -20, 2, 2, 2);
    kubus(53, 46, -20, 2, 2, 2);
    kubus(53, 46, -17, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 48, -20, 5, 5, 2);

    //=================KAMAR 1 KIRI KAPAL LT.4=======================
    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 46, 10, 2, 2, 2);
    kubus(-49, 46, 15, 2, 2, 2);
    kubus(-49, 46, 10, 2, 2, 2);
    kubus(-59, 46, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-59, 48, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 50, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-59, 46, 3, 2, 2, 2);
    kubus(-59, 46, 6, 2, 2, 2);
    kubus(-56, 46, 6, 2, 2, 2);
    kubus(-56, 46, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-59, 48, 3, 5, 5, 2);

    //==================KAMAR 2 KIRI KAPAL LT.4=======================

  //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 46, 10, 2, 2, 2);
    kubus(-30, 46, 15, 2, 2, 2);
    kubus(-30, 46, 10, 2, 2, 2);
    kubus(-40, 46, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-40, 48, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 50, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(-40, 46, 3, 2, 2, 2);
    kubus(-40, 46, 6, 2, 2, 2);
    kubus(-37, 46, 6, 2, 2, 2);
    kubus(-37, 46, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(-40, 48, 3, 5, 5, 2);

    //==================KAMAR 3 KIRI KAPAL LT.4=======================

    //Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(-7, 46, 10, 2, 2, 2);
    kubus(3, 46, 15, 2, 2, 2);
    kubus(3, 46, 10, 2, 2, 2);
    kubus(-7, 46, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(-7, 48, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(2, 50, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(0, 46, 3, 2, 2, 2);
    kubus(0, 46, 6, 2, 2, 2);
    kubus(3, 46, 6, 2, 2, 2);
    kubus(3, 46, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(0, 48, 3, 5, 5, 2);

    //==================KAMAR 4 KIRI KAPAL LT.4=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 46, 10, 2, 2, 2);
    kubus(17, 46, 15, 2, 2, 2);
    kubus(17, 46, 10, 2, 2, 2);
    kubus(27, 46, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(17, 48, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(26, 50, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(27, 46, 3, 2, 2, 2);
    kubus(27, 46, 6, 2, 2, 2);
    kubus(24, 46, 6, 2, 2, 2);
    kubus(24, 46, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(24, 48, 3, 5, 5, 2);

    //==================KAMAR 5 KIRI KAPAL LT.4=======================

//Kaki Kasur
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 46, 10, 2, 2, 2);
    kubus(46, 46, 15, 2, 2, 2);
    kubus(46, 46, 10, 2, 2, 2);
    kubus(56, 46, 15, 2, 2, 2);

    //Badan Kasur
    glColor3f(1.0, 1.0, 1.0);
    kubus(46, 48, 10, 12, 7, 2);

    //Bantal
    glColor3f(0.64, 0.16, 0.16);
    kubus(55, 50, 11, 3, 5, 1);

    //kaki meja
    glColor3f(0.64, 0.16, 0.16);
    kubus(56, 46, 3, 2, 2, 2);
    kubus(56, 46, 6, 2, 2, 2);
    kubus(53, 46, 6, 2, 2, 2);
    kubus(53, 46, 3, 2, 2, 2);
    //Badan Meja
    glColor3f(0.98, 0.49, 0.31);
    kubus(53, 48, 3, 5, 5, 2);


   //kolam renang tutup belakang
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(55.0, 56.0, -17.0);
    glVertex3f(55.0, 56.0, 17.0);
    glVertex3f(55.0, 55.0, 17.0);
    glVertex3f(55.0, 55.0, -17.0);
    glEnd();

    //lis tutup belakang kolam
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(55.0, 56.0, -17.0);
    glVertex3f(55.0, 56.0, 17.0);
    glVertex3f(55.0, 55.0, 17.0);
    glVertex3f(55.0, 55.0, -17.0);
    glEnd();

    //kolam renang tutup depan
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(35.0, 56.0, -17.0);
    glVertex3f(35.0, 56.0, 17.0);
    glVertex3f(35.0, 55.0, 17.0);
    glVertex3f(35.0, 55.0, -17.0);
    glEnd();

    //lis tutup depan kolam
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(35.0, 56.0, -17.0);
    glVertex3f(35.0, 56.0, 17.0);
    glVertex3f(35.0, 55.0, 17.0);
    glVertex3f(35.0, 55.0, -17.0);
    glEnd();

    //kolam samping kiri
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(35.0, 56.0, 17.0);
    glVertex3f(55.0, 56.0, 17.0);
    glVertex3f(55.0, 55.0, 17.0);
    glVertex3f(35.0, 55.0, 17.0);
    glEnd();

    //lis samping kiri
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(35.0, 56.0, 17.0);
    glVertex3f(55.0, 56.0, 17.0);
    glVertex3f(55.0, 55.0, 17.0);
    glVertex3f(35.0, 55.0, 17.0);
    glEnd();

    //kolam samping kanan
    glBegin(GL_QUADS);
    glColor3ub(220, 220, 220);
    glVertex3f(35.0, 56.0, -17.0);
    glVertex3f(55.0, 56.0, -17.0);
    glVertex3f(55.0, 55.0, -17.0);
    glVertex3f(35.0, 55.0, -17.0);
    glEnd();

    //lis samping kanan
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(35.0, 56.0, -17.0);
    glVertex3f(55.0, 56.0, -17.0);
    glVertex3f(55.0, 55.0, -17.0);
    glVertex3f(35.0, 55.0, -17.0);
    glEnd();

    //air kolam
    glBegin(GL_QUADS);
    glColor3ub(30, 144, 255);
    glVertex3f(35.0, 55.1, -17.0);
    glVertex3f(35.0, 55.1, 17.0);
    glVertex3f(55.0, 55.1, 17.0);
    glVertex3f(55.0, 55.1, -17.0);
    glEnd();

    // atas samping kiri
    glBegin(GL_QUADS);
    glColor3ub(254, 240, 245);
    glVertex3f(-75.0, 20.0, -30.0);
    glVertex3f(70.0, 20.0, -30.0);
    glVertex3f(70.0, 0.0, -30.0);
    glVertex3f(-75.0, 0.0, -30.0);
    glEnd();


    //bawah samping kanan
    glBegin(GL_QUADS);
    glColor3ub(250, 99, 71);
    glVertex3f(-75.0, 0.0, -30.0);
    glVertex3f(70.0, 0.0, -30.0);
    glVertex3f(77.0, -12.0, -20.0);
    glVertex3f(-75.0, -12.0, -20.0);
    glEnd();

    // atas belakang
    glBegin(GL_QUADS);
    glColor3ub(175, 238, 239);
    glVertex3f(70.0, 0.0, 30.0);
    glVertex3f(70.0, 20.0, 30.0);
    glVertex3f(70.0, 20.0, -30.0);
    glVertex3f(70.0, 0.0, -30.0);
    glEnd();

    // bawah belakang
    glBegin(GL_QUADS);
    glColor3ub(72, 209, 204);
    glVertex3f(77.0, -12.0, 20.0);
    glVertex3f(70.0, 0.0, 30.0);
    glVertex3f(70.0, 0.0, -30.0);
    glVertex3f(77.0, -12.0, -20.0);
    glEnd();

    //alas
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, -11.8, 20.0);
    glVertex3f(77.0, -11.8, 20.0);
    glVertex3f(77.0, -11.8, -20.0);
    glVertex3f(-75.0, -11.8, -20.0);
    glEnd();

    //alas atas pondasi
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, 15.0, 30.0);
    glVertex3f(70.0, 15.0, 30.0);
    glVertex3f(70.0, 15.0, -30.0);
    glVertex3f(-75.0, 15.0, -30.0);
    glEnd();

    //segitiga atas samping kanan
    glBegin(GL_QUADS);
    glColor3ub(245, 245, 223);
    glVertex3f(-120.0, 20.0, 0.0);
    glVertex3f(-75.0, 20.0, -30.0);
    glVertex3f(-75.0, 0.0, -30.0);
    glVertex3f(-110.0, 0.0, 0.0);
    glEnd();

    //segitiga bawah samping kanan
    glBegin(GL_QUADS);
    glColor3ub(188, 143, 142);
    glVertex3f(-110.0, 0.0, 0.0);
    glVertex3f(-75.0, 0.0, -30.0);
    glVertex3f(-75.0, -12.0, -20.0);
    glVertex3f(-100.0, -12.0, 0.0);
    glEnd();

    //alas depan segitiga
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, -11.8, 20.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, -11.8, -20.0);
    glColor3ub(0, 0, 0);
    glVertex3f(-100, -11.8, 0.0);
    glEnd();

    //alas depan segitiga atas
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, 15.0, 29.2);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, 15.0, -29.2);
    glColor3ub(0, 0, 0);
    glVertex3f(-115, 15.0, 0.0);
    glEnd();

    ///alas rufftoop
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-60.0, 55.0, 22.0);
    glVertex3f(60.0, 55.0, 22.0);
    glVertex3f(60.0, 55.0, -22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-60.0, 55.0, 22.0);
    glVertex3f(60.0, 55.0, 22.0);
    glVertex3f(60.0, 55.0, -22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

    //alas lantai 1
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-75.0, 15.1, 22.0);
    glVertex3f(60.0, 15.1, 22.0);
    glVertex3f(60.0, 15.1, -22.0);
    glVertex3f(-75.0, 15.1, -22.0);
    glEnd();

    //lis lantai 1
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-75.0, 15.1, 23.0);
    glVertex3f(60.0, 15.1, 23.0);
    glVertex3f(60.0, 15.1, -22.0);
    glVertex3f(-75.0, 15.1, -22.0);
    glEnd();

   //alas lantai2
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-71.0, 25.0, 22.0);
    glVertex3f(60.0, 25.0, 22.0);
    glVertex3f(60.0, 25.0, -22.0);
    glVertex3f(-71.0, 25.0, -22.0);
    glEnd();

    //lis lantai 2
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-71.3, 25.0, 23.0);
    glVertex3f(60.0, 25.0, 23.0);
    glVertex3f(60.0, 25.0, -22.0);
    glVertex3f(-71.3, 25.0, -22.0);
    glEnd();

    //alas lantai 3
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-66.0, 35.0, 22.0);
    glVertex3f(60.0, 35.0, 22.0);
    glVertex3f(60.0, 35.0, -22.0);
    glVertex3f(-66.0, 35.0, -22.0);
    glEnd();

    //lis lantai3
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-68.0, 35.0, 23.0);
    glVertex3f(60.0, 35.0, 23.0);
    glVertex3f(60.0, 35.0, -22.0);
    glVertex3f(-68.0, 35.0, -22.0);
    glEnd();

    //alas lantai 4
    glBegin(GL_QUADS);
    glColor3ub(154, 205, 49);
    glVertex3f(-63.7, 45.0, 22.0);
    glVertex3f(60.0, 45.0, 22.0);
    glVertex3f(60.0, 45.0, -22.0);
    glVertex3f(-63.7, 45.0, -22.0);
    glEnd();

    //lis lantai 4
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-63.9, 45.0, 23.0);
    glVertex3f(60.0, 45.0, 23.0);
    glVertex3f(60.0, 45.0, -22.0);
    glVertex3f(-63.9, 45.0, -22.0);
    glEnd();

    //Ruang bagian atas nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-35.0, 62.0, 10.0);
    glVertex3f(-35.0, 62.0, -10.0);
    glVertex3f(-50.0, 62.0, -10.0);
    glEnd();

    //Ruang bagian atas kanan nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0, -10.0);
    glVertex3f(-35.0, 62.0, -10.0);
    glVertex3f(-35.0, 62.0, -20.0);
    glVertex3f(-45.0, 62.0, -20.0);
    glEnd();

    //Ruang bagian atas kiri nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-35.0, 62.0, 10.0);
    glVertex3f(-35.0, 62.0, 20.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glEnd();

    //Ruang bagian depan nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-50.0, 55.0, 10.0);
    glVertex3f(-50.0, 55.0, -10.0);
    glVertex3f(-50.0, 62.0, -10.0);
    glEnd();

    //Ruang bagian depan  kanan nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 55.0, -10.0);
    glVertex3f(-50.0, 62.0, -10.0);
    glVertex3f(-45.0, 62.0, -20.0);
    glVertex3f(-45.0, 55.0, -20.0);
    glEnd();

    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-50.0, 55.0, -10.0);
    glVertex3f(-50.0, 62.0, -10.0);
    glVertex3f(-45.0, 62.0, -20.0);
    glVertex3f(-45.0, 55.0, -20.0);
    glEnd();

    //Ruang bagian depan  kiri nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-50.0, 55.0, 10.0);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glVertex3f(-45.0, 55.0, 20.0);
    glEnd();

    //lis
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(-50.0, 55.0, 10.0);
    glVertex3f(-50.0, 62.0, 10.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glVertex3f(-45.0, 55.0, 20.0);
    glEnd();

    //Ruang bagian  kiri nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-45.0, 55.0, 20.0);
    glVertex3f(-45.0, 62.0, 20.0);
    glVertex3f(-35.0, 62.0, 20.0);
    glVertex3f(-35.0, 55.0, 20.0);
    glEnd();

    //Ruang bagian kanan nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-45.0, 55.0, -20.0);
    glVertex3f(-45.0, 62.0, -20.0);
    glVertex3f(-35.0, 62.0, -20.0);
    glVertex3f(-35.0, 55.0, -20.0);
    glEnd();

    //Ruang bagian belakang nahkoda
    glBegin(GL_QUADS);
    glColor3ub(216, 191, 216);
    glVertex3f(-35.0, 55.0, 20.0);
    glVertex3f(-35.0, 62.0, 20.0);
    glVertex3f(-35.0, 62.0, -20.0);
    glVertex3f(-35.0, 55.0, -20.0);
    glEnd();

    //rumah kapal 2 tutup belakang
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(60.0, 15.0, -22.0);
    glVertex3f(60.0, 15.0, 22.0);
    glVertex3f(60.0, 55.0, 22.0);
    glVertex3f(60.0, 55.0, -22.0);
    glEnd();

    //rumah kapal 2 tutup depan
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0, -22.0);
    glVertex3f(-75.0, 15.0, 22.0);
    glVertex3f(-60.0, 55.0, 22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

    //rumah kapal 2 tutup kanan
    /*glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0, -22.0);
    glVertex3f(60.0, 15.0, -22.0);
    glVertex3f(60.0, 55.0, -22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();*/

    //sekat
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3f(30.0, 15.0, -22.0);
    glVertex3f(30.0, 15.0, 22.0);
    glVertex3f(30.0, 55.0, 22.0);
    glVertex3f(30.0, 55.0, -22.0);
    glEnd();

    //sekat
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3f(6.0, 15.0, -22.0);
    glVertex3f(6.0, 15.0, 22.0);
    glVertex3f(6.0, 55.0, 22.0);
    glVertex3f(6.0, 55.0, -22.0);
    glEnd();

    //sekat
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3f(-18.0, 15.0, -22.0);
    glVertex3f(-18.0, 15.0, 22.0);
    glVertex3f(-18.0, 55.0, 22.0);
    glVertex3f(-18.0, 55.0, -22.0);
    glEnd();

    //sekat
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3f(-42.0, 15.0, -22.0);
    glVertex3f(-42.0, 15.0, 22.0);
    glVertex3f(-42.0, 55.0, 22.0);
    glVertex3f(-42.0, 55.0, -22.0);
    glEnd();

    //sekat
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3f(-60.0, 15.0, -22.0);
    glVertex3f(-60.0, 15.0, 22.0);
    glVertex3f(-60.0, 55.0, 22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

    //sekat tengah
    glBegin(GL_QUADS);
    glColor3ub(169, 169, 169);
    glVertex3f(-75.0, 15.0, 0.0);
    glVertex3f(60.0, 15.0, 0.0);
    glVertex3f(60.0, 55.0, 0.0);
    glVertex3f(-60.0, 55.0, 0.0);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 18.0, -22.1);
    glVertex3f(28.0, 18.0, -22.1);
    glVertex3f(28.0, 22.0, -22.1);
    glVertex3f(20.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 28.0, -22.1);
    glVertex3f(28.0, 28.0, -22.1);
    glVertex3f(28.0, 32.0, -22.1);
    glVertex3f(20.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 38.0, -22.1);
    glVertex3f(28.0, 38.0, -22.1);
    glVertex3f(28.0, 42.0, -22.1);
    glVertex3f(20.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 48.0, -22.1);
    glVertex3f(28.0, 48.0, -22.1);
    glVertex3f(28.0, 52.0, -22.1);
    glVertex3f(20.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 18.0, -22.1);
    glVertex3f(16.0, 18.0, -22.1);
    glVertex3f(16.0, 22.0, -22.1);
    glVertex3f(8.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 38.0, -22.1);
    glVertex3f(16.0, 38.0, -22.1);
    glVertex3f(16.0, 42.0, -22.1);
    glVertex3f(8.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 28.0, -22.1);
    glVertex3f(16.0, 28.0, -22.1);
    glVertex3f(16.0, 32.0, -22.1);
    glVertex3f(8.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 48.0, -22.1);
    glVertex3f(16.0, 48.0, -22.1);
    glVertex3f(16.0, 52.0, -22.1);
    glVertex3f(8.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 48.0, -22.1);
    glVertex3f(-4.0, 48.0, -22.1);
    glVertex3f(-4.0, 52.0, -22.1);
    glVertex3f(4.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 18.0, -22.1);
    glVertex3f(-4.0, 18.0, -22.1);
    glVertex3f(-4.0, 22.0, -22.1);
    glVertex3f(4.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 28.0, -22.1);
    glVertex3f(-4.0, 28.0, -22.1);
    glVertex3f(-4.0, 32.0, -22.1);
    glVertex3f(4.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 38.0, -22.1);
    glVertex3f(-4.0, 38.0, -22.1);
    glVertex3f(-4.0, 42.0, -22.1);
    glVertex3f(4.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 38.0, -22.1);
    glVertex3f(-16.0, 38.0, -22.1);
    glVertex3f(-16.0, 42.0, -22.1);
    glVertex3f(-8.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 28.0, -22.1);
    glVertex3f(-16.0, 28.0, -22.1);
    glVertex3f(-16.0, 32.0, -22.1);
    glVertex3f(-8.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 18.0, -22.1);
    glVertex3f(-16.0, 18.0, -22.1);
    glVertex3f(-16.0, 22.0, -22.1);
    glVertex3f(-8.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 48.0, -22.1);
    glVertex3f(-16.0, 48.0, -22.1);
    glVertex3f(-16.0, 52.0, -22.1);
    glVertex3f(-8.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 48.0, -22.1);
    glVertex3f(-20.0, 48.0, -22.1);
    glVertex3f(-20.0, 52.0, -22.1);
    glVertex3f(-28.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 18.0, -22.1);
    glVertex3f(-20.0, 18.0, -22.1);
    glVertex3f(-20.0, 22.0, -22.1);
    glVertex3f(-28.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 38.0, -22.1);
    glVertex3f(-20.0, 38.0, -22.1);
    glVertex3f(-20.0, 42.0, -22.1);
    glVertex3f(-28.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 28.0, -22.1);
    glVertex3f(-20.0, 28.0, -22.1);
    glVertex3f(-20.0, 32.0, -22.1);
    glVertex3f(-28.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 28.0, -22.1);
    glVertex3f(-32.0, 28.0, -22.1);
    glVertex3f(-32.0, 32.0, -22.1);
    glVertex3f(-40.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 18.0, -22.1);
    glVertex3f(-32.0, 18.0, -22.1);
    glVertex3f(-32.0, 22.0, -22.1);
    glVertex3f(-40.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 38.0, -22.1);
    glVertex3f(-32.0, 38.0, -22.1);
    glVertex3f(-32.0, 42.0, -22.1);
    glVertex3f(-40.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 48.0, -22.1);
    glVertex3f(-32.0, 48.0, -22.1);
    glVertex3f(-32.0, 52.0, -22.1);
    glVertex3f(-40.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 18.0, -22.1);
    glVertex3f(-44.0, 18.0, -22.1);
    glVertex3f(-44.0, 22.0, -22.1);
    glVertex3f(-52.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 38.0, -22.1);
    glVertex3f(-44.0, 38.0, -22.1);
    glVertex3f(-44.0, 42.0, -22.1);
    glVertex3f(-52.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 28.0, -22.1);
    glVertex3f(-44.0, 28.0, -22.1);
    glVertex3f(-44.0, 32.0, -22.1);
    glVertex3f(-52.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 48.0, -22.1);
    glVertex3f(-44.0, 48.0, -22.1);
    glVertex3f(-44.0, 52.0, -22.1);
    glVertex3f(-52.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-61.0, 48.0, -22.1);
    glVertex3f(-56.0, 48.0, -22.1);
    glVertex3f(-56.0, 52.0, -22.1);
    glVertex3f(-60.0, 52.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 18.0, -22.1);
    glVertex3f(-56.0, 18.0, -22.1);
    glVertex3f(-56.0, 22.0, -22.1);
    glVertex3f(-64.0, 22.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 28.0, -22.1);
    glVertex3f(-56.0, 28.0, -22.1);
    glVertex3f(-56.0, 32.0, -22.1);
    glVertex3f(-64.0, 32.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 38.0, -22.1);
    glVertex3f(-56.0, 38.0, -22.1);
    glVertex3f(-56.0, 42.0, -22.1);
    glVertex3f(-64.0, 42.0, -22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 18.0, -21.9);
    glVertex3f(28.0, 18.0, -21.9);
    glVertex3f(28.0, 22.0, -21.9);
    glVertex3f(20.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 28.0, -21.9);
    glVertex3f(28.0, 28.0, -21.9);
    glVertex3f(28.0, 32.0, -21.9);
    glVertex3f(20.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 38.0, -21.9);
    glVertex3f(28.0, 38.0, -21.9);
    glVertex3f(28.0, 42.0, -21.9);
    glVertex3f(20.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 48.0, -21.9);
    glVertex3f(28.0, 48.0, -21.9);
    glVertex3f(28.0, 52.0, -21.9);
    glVertex3f(20.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 18.0, -21.9);
    glVertex3f(16.0, 18.0, -21.9);
    glVertex3f(16.0, 22.0, -21.9);
    glVertex3f(8.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 38.0, -21.9);
    glVertex3f(16.0, 38.0, -21.9);
    glVertex3f(16.0, 42.0, -21.9);
    glVertex3f(8.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 28.0, -21.9);
    glVertex3f(16.0, 28.0, -21.9);
    glVertex3f(16.0, 32.0, -21.9);
    glVertex3f(8.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 48.0, -21.9);
    glVertex3f(16.0, 48.0, -21.9);
    glVertex3f(16.0, 52.0, -21.9);
    glVertex3f(8.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 48.0, -21.9);
    glVertex3f(-4.0, 48.0, -21.9);
    glVertex3f(-4.0, 52.0, -21.9);
    glVertex3f(4.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 18.0, -21.9);
    glVertex3f(-4.0, 18.0, -21.9);
    glVertex3f(-4.0, 22.0, -21.9);
    glVertex3f(4.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 28.0, -21.9);
    glVertex3f(-4.0, 28.0, -21.9);
    glVertex3f(-4.0, 32.0, -21.9);
    glVertex3f(4.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 38.0, -21.9);
    glVertex3f(-4.0, 38.0, -21.9);
    glVertex3f(-4.0, 42.0, -21.9);
    glVertex3f(4.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 38.0, -21.9);
    glVertex3f(-16.0, 38.0, -21.9);
    glVertex3f(-16.0, 42.0, -21.9);
    glVertex3f(-8.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 28.0, -21.9);
    glVertex3f(-16.0, 28.0, -21.9);
    glVertex3f(-16.0, 32.0, -21.9);
    glVertex3f(-8.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 18.0, -21.9);
    glVertex3f(-16.0, 18.0, -21.9);
    glVertex3f(-16.0, 22.0, -21.9);
    glVertex3f(-8.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 48.0, -21.9);
    glVertex3f(-16.0, 48.0, -21.9);
    glVertex3f(-16.0, 52.0, -21.9);
    glVertex3f(-8.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 48.0, -21.9);
    glVertex3f(-20.0, 48.0, -21.9);
    glVertex3f(-20.0, 52.0, -21.9);
    glVertex3f(-28.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 18.0, -21.9);
    glVertex3f(-20.0, 18.0, -21.9);
    glVertex3f(-20.0, 22.0, -21.9);
    glVertex3f(-28.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 38.0, -21.9);
    glVertex3f(-20.0, 38.0, -21.9);
    glVertex3f(-20.0, 42.0, -21.9);
    glVertex3f(-28.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 28.0, -21.9);
    glVertex3f(-20.0, 28.0, -21.9);
    glVertex3f(-20.0, 32.0, -21.9);
    glVertex3f(-28.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 28.0, -21.9);
    glVertex3f(-32.0, 28.0, -21.9);
    glVertex3f(-32.0, 32.0, -21.9);
    glVertex3f(-40.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 18.0, -21.9);
    glVertex3f(-32.0, 18.0, -21.9);
    glVertex3f(-32.0, 22.0, -21.9);
    glVertex3f(-40.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 38.0, -21.9);
    glVertex3f(-32.0, 38.0, -21.9);
    glVertex3f(-32.0, 42.0, -21.9);
    glVertex3f(-40.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 48.0, -21.9);
    glVertex3f(-32.0, 48.0, -21.9);
    glVertex3f(-32.0, 52.0, -21.9);
    glVertex3f(-40.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 18.0, -21.9);
    glVertex3f(-44.0, 18.0, -21.9);
    glVertex3f(-44.0, 22.0, -21.9);
    glVertex3f(-52.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 38.0, -21.9);
    glVertex3f(-44.0, 38.0, -21.9);
    glVertex3f(-44.0, 42.0, -21.9);
    glVertex3f(-52.0, 42.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 28.0, -21.9);
    glVertex3f(-44.0, 28.0, -21.9);
    glVertex3f(-44.0, 32.0, -21.9);
    glVertex3f(-52.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 48.0, -21.9);
    glVertex3f(-44.0, 48.0, -21.9);
    glVertex3f(-44.0, 52.0, -21.9);
    glVertex3f(-52.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-61.0, 48.0, -21.9);
    glVertex3f(-56.0, 48.0, -21.9);
    glVertex3f(-56.0, 52.0, -21.9);
    glVertex3f(-60.0, 52.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 18.0, -21.9);
    glVertex3f(-56.0, 18.0, -21.9);
    glVertex3f(-56.0, 22.0, -21.9);
    glVertex3f(-64.0, 22.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 28.0, -21.9);
    glVertex3f(-56.0, 28.0, -21.9);
    glVertex3f(-56.0, 32.0, -21.9);
    glVertex3f(-64.0, 32.0, -21.9);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 38.0, -21.9);
    glVertex3f(-56.0, 38.0, -21.9);
    glVertex3f(-56.0, 42.0, -21.9);
    glVertex3f(-64.0, 42.0, -21.9);
    glEnd();

    //jendela belakang kanan luar
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 48.0, -22.1);
    glVertex3f(58.0, 48.0, -22.1);
    glVertex3f(58.0, 52.0, -22.1);
    glVertex3f(50.0, 52.0, -22.1);
    glEnd();

    //jendela kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 48.0, -21.9);
    glVertex3f(58.0, 48.0, -21.9);
    glVertex3f(58.0, 52.0, -21.9);
    glVertex3f(50.0, 52.0, -21.9);
    glEnd();

    //jendela belakang kanan luar
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 38.0, -22.1);
    glVertex3f(58.0, 38.0, -22.1);
    glVertex3f(58.0, 42.0, -22.1);
    glVertex3f(50.0, 42.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 38.0, -21.9);
    glVertex3f(58.0, 38.0, -21.9);
    glVertex3f(58.0, 42.0, -21.9);
    glVertex3f(50.0, 42.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 28.0, -22.1);
    glVertex3f(58.0, 28.0, -22.1);
    glVertex3f(58.0, 32.0, -22.1);
    glVertex3f(50.0, 32.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 28.0, -21.9);
    glVertex3f(58.0, 28.0, -21.9);
    glVertex3f(58.0, 32.0, -21.9);
    glVertex3f(50.0, 32.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 18.0, -22.1);
    glVertex3f(58.0, 18.0, -22.1);
    glVertex3f(58.0, 22.0, -22.1);
    glVertex3f(50.0, 22.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 18.0, -21.9);
    glVertex3f(58.0, 18.0, -21.9);
    glVertex3f(58.0, 22.0, -21.9);
    glVertex3f(50.0, 22.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 18.0, -22.1);
    glVertex3f(47.0, 18.0, -22.1);
    glVertex3f(47.0, 22.0, -22.1);
    glVertex3f(39.0, 22.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 18.0, -21.9);
    glVertex3f(47.0, 18.0, -21.9);
    glVertex3f(47.0, 22.0, -21.9);
    glVertex3f(39.0, 22.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 28.0, -22.1);
    glVertex3f(47.0, 28.0, -22.1);
    glVertex3f(47.0, 32.0, -22.1);
    glVertex3f(39.0, 32.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 28.0, -21.9);
    glVertex3f(47.0, 28.0, -21.9);
    glVertex3f(47.0, 32.0, -21.9);
    glVertex3f(39.0, 32.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 38.0, -22.1);
    glVertex3f(47.0, 38.0, -22.1);
    glVertex3f(47.0, 42.0, -22.1);
    glVertex3f(39.0, 42.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 38.0, -21.9);
    glVertex3f(47.0, 38.0, -21.9);
    glVertex3f(47.0, 42.0, -21.9);
    glVertex3f(39.0, 42.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 48.0, -22.1);
    glVertex3f(47.0, 48.0, -22.1);
    glVertex3f(47.0, 52.0, -22.1);
    glVertex3f(39.0, 52.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 48.0, -21.9);
    glVertex3f(47.0, 48.0, -21.9);
    glVertex3f(47.0, 52.0, -21.9);
    glVertex3f(39.0, 52.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 48.0, -22.1);
    glVertex3f(37.0, 48.0, -22.1);
    glVertex3f(37.0, 52.0, -22.1);
    glVertex3f(30.0, 52.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 48.0, -21.9);
    glVertex3f(37.0, 48.0, -21.9);
    glVertex3f(37.0, 52.0, -21.9);
    glVertex3f(30.0, 52.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 38.0, -22.1);
    glVertex3f(37.0, 38.0, -22.1);
    glVertex3f(37.0, 42.0, -22.1);
    glVertex3f(30.0, 42.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 38.0, -21.9);
    glVertex3f(37.0, 38.0, -21.9);
    glVertex3f(37.0, 42.0, -21.9);
    glVertex3f(30.0, 42.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 28.0, -22.1);
    glVertex3f(37.0, 28.0, -22.1);
    glVertex3f(37.0, 32.0, -22.1);
    glVertex3f(30.0, 32.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 28.0, -21.9);
    glVertex3f(37.0, 28.0, -21.9);
    glVertex3f(37.0, 32.0, -21.9);
    glVertex3f(30.0, 32.0, -21.9);
    glEnd();

    //jendela belakang kanan
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 18.0, -22.1);
    glVertex3f(37.0, 18.0, -22.1);
    glVertex3f(37.0, 22.0, -22.1);
    glVertex3f(30.0, 22.0, -22.1);
    glEnd();

    //jendela belakang kanan dalam
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 18.0, -21.9);
    glVertex3f(37.0, 18.0, -21.9);
    glVertex3f(37.0, 22.0, -21.9);
    glVertex3f(30.0, 22.0, -21.9);
    glEnd();

    //sekoci kanan tutup kanan
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, -31.0);
    glVertex3f(10.0, 20.0, -31.0);
    glVertex3f(10.0, 15.0, -31.0);
    glVertex3f(-10.0, 15.0, -31.0);
    glEnd();

    //sekoci kanan tutup kiri
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, -40.0);
    glVertex3f(10.0, 20.0, -40.0);
    glVertex3f(10.0, 15.0, -40.0);
    glVertex3f(-10.0, 15.0, -40.0);
    glEnd();

    //tutup belakang sekoci kanan
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(10.0, 15.0, -31.0);
    glVertex3f(10.0, 20.0, -31.0);
    glVertex3f(10.0, 20.0, -40.0);
    glVertex3f(10.0, 15.0, -40.0);
    glEnd();

    //alas sekoci kanan
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 15.0, -31.0);
    glVertex3f(10.0, 15.0, -31.0);
    glVertex3f(10.0, 15.0, -40.0);
    glVertex3f(-10.0, 15.0, -40.0);
    glEnd();

    //segitiga sekoci samping kanan tutup kanan
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, -31.0);
    glVertex3f(-15.0, 20.0, -35.5);
    glVertex3f(-15.0, 15.0, -35.5);
    glVertex3f(-10.0, 15.0, -31.0);
    glEnd();

    //segitiga sekoci samping kanan tutup kiri
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, -40.0);
    glVertex3f(-15.0, 20.0, -35.5);
    glVertex3f(-15.0, 15.0, -35.5);
    glVertex3f(-10.0, 15.0, -40.0);
    glEnd();

    //alas segitiga sekoci bagian kanan
    glBegin(GL_POLYGON);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 15.0, -31.0);
    glColor3ub(245, 245, 223);
    glVertex3f(-10.0, 15.0, -40.0);
    glColor3ub(245, 245, 223);
    glVertex3f(-15.5, 15.0, -35.5);
    glEnd();

}

void kapal_transparan(void)
{
    //tutup kanan dek atas
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0, -22.0);
    glVertex3f(60.0, 15.0, -22.0);
    glVertex3f(60.0, 55.0, -22.0);
    glVertex3f(-60.0, 55.0, -22.0);
    glEnd();

    //rumah kapal tutup kiri
    glBegin(GL_QUADS);
    glColor3ub(245, 222, 179);
    glVertex3f(-75.0, 15.0, 22.0);
    glVertex3f(60.0, 15.0, 22.0);
    glVertex3f(60.0, 55.0, 22.0);
    glVertex3f(-60.0, 55.0, 22.0);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 18.0, 22.1);
    glVertex3f(28.0, 18.0, 22.1);
    glVertex3f(28.0, 22.0, 22.1);
    glVertex3f(20.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 28.0, 22.1);
    glVertex3f(28.0, 28.0, 22.1);
    glVertex3f(28.0, 32.0, 22.1);
    glVertex3f(20.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 38.0, 22.1);
    glVertex3f(28.0, 38.0, 22.1);
    glVertex3f(28.0, 42.0, 22.1);
    glVertex3f(20.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(20.0, 48.0, 22.1);
    glVertex3f(28.0, 48.0, 22.1);
    glVertex3f(28.0, 52.0, 22.1);
    glVertex3f(20.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 18.0, 22.1);
    glVertex3f(16.0, 18.0, 22.1);
    glVertex3f(16.0, 22.0, 22.1);
    glVertex3f(8.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 38.0, 22.1);
    glVertex3f(16.0, 38.0, 22.1);
    glVertex3f(16.0, 42.0, 22.1);
    glVertex3f(8.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 28.0, 22.1);
    glVertex3f(16.0, 28.0, 22.1);
    glVertex3f(16.0, 32.0, 22.1);
    glVertex3f(8.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(8.0, 48.0, 22.1);
    glVertex3f(16.0, 48.0, 22.1);
    glVertex3f(16.0, 52.0, 22.1);
    glVertex3f(8.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 48.0, 22.1);
    glVertex3f(-4.0, 48.0, 22.1);
    glVertex3f(-4.0, 52.0, 22.1);
    glVertex3f(4.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 18.0, 22.1);
    glVertex3f(-4.0, 18.0, 22.1);
    glVertex3f(-4.0, 22.0, 22.1);
    glVertex3f(4.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 28.0, 22.1);
    glVertex3f(-4.0, 28.0, 22.1);
    glVertex3f(-4.0, 32.0, 22.1);
    glVertex3f(4.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(4.0, 38.0, 22.1);
    glVertex3f(-4.0, 38.0, 22.1);
    glVertex3f(-4.0, 42.0, 22.1);
    glVertex3f(4.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 38.0, 22.1);
    glVertex3f(-16.0, 38.0, 22.1);
    glVertex3f(-16.0, 42.0, 22.1);
    glVertex3f(-8.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 28.0, 22.1);
    glVertex3f(-16.0, 28.0, 22.1);
    glVertex3f(-16.0, 32.0, 22.1);
    glVertex3f(-8.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 18.0, 22.1);
    glVertex3f(-16.0, 18.0, 22.1);
    glVertex3f(-16.0, 22.0, 22.1);
    glVertex3f(-8.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-8.0, 48.0, 22.1);
    glVertex3f(-16.0, 48.0, 22.1);
    glVertex3f(-16.0, 52.0, 22.1);
    glVertex3f(-8.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 48.0, 22.1);
    glVertex3f(-20.0, 48.0, 22.1);
    glVertex3f(-20.0, 52.0, 22.1);
    glVertex3f(-28.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 18.0, 22.1);
    glVertex3f(-20.0, 18.0, 22.1);
    glVertex3f(-20.0, 22.0, 22.1);
    glVertex3f(-28.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 38.0, 22.1);
    glVertex3f(-20.0, 38.0, 22.1);
    glVertex3f(-20.0, 42.0, 22.1);
    glVertex3f(-28.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-28.0, 28.0, 22.1);
    glVertex3f(-20.0, 28.0, 22.1);
    glVertex3f(-20.0, 32.0, 22.1);
    glVertex3f(-28.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 28.0, 22.1);
    glVertex3f(-32.0, 28.0, 22.1);
    glVertex3f(-32.0, 32.0, 22.1);
    glVertex3f(-40.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 18.0, 22.1);
    glVertex3f(-32.0, 18.0, 22.1);
    glVertex3f(-32.0, 22.0, 22.1);
    glVertex3f(-40.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 38.0, 22.1);
    glVertex3f(-32.0, 38.0, 22.1);
    glVertex3f(-32.0, 42.0, 22.1);
    glVertex3f(-40.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-40.0, 48.0, 22.1);
    glVertex3f(-32.0, 48.0, 22.1);
    glVertex3f(-32.0, 52.0, 22.1);
    glVertex3f(-40.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 18.0, 22.1);
    glVertex3f(-44.0, 18.0, 22.1);
    glVertex3f(-44.0, 22.0, 22.1);
    glVertex3f(-52.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 38.0, 22.1);
    glVertex3f(-44.0, 38.0, 22.1);
    glVertex3f(-44.0, 42.0, 22.1);
    glVertex3f(-52.0, 42.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 28.0, 22.1);
    glVertex3f(-44.0, 28.0, 22.1);
    glVertex3f(-44.0, 32.0, 22.1);
    glVertex3f(-52.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-52.0, 48.0, 22.1);
    glVertex3f(-44.0, 48.0, 22.1);
    glVertex3f(-44.0, 52.0, 22.1);
    glVertex3f(-52.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-61.0, 48.0, 22.1);
    glVertex3f(-56.0, 48.0, 22.1);
    glVertex3f(-56.0, 52.0, 22.1);
    glVertex3f(-60.0, 52.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 18.0, 22.1);
    glVertex3f(-56.0, 18.0, 22.1);
    glVertex3f(-56.0, 22.0, 22.1);
    glVertex3f(-64.0, 22.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 28.0, 22.1);
    glVertex3f(-56.0, 28.0, 22.1);
    glVertex3f(-56.0, 32.0, 22.1);
    glVertex3f(-64.0, 32.0, 22.1);
    glEnd();

    //jendela
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-64.0, 38.0, 22.1);
    glVertex3f(-56.0, 38.0, 22.1);
    glVertex3f(-56.0, 42.0, 22.1);
    glVertex3f(-64.0, 42.0, 22.1);
    glEnd();

    //jendela belakang kiri 4
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 48.0, 22.1);
    glVertex3f(58.0, 48.0, 22.1);
    glVertex3f(58.0, 52.0, 22.1);
    glVertex3f(50.0, 52.0, 22.1);
    glEnd();

    //jendela belakang kiri 3
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 38.0, 22.1);
    glVertex3f(58.0, 38.0, 22.1);
    glVertex3f(58.0, 42.0, 22.1);
    glVertex3f(50.0, 42.0, 22.1);
    glEnd();

    //jendela belakang kiri 2
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 28.0, 22.1);
    glVertex3f(58.0, 28.0, 22.1);
    glVertex3f(58.0, 32.0, 22.1);
    glVertex3f(50.0, 32.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(50.0, 18.0, 22.1);
    glVertex3f(58.0, 18.0, 22.1);
    glVertex3f(58.0, 22.0, 22.1);
    glVertex3f(50.0, 22.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 18.0, 22.1);
    glVertex3f(47.0, 18.0, 22.1);
    glVertex3f(47.0, 22.0, 22.1);
    glVertex3f(39.0, 22.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 28.0, 22.1);
    glVertex3f(47.0, 28.0, 22.1);
    glVertex3f(47.0, 32.0, 22.1);
    glVertex3f(39.0, 32.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 38.0, 22.1);
    glVertex3f(47.0, 38.0, 22.1);
    glVertex3f(47.0, 42.0, 22.1);
    glVertex3f(39.0, 42.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(39.0, 48.0, 22.1);
    glVertex3f(47.0, 48.0, 22.1);
    glVertex3f(47.0, 52.0, 22.1);
    glVertex3f(39.0, 52.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 48.0, 22.1);
    glVertex3f(37.0, 48.0, 22.1);
    glVertex3f(37.0, 52.0, 22.1);
    glVertex3f(30.0, 52.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 38.0, 22.1);
    glVertex3f(37.0, 38.0, 22.1);
    glVertex3f(37.0, 42.0, 22.1);
    glVertex3f(30.0, 42.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 28.0, 22.1);
    glVertex3f(37.0, 28.0, 22.1);
    glVertex3f(37.0, 32.0, 22.1);
    glVertex3f(30.0, 32.0, 22.1);
    glEnd();

    //jendela belakang kiri 1
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(30.0, 18.0, 22.1);
    glVertex3f(37.0, 18.0, 22.1);
    glVertex3f(37.0, 22.0, 22.1);
    glVertex3f(30.0, 22.0, 22.1);
    glEnd();

    //sekoci kiri tutup kanan
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, 31.0);
    glVertex3f(10.0, 20.0, 31.0);
    glVertex3f(10.0, 15.0, 31.0);
    glVertex3f(-10.0, 15.0, 31.0);
    glEnd();

    //sekoci kiri tutup kiri
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, 40.0);
    glVertex3f(10.0, 20.0, 40.0);
    glVertex3f(10.0, 15.0, 40.0);
    glVertex3f(-10.0, 15.0, 40.0);
    glEnd();

    //tutup belakang sekoci kiri
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(10.0, 15.0, 31.0);
    glVertex3f(10.0, 20.0, 31.0);
    glVertex3f(10.0, 20.0, 40.0);
    glVertex3f(10.0, 15.0, 40.0);
    glEnd();

    //alas sekoci kiri
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 15.0, 31.0);
    glVertex3f(10.0, 15.0, 31.0);
    glVertex3f(10.0, 15.0, 40.0);
    glVertex3f(-10.0, 15.0, 40.0);
    glEnd();

    //segitiga sekoci samping kiri tutup kanan
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, 31.0);
    glVertex3f(-15.0, 20.0, 35.5);
    glVertex3f(-15.0, 15.0, 35.5);
    glVertex3f(-10.0, 15.0, 31.0);
    glEnd();

    //segitiga sekoci samping kiri tutup kiri
    glBegin(GL_QUADS);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 20.0, 40.0);
    glVertex3f(-15.0, 20.0, 35.5);
    glVertex3f(-15.0, 15.0, 35.5);
    glVertex3f(-10.0, 15.0, 40.0);
    glEnd();

    //alas segitiga sekoci bagian kiri
    glBegin(GL_POLYGON);
    glColor3ub(245, 245, 223);
    glVertex3f(-10.0, 15.0, 31.0);
    glColor3ub(245, 245, 223);
    glVertex3f(-10.0, 15.0, 40.0);
    glColor3ub(245, 245, 223);
    glVertex3f(-15.5, 15.0, 35.0);
    glEnd();

    //alas segitiga sekoci bagian kanan
    /*glBegin(GL_POLYGON);
    glColor3ub(251, 127, 80);
    glVertex3f(-10.0, 15.0, -31.0);
    glColor3ub(245, 245, 223);
    glVertex3f(-10.0, 15.0, -40.0);
    glColor3ub(245, 245, 223);
    glVertex3f(-15.5, 15.0, -35.5);
    glEnd();*/

    //atas samping kiri
    glBegin(GL_QUADS);
    glColor3ub(254, 240, 245);
    glVertex3f(-75.0, 20.0, 30.0);
    glVertex3f(70.0, 20.0, 30.0);
    glVertex3f(70.0, 0.0, 30.0);
    glVertex3f(-75.0, 0.0, 30.0);
    glEnd();

    //bawah sampin kiri
    glBegin(GL_QUADS);
    glColor3ub(250, 99, 71);
    glVertex3f(-75.0, 0.0, 30.0);
    glVertex3f(70.0, 0.0, 30.0);
    glVertex3f(77.0, -12.0, 20.0);
    glVertex3f(-75.0, -12.0, 20.0);
    glEnd();

    //segitiga atas samping kiri
    glBegin(GL_QUADS);
    glColor3ub(245, 245, 223);
    glVertex3f(-120.0, 20.0, 0.0);
    glVertex3f(-75.0, 20.0, 30.0);
    glVertex3f(-75.0, 0.0, 30.0);
    glVertex3f(-110.0, 0.0, 0.0);
    glEnd();

    //segitiga bawah samping kiri
    glBegin(GL_QUADS);
    glColor3ub(188, 143, 142);
    glVertex3f(-110.0, 0.0, 0.0);
    glVertex3f(-75.0, 0.0, 30.0);
    glVertex3f(-75.0, -12.0, 20.0);
    glVertex3f(-100.0, -12.0, 0.0);
    glEnd();
}

void hilang(void)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    dasar();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    kapal_transparan();
    dasar();
    glPushMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void display(void)
{
    if (is_depth)
        tampil();
    else
        hilang();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case'w':
    case'W':
        glTranslatef(0.0, 0.0, 3.0);
        break;
    case'd':
    case'D':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case's':
    case'S':
        glTranslatef(0.0, 0.0, -3.0);
        break;
    case'a':
    case'A':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case'7':
        glTranslatef(0.0, 3.0, 0.0);
        break;
    case'9':
        glTranslatef(0.0, -3.0, 0.0);
        break;
    case'2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case'8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case'6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case'4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case'1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case'3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case'5':
        if (is_depth)
        {
            is_depth = 0;
            tampil();
        }
        else
        {
            is_depth = 1;
            hilang();
        }
        break;
    }
    display();
}

void idle()
{
    if (!mouseDown)
    {
        xrot == 0.3f;
        yrot == 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void ok()
{
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
}

void mouseMotion(int x, int y)
{
    ok();
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(20.5, -30.0, -170.0);
    glMatrixMode(GL_MODELVIEW);
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(1.5f);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1350, 1150);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TR Grafkom Kapal Quantum Of The Seas");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
