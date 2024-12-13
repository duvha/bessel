#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include <vector>

class Graph : public QWidget
{
	Q_OBJECT
	
public:
    explicit Graph(QWidget *parent);
    std::vector<std::pair<double, double>> data();
    void setData(std::vector<std::pair<double, double>> data);
	~Graph();

protected:
	void paintEvent(QPaintEvent * /*event*/ );
	
private:
    std::vector<std::pair<double, double>> m_data;
};

#endif // GRAPH_H
