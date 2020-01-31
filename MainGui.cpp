#include "MainGui.h"

MainGui::MainGui(QWidget *parent)
    : QMainWindow(parent)
{
    resize(GUI_WIDTH, GUI_HEIGHT);
    setMinimumSize(GUI_WIDTH, GUI_HEIGHT);
    setMaximumSize(GUI_WIDTH, GUI_HEIGHT);
    setWindowTitle(GUI_TITLE);
}

MainGui::~MainGui()
{
}

void MainGui::paintEvent(QPaintEvent *event)
{
    QPainter *painter = new QPainter;
    painter->begin(this);

    _world->draw(painter);
    _zoning->draw(painter);
    _wait_select->draw(painter);
    _resource_panel->draw(painter);
    _power_panel->draw(painter);
    _research_panel->draw(painter);
    _text_browser->draw(painter);

    painter->end();
}

void MainGui::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButtons b = event->buttons();
    int posX = event->x();
    int posY = event->y();

    if(b == Qt::LeftButton)
    {
        if(_world->inWorld(posX, posY))
        {
            _zoning = _world->getZoningWithPos(posX, posY);
        }
    }
    update();
}
