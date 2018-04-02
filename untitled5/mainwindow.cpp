#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    enabled = false;
    graph = NULL;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonBuscar_clicked()
{

    QFile write("C:/Users/Usuario/Documents/NetBeansProjects/JavaApplicationTwitter/word.txt");
    if(!write.open(QIODevice::WriteOnly | QIODevice::Text)) {

        return;
    }
    QTextStream out(&write);
    out << ui->lineEditWord->text();
    write.close();

    system("java -jar C:/Users/Usuario/Documents/NetBeansProjects/JavaApplicationTwitter/dist/JavaApplicationTwitter.jar");

}

void MainWindow::on_pushButtonMostrar_clicked()
{

    QFile file("C:/Users/Usuario/Documents/NetBeansProjects/JavaApplicationTwitter/tweets.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {

        return;
    }

    QTextStream in(&file);

    QString line = in.readLine(); //se lee la linea
    int sizeDoc = line.size();
    QByteArray array = line.toLatin1();
    QString word = ""; //a esta variable se le ira agregando caracter por caracter lo leido en el txt
    char *author = array.data();
    for(int i = 0; i < sizeDoc; i++) {
        QChar charac(author[i]);
        word += charac;
        if(charac == " ") {
            QLabel *label11 = new QLabel(this);
            QLabel *label12 = new QLabel(this);
            QPixmap pixmap("C:/Users/Usuario/Documents/untitled5/Circle.png");
            label11->setPixmap(pixmap);
            label12->setText(word);
            label11->setGeometry(x,y,70,70);
            label12->setGraphicsEffect(x+25,y,70,70);
            label11->setScaledContents(true);
            label12->setScaledContents(true);
            graph->addV(word,label12);
            if(graph->get_Num_of_Vertex() >= 2){
                Vertex *starting = graph->get_Vertexes()[graph->get_Num_of_Vertex()-2];
                Vertex *end =graph->get_Vertexes()[graph->get_Num_of_Vertex()-1];
                graph->addEdg(starting, end, 0);
            }
            word = "";
            x= x+55;
            y = y+55;
            /*ui->textEditPrueba->append(word);
            word = "";*/
        }


    }
    file.close();
    enabled = true;
    update();
}

void MainWindow::paintEvent(QPaintEvent *e){
    QPainter brush(this);
    if(!enabled){
        for(int i=0; i<graph->get_Num_of_Vertex()-1;i++){
            brush.drawLine(starting_point[i], end_point[i]);
        }
        e->accept();
        return;
    }
    QPoint pStart;
    QPoint pEnd;
    for(int i=0; i<graph->get_Num_of_Vertex()-1; i++){
        pStart.setX(graph->get_Vertexes()[i]->posX()+10);
        pStart.setY(graph->get_Vertexes()[i]->posY()+40);
        pEnd.setX(graph->get_Vertexes()[i]->get_edges()[0]->get_endV()->posX()-10);
        pEnd.setY(graph->get_Vertexes()[i]->get_edges()[0]->get_endV()->posY()+5);
        starting_point.push_back(pStart);
        end_point.push_back(pEnd);
    }
    for(int i=0; i<starting_point.size();i++){
        brush.drawLine(starting_point[i], end_point[i]);
    }
    enabled = false;
    e->accept();
}
