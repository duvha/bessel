#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QLabel>

#include "besselview.h"
#include "bessel.h"
#include "graph.h"

BesselView::BesselView(QWidget *parent)
	: QWidget(parent)
{
    bessel = new Bessel();
	QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *layout1 = new QVBoxLayout;
	QHBoxLayout *layout2 = new QHBoxLayout;

    slider = new QSlider(Qt::Vertical, this);
    slider->setRange(0, 99);
    slider->setValue(bessel->output());
    slider->setMinimumSize(slider->sizeHint());
	slider->setPageStep(1);
    layout1->addWidget(slider);

    label = new QLabel(this);
	label->setNum(slider->value());
    label->setMinimumSize(label->sizeHint());
    layout1->addWidget(label);
	
	graph = new Graph(this);
	sideBands(slider->value());
	graph->setMinimumSize(200, 100);
	layout2->addWidget(graph, 1);
	//layout2->addStretch();

	layout->addLayout(layout1);
	layout->addLayout(layout2);

    setLayout(layout);
	show();

    connect(slider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(sideBands(int)));
}

void BesselView::sideBands(int output)
{
    graph->setData(bessel->sideBands(output));
}

BesselView::~BesselView()
{
    delete slider;
    delete label;

    delete bessel;
    delete graph;
}
