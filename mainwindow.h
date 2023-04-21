#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *m_label;
    QTimer *m_timer;
    int m_x;
    int m_y;
    int m_directionX;
    int m_directionY;

private slots:
    void moveHorizontally();
    void moveVertically();
};

#endif // MAINWINDOW_H
