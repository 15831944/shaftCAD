#include "shaft.h"
#include "calculate.h"
#include "entity.h"
#include "toparcitem.h"
#include <iostream>


Shaft::Shaft()
{

};

Shaft::~Shaft(){}

std::vector<BottomItem> Shaft::getVecBottom() const
{
    return mVecBottom;
}

void Shaft::setVecBottom(const std::vector<BottomItem> &vecBottom)
{
    mVecBottom = vecBottom;
}

std::vector<WallItem> Shaft::getVecWall() const
{
    return mVecWall;
}

void Shaft::setVecWall(const std::vector<WallItem> &vecWall)
{
    mVecWall = vecWall;
}

std::vector<TopArcItem> Shaft::getVecTop() const
{
    return mVecTop;
}

void Shaft::setVecTop(const std::vector<TopArcItem> &vecTop)
{
    mVecTop = vecTop;
}

double Shaft::getTopKeyX() const
{
    return topKeyX;
}

void Shaft::setTopKeyX(double value)
{
    topKeyX = value;
}

double Shaft::getK_elastic_coefficient() const
{
    return k_elastic_coefficient;
}

void Shaft::setK_elastic_coefficient(double value)
{
    k_elastic_coefficient = value;
}

double Shaft::getBottomLength() const
{
    return bottomLength;
}

void Shaft::setBottomLength(double value)
{
    bottomLength = value;
}

double Shaft::getBottomWidth() const
{
    return bottomWidth;
}

void Shaft::setBottomWidth(double value)
{
    bottomWidth = value;
}

double Shaft::getElastic() const
{
    return elastic;
}

void Shaft::setElastic(double value)
{
    elastic = value;
}

double Shaft::getWallThickness() const
{
    return wallThickness;
}

void Shaft::setWallThickness(double value)
{
    wallThickness = value;
}

double Shaft::getGamma_concreteWeight() const
{
    return gamma_concreteWeight;
}

void Shaft::setGamma_concreteWeight(double value)
{
    gamma_concreteWeight = value;
}

int Shaft::getWallKeyX() const
{
    return wallKeyX;
}

void Shaft::setWallKeyX(int value)
{
    wallKeyX = value;
}

double Shaft::getGamma0_StoneWeight() const
{
    return gamma0_StoneWeight;
}

void Shaft::setGamma0_StoneWeight(double value)
{
    gamma0_StoneWeight = value;
}

double Shaft::getB_TunnelWidth() const
{
    return B_TunnelWidth;
}

void Shaft::setB_TunnelWidth(double value)
{
    B_TunnelWidth = value;
}

int Shaft::getStoneLevel() const
{
    return stoneLevel;
}

void Shaft::setStoneLevel(int value)
{
    stoneLevel = value;
}

double Shaft::getH1_wallHeight() const
{
    return h1_wallHeight;
}

void Shaft::setH1_wallHeight(double value)
{
    h1_wallHeight = value;
}

double Shaft::getL0_InnerCircleWidth() const
{
    return l0_InnerCircleWidth;
}

void Shaft::setL0_InnerCircleWidth(double value)
{
    l0_InnerCircleWidth = value;
}

double Shaft::getF0_InnerCircleHeight() const
{
    return f0_InnerCircleHeight;
}

void Shaft::setF0_InnerCircleHeight(double value)
{
    f0_InnerCircleHeight = value;
}

double Shaft::getTopThickness() const
{
    return topThickness;
}

void Shaft::setTopThickness(double value)
{
    topThickness = value;
}

double Shaft::getBottomThickness() const
{
    return bottomThickness;
}

void Shaft::setBottomThickness(double value)
{
    bottomThickness = value;
}

double Shaft::getGangjinD() const
{
    return gangjinD;
}

void Shaft::setGangjinD(double value)
{
    gangjinD = value;
}

double Shaft::getProtectThickness() const
{
    return protectThickness;
}

void Shaft::setProtectThickness(double value)
{
    protectThickness = value;
}

int Shaft::getBottomKeyX() const
{
    return bottomKeyX;
}

void Shaft::setBottomKeyX(int value)
{
    bottomKeyX = value;
}

double Shaft::getQ_AverageLoad() const
{
    return q_AverageLoad;
}

void Shaft::setQ_AverageLoad(double value)
{
    q_AverageLoad = value;
}


/* 判断深埋、浅埋
 *
 * parameters:
 * H: 井筒埋深
 * a：井筒宽度的二分之一
 * height：井筒高度
 * fai: 内摩擦角
 * Rc: 岩石的单轴抗压强度
 */
bool Shaft::IsDeepMai(){
    return true;
}


/*
 * 顶板外壁厚度计算
 * parameters:
 * fc: 凝土轴心抗拉强度设计值， MN/m^2;
 * rou_min: 最小配筋率;
 * fy: 钢筋抗拉强度设计值，MN/m^2；
 * Vk: 结构安全系数;
 * Rn: 计算处井壁内半径;
 * gamma0: 结构重要性系数；
 */

double Shaft::GetTopOutterThickness(){
    double fs = rou_min * fy + fc;

    double t = Rn * (sqrt(fs/ (fs - 3.24 * Pk1))  - 1);
std::cout << "Top outter thickness: " << t << std::endl;
    return t;
}

/*
 * 顶板内壁厚度设计
 * parameters:
 * kz: 荷载折减系数
 */
double Shaft::GetTopInngerThickness(){
    double fs = rou_min * fy + fc;
    std::cout << "fs: " << fs << std::endl;
    double Pk2 = 0.01 * H * Kz;
    double t = Rn * (sqrt(fs/ (fs - (3.24 * Pk2))) - 1);
    std::cout << "Top inner thickness: " << t << std::endl;
    return t;
}

double Shaft::GetTopThickness(){
    topThickness = GetTopInngerThickness() + GetTopOutterThickness();
    return topThickness;
}

double Shaft::GetBottomThickness(){
    if(IsBottomArc == true){
        printf("==========Get arc bottom thickness========\n");
        return GetArcBottomThickness();
    }else{
        printf("==========Get line bottom thickness========\n");

        return GetLineBottomThickness();
    }
}

double Shaft::GetArcBottomThickness(){
    return lambda * GetTopOutterThickness();
}


std::vector<BottomItem> Shaft::InitBottomVec(){

    std::vector<BottomItem> mVecItems(bottomKeyX);

    double M0 = q_AverageLoad * bottomLength * bottomLength / 12;
    double Q0 = q_AverageLoad * bottomLength / 2;
    std::cout << "M0: " << M0 << "  Q0: " << Q0 << std::endl;

    double I = bottomWidth * bottomLength * bottomLength / 12;

    std::cout << "I: " << I << std::endl;
    double K = bottomWidth * k_elastic_coefficient;

    std::cout << "K: " << K << std::endl;
    double a = pow(K/(4 * elastic * I), 0.25);

    std::cout << "a: " << a << std::endl;

    double y0 = 0, angle0 = 0;

    for(int i = 0; i < bottomKeyX; i++){
        mVecItems[i].setId(i);
    }

    for(BottomItem & it : mVecItems){

        // ch 双曲余弦 cosh()， sh 双曲正弦 sinh()
        double tmp = a * it.getId();

        double fai1 = cosh(tmp) * cos(tmp);
        double fai2 = cosh(tmp) * sin(tmp) + sinh(tmp) * cos(tmp);
        double fai3 = sinh(tmp) * sin(tmp);
        double fai4 = cosh(tmp) * sin(tmp) - sinh(tmp) * cos(tmp);

        fai1 = round(fai1);
        fai2 = round(fai2 * 1000) / 1000;
        fai3 = round(fai3 * 100000) / 100000;
        fai4 = round(fai4 * 100000) / 100000;

        it.setFai1(fai1);
        it.setFai2(fai2);
        it.setFai3(fai3);
        it.setFai4(fai4);

        double y = (y0 * fai1) + (angle0 * fai2 / (2 * a)) -
                (2 * M0 * pow(a, 3)* fai3 / K) -
                (a * Q0 * fai4 / K) + (q_AverageLoad * (1 - fai1) / K);
        double angle = 0 - (y0 * a * fai4) + (angle0 * fai1)-
                (2 * M0 * pow(a, 3) * fai2 / K) -
                (2 * a * a * Q0 * fai3 / K) +
                (a * q_AverageLoad * fai4 / K);
        double M = (y0 * K * fai3 / (2*a*a)) +
                (angle0 * K *fai4 / (4 * pow(a,3))) +
                (M0 * fai1) + (Q0 * fai2 / (2 * a)) -
                (q_AverageLoad * fai3 / (2*a*a));
        double Q = (y0 * K * fai2 / (2 * a)) +
                (angle0 * K * fai3 / (2 * a *a)) -
                (M0 * a * fai4) + (Q0 * fai1) - (q_AverageLoad * fai2 / (2 * a));

        M = round(M*1000)/1000;
        Q = round(Q*1000) / 1000;

        it.setY(y);
        it.setAngle(angle);
        it.setM_Wanju(M);
        it.setQ_Zhouli(Q);

        std::cout <<"X: " << it.getId() <<" fai1: " <<
                    it.getFai1() << "   fai2: " << it.getFai2()
                 << "   fai3: " << it.getFai3() << "    fai4: " <<it.getFai4() << std::endl;

        std::cout << "X: " <<it.getId() << "    y:" << it.getY()
                  << "  angle: " << it.getAngle() << "  M: " <<it.getM_Wanju()
                  <<"   Q: " << it.getQ_Zhouli() << std::endl;
    }

    mVecBottom = mVecItems;
    return mVecItems;
}

/*
 * 底板为直线时计算底板厚度
 * parameters：
 *
 */
double Shaft::GetLineBottomThickness(){

    std::vector<BottomItem> mVecItems = InitBottomVec();

    double maxM = mVecItems[0].getM_Wanju();

    for(BottomItem it:mVecItems){
        if(it.getM_Wanju() > maxM){
            maxM = it.getM_Wanju();
        }
    }

    double A_Square = bottomWidth * bottomThickness;
    double h1 = protectThickness + (0.5 * gangjinD);
    double h0 = bottomThickness - h1;

    double As = maxM / (0.9 * fy * h0);
    double rou = As / A_Square;
    printf("h0: %lf     maxM: %lf   As: %lf     rou: %lf\n", h0, maxM, As, rou);
    if(rou > rou_min){
        rou = 0.004; // 若不满足
        double avaliableH = (sqrt(pow(h1,2) + (4 * maxM / (0.004 * 0.9 * fy * bottomWidth)) - h1 )) / 2;
        return avaliableH + h1;
    }else{
        return bottomThickness;
    }

}

double Shaft::GetWallThickness(){

    std::cout << "============1) Calculate Geo Structure==========" << std::endl;

    double d0 = topThickness;
    double dc = d0;
    double R0 = f0_InnerCircleHeight;
    double R = R0 + (d0 * 0.5);
    double sin_fain = (l0_InnerCircleWidth * 0.5) / (R - (d0 * 0.5));

    double l = l0_InnerCircleWidth + dc;
    double f = dc * 0.5 + f0_InnerCircleHeight;

    double l1 = 2 * d0 + l0_InnerCircleWidth;
    double f1 = f0_InnerCircleHeight + d0;
    double R1 = R0+d0;

    std::cout << "d0: " << d0<< "   dc: " << dc << "    R0:"
              << R0 << "    l1: " << l1 << "    f1: " <<f1<<"   R1: " << R1<< std::endl;

    std::cout << "============End 1)==========" << std::endl;

    std::cout << "============2) Calculate Change Unit==========" << std::endl;

    double fain = asin(sin_fain);
    double cos_fain = cos(fain);
    fain = round(fain*100)/100; //fain 保留两位小数
    double K0 = (1- cos_fain) / sin_fain;
    double k1 = fain - sin_fain;
    double K1 = (1- cos_fain - (0.5* pow(sin_fain, 2))) / sin_fain;
    double k2 = (1.5 * fain) - (2 * sin_fain) + (0.5 * sin_fain * cos_fain);
    double K2 = (0.333333 - cos_fain + pow(cos_fain, 2) - (pow(cos_fain, 3) / 3)) / sin_fain;
    double I0 = pow(d0, 3) / 12;
    double In = I0;
    double ksai = 1 - (I0 / In);

    printf("I0: %lf, ksai: %lf\n", I0, ksai);
    printf("K0: %lf\nk1: %lf , K1: %lf\nk2: %lf , K2: %lf\n", K0, k1, K1, k2,K2);

    double delta11 = (2 * R * (fain - (ksai * K0))) / (elastic * I0);
    double delta12 = (2* pow(R,2) * (k1 - (ksai * K1))) / (elastic * I0);
    double delta22 = (2 * pow(R,3) * (k2 - (ksai * K2))) / (elastic * I0);

    double delta21 = delta12;
    std::cout << "delta11: " << delta11 << "    delta12: " << delta12 << "  delta22: " << delta22 << std::endl;
    std::cout << "============End 2)==========" << std::endl;

    std::cout << "============3) Calculate Arc Change Load==========" << std::endl;
    double i = 0.1;
    if( B_TunnelWidth >= 5) i = 0.1;
    else i = 0.2;
    std::cout << "stone level: " << stoneLevel << std::endl;
    double h2 = 0.45 * pow(2, stoneLevel-1) * ((B_TunnelWidth - 5) * i + 1);
    double Hp = 2 * h2;

    double q1 = gamma0_StoneWeight * h2;
    double e = 0.1 * q1;
    double q2 = 2;
    double q3 = gamma0_StoneWeight * d0;
    double q = q1+q2+q3;

    std::cout << "q: " << q<< std::endl;

    double a1 = (fain - (sin_fain * cos_fain)) / 4;
    double A1 = (2 - (3 * cos_fain) + pow(cos_fain,3)) / (6 * sin_fain);
    double a2 = 0.5 * ((fain * 0.5) - (0.5 * sin_fain * cos_fain) - (pow(sin_fain, 3) / 3));
    double A2 = (0.666666 - cos_fain + (pow(cos_fain, 3) * 0.333333) - (pow(sin_fain,4)*0.25)) / (2*sin_fain);

    double delta1q = - (2 * q * pow(R,3) * (a1-(ksai * A1)) / (elastic * I0));
    double delta2q = - (2 * q * pow(R,4) * (a2 - (ksai * A2)) / (elastic * I0));

    double a3 = 0.25 * ((3 * fain) - (4 * sin_fain) + (sin_fain * cos_fain));
    double A3 = (0.333333 - cos_fain + pow(cos_fain, 2) - (pow(cos_fain,3) * 0.333333))
            / (2 * sin_fain);
    double a4 = 0.5 * ((2.5 * fain) - (4 * sin_fain) + (1.5 * sin_fain * cos_fain) + (pow(sin_fain,3) / 3));
    double A4 = (7 - (4 * cos_fain) - (pow(sin_fain, 2) * 6) - (pow(cos_fain, 3) * 4) + pow(cos_fain, 4)) / (8 * sin_fain);

    double delta1e = - (2 * e * pow(R,3) * (a3-(ksai * A3)) / (elastic * I0));
    double delta2e = - (2 * e * pow(R,4) * (a4-(ksai * A4)) / (elastic * I0));

    double delta1p = delta1q + delta1e;
    double delta2p = delta2q + delta2e;

    std::cout << "a1  A1 : " << a1 << " "<< A1  << std::endl;
    std::cout << "a2  A2 : " << a2 << " "<< A2  << std::endl;
    std::cout << "a3  A3 : " << a3 << " "<< A3  << std::endl;
    std::cout << "a4  A4 : " << a4 << " "<< A4  << std::endl;

    std::cout << "delta 1p = delta 1q + delta 1e : " << delta1p << " =  " << delta1q << "+" << delta1e << std::endl;
    std::cout << "delta 2p = delta 2q + delta 2e : " << delta2p << " =  " << delta2q << "+" << delta2e << std::endl;

    double gen2 = round(sqrt(2) * 1000) / 1000;
    double pi = asin(0.5) * 6;

    double a9 = (1.5 - (gen2 * sin_fain) - (gen2 * cos_fain) + (sin_fain * cos_fain)) /
            (3 * (1 - (2 * pow(cos_fain, 2))));
    double A9 = ((gen2 / 6) - (gen2 * pi / 8) + (fain * gen2 / 2) + cos_fain - (0.5 * gen2 * pow(sin_fain,2)) - (2 * pow(cos_fain, 3) / 3)) /
            (3 * sin_fain * (1 - (2 * pow(cos_fain,2))));
    double a10 = (1.5 + (gen2 * 0.333333) - (gen2 * pi * 0.125) +
                  (gen2 * fain * 0.5) - ((1+gen2) * sin_fain)
                  - (gen2 * cos_fain) - (gen2 * 0.5 * pow(sin_fain,2))
                  + ((gen2 * 0.5 + 1) * sin_fain * cos_fain) + (2 * pow(sin_fain,3) / 3)
                  ) / (3 * (1 - (2 * pow(cos_fain, 2))));
    double A10 = (0.458333 + (gen2 * 0.1666666) - (gen2 * pi * 0.125) + (gen2 * fain * 0.5) + cos_fain -
                  (0.5 * (1+gen2) * pow(sin_fain,2)) - (0.5 * gen2 * sin_fain * cos_fain) -
                  (0.5 * gen2 * pow(sin_fain, 3)) -
                  (0.333333 * (2+ gen2) * pow(cos_fain,3)) + (0.5 * pow(sin_fain, 4))) /
            (3 * sin_fain * (1 - (2 * pow(cos_fain,2))));

    std::cout << "a9  A9 : " << a9 << " "<< A9  << std::endl;
    std::cout << "a10  A10 : " << a10 << " "<< A10  << std::endl;


    double sigmaN ;

    // 只记录系数 sigman的系数
    double delta1sigmaN = - (((2 * pow(R ,3)) * (a9 - (ksai * A9))) / (elastic * I0));
    double delta2SigmaN = - (((2 * pow(R, 4)) * (a10 - (ksai * A10))) / (elastic * I0));

    std::cout <<"delta 1 sigma: " << delta1sigmaN << "      delta 2 sigma: " << delta2SigmaN<<std::endl;
    std::cout << "============End 3)==========" << std::endl;


    std::cout << "============4) Calculate Wall Top Move==========" << std::endl;
    double a = pow(140000/(4 * elastic * I0), 0.25);
    a = round(a*100)/100;
    // h1 = 钢筋直径 * 0.5 + 保护层厚度
    double lambda_changeHeight = a * h1_wallHeight;
    double A = 6 / (pow(a, 3) * pow(dc, 3));

    std::cout <<"aplha: " << a  << "    lambda: " << lambda_changeHeight<< "    A: " << A << std::endl;


    double chLambda = cosh(lambda_changeHeight), cosLambda = cos(lambda_changeHeight),
            shLambda = sinh(lambda_changeHeight), sinLambda = sin(lambda_changeHeight);

    double fai1lambda = chLambda * cosLambda,
            fai2lambda = (chLambda * sinLambda) + (shLambda * cosLambda),
//            fai3lambda = shLambda * sinLambda,
            fai3lambda = chLambda * sinLambda,
            fai4lambda = (chLambda * sinLambda) - (shLambda * cosLambda),
            fai9lambda = 0.5 * (pow(chLambda, 2) + pow(cosLambda, 2)),
            fai10lambda = 0.5 * ((shLambda * chLambda) - (sinLambda * cosLambda)),
            fai11lambda = 0.5 * ((shLambda * chLambda) + (sinLambda * cosLambda)),
//            fai12lambda = 0.5 * (pow(shLambda,2) - pow(sinLambda,2)),
            fai12lambda = 0.5 * (pow(chLambda,2) - pow(sin_fain, 2)),
//            fai13lambda = 0.5 * (pow(chLambda,2) + pow(sinLambda, 2)),
            fai13lambda = 0.5 * (pow(shLambda,2) + pow(sin_fain, 2)),
//            fai14lambda = 0.5 * pow(chLambda - cosLambda, 2),
            fai14lambda = 0.5 * (pow(chLambda,2) - pow(cosLambda, 2)),
            fai15lambda = 0.5 * (shLambda + sinLambda) * (chLambda - cosLambda);

    printf("fai1 -fai4, fai9 - fai 15: \n %lf  %lf  %lf  %lf \n %lf  %lf  %lf  %lf  %lf"
           " %lf  %lf\n", fai1lambda, fai2lambda, fai3lambda, fai4lambda,
            fai9lambda, fai10lambda, fai11lambda,fai12lambda,fai13lambda,fai14lambda,
           fai15lambda);

    double mother = 1.4e5; // 分母， 1.4 * 10^5
    double beta1 = 4 * pow(a, 3) * ((fai12lambda * A + fai11lambda) / (fai10lambda * A + fai9lambda) ) / mother;
    double beta2 = 2 * pow(a, 2) * ((fai11lambda * A + fai13lambda) / (fai10lambda * A + fai9lambda)) / mother;
    double u1 = beta2,
            u2 = 2 * a * ((fai13lambda * A + fai10lambda) / (fai10lambda * A + fai9lambda )) / mother;
    double beta3 = 0.2 * pow(a, 3) * ( (fai1lambda * A) / (fai10lambda * A + fai9lambda)) / mother;
    double u3 = 0.1 * pow(a, 2) * ( (fai2lambda * A) / (fai10lambda * A + fai9lambda)) / mother;
    double betaNe = - (a * ( (fai3lambda * A + fai4lambda) / (fai10lambda * A + fai9lambda) ) * e / mother);
    double uNe = - ((fai15lambda * A + fai14lambda) / (fai10lambda * A + fai9lambda)) * e / mother;

    std::cout << "beta 1-3 : " << beta1 << " " <<beta2 << " " << beta3 << std::endl;
    std:: cout << "u1 - 3: " << u1 << " "<< u2 <<"  "<< u3 << std::endl;
    std::cout << "beta ne: "<< betaNe << "  u ne: " << uNe <<std::endl;


    double Vnp0 = q * l * 0.5;
    double Qnp0 = - (e * f);
    double Mnp0 = - ( (0.125 * q * l * l) + (0.5 * e * f * f) );

    // 记录 Sigma N 的系数
    double MnSigma0 = (pow(R, 2) * (pow(cos_fain,2) - pow(sin_fain,2) + (gen2 * sin_fain) - (gen2 * cos_fain)))/
            (3 * (1 - (2 * pow(cos_fain,2))));
    double QnSigma0 = (R * ((gen2 / 3) - cos_fain + (2 * pow(cos_fain,3) / 3)))/
            (1 - (2 * pow(cos_fain,2)));
    double VnSigma0 = (R * ((gen2 / 3) - (sin_fain / 3) - (2 * sin_fain *pow(cos_fain,2) / 3)))/
            (1 - (2 * pow(cos_fain,2)));
    printf("Vnp0: %lf , Qnp0: %lf , Mnp0: %lf \n", Vnp0, Qnp0, Mnp0);
    printf("MnSigma: %lf , QnSigma: %lf , VnSigma: %lf\n", MnSigma0, QnSigma0, VnSigma0);

    // 边墙自重
    double Vc = gamma_concreteWeight * dc * h1_wallHeight;

    double a11 = 2 * beta1 + delta11;
    double a12 = 2 * (f * beta1 + beta2) + delta12;
    double a21 = a12,
            a22 = delta22 + (2 * u2) + (4 * f * beta2) + (2 * f * f *beta1);

    printf("Vc: %lf \n", Vc);
    std::cout << "a11: " << a11 << "  a12: " << a12 <<"   a22: " << a22 << std::endl;

    // a1p 中的常数项
    double a1pNumber = delta1p + (2 * beta1 * Mnp0) + (2 * beta2 * Qnp0) +
            (2 * Vnp0 * beta3) + (2 * Vc * beta3) + (2 * betaNe);
    double a1pSigma = delta1sigmaN + (2 * beta1 * MnSigma0) + (2 * beta2 * QnSigma0) + (2 * beta3 * VnSigma0);

    double a2pNumber = delta2p + (2 * u1 * Mnp0) + (2 * u2 *Qnp0) + (2 * u3 * (Vnp0 + Vc)) + (2 * uNe)+
            (2 * f * Mnp0 * beta1) + (2 * f * Qnp0 * beta2) + (2 * f * (Vnp0 + Vc) * beta3) + (2 * f * betaNe);
    double a2pSigma = delta2SigmaN + (2 * u1 * MnSigma0) + (2 * u2 * QnSigma0) +
            (2 * u3 * VnSigma0) + (2 * f * beta1 * MnSigma0) + (2 * f * beta2 * QnSigma0)+
            (2 * f * beta3 * VnSigma0);


    printf("a1p = %lf + %lf sigma\na2p = %lf + %lf sigma\n", a1pNumber, a1pSigma, a2pNumber, a2pSigma);
    std::cout << "a1p number: " << a1pNumber << "  a1p sigma: " << a1pSigma <<
                 "  a2p number: " << a2pNumber << "  a2p sigma: " << a2pSigma << std::endl;

    // 将 U0 代入第三个式子中分别得到 X1, X2, sigmaN, 常数项系数
    double u0X1 = mother * sin_fain * u1;
    double u0X2 = mother * sin_fain * (f * u1 + u2);
    double u0Sigma = mother * sin_fain * (u1 * MnSigma0 + (u2 * QnSigma0) + (u3 * VnSigma0)) - 1;
    double u0Number = mother * sin_fain * (u1 * Mnp0 + (u2 * Qnp0) + (u3 * (Vnp0 + Vc)) + uNe);

    std::cout << "u0X1: " << u0X1 << "  u0X2: " << u0X2 << "    u0Sigma: " << u0Sigma << "  u0Number: " <<u0Number <<std::endl;

    /*
     * 用克拉默法则解非齐次线性方程组
     * a11 X1 + a12 X2 + a1pSigma SigmaN + a1pNumber = 0;
     * a21 X1 + a22 X2 + a2pSigma SigmaN + a2pNumber = 0;
     * u0X1 X1 + u0X2 X2 + u0Sigma SigmaN + u0Number = 0;
     *
     * 转换为线性非齐次方程组为
     * a11 X1 + a12 X2 + a1pSigma SigmaN = - a1pNumber;
     * a21 X1 + a22 X2 + a2pSigma SigmaN = - a2pNumber;
     * u0X1 X1 + u0X2 X2 + u0Sigma SigmaN = - u0Number;
     *
     */

    double matrix[4][5] = {0 , 0, 0, 0, 0,
                          0, a11, a12, a1pSigma, _chgsign(a1pNumber),
                          0, a21, a22, a2pSigma, _chgsign(a2pNumber),
                          0, u0X1, u0X2, u0Sigma, _chgsign(u0Number)};

    double * result = SolveEquation(matrix);
    double X1 = * result, X2 = *(result + 1) ;
    sigmaN = * (result + 3);


    std::cout << "X1: " << X1 << "   X2: " << X2 << "    SigmaN: " << sigmaN << std::endl;



    double u0 = u0X1 * X1 + (u0X2 * X2) + (u0Sigma * sigmaN) + u0Number;
    double beta0 = beta1 * X1 + (X2 * (f*beta1 + beta2)) + ((MnSigma0 * sigmaN + Mnp0) * beta1) +
            ((QnSigma0 * sigmaN + Qnp0) * beta2) + ((VnSigma0 * sigmaN + Vnp0 + Vc) * beta3) + betaNe;

    std::cout << "u0: " << u0 << "   beta0: " << beta0 <<std::endl;


    // 计算拱圈界面内力
    std::vector<TopArcItem> mVecItems(topKeyX);

    for(int i = 0; i < topKeyX; i++){
        mVecItems[i].setId(i);
        // fai = pi/2 * i/(x-1)
        mVecItems[i].setFai((pi/2 )* (i/(topKeyX - 1)));
    }

    std::cout << "========== 7) Top Arc Item============" << std::endl;

    for(TopArcItem & it: mVecItems){

        double x = R * sin(it.getFai()), y = R - (R * cos(it.getFai()));
        it.setX(x);
        it.setY(y);

        double M = X1 + (X2 * y) - (q * x *x * 0.5) - (0.5 * e * y * y),
                N = X2 * cos(it.getFai()) + (q * x * sin(it.getFai())) - (e * y * cos(it.getFai()));
        it.setM_wanju(M);
        it.setN_zhouli(N);

        std::cout << "Id : " << it.getId() << " x: " << x << "  y: " << y
                  << "  X1: " << X1 << "    M: " << it.getM_wanju()
                  <<"     N: " << it.getN_zhouli() << std::endl;
    }

    mVecTop = mVecItems;
    std::cout << "==========End Top Arc Item============" << std::endl;
    
    std::cout << "========== 7) Wall Item============" << std::endl;
    double M0 = X1 + (f * X2) + Mnp0 + (MnSigma0 * sigmaN),
            Q0 = X2 + Qnp0 + (QnSigma0 * sigmaN),
            V0 = VnSigma0 * sigmaN + Vnp0;

    double theta0 = beta0, y0 = u0;

    // 将墙分为五段，每段自重
    double Nd =  gamma_concreteWeight * dc * h1_wallHeight * 0.2;

    std::vector<WallItem> mVecWallItems(wallKeyX);



    for(int i = 0; i < wallKeyX; i++){
        mVecWallItems[i].setId(i);
    }

    double maxM = 1.4e-5;
    for(WallItem &it: mVecWallItems){
        double ax = a * it.getId();

        double chax = cosh(ax), shax = sinh(ax),
                sinax = sin(ax), cosax = cos(ax);

        double tmpfai1 = chax * cosax, tmpfai2 = chax * sinax - (shax * cosax),
                tmpfai3 = chax * sinax, tmpfai4 = chax * sinax - (shax * cosax);

        it.setFai1(tmpfai1);
        it.setFai2(tmpfai2);
        it.setFai3(tmpfai3);
        it.setFai4(tmpfai4);

        double Mi = M0 * tmpfai1 + (Q0 * tmpfai2 * 0.5) / a -
                (7000 * y0 * tmpfai3 / pow(a, 2)) + (7000 * theta0 * tmpfai4/ pow(a,3))-
                (0.5 * e * tmpfai3 / pow(a, 2));
        double Ni = Nd * it.getId() + Vnp0;



        it.setM_wanju(Mi);
        it.setQ_zhouli(Ni);
        if(Mi > maxM) maxM = Mi;
        printf("x: %d, ax: %lf, fai1: %lf, fai2: %lf,"
               " fai3: %lf, fai4: %lf, Mi: %lf, Ni: %lf\n", it.getId(),
               ax, tmpfai1, tmpfai2, tmpfai3, tmpfai4, it.getM_wanju(), it.getQ_zhouli());

    }

    mVecWall = mVecWallItems;

    std::cout << "========== End Wall Item============" << std::endl;
    double h1_tmp = 0.5 * gangjinD + protectThickness;
    std::cout << "h1: " << h1_tmp << std::endl;
    double h0_avaliableWidth = wallThickness - h1_tmp;
    std::cout << "avaliable width: " << h0_avaliableWidth << std::endl;
    double As = maxM / (0.9 * fy * h0_avaliableWidth);
    double rou = As / wallThickness;
    std::cout <<"MaxM: " << maxM <<"    As: " << As <<"   rou: " << rou << std::endl;
    if(rou <= rou_min){
        rou = 0.004;
        h0_avaliableWidth = (sqrt(pow(h1_tmp,2 ) + (4 * maxM / (0.004 * 0.9 * fy * wallThickness))) - h1_tmp) * 0.5;
        std::cout << "avaliable width: " << h0_avaliableWidth << std::endl;
        std::cout << "wall Thickness: " << h0_avaliableWidth + h1_tmp << std::endl;
        return h0_avaliableWidth + h1_tmp;
    }else{
        std::cout << "wall Thickness: " << wallThickness << std::endl;

        return wallThickness;
    }
    


}
