#include "widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    polygonMode = GL_FILL;
    shadeMode = GL_FLAT;

    bDepthTest = GL_TRUE;
    bCullFace = GL_FALSE;
    setWindowTitle("OpenGL Pyramid3D");
    resize(600, 600);
}

Widget::~Widget()
{
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, (GLint)w, (GLint)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glShadeModel(GL_FLAT);

    if(bDepthTest)
    {
        glEnable(GL_DEPTH_TEST);
    }
    else
    {
        glDisable(GL_DEPTH_TEST);
    }

    if(bCullFace)
    {
        glEnable(GL_CULL_FACE);
    }
    else
    {
        glDisable(GL_CULL_FACE);
    }

    glFrontFace(bCcwFront ? GL_CCW:GL_CW);

    glPushMatrix();
    glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
    glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1,1,1);
    glVertex3f(0.0, 0.0, -0.8);
    glColor3f(1,0,0);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);

    glColor3f(1,1,0);
    glVertex2f(-0.5, -0.5);

    glColor3f(0,1,0);
    glVertex2f(0.5, -0.5);

    glColor3f(0,0,1);
    glVertex2f(0.5, 0.5);
    glEnd();

    glPopMatrix();

    glBegin(GL_POLYGON);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.1, -0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.9, -0.5);
    glVertex2f(0.1, -0.5);
    glEnd();

    glPushMatrix( );
     glTranslatef(-0.25f, 0.0f, 0.0f);
     // CCW
     glBegin(GL_POLYGON);
       glVertex2f(0.0, 0.5);
       glVertex2f(-0.4, -0.5);
       glVertex2f(0.4, -0.5);
     glEnd( );
     glTranslatef(1.0f, 0.0f, 0.0f);
     // CW
     glBegin(GL_POLYGON);
       glVertex2f(0.0, 0.5);
       glVertex2f(0.4, -0.5);
       glVertex2f(-0.4, -0.5);
     glEnd( );
     glPopMatrix( );
     glColor3f(1,1,1);
     glBegin(GL_POLYGON);
     glVertex2f(-0.5, 0.5);
     glVertex2f(-0.5, -0.5);
     glVertex2f(0.5, -0.5);
     glVertex2f(0.5, 0.5);
        glEnd();
    glFlush();
}

void Widget::keyPressEvent(QKeyEvent* event)
{
    switch(event->key())
    {
    case Qt::Key_Up:
//        bDepthTest = GL_TRUE;
    bCullFace = GL_TRUE;
        break;
    case Qt::Key_Down:
//        bDepthTest = GL_FALSE;
    bCullFace = GL_FALSE;
        break;
    case Qt::Key_Left:
//        bCullFace = GL_TRUE;
    bCcwFront = GL_TRUE;
        break;
    case Qt::Key_Right:
//        bCullFace = GL_FALSE;
    bCcwFront = GL_FALSE;
        break;

//    case Qt::Key_1:
//        yAngle +=2;
//        break;
//    case Qt::Key_2:
//        yAngle -=2;
//        break;
//    case Qt::Key_3:
//        xAngle +=2;
//        break;
//    case Qt::Key_4:
//        shadeMode = GL_SMOOTH;
////        xAngle -=2;
//        break;
//    case Qt::Key_5:
//        shadeMode = GL_FLAT;
////        zAngle +=2;
//        break;
//    case Qt::Key_6:
//        zAngle -=2;
//        break;
//    case Qt::Key_0:
//        xAngle = yAngle = zAngle = 0.0;
//        break;
    case Qt::Key_1:
    polygonMode = GL_POINT;
        break;
    case Qt::Key_2:
    polygonMode = GL_LINE;
        break;
    case Qt::Key_3:
    polygonMode = GL_FILL;
        break;
    case Qt::Key_4:
    shadeMode = GL_SMOOTH;
    case Qt::Key_5:
    shadeMode = GL_FLAT;
        break;
    }


//QString str = QString("Pyramid3D : x : %1, y : %2, z : %3").arg(xAngle).arg(yAngle).arg(zAngle);

QString str = QString("Culling3D : Cull : %1, Front : %2").arg(bCullFace).arg(bCcwFront);

setWindowTitle(str);
update();

}


