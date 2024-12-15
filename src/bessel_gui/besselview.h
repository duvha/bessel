#ifndef BESSELVIEW_H
#define BESSELVIEW_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QDial;
class QLabel;

class Bessel;
class Graph;

class BesselView : public QWidget
{
    Q_OBJECT
public:
    explicit BesselView(QWidget *parent = nullptr);
    ~BesselView();

public slots:
    void sideBands(int output);

private:
    QVBoxLayout *layout;
    QDial *dial;
    QLabel *label;
    Graph *graph;
	
	Bessel *bessel;
};

#endif // BESSELVIEW_H
