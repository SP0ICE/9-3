#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_label(new QLabel(this)), m_timer(new QTimer(this)),
      m_x(0), m_y(0), m_directionX(1), m_directionY(1)
{
    // Set the label's text and move it to the top-left corner of the central widget
    m_label->setText("Move me!");
    m_label->move(0, 0);

    // Create the central widget and set the label as its child
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    centralWidget->setLayout(new QVBoxLayout);
    centralWidget->layout()->addWidget(m_label);

    // Connect the timer to a slot that will move the label horizontally
    connect(m_timer, &QTimer::timeout, this, &MainWindow::moveHorizontally);

    // Create the "Horiz" button and connect it to the timer
    QPushButton *horizButton = new QPushButton("Horiz", centralWidget);
    connect(horizButton, &QPushButton::clicked, m_timer, [this]() {
        m_timer->start(10);
        m_directionX = 1;
    });

    // Create the "Vert" button and connect it to a slot that will move the label vertically
    QPushButton *vertButton = new QPushButton("Vert", centralWidget);
    connect(vertButton, &QPushButton::clicked, this, &MainWindow::moveVertically);

    // Add the buttons to the central widget's layout
    centralWidget->layout()->addWidget(horizButton);
    centralWidget->layout()->addWidget(vertButton);

    // Set the main window's size and show it
    resize(400, 300);
}

MainWindow::~MainWindow()
{
}

void MainWindow::moveHorizontally()
{
    m_x += m_directionX;

    // If the label goes out of bounds, reverse the direction
    if (m_x > centralWidget()->width() - m_label->width() || m_x < 0) {
        m_directionX = -m_directionX;
    }

    m_label->move(m_x, m_y);
}

void MainWindow::moveVertically()
{
    m_y += m_directionY;

    // If the label goes out of bounds, reverse the direction
    if (m_y > centralWidget()->height() - m_label->height() || m_y < 0) {
        m_directionY = -m_directionY;
    }

    m_label->move(m_x, m_y);
}
