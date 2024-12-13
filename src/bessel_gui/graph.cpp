#include <iostream>

#include <QPainter>
#include <QPen>

#include "graph.h"

Graph::Graph(QWidget *parent)
	: QWidget(parent)
{
	
}

Graph::~Graph()
{
}

std::vector<std::pair<double, double>> Graph::data()
{
	return m_data;
}

void Graph::setData(std::vector<std::pair<double, double>> data)
{
    m_data =data;
	
	update();
}

void Graph::paintEvent(QPaintEvent * /* event */)
{
	QPainter painter(this);
	painter.drawRect(rect().adjusted(0, 0, -1, -1));

	QPen greenPen, redPen;
	greenPen.setWidthF(0.1);
	greenPen.setColor(Qt::green);
	redPen.setWidthF(0.1);
	redPen.setColor(Qt::red);
	painter.setRenderHint(QPainter::Antialiasing, true);

	int range = data().size();
	if (range < 10) range = 10;

	painter.setViewport(0, 0, width(), height());
	painter.setWindow(-1, 0, range + 1, 1);
    for(std::vector<std::pair<double, double>>::iterator it = m_data.begin(); it != m_data.end(); ++it)
    {
        if (it->second >= 0)
        {
            painter.setPen(greenPen);
        }
        else
        {
            painter.setPen(redPen);
        }
        painter.drawLine(QLineF(it->first, 1.0, it->first, 1.0 - it->second));
    }
}
