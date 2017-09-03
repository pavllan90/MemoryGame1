#ifndef GLCARD_H
#define GLCARD_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>


class glcard : public QGLWidget
{
    Q_OBJECT
public:
    glcard(QImage m);
    GLfloat xAr;
    QTimer* t;
    GLuint tex [2];
    QImage m1;
    void genTex();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent* event);
signals:
    void clicked();
public slots:
    void rot();
    
};

#endif // GLCARD_H
