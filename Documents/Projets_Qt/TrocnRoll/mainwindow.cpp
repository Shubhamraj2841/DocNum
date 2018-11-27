#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //SetUp
    SetupFenetre();
    SetupMessages();
    SetupObjets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::Setup
 *
 * Fonction de SetUp
 */
void MainWindow::SetupFenetre()
{
    //Nom Fenetre
    this->setWindowTitle("Troc'nRoll");

    //Proportions Splitter
    int w = ui->splitter->width();
    ui->splitter->setSizes({w/4, 3*w/4});

    //Tests
    ui->myList->addItem("Test");
    ui->myList->addItem("Test2");
    ui->myList->addItem("Test3");
    ui->myList->addItem("Test4");

    //ui->webView->setUrl(QUrl(QStringLiteral("http://www.qt.io")));
}

/**
 * @brief MainWindow::SetupMessages
 */
void MainWindow::SetupMessages()
{
    //Récupération des anciens messages dans l'historique
    std::vector<Message> test = Message::getMessagesHist();

    qDebug() << test.size();

    for (auto &itMessages : test)
    {
        ui->myList->addItem(itMessages.getTitre());
    }
}

/**
 * @brief MainWindow::SetupObjets
 */
void MainWindow::SetupObjets()
{
    QFile file("Ressources\\objets.xml");
    if(!file.open(QFile::ReadWrite | QFile::Text))
    {
        qDebug() << "Cannot read file" << file.errorString();
        return;
    }
    //ZONE DE TESTS
    /*
    std::vector<std::vector<QString>> test_desc;
    std::vector<QString> test_param;
    test_param.push_back("Taille");
    test_param.push_back("4 m");
    test_desc.push_back(test_param);

    Objet test("Crayon", 2, test_desc);

    XmlObjetsWriter xmlWriter;
    xmlWriter.write("Ressources\\objets.xml", &test);
    */
    //FIN ZONE DE TESTS
    list_objets = new ListObjets;
    XmlObjetsReader xmlReader(list_objets);
    if (!xmlReader.read(&file)) qDebug() << "Parse error in file ";
    else qDebug() << list_objets->getSize();

    for(int i = 0; i < list_objets->getSize(); i++)
    {
        ui->Objets_List->addItem(list_objets->getObjetNom(i));
    }
}

void MainWindow::on_Objets_Btn_add_param_clicked()
{
    qDebug() << "aaa";
    FrameAddParam* frame = new FrameAddParam;
    connect(frame, SIGNAL(paramSupp(FrameAddParam*)), this, SLOT(suppParametre(FrameAddParam*)));
    ui->Objets_desc_Content->layout()->addWidget(frame);
    frames_param.insert(frame);
    qDebug() << frames_param.size();
}

void MainWindow::suppParametre(FrameAddParam* _widget)
{
    frames_param.erase(_widget);
    _widget->close();
}

void MainWindow::on_Objets_Btn_add_clicked()
{
    QString nom = ui->Objets_LineEdit_nom->text();
    if(!list_objets->exist(nom))
    {
        unsigned int quantite = ui->Objets_Spin_quantite->value();

        std::vector<std::vector<QString>> description;
        std::set<FrameAddParam*>::iterator it;
        for(it = frames_param.begin(); it != frames_param.end(); it++)
        {
            if((*it)->getNom() != "" && (*it)->getValeur() != "")
            {
                std::vector<QString> param;
                param.push_back((*it)->getNom());
                param.push_back((*it)->getValeur());
                description.push_back(param);
            }
        }
        Objet obj(nom, quantite, description);
        XmlObjetsWriter xmlWriter;
        xmlWriter.write("Ressources\\objets.xml", &obj);
        ui->Objets_List->addItem(nom);
    }
}
