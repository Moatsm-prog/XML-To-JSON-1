#include "../Headers/graph.h"
#include "ui_graph.h"

Graph::Graph(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Graph)
{
    ui->setupUi(this);
    QPixmap p("sample.dot.jpeg");
    ui->label->setPixmap(p);
}

Graph::~Graph()
{
    delete ui;
}
