#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    GLfloat alpha;
    GLfloat src;
    GLenum dest;

    bool alias;
    bool hint;
private:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    Ui::Widget *ui;

protected:
    void keyPressEvent(QKeyEvent *event);
};
#endif // WIDGET_H
