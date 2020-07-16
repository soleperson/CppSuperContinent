#include "GUI_power_panel.h"

void GUI_power_panel::updatePowser()
{
    _powers[0] = displayNumber(research_points);
    _powers[1] = displayNumber(military_power);
    _powers[2] = displayNumber(civil_power);
}

void GUI_power_panel::draw(QPainter *painter)
{
    updatePowser();

    painter->setBrush(WHITE);
    for(int i=0; i<3; i++)
    {
        QRect rTitle(POWER_PANEL_START_X, POWER_PANEL_START_Y + i * POWER_PANEL_H_SIZE,
                     40, 20);
        painter->drawRect(rTitle);
        painter->drawText(rTitle, Qt::AlignCenter, _title[i]);

        QRect rPower(POWER_PANEL_START_X+40, POWER_PANEL_START_Y + i * POWER_PANEL_H_SIZE,
                     120,20);
        painter->drawRect(rPower);
        painter->drawText(rPower, Qt::AlignCenter, _powers[i]);
    }
}

GUI_power_panel::GUI_power_panel()
{

}