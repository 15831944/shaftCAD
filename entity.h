#ifndef ENTITY_H
#define ENTITY_H


class BottomItem{

public:

    BottomItem(){};
    ~BottomItem(){};
    int getId() const;
    void setId(int value);

    double getY() const;
    void setY(double value);

    double getAngle() const;
    void setAngle(double value);

    double getM_Wanju() const;
    void setM_Wanju(double value);

    double getQ_Zhouli() const;
    void setQ_Zhouli(double value);

    double getFai1() const;
    void setFai1(double value);

    double getFai2() const;
    void setFai2(double value);

    double getFai3() const;
    void setFai3(double value);

    double getFai4() const;
    void setFai4(double value);

private:

    int id;
    double y;
    double angle;
    double M_Wanju;
    double Q_Zhouli;

    double fai1;
    double fai2;
    double fai3;
    double fai4;

};

class WallItem{

private:
    int id;
    double M_wanju;
    double Q_zhouli;

    double fai1;
    double fai2;
    double fai3;
    double fai4;

public:
    WallItem(){};
    ~WallItem(){};

    int getId() const;
    void setId(int value);
    double getM_wanju() const;
    void setM_wanju(double value);
    double getQ_zhouli() const;
    void setQ_zhouli(double value);
    double getFai1() const;
    void setFai1(double value);
    double getFai2() const;
    void setFai2(double value);
    double getFai3() const;
    void setFai3(double value);
    double getFai4() const;
    void setFai4(double value);
};


#endif // ENTITY_H
