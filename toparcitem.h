#ifndef WALLITEM_H
#define WALLITEM_H


class TopArcItem
{
public:
    TopArcItem();
    int getId() const;
    void setId(int value);

    double getFai() const;
    void setFai(double value);

    double getX() const;
    void setX(double value);

    double getY() const;
    void setY(double value);


    double getM_wanju() const;
    void setM_wanju(double value);

    double getN_zhouli() const;
    void setN_zhouli(double value);

private:
    int id;
    double fai; // 弧度制
    double x;
    double y;

    double M_wanju;
    double N_zhouli;
};

#endif // WALLITEM_H
