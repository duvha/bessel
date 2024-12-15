#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDial>
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

    dial = new QDial(this);
    dial->setRange(0, 99);
    dial->setValue(bessel->output());
    dial->setMinimumSize(dial->sizeHint());
	dial->setPageStep(1);
    layout1->addWidget(dial);

    label = new QLabel(this);
	label->setNum(dial->value());
    label->setMinimumSize(label->sizeHint());
    layout1->addWidget(label);
	
	graph = new Graph(this);
	sideBands(dial->value());
	graph->setMinimumSize(200, 100);
	layout2->addWidget(graph, 1);
	//layout2->addStretch();

	layout->addLayout(layout1);
	layout->addLayout(layout2);

    setLayout(layout);
	show();

    connect(dial, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
    connect(dial, SIGNAL(valueChanged(int)), this, SLOT(sideBands(int)));
}

void BesselView::sideBands(int output)
{
    graph->setData(bessel->sideBands(output));
}

BesselView::~BesselView()
{
    delete dial;
    delete label;

    delete bessel;
    delete graph;
}
