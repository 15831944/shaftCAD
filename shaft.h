

#ifndef SHAFT_H
#define SHAFT_H

#include "entity.h"
#include "toparcitem.h"
#include <vector>

class Shaft
{
public:
    Shaft();
    ~Shaft();

private:

    double halfCircleR; // 半圆拱半径, m
    double wallHeight; // 直墙高度,m
    double bottomArcR; // 底板反拱半径, m

    /*
     * 用于顶板外壁厚度计算的参数
     * parameters:
     * fc: 凝土轴心抗拉强度设计值， MN/m^2;
     * rou_min: 最小配筋率;
     * fy: 钢筋抗拉强度设计值，MN/m^2；
     * Vk: 结构安全系数;
     * Rn: 计算处井壁内半径;
     */
    double fc;
    double rou_min;
    double fy;
    double H; // 井筒埋深， m
    double Rn;
    double Pk1;

    //计算顶板内壁厚度
    double Kz; //荷载折减系数，0.81 - 1.00之间
    double topThickness; //顶板厚度
    double topKeyX; //顶板关键点个数

    // 底板厚度计算
    bool IsBottomArc; // 底板是否为拱形，false：底板为直线，true：底板为拱形

    //底板为拱形计算所需参数
    double lambda;

    //底板为直线时计算所需参数
    double bottomWidth; //底板宽度
    double bottomLength; //底板长度
    double elastic; // 弹性模量, E
    double k_elastic_coefficient; // 地基的弹性压缩系数
    double q_AverageLoad; // 均布荷载, kN/m
    int bottomKeyX; //关键点个数
    double protectThickness; // 保护层厚度
    double gangjinD; //钢筋直径
    double bottomThickness; //底板厚度

    // 直墙厚度计算
    double f0_InnerCircleHeight; //内圆矢高
    double l0_InnerCircleWidth; //内圆跨径
    double h1_wallHeight; //侧墙计算长度
    int stoneLevel; //围岩级别
    double B_TunnelWidth; // 隧道宽度
    double gamma0_StoneWeight; //围岩容重
    int wallKeyX; //直墙关键点个数
    double gamma_concreteWeight; //混凝土容重
    double wallThickness; //直墙厚度
    
    std::vector<BottomItem> mVecBottom;
    std::vector<TopArcItem> mVecTop;
    std::vector<WallItem> mVecWall;

    
public:

    void SetHalfCircleR(double value){halfCircleR = value;};
    double GetHalfCircleR() {return halfCircleR;};
    void SetWallHeight(double value){wallHeight = value;};
    double GetWallHeight() {return wallHeight;};
    void SetBottomArcR(double value){bottomArcR = value;};
    double GetBottomArcR() {return bottomArcR;};

    void SetH(const double value){H = value;};
    double GetH() const {return H;};

    void SetFc(const double value){fc = value;};
    double GetFc() const {return fc;};
    void SetRoumin(double roumin) {rou_min = roumin;};
    double GetRoumin() const {return rou_min;};
    void SetFy(double value) {fy = value;};
    double GetFy() const {return fy;};
    void SetRn(double value){Rn = value;};
    double GetRn() const {return Rn;};
    void SetPk1(double value){Pk1 = value;};
    double GetPk1() const {return Pk1;};

    void SetKz(double value) {Kz = value;};
    double GetKz() const {return Kz;};
    void SetLambda(double value) { lambda = value;};
    double Getlambda() const {return lambda;};

    void SetIsBottomArc(bool value) { IsBottomArc = value;};
    bool GetIsBottomArc() const {return IsBottomArc;};

    double getVk() const;
    void setVk(double value);

    double getQ_AverageLoad() const;
    void setQ_AverageLoad(double value);

    int getBottomKeyX() const;
    void setBottomKeyX(int value);

    double getProtectThickness() const;
    void setProtectThickness(double value);

    double getGangjinD() const;
    void setGangjinD(double value);

    double getBottomThickness() const;
    void setBottomThickness(double value);

    double getTopThickness() const;
    void setTopThickness(double value);

    double getF0_InnerCircleHeight() const;
    void setF0_InnerCircleHeight(double value);

    double getL0_InnerCircleWidth() const;
    void setL0_InnerCircleWidth(double value);

    double getH1_wallHeight() const;
    void setH1_wallHeight(double value);

    int getStoneLevel() const;
    void setStoneLevel(int value);

    double getB_TunnelWidth() const;
    void setB_TunnelWidth(double value);

    double getGamma0_StoneWeight() const;
    void setGamma0_StoneWeight(double value);

    int getWallKeyX() const;
    void setWallKeyX(int value);

    double getGamma_concreteWeight() const;
    void setGamma_concreteWeight(double value);

    double getWallThickness() const;
    void setWallThickness(double value);

    // 获取顶板、底板、直墙厚度
    double GetTopThickness();
    double GetBottomThickness();
    double GetWallThickness();

    double getElastic() const;
    void setElastic(double value);

    double getBottomWidth() const;
    void setBottomWidth(double value);

    double getBottomLength() const;
    void setBottomLength(double value);

    double getK_elastic_coefficient() const;
    void setK_elastic_coefficient(double value);

    double getTopKeyX() const;
    void setTopKeyX(double value);

    std::vector<TopArcItem> getVecTop() const;
    void setVecTop(const std::vector<TopArcItem> &vecTop);
    
    std::vector<WallItem> getVecWall() const;
    void setVecWall(const std::vector<WallItem> &vecWall);
    
    std::vector<BottomItem> getVecBottom() const;
    void setVecBottom(const std::vector<BottomItem> &vecBottom);

private:
    bool IsDeepMai();
    
    double GetTopOutterThickness();
    double GetTopInngerThickness();

    std::vector<BottomItem> InitBottomVec();

    // 底板为拱形时计算底板厚度
    double GetArcBottomThickness();
    // 底板为直线时获取底板厚度
    double GetLineBottomThickness();


};

#endif // SHAFT_H
