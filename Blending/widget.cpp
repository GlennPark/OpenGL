#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    alpha = 0.5f;
    src = GL_SRC_ALPHA;
    dest = GL_ONE_MINUS_SRC_ALPHA;

    setWindowTitle("Opengl Blending");
    resize(600, 600);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::initializeGL()
{
    initializeOpenGLFunctions();
//    glClearColor(1.0, 1.0, 1.0, 1.0);
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
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_BLEND);
    glBlendFunc(src, dest);

//    glColor3f(0, 0, 1);
//    glRectf(-0.5, 0.8, 0.5, 0.0);

//    glColor4f(1, 0, 0, alpha);
//    glBegin(GL_TRIANGLES);
//    glVertex2f(0.0, 0.5);
//    glVertex2f(-0.5, -0.5);
//    glVertex2f(0.5, -0.5);
    if(alias)
    {
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_POLYGON_SMOOTH);
    }
    else
    {
        glDisable(GL_POINT_SMOOTH);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_POLYGON_SMOOTH);
    }

    glHint(GL_POINT_SMOOTH_HINT, hint?GL_NICEST:GL_FASTEST);
    glHint(GL_LINE_SMOOTH_HINT, hint?GL_NICEST:GL_FASTEST);
    glHint(GL_POLYGON_SMOOTH_HINT, hint?GL_NICEST:GL_FASTEST);

    glPointSize(10.0);
    glColor3f(1,1,1);
    glBegin(GL_POINTS);
    glVertex2f(0.0, 0.8);

    glEnd();

    glLineWidth(5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.8, 0.7);
    glVertex2f(0.8, 0.5);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(0.0, 0.4);
    glColor3f(0,1,0);
    glVertex2f(-0.4, 0.0);
    glColor3f(0,0,1);
    glVertex2f(0.0, -0.4);
    glColor3f(1,1,0);
    glVertex2f(0.4, 0.0);

    glEnd();

    glFlush();
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        alias = true;
    alpha += 0.1;
    break;
    case Qt::Key_Down:
        alias = false;
    alpha -= 0.1;
    break;
    case Qt::Key_Left:
        hint = true;
        src = GL_ONE;
        dest = GL_ZERO;
        break;
    case Qt::Key_Right:
        hint = false;
        src = GL_SRC_ALPHA;
        dest = GL_ONE_MINUS_SRC_ALPHA;

        break;
    }
    update();
}
