// ×ÜÌå³ÌÐò.cpp : ¶šÒå¿ØÖÆÌšÓŠÓÃ³ÌÐòµÄÈë¿Úµã¡£
//
#define NDEBUGLESS0

//#include "stdafx.h"
#include <iostream>
#include "math.h"
#include <stdlib.h>
#include "time.h"
#include <iomanip>
#include<fstream>
const int new_voice=150;
const int new_media=150;
const int new_data=150;
const int qie_voice=15;
const int new_voice1=150;
const int new_media1=150;
const int new_data1=150;
const int qie_voice1=15;
const int new_voice2=150;
const int new_media2=150;
const int new_data2=150;
const int qie_voice2=15;
const int size_total=new_voice+new_media+new_data+qie_voice+new_voice1+new_media1+new_data1+qie_voice1+new_voice2+new_media2+new_data2+qie_voice2;
const int BV=32;
const int BMmin=64;
const int BMmax=128;
const int BDmin=0;
const int BDmax=128;
const double e=2.71828;
const double a=-2*log(0.0001/(1-0.0001))/64;
const double c=-log(0.0009)/(128-BDmin);
const double jingdu=0.0001;
const int TOTALBAND=66000;
double mk=c;
using namespace std;
int my_count[12]= {0},m,Uv=3,Uv1=6,Uv2=9,mark=0,del=0,returnband[12]= {0};
float Umax=0,Lb=TOTALBAND,LBK=TOTALBAND,temp=0,RB,n,b1,b2,b3,b4,b5,b6,b_total,U1,U2,U3,U4,U5,U6,Uz,b_media,b_data,b_media1,b_data1,b_media2,b_data2,Bz;


//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}


float Uv_(int R)
{
    if(R>=BV)
        return 3;
    else
        return 0;
}

float Uqv(int R)
{
    if(R>=BV)
        return 6;
    else
        return 0;
}
float Um(float R)
{
    float temp;
    temp = 2/(1+pow(e,-a*(R-96)));
    return temp;
}
float Umb(float R)
{
    float temp;
    temp = (2*a*pow(e,-a*(R-96)))/pow((1+pow(e,-a*(R-96))),2);
    return temp;
}
float Ud(float R)
{
    float temp;
    temp=1*(1-pow(e,-c*(R-BDmin)));
    return temp;
}
float Udb(float R)
{
    float temp;
    temp=1*c*pow(e,-c*(R-BDmin));
    return temp;
}
float bm(float m)
{
    float temp;
    temp=96-(log(a/(2*m/2)-1-pow(((pow(a/(m/2),2))/4-a/(m/2)),0.5)))/a;
    return temp;
}
float bd(float m)
{
    float temp;
    temp=-(log(m/(1*c)))/c+BDmin;
    return temp;
}
float Uv1_(int R)
{
    if(R>=BV)
        return 3*2;
    else
        return 0;
}

float Uqv1(int R)
{
    if(R>=BV)
        return 6*2;
    else
        return 0;
}
float Um1(float R)
{
    float temp;
    temp = 2*2/(1+pow(e,-a*(R-96)));
    return temp;
}
float Umb1(float R)
{
    float temp;
    temp = 2*(2*a*pow(e,-a*(R-96)))/pow((1+pow(e,-a*(R-96))),2);
    return temp;
}
float Ud1(float R)
{
    float temp;
    temp=2*1*(1-pow(e,-c*(R-BDmin)));
    return temp;
}
float Udb1(float R)
{
    float temp;
    temp=2*1*c*pow(e,-c*(R-BDmin));
    return temp;
}
float bm1(float m)
{
    float temp;
    temp=96-(log(a/(2*m/(2*2))-1-pow(((pow(a/(m/(2*2)),2))/4-a/(m/(2*2))),0.5)))/a;
    return temp;
}
float bd1(float m)
{
    float temp;
    temp=-(log(m/(2*1*c)))/c+BDmin;
    return temp;
}

float Uv2_(int R)
{
    if(R>=BV)
        return 3*3;
    else
        return 0;
}

float Uqv2(int R)
{
    if(R>=BV)
        return 6*3;
    else
        return 0;
}
float Um2(float R)
{
    float temp;
    temp = 3*2/(1+pow(e,-a*(R-96)));
    return temp;
}
float Umb2(float R)
{
    float temp;
    temp = 3*(2*a*pow(e,-a*(R-96)))/pow((1+pow(e,-a*(R-96))),2);
    return temp;
}
float Ud2(float R)
{
    float temp;
    temp=3*1*(1-pow(e,-c*(R-BDmin)));
    return temp;
}
float Udb2(float R)
{
    float temp;
    temp=3*1*c*pow(e,-c*(R-BDmin));
    return temp;
}
float bm2(float m)
{
    float temp;
    temp=96-(log(a/(2*m/(2*3))-1-pow(((pow(a/(m/(2*3)),2))/4-a/(m/(2*3))),0.5)))/a;
    return temp;
}
float bd2(float m)
{
    float temp;
    temp=-(log(m/(3*1*c)))/c+BDmin;
    return temp;
}

void Umaxjs1(int C)
{

    RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
    temp=0;
    mark=0;
    returnband[6]=mark;
    for(n=jingdu; n<mk; n=n+jingdu)
    {
        b1=bm(n);
        b2=bd(n);
        b3=bm1(n);
        b4=bd1(n);
        b5=bm2(n);
        b6=bd2(n);
        b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
        if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
        {
            mark=1;
            U1=Um(b1);
            U2=Ud(b2);
            U3=Um1(b3);
            U4=Ud1(b4);
            U5=Um2(b5);
            U6=Ud2(b6);
            Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
            if(Uz>temp)
            {
                temp=Uz;
                returnband[0]=b1;
                returnband[1]=b2;
                returnband[2]=b3;
                returnband[3]=b4;
                returnband[4]=b5;
                returnband[5]=b6;

                //b_media=b1;
                //b_data=b2;
                //b_media1=b3;
                //b_data1=b4;
                //b_media2=b5;
                //b_data2=b6;

            }
        }
        else
        {
            // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
        }

    }
    if(mark==1)
    {
        Umax=temp;
        returnband[6]=mark;
        ///cout<<"接入业务"<<C<<"成功!"<<endl;
        //cout<<"Umax="<<Umax<<endl;
        //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
        //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
        //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
        //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
        //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
        //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
        //cout<<"b_media="<<b_media<<endl;
        //cout<<"b_data="<<b_data<<endl;
        //cout<<"b_media1="<<b_media1<<endl;
        //cout<<"b_data1="<<b_data1<<endl;
        //cout<<"b_media2="<<b_media2<<endl;
        //cout<<"b_data2="<<b_data2<<endl;
        Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
        //cout<<"Bz="<<Bz<<endl;
//return returnband;
    }
    else
    {
        RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
        temp=0;
        mark=0;
        returnband[6]=mark;
        for(del=1; del<=my_count[2]; del++)
        {
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+(my_count[2]-del)*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+(my_count[2]-del)*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }
                else
                {
                    // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                }

            }
            if(mark==1) break;

        }
        if(mark==1)
        {
            Umax=temp;
            returnband[6]=mark;
            returnband[7]=2;
            returnband[8]=del;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"普通数据业务被踢出个数="<<del<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+(my_count[2]-del)*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
            my_count[2]=my_count[2]-del;
//return returnband;
        }
        else
        {
            returnband[9]=2;
            returnband[10]=my_count[2];
            my_count[2]=0;
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=mark;
            for(del=1; del<=my_count[6]; del++)
            {
                for(n=jingdu; n<mk; n=n+jingdu)
                {
                    b1=bm(n);
                    b2=0;
                    b3=bm1(n);
                    b4=bd1(n);
                    b5=bm2(n);
                    b6=bd2(n);
                    b_total=my_count[1]*b1+my_count[5]*b3+(my_count[6]-del)*b4+my_count[9]*b5+my_count[10]*b6;
                    if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                    {
                        mark=1;
                        U1=Um(b1);
                        //U2=Ud(b2);
                        U3=Um1(b3);
                        U4=Ud1(b4);
                        U5=Um2(b5);
                        U6=Ud2(b6);
                        Uz=my_count[1]*U1+my_count[0]*Uv+my_count[5]*U3+(my_count[6]-del)*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                        if(Uz>temp)
                        {
                            temp=Uz;
                            returnband[0]=b1;
                            returnband[1]=b2;
                            returnband[2]=b3;
                            returnband[3]=b4;
                            returnband[4]=b5;
                            returnband[5]=b6;
                        }
                    }
                    else
                    {
                        // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                    }

                }
                if(mark==1) break;

            }
            if(mark==1)
            {
                Umax=temp;
                returnband[6]=mark;
                returnband[7]=6;
                returnband[8]=del;
                //cout<<"接入业务"<<C<<"成功!"<<endl;
                //cout<<"一级数据业务被踢出个数="<<del<<endl;
                //cout<<"Umax="<<Umax<<endl;
                //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                //cout<<"b_media="<<b_media<<endl;
                //cout<<"b_data="<<b_data<<endl;
                //cout<<"b_media1="<<b_media1<<endl;
                //cout<<"b_data1="<<b_data1<<endl;
                //cout<<"b_media2="<<b_media2<<endl;
                //cout<<"b_data2="<<b_data2<<endl;
                Bz=my_count[0]*BV+my_count[1]*b_media+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+(my_count[6]-del)*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                //cout<<"Bz="<<Bz<<endl;
                my_count[6]=my_count[6]-del;
//return returnband;
            }
            else
            {
                returnband[9]=6;
                returnband[10]=my_count[6];
                my_count[6]=0;
                RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                temp=0;
                mark=0;
                returnband[6]=mark;
                for(del=1; del<=my_count[10]; del++)
                {
                    for(n=jingdu; n<mk; n=n+jingdu)
                    {
                        b1=bm(n);
                        b2=0;
                        b3=bm1(n);
                        b4=0;
                        b5=bm2(n);
                        b6=bd2(n);
                        b_total=my_count[1]*b1+my_count[5]*b3+my_count[9]*b5+(my_count[10]-del)*b6;
                        if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b6>=BDmin&&b6<=BDmax)
                        {
                            mark=1;
                            U1=Um(b1);
                            //U2=Ud(b2);
                            U3=Um1(b3);
                            //U4=Ud1(b4);
                            U5=Um2(b5);
                            U6=Ud2(b6);
                            Uz=my_count[1]*U1+my_count[0]*Uv+my_count[5]*U3+my_count[4]*Uv1+my_count[9]*U5+(my_count[10]-del)*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                            if(Uz>temp)
                            {
                                temp=Uz;
                                returnband[0]=b1;
                                returnband[1]=b2;
                                returnband[2]=b3;
                                returnband[3]=b4;
                                returnband[4]=b5;
                                returnband[5]=b6;
                            }
                        }
                        else
                        {
                            // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                        }

                    }
                    if(mark==1) break;

                }
                if(mark==1)
                {
                    Umax=temp;
                    returnband[6]=mark;
                    returnband[7]=10;
                    returnband[8]=del;
                    //cout<<"接入业务"<<C<<"成功!"<<endl;
                    ///cout<<"二级数据业务被踢出个数="<<del<<endl;
                    //cout<<"Umax="<<Umax<<endl;
                    //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                    //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                    //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                    //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                    //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                    //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                    //cout<<"b_media="<<b_media<<endl;
                    //cout<<"b_data="<<b_data<<endl;
                    //cout<<"b_media1="<<b_media1<<endl;
                    ///cout<<"b_data1="<<b_data1<<endl;
                    //cout<<"b_media2="<<b_media2<<endl;
                    //cout<<"b_data2="<<b_data2<<endl;
                    Bz=my_count[0]*BV+my_count[1]*b_media+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+(my_count[10]-del)*b_data2+my_count[11]*BV;
                    //cout<<"Bz="<<Bz<<endl;
                    my_count[10]=my_count[10]-del;
//return returnband;
                }
                else
                {
                    returnband[9]=10;
                    returnband[10]=my_count[10];
                    my_count[10]=0;
                    RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                    temp=0;
                    mark=0;
                    returnband[6]=mark;
                    for(del=1; del<=my_count[1]; del++)
                    {
                        for(n=jingdu; n<mk; n=n+jingdu)
                        {
                            b1=bm(n);
                            b2=0;
                            b3=bm1(n);
                            b4=0;
                            b5=bm2(n);
                            b6=0;
                            b_total=(my_count[1]-del)*b1+my_count[5]*b3+my_count[9]*b5;
                            if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax)
                            {
                                mark=1;
                                U1=Um(b1);
                                //U2=Ud(b2);
                                U3=Um1(b3);
                                //U4=Ud1(b4);
                                U5=Um2(b5);
                                //U6=Ud2(b6);
                                Uz=(my_count[1]-del)*U1+my_count[0]*Uv+my_count[5]*U3+my_count[4]*Uv1+my_count[9]*U5+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                                if(Uz>temp)
                                {
                                    temp=Uz;
                                    returnband[0]=b1;
                                    returnband[1]=b2;
                                    returnband[2]=b3;
                                    returnband[3]=b4;
                                    returnband[4]=b5;
                                    returnband[5]=b6;
                                }
                            }
                            else
                            {
                                // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                            }

                        }
                        if(mark==1) break;

                    }
                    if(mark==1)
                    {
                        Umax=temp;
                        returnband[6]=mark;
                        returnband[7]=1;
                        returnband[8]=del;
                        //cout<<"接入业务"<<C<<"成功!"<<endl;
                        //cout<<"普通流媒体业务被踢出个数="<<del<<endl;
                        //cout<<"Umax="<<Umax<<endl;
                        //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                        //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                        //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                        //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                        //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                        //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                        //cout<<"b_media="<<b_media<<endl;
                        //cout<<"b_data="<<b_data<<endl;
                        //cout<<"b_media1="<<b_media1<<endl;
                        //cout<<"b_data1="<<b_data1<<endl;
                        //cout<<"b_media2="<<b_media2<<endl;
                        //cout<<"b_data2="<<b_data2<<endl;
                        Bz=my_count[0]*BV+(my_count[1]-del)*b_media+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[11]*BV;
                        //cout<<"Bz="<<Bz<<endl;
                        my_count[1]=my_count[1]-del;
//return returnband;
                    }
                    else
                    {
                        returnband[9]=1;
                        returnband[10]=my_count[1];
                        my_count[1]=0;
                        RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                        temp=0;
                        mark=0;
                        returnband[6]=mark;
                        for(del=1; del<=my_count[5]; del++)
                        {
                            for(n=jingdu; n<mk; n=n+jingdu)
                            {
                                b1=0;
                                b2=0;
                                b3=bm1(n);
                                b4=0;
                                b5=bm2(n);
                                b6=0;
                                b_total=(my_count[5]-del)*b3+my_count[9]*b5;
                                if(b_total<=RB&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax)
                                {
                                    mark=1;
                                    //U1=Um(b1);
                                    //U2=Ud(b2);
                                    U3=Um1(b3);
                                    //U4=Ud1(b4);
                                    U5=Um2(b5);
                                    //U6=Ud2(b6);
                                    Uz=my_count[0]*Uv+(my_count[5]-del)*U3+my_count[4]*Uv1+my_count[9]*U5+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                                    if(Uz>temp)
                                    {
                                        temp=Uz;
                                        returnband[0]=b1;
                                        returnband[1]=b2;
                                        returnband[2]=b3;
                                        returnband[3]=b4;
                                        returnband[4]=b5;
                                        returnband[5]=b6;
                                    }
                                }
                                else
                                {
                                    // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                                }

                            }
                            if(mark==1) break;

                        }
                        if(mark==1)
                        {
                            Umax=temp;
                            returnband[6]=mark;
                            returnband[7]=5;
                            returnband[8]=del;
                            //cout<<"接入业务"<<C<<"成功!"<<endl;
                            //cout<<"一级流媒体业务被踢出个数="<<del<<endl;
                            //cout<<"Umax="<<Umax<<endl;
                            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                            //cout<<"b_media="<<b_media<<endl;
                            //cout<<"b_data="<<b_data<<endl;
                            //cout<<"b_media1="<<b_media1<<endl;
                            //cout<<"b_data1="<<b_data1<<endl;
                            //cout<<"b_media2="<<b_media2<<endl;
                            ////cout<<"b_data2="<<b_data2<<endl;
                            Bz=my_count[0]*BV+my_count[3]*BV+my_count[4]*BV+(my_count[5]-del)*b_media1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[11]*BV;
                            //cout<<"Bz="<<Bz<<endl;
                            my_count[5]=my_count[5]-del;
//return  returnband;
                        }
                        else
                        {
                            returnband[9]=5;
                            returnband[10]=my_count[5];
                            my_count[5]=0;
                            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                            temp=0;
                            mark=0;
                            returnband[6]=mark;
                            for(del=1; del<=my_count[9]; del++)
                            {
                                for(n=jingdu; n<mk; n=n+jingdu)
                                {
                                    b1=0;
                                    b2=0;
                                    b3=0;
                                    b4=0;
                                    b5=bm2(n);
                                    b6=0;
                                    b_total=(my_count[9]-del)*b5;
                                    if(b_total<=RB&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax)
                                    {
                                        mark=1;
                                        //U1=Um(b1);
                                        //U2=Ud(b2);
                                        //U3=Um1(b3);
                                        //U4=Ud1(b4);
                                        U5=Um2(b5);
                                        //U6=Ud2(b6);
                                        Uz=my_count[0]*Uv+my_count[4]*Uv1+(my_count[9]-del)*U5+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                                        if(Uz>temp)
                                        {
                                            temp=Uz;
                                            returnband[0]=b1;
                                            returnband[1]=b2;
                                            returnband[2]=b3;
                                            returnband[3]=b4;
                                            returnband[4]=b5;
                                            returnband[5]=b6;
                                        }
                                    }
                                    else
                                    {
                                        // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                                    }

                                }
                                if(mark==1) break;

                            }
                            if(mark==1)
                            {
                                Umax=temp;
                                returnband[6]=mark;
                                returnband[7]=9;
                                returnband[8]=del;
                                //cout<<"接入业务"<<C<<"成功!"<<endl;
                                //cout<<"二级流媒体业务被踢出个数="<<del<<endl;
                                //cout<<"Umax="<<Umax<<endl;
                                //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                                //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                                //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                                //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                                //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                                //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                                //cout<<"b_media="<<b_media<<endl;
                                //cout<<"b_data="<<b_data<<endl;
                                //cout<<"b_media1="<<b_media1<<endl;
                                //cout<<"b_data1="<<b_data1<<endl;
                                //cout<<"b_media2="<<b_media2<<endl;
                                //cout<<"b_data2="<<b_data2<<endl;
                                Bz=my_count[0]*BV+my_count[3]*BV+my_count[4]*BV+my_count[7]*BV+my_count[8]*BV+(my_count[9]-del)*b_media2+my_count[11]*BV;
                                //cout<<"Bz="<<Bz<<endl;
                                my_count[9]=my_count[9]-del;
//return  returnband;
                            }
                            else
                            {
                                my_count[C]=my_count[C]-1;
                                returnband[6]=mark;
                                // cout<<"接入业务"<<C<<"失败!"<<"当前业务个数="<<my_count[C]<<endl;
                            }
                        }
                    }
                }
            }
        }
    }
}
void Umaxjs2(int C)
{
    RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
    temp=0;
    mark=0;
    returnband[6]=mark;
    for(n=jingdu; n<mk; n=n+jingdu)
    {
        b1=bm(n);
        b2=bd(n);
        b3=bm1(n);
        b4=bd1(n);
        b5=bm2(n);
        b6=bd2(n);
        b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
        if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
        {
            mark=1;
            U1=Um(b1);
            U2=Ud(b2);
            U3=Um1(b3);
            U4=Ud1(b4);
            U5=Um2(b5);
            U6=Ud2(b6);
            Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
            if(Uz>temp)
            {
                temp=Uz;
                returnband[0]=b1;
                returnband[1]=b2;
                returnband[2]=b3;
                returnband[3]=b4;
                returnband[4]=b5;
                returnband[5]=b6;

            }
        }

    }
    if(mark==1)
    {
        Umax=temp;
        returnband[6]=mark;
        //cout<<"接入业务"<<C<<"成功!"<<endl;
        //cout<<"Umax="<<Umax<<endl;
        //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
        //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
        //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
        //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
        //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
        //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
        //cout<<"b_media="<<b_media<<endl;
        //cout<<"b_data="<<b_data<<endl;
        //cout<<"b_media1="<<b_media1<<endl;
        //cout<<"b_data1="<<b_data1<<endl;
        //cout<<"b_media2="<<b_media2<<endl;
        //cout<<"b_data2="<<b_data2<<endl;
        Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
        //cout<<"Bz="<<Bz<<endl;
    }
    else
    {
        my_count[C]=my_count[C]-1;
        // cout<<"接入业务"<<C<<"失败!"<<"当前业务个数="<<my_count[C]<<endl;
    }


}
void Umaxjs3(int C)//Ò»Œ¶Á÷ÃœÌå
{
    RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
    temp=0;
    mark=0;
    returnband[6]=mark;
    for(n=jingdu; n<mk; n=n+jingdu)
    {
        b1=bm(n);
        b2=bd(n);
        b3=bm1(n);
        b4=bd1(n);
        b5=bm2(n);
        b6=bd2(n);
        b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
        if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
        {
            mark=1;
            U1=Um(b1);
            U2=Ud(b2);
            U3=Um1(b3);
            U4=Ud1(b4);
            U5=Um2(b5);
            U6=Ud2(b6);
            Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
            if(Uz>temp)
            {
                temp=Uz;
                returnband[0]=b1;
                returnband[1]=b2;
                returnband[2]=b3;
                returnband[3]=b4;
                returnband[4]=b5;
                returnband[5]=b6;

            }
        }

    }
    if(mark==1)
    {
        Umax=temp;
        returnband[6]=mark;
        //cout<<"接入业务"<<C<<"成功!"<<endl;
        //cout<<"Umax="<<Umax<<endl;
        //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
        //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
        //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
        //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
        //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
        //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
        //cout<<"b_media="<<b_media<<endl;
        //cout<<"b_data="<<b_data<<endl;
        //cout<<"b_media1="<<b_media1<<endl;
        //cout<<"b_data1="<<b_data1<<endl;
        //cout<<"b_media2="<<b_media2<<endl;
        //cout<<"b_data2="<<b_data2<<endl;
        Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
        //cout<<"Bz="<<Bz<<endl;
    }
    else
    {
        RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
        temp=0;
        mark=0;
        returnband[6]=mark;
        for(del=1; del<=my_count[2]; del++)
        {
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+(my_count[2]-del)*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+(my_count[2]-del)*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;
                    }
                }
                else
                {
                    // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                }

            }
            if(mark==1) break;

        }
        if(mark==1)
        {
            Umax=temp;
            returnband[6]=mark;
            returnband[7]=2;
            returnband[8]=del;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"普通数据业务被踢出个数="<<del<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            ///cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            ///cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+(my_count[2]-del)*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
            my_count[2]=my_count[2]-del;
        }
        else
        {
            returnband[9]=2;
            returnband[10]=my_count[2];
            my_count[2]=0;
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=mark;
            for(del=1; del<=my_count[1]; del++)
            {
                for(n=jingdu; n<mk; n=n+jingdu)
                {
                    b1=bm(n);
                    b2=0;
                    b3=bm1(n);
                    b4=bd1(n);
                    b5=bm2(n);
                    b6=bd2(n);
                    b_total=(my_count[1]-del)*b1+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                    if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                    {
                        mark=1;
                        U1=Um(b1);
                        //U2=Ud(b2);
                        U3=Um1(b3);
                        U4=Ud1(b4);
                        U5=Um2(b5);
                        U6=Ud2(b6);
                        Uz=(my_count[1]-del)*U1+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                        if(Uz>temp)
                        {
                            temp=Uz;
                            returnband[0]=b1;
                            returnband[1]=b2;
                            returnband[2]=b3;
                            returnband[3]=b4;
                            returnband[4]=b5;
                            returnband[5]=b6;
                        }
                    }
                    else
                    {
                        // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                    }

                }
                if(mark==1) break;

            }
            if(mark==1)
            {
                Umax=temp;
                returnband[6]=mark;
                returnband[7]=1;
                returnband[8]=del;
                //cout<<"接入业务"<<C<<"成功!"<<endl;
                //cout<<"普通流媒体业务被踢出个数="<<del<<endl;
                //cout<<"Umax="<<Umax<<endl;
                //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                //cout<<"b_media="<<b_media<<endl;
                //cout<<"b_data="<<b_data<<endl;
                //cout<<"b_media1="<<b_media1<<endl;
                //cout<<"b_data1="<<b_data1<<endl;
                //cout<<"b_media2="<<b_media2<<endl;
                //cout<<"b_data2="<<b_data2<<endl;
                Bz=my_count[0]*BV+(my_count[1]-del)*b_media+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                //cout<<"Bz="<<Bz<<endl;
                my_count[1]=my_count[1]-del;
            }
            else
            {
                my_count[C]=my_count[C]-1;
                returnband[6]=mark;
                //cout<<"接入业务"<<C<<"失败!"<<"当前业务个数="<<my_count[C]<<endl;
            }
        }
    }


}
/*int * asrand()
{
	int *p1=new int[size_total];
	int a[new_voice];
	int b[new_media];
	int c[new_data];
	int d[qie_voice];
	int e[new_voice1];
	int f[new_media1];
	int g[new_data1];
	int h[qie_voice1];
	int z[new_voice2];
	int w[new_media2];
	int k[new_data2];
	int l[qie_voice2];
   	int i,j;
	////ÆÕÍšÓÃ»§
	for(i=0;i<new_voice;i++)
	    a[i]=0;
    for(i=0;i<new_media;i++)
		b[i]=1;
    for(i=0;i<new_data;i++)
		c[i]=2;
	for(i=0;i<qie_voice;i++)
	    d[i]=3;
   ////Ò»Œ¶ÓÃ»§
	for(i=0;i<new_voice1;i++)
	    e[i]=4;
    for(i=0;i<new_media1;i++)
		f[i]=5;
    for(i=0;i<new_data1;i++)
		g[i]=6;
	for(i=0;i<qie_voice1;i++)
	    h[i]=7;
	/////¶þŒ¶ÓÃ»§
	for(i=0;i<new_voice2;i++)
	    z[i]=8;
    for(i=0;i<new_media2;i++)
		w[i]=9;
    for(i=0;i<new_data2;i++)
		k[i]=10;
	for(i=0;i<qie_voice2;i++)
	    l[i]=11;
	//////ÆÕÍšÓÃ»§
    for(j=0;j<new_voice;j++)
		p1[j]=a[j];
    for(j=0;j<new_media;j++)
        p1[new_voice+j]=b[j];
    for(j=0;j<new_data;j++)
        p1[new_voice+new_media+j]=c[j];
	for(j=0;j<qie_voice;j++)
        p1[new_voice+new_media+new_data+j]=d[j];
   //////Ò»Œ¶ÓÃ»§
	for(j=0;j<new_voice1;j++)
        p1[new_voice+new_media+new_data+qie_voice+j]=e[j];
	 for(j=0;j<new_media1;j++)
        p1[new_voice+new_media+new_data+qie_voice+new_voice1+j]=f[j];
    for(j=0;j<new_data1;j++)
        p1[new_voice+new_media+new_data+qie_voice+new_voice1+new_media1+j]=g[j];
	for(j=0;j<qie_voice1;j++)
        p1[new_voice+new_media+new_data+qie_voice+new_voice1+new_media1+new_data1+j]=h[j];
	//////¶þŒ¶ÓÃ»§
	 for(j=0;j<new_voice2;j++)
        p1[new_voice+new_media+new_data+qie_voice+new_voice1+new_media1+new_data1+qie_voice1+j]=z[j];
	 for(j=0;j<new_media2;j++)
        p1[new_voice+new_media+new_data+qie_voice+new_voice1+new_media1+new_data1+qie_voice1+new_voice2+j]=w[j];
    for(j=0;j<new_data2;j++)
        p1[new_voice+new_media+new_data+qie_voice+new_voice1+new_media1+new_data1+qie_voice1+new_voice2+new_media2+j]=k[j];
	for(j=0;j<qie_voice2;j++)
        p1[new_voice+new_media+new_data+qie_voice+new_voice1+new_media1+new_data1+qie_voice1+new_voice2+new_media2+new_data2+j]=l[j];

	srand((unsigned)time(NULL));
	int my_count=0,p,q,t;
    for(i=0;i<size_total;i++)
       {
         p=rand()%size_total;
	     q=rand()%size_total;
	     t=p1[p];
	     p1[p]=p1[q];
	     p1[q]=t;
       }
  //  for(i=0;i<size_total;i++)
     // {
	//	 if (my_count % 10 == 0 && my_count != 0)
	//		 cout << endl;
	//	 my_count++;
	 //    cout<<setw(3)<<setfill(' ')<<p1[i];
     // }
   return  p1;
  }*/



////////haimeigai  a sdasda sda
void switchcaseout(int m)
{
    switch(m)
    {
    case 0:
    case 3:
    case 4:
    case 7:
    case 8:
    case 11:
    {
#ifndef NDEBUGLESS0
        if(my_count[m]<=0)   break;
#endif // NDEBUGLESS0
        my_count[m]--;
        if((my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV)<=LBK)
        {
            Lb=LBK-(my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV);
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            //cout<<"**********语音业务个数为"<<my_count[0]<<endl;
        }
        else
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=m;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }

            }
            Umax=temp;
            returnband[6]=m;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
        }

        break;
    }//case0,3,4,7,8,11
    case 1:
    {
#ifndef NDEBUGLESS0
        if(my_count[m]<=0)   break;
#endif // NDEBUGLESS0
        my_count[m]--;

        if((my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV)<=LBK)
        {
            Lb=LBK-(my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV);
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            //cout<<"**********语音业务个数为"<<my_count[0]<<endl;
        }
        else
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=m;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }

            }
            Umax=temp;
            returnband[6]=m;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
        }

        break;
    }//case1
    case 2:
    {
#ifndef NDEBUGLESS0
        if(my_count[m]<=0)   break;
#endif // NDEBUGLESS0
        my_count[m]--;

        if((my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV)<=LBK)
        {
            Lb=LBK-(my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV);
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            //cout<<"**********语音业务个数为"<<my_count[0]<<endl;
        }
        else
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=m;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }

            }
            Umax=temp;
            returnband[6]=m;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
        }

        break;
    }//case2
    case 5:
    {
#ifndef NDEBUGLESS0
        if(my_count[m]<=0)   break;
#endif // NDEBUGLESS0
        my_count[m]--;

        if((my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV)<=LBK)
        {
            Lb=LBK-(my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV);
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            //cout<<"**********语音业务个数为"<<my_count[0]<<endl;
        }
        else
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=m;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }

            }
            Umax=temp;
            returnband[6]=m;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
        }

        break;
    }//case5
    case 6:
    {
#ifndef NDEBUGLESS0
        if(my_count[m]<=0)   break;
#endif // NDEBUGLESS0
        my_count[m]--;

        if((my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV)<=LBK)
        {
            Lb=LBK-(my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV);
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            //cout<<"**********语音业务个数为"<<my_count[0]<<endl;
        }
        else
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=m;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }

            }
            Umax=temp;
            returnband[6]=m;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
        }

        break;
    }//case6
    case 9:
    {
#ifndef NDEBUGLESS0
        if(my_count[m]<=0)   break;
#endif // NDEBUGLESS0
        my_count[m]--;

        if((my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV)<=LBK)
        {
            Lb=LBK-(my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV);
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            //cout<<"**********语音业务个数为"<<my_count[0]<<endl;
        }
        else
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=m;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }

            }
            Umax=temp;
            returnband[6]=m;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
        }

        break;
    }//case9
    case 10:
    {
#ifndef NDEBUGLESS0
        if(my_count[m]<=0)   break;
#endif // NDEBUGLESS0
        my_count[m]--;

        if((my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV)<=LBK)
        {
            Lb=LBK-(my_count[0]*BV+my_count[1]*BMmax+my_count[2]*BDmax+my_count[3]*BV+my_count[4]*BV+my_count[5]*BMmax+my_count[6]*BDmax+my_count[7]*BV+my_count[8]*BV+my_count[9]*BMmax+my_count[10]*BDmax+my_count[11]*BV);
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            //cout<<"**********语音业务个数为"<<my_count[0]<<endl;
        }
        else
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=m;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;

                    }
                }

            }
            Umax=temp;
            returnband[6]=m;
            //cout<<"接入业务"<<C<<"成功!"<<endl;
            //cout<<"Umax="<<Umax<<endl;
            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
            //cout<<"b_media="<<b_media<<endl;
            //cout<<"b_data="<<b_data<<endl;
            //cout<<"b_media1="<<b_media1<<endl;
            //cout<<"b_data1="<<b_data1<<endl;
            //cout<<"b_media2="<<b_media2<<endl;
            //cout<<"b_data2="<<b_data2<<endl;
            Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
            //cout<<"Bz="<<Bz<<endl;
        }

        break;
    }//case10
    /*default:
    {
        char tempcs[100];
        printf("switchcaseout default\n");
        cin>>tempcs;
    }*/
    }  //switch



}
void switchcasein(int m)
{
    switch(m)
    {
    case 0:
    {
        my_count[0]++;
        if(Lb>=BV)
        {
            Lb=Lb-BV;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********普通语音业务个数为"<<my_count[0]<<endl;
        }
        else if(Lb>=0&&Lb<BV)
        {
            Umaxjs1(0);
        }

        break;
    }//case0
    case 1:
    {
        my_count[1]++;
        if(Lb>=BMmax)
        {
            Lb=Lb-BMmax;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********普通流媒体业务个数为"<<my_count[1]<<endl;
        }
        else if(Lb>=0&&Lb<BMmax)
        {
            Umaxjs2(1);
        }
        break;
    }//case1

    case 2:
    {
        my_count[2]++;
        if(Lb>=BDmax)
        {
            Lb=Lb-BDmax;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********普通数据业务个数为"<<my_count[2]<<endl;
        }
        else if(Lb>=0&&Lb<BDmax)
        {
            Umaxjs2(2);
        }
        break;
    }//case2

    case 3:
    {
        my_count[3]++;
        if(Lb>=BV)
        {
            Lb=Lb-BV;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********普通切换语音业务个数为"<<my_count[3]<<endl;
        }
        else if(Lb>=0&&Lb<BV)
        {
            Umaxjs1(3);
        }

        break;
    }//case3........
    case 4://Ò»Œ¶ÓïÒô
    {
        my_count[4]++;
        if(Lb>=BV)
        {
            Lb=Lb-BV;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********一级语音业务个数为"<<my_count[4]<<endl;
        }
        else if(Lb>=0&&Lb<BV)
        {
            Umaxjs1(4);
        }

        break;
    }//case4
    case 5:
    {
        my_count[5]++;
        if(Lb>=BMmax)
        {
            Lb=Lb-BMmax;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********一级流媒体业务个数为"<<my_count[5]<<endl;
        }
        else if(Lb>=0&&Lb<BMmax)
        {
            Umaxjs3(5);
        }

        break;
    }//case5

    case 6:
    {
        my_count[6]++;
        if(Lb>=BDmax)
        {
            Lb=Lb-BDmax;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********一级数据业务个数为"<<my_count[6]<<endl;
        }
        else if(Lb>=0&&Lb<BDmax)
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=mark;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;
                    }
                }
                else
                {
                    // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                }

            }
            if(mark==1)
            {
                Umax=temp;
                returnband[6]=mark;
                ///cout<<"接入一级数据成功!"<<endl;
                ///cout<<"Umax="<<Umax<<endl;
                ///cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                ///cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                ///cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                ///cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                ///cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                ///cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                ///cout<<"b_media="<<b_media<<endl;
                ///cout<<"b_data="<<b_data<<endl;
                ////cout<<"b_media1="<<b_media1<<endl;
                ///cout<<"b_data1="<<b_data1<<endl;
                //cout<<"b_media2="<<b_media2<<endl;
                //cout<<"b_data2="<<b_data2<<endl;
                Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                //cout<<"Bz="<<Bz<<endl;
            }
            else //{
                //   my_count[6]=my_count[6]-1;
                //	cout<<"œÓÈëÒ»Œ¶ÊýŸÝÊ§°Ü£¡µ±Ç°Ò»Œ¶ÊýŸÝžöÊý:"<<my_count[6]<<endl;
                //}
            {
                RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                temp=0;
                mark=0;
                returnband[6]=mark;
                for(del=1; del<=my_count[2]; del++)
                {
                    for(n=jingdu; n<mk; n=n+jingdu)
                    {
                        b1=bm(n);
                        b2=bd(n);
                        b3=bm1(n);
                        b4=bd1(n);
                        b5=bm2(n);
                        b6=bd2(n);
                        b_total=my_count[1]*b1+(my_count[2]-del)*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                        if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                        {
                            mark=1;
                            U1=Um(b1);
                            U2=Ud(b2);
                            U3=Um1(b3);
                            U4=Ud1(b4);
                            U5=Um2(b5);
                            U6=Ud2(b6);
                            Uz=my_count[1]*U1+(my_count[2]-del)*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                            if(Uz>temp)
                            {
                                temp=Uz;
                                returnband[0]=b1;
                                returnband[1]=b2;
                                returnband[2]=b3;
                                returnband[3]=b4;
                                returnband[4]=b5;
                                returnband[5]=b6;
                            }
                        }
                        else
                        {
                            // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                        }

                    }
                    if(mark==1) break;

                }
                if(mark==1)
                {
                    Umax=temp;
                    returnband[6]=mark;
                    returnband[7]=2;
                    returnband[8]=del;
                    //cout<<"接入一级数据业务成功!"<<endl;
                    //cout<<"数据业务被踢出个数="<<del<<endl;
                    //cout<<"Umax="<<Umax<<endl;
                    ///cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                    ///cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                    ///cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                    ///cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                    ///cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                    //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                    //cout<<"b_media="<<b_media<<endl;
                    ///cout<<"b_data="<<b_data<<endl;
                    ///cout<<"b_media1="<<b_media1<<endl;
                    ///cout<<"b_data1="<<b_data1<<endl;
                    ///cout<<"b_media2="<<b_media2<<endl;
                    //cout<<"b_data2="<<b_data2<<endl;
                    Bz=my_count[0]*BV+my_count[1]*b_media+(my_count[2]-del)*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                    //cout<<"Bz="<<Bz<<endl;
                    my_count[2]=my_count[2]-del;
                }
                else
                {
                    my_count[6]=my_count[6]-1;
                    returnband[6]=0;
                    // cout<<"接入一级数据失败！当前一级数据个数:"<<my_count[6]<<endl;
                }


            }
        }

        break;
    }//case6

    case 7:
    {
        my_count[7]++;
        if(Lb>=BV)
        {
            Lb=Lb-BV;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********一级切换语音业务个数为"<<my_count[7]<<endl;
        }
        else if(Lb>=0&&Lb<BV)
        {
            Umaxjs1(7);
        }
        break;
    }//case7
    case 8://¶þŒ¶ÓïÒô
    {
        my_count[8]++;
        if(Lb>=BV)
        {
            Lb=Lb-BV;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********二级语音业务个数为"<<my_count[8]<<endl;
        }
        else if(Lb>=0&&Lb<BV)
        {
            Umaxjs1(8);
        }

        break;
    }//case8
    case 9:
    {
        my_count[9]++;
        if(Lb>=BMmax)
        {
            Lb=Lb-BMmax;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********二级流媒体业务个数为"<<my_count[9]<<endl;
        }
        else if(Lb>=0&&Lb<BMmax)
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=mark;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;
                    }
                }
                else
                {
                    // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                }

            }
            if(mark==1)
            {
                Umax=temp;
                returnband[6]=mark;
                //cout<<"接入二级流媒体成功!"<<endl;
                //cout<<"Umax="<<Umax<<endl;
                ///cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                ///cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                ///cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                ///cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                ///cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                ///cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                ///cout<<"b_media="<<b_media<<endl;
                //cout<<"b_data="<<b_data<<endl;
                //cout<<"b_media1="<<b_media1<<endl;
                //cout<<"b_data1="<<b_data1<<endl;
                //cout<<"b_media2="<<b_media2<<endl;
                //cout<<"b_data2="<<b_data2<<endl;
                Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                //cout<<"Bz="<<Bz<<endl;
            }
            else
            {

                RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                temp=0;
                mark=0;
                returnband[6]=mark;
                for(del=1; del<=my_count[2]; del++)
                {
                    for(n=jingdu; n<mk; n=n+jingdu)
                    {
                        b1=bm(n);
                        b2=bd(n);
                        b3=bm1(n);
                        b4=bd1(n);
                        b5=bm2(n);
                        b6=bd2(n);
                        b_total=my_count[1]*b1+(my_count[2]-del)*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                        if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                        {
                            mark=1;
                            U1=Um(b1);
                            U2=Ud(b2);
                            U3=Um1(b3);
                            U4=Ud1(b4);
                            U5=Um2(b5);
                            U6=Ud2(b6);
                            Uz=my_count[1]*U1+(my_count[2]-del)*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2;
                            if(Uz>temp)
                            {
                                temp=Uz;
                                returnband[0]=b1;
                                returnband[1]=b2;
                                returnband[2]=b3;
                                returnband[3]=b4;
                                returnband[4]=b5;
                                returnband[5]=b6;
                            }
                        }
                        else
                        {
                            // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                        }

                    }
                    if(mark==1) break;

                }
                if(mark==1)
                {
                    Umax=temp;
                    returnband[6]=mark;
                    returnband[7]=2;
                    returnband[8]=del;
                    //cout<<"接入二级流媒体业务成功!"<<endl;
                    //cout<<"普通数据业务被踢出个数="<<del<<endl;
                    //cout<<"Umax="<<Umax<<endl;
                    //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                    //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                    //cout<<"U_media="<<Um1(b_media1)*my_count[5]<<endl;
                    //cout<<"U_data="<<Ud1(b_data1)*my_count[6]<<endl;
                    //cout<<"U_media="<<Um2(b_media2)*my_count[9]<<endl;
                    //cout<<"U_data="<<Ud2(b_data2)*my_count[10]<<endl;
                    //cout<<"b_media="<<b_media<<endl;
                    //cout<<"b_data="<<b_data<<endl;
                    //cout<<"b_media1="<<b_media1<<endl;
                    //cout<<"b_data1="<<b_data1<<endl;
                    //cout<<"b_media2="<<b_media2<<endl;
                    //cout<<"b_data2="<<b_data2<<endl;
                    Bz=my_count[0]*BV+my_count[1]*b_media+(my_count[2]-del)*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                    //cout<<"Bz="<<Bz<<endl;
                    my_count[2]=my_count[2]-del;
                }
                else
                {
                    returnband[9]=2;
                    returnband[10]=my_count[2];
                    my_count[2]=0;
                    RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                    temp=0;
                    mark=0;
                    returnband[6]=mark;
                    for(del=1; del<=my_count[6]; del++)
                    {
                        for(n=jingdu; n<mk; n=n+jingdu)
                        {
                            b1=bm(n);
                            b2=0;
                            b3=bm1(n);
                            b4=bd1(n);
                            b5=bm2(n);
                            b6=bd2(n);
                            b_total=my_count[1]*b1+my_count[5]*b3+(my_count[6]-del)*b4+my_count[9]*b5+my_count[10]*b6;
                            if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                            {
                                mark=1;
                                U1=Um(b1);
                                //U2=Ud(b2);
                                U3=Um1(b3);
                                U4=Ud1(b4);
                                U5=Um2(b5);
                                U6=Ud2(b6);
                                Uz=my_count[1]*U1+my_count[0]*Uv+my_count[5]*U3+(my_count[6]-del)*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2;
                                if(Uz>temp)
                                {
                                    temp=Uz;
                                    returnband[0]=b1;
                                    returnband[1]=b2;
                                    returnband[2]=b3;
                                    returnband[3]=b4;
                                    returnband[4]=b5;
                                    returnband[5]=b6;
                                }
                            }
                            else
                            {
                                // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                            }

                        }
                        if(mark==1) break;

                    }
                    if(mark==1)
                    {
                        Umax=temp;
                        returnband[6]=mark;
                        returnband[7]=6;
                        returnband[8]=del;
                        //cout<<"接入二级流媒体业务成功!"<<endl;
                        //cout<<"一级数据业务被踢出个数="<<del<<endl;
                        //cout<<"Umax="<<Umax<<endl;
                        //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                        //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                        //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                        ///cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                        ///cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                        //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                        //cout<<"b_media="<<b_media<<endl;
                        //cout<<"b_data="<<b_data<<endl;
                        //cout<<"b_media1="<<b_media1<<endl;
                        //cout<<"b_data1="<<b_data1<<endl;
                        //cout<<"b_media2="<<b_media2<<endl;
                        //cout<<"b_data2="<<b_data2<<endl;
                        Bz=my_count[0]*BV+my_count[1]*b_media+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+(my_count[6]-del)*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                        //cout<<"Bz="<<Bz<<endl;
                        my_count[6]=my_count[6]-del;
                    }
                    else
                    {
                        returnband[9]=6;
                        returnband[10]=my_count[6];
                        my_count[6]=0;
                        RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                        temp=0;
                        mark=0;
                        returnband[6]=mark;
                        for(del=1; del<=my_count[1]; del++)
                        {
                            for(n=jingdu; n<mk; n=n+jingdu)
                            {
                                b1=bm(n);
                                b2=0;
                                b3=bm1(n);
                                b4=0;
                                b5=bm2(n);
                                b6=bd2(n);
                                b_total=(my_count[1]-del)*b1+my_count[5]*b3+my_count[9]*b5+my_count[10]*b6;
                                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b6>=BDmin&&b6<=BDmax)
                                {
                                    mark=1;
                                    U1=Um(b1);
                                    //U2=Ud(b2);
                                    U3=Um1(b3);
                                    //U4=Ud1(b4);
                                    U5=Um2(b5);
                                    U6=Ud2(b6);
                                    Uz=(my_count[1]-del)*U1+my_count[0]*Uv+my_count[5]*U3+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2;
                                    if(Uz>temp)
                                    {
                                        temp=Uz;
                                        returnband[0]=b1;
                                        returnband[1]=b2;
                                        returnband[2]=b3;
                                        returnband[3]=b4;
                                        returnband[4]=b5;
                                        returnband[5]=b6;
                                    }
                                }
                                else
                                {
                                    // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                                }

                            }
                            if(mark==1) break;

                        }
                        if(mark==1)
                        {
                            Umax=temp;
                            returnband[6]=mark;
                            returnband[7]=1;
                            returnband[8]=del;
                            //cout<<"接入二级流媒体业务成功!"<<endl;
                            //cout<<"普通流媒体业务被踢出个数="<<del<<endl;
                            //cout<<"Umax="<<Umax<<endl;
                            //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                            //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                            //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                            //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                            //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                            //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                            ///cout<<"b_media="<<b_media<<endl;
                            //cout<<"b_data="<<b_data<<endl;
                            //cout<<"b_media1="<<b_media1<<endl;
                            //cout<<"b_data1="<<b_data1<<endl;
                            //cout<<"b_media2="<<b_media2<<endl;
                            //cout<<"b_data2="<<b_data2<<endl;
                            Bz=my_count[0]*BV+(my_count[1]-del)*b_media+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                            //cout<<"Bz="<<Bz<<endl;
                            my_count[1]=my_count[1]-del;
                        }
                        else
                        {
                            returnband[9]=1;
                            returnband[10]=my_count[1];
                            my_count[1]=0;
                            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                            temp=0;
                            mark=0;
                            returnband[6]=mark;
                            for(del=1; del<=my_count[5]; del++)
                            {
                                for(n=jingdu; n<mk; n=n+jingdu)
                                {
                                    b1=0;
                                    b2=0;
                                    b3=bm1(n);
                                    b4=0;
                                    b5=bm2(n);
                                    b6=bd2(n);
                                    b_total=(my_count[5]-del)*b3+my_count[9]*b5+my_count[10]*b6;
                                    if(b_total<=RB&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b6>=BDmin&&b6<=BDmax)
                                    {
                                        mark=1;
                                        //U1=Um(b1);
                                        //U2=Ud(b2);
                                        U3=Um1(b3);
                                        //U4=Ud1(b4);
                                        U5=Um2(b5);
                                        U6=Ud2(b6);
                                        Uz=my_count[0]*Uv+(my_count[5]-del)*U3+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2;
                                        if(Uz>temp)
                                        {
                                            temp=Uz;
                                            returnband[0]=b1;
                                            returnband[1]=b2;
                                            returnband[2]=b3;
                                            returnband[3]=b4;
                                            returnband[4]=b5;
                                            returnband[5]=b6;
                                        }
                                    }
                                    else
                                    {
                                        // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                                    }

                                }
                                if(mark==1) break;

                            }
                            if(mark==1)
                            {
                                Umax=temp;
                                returnband[6]=mark;
                                returnband[7]=5;
                                returnband[8]=del;
                                //cout<<"接入二级流媒体业务成功!"<<endl;
                                //cout<<"一级流媒体业务被踢出个数="<<del<<endl;
                                //cout<<"Umax="<<Umax<<endl;
                                //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                                //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                                //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                                //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                                //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                                //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                                //cout<<"b_media="<<b_media<<endl;
                                //cout<<"b_data="<<b_data<<endl;
                                //cout<<"b_media1="<<b_media1<<endl;
                                //cout<<"b_data1="<<b_data1<<endl;
                                //cout<<"b_media2="<<b_media2<<endl;
                                //cout<<"b_data2="<<b_data2<<endl;
                                Bz=my_count[0]*BV+my_count[3]*BV+my_count[4]*BV+(my_count[5]-del)*b_media1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                                //cout<<"Bz="<<Bz<<endl;
                                my_count[5]=my_count[5]-del;
                            }
                            else
                            {
                                my_count[9]=my_count[9]-1;
                                returnband[6]=0;
                                //cout<<"接入二级流媒体失败！当前个数:"<<my_count[9]<<endl;
                            }
                        }
                    }
                }
            }

        }

        break;
    }//case9

    case 10:
    {
        my_count[10]++;
        if(Lb>=BDmax)
        {
            Lb=Lb-BDmax;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********二级数据业务个数为"<<my_count[10]<<endl;
        }
        else if(Lb>=0&&Lb<BDmax)
        {
            RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
            temp=0;
            mark=0;
            returnband[6]=mark;
            for(n=jingdu; n<mk; n=n+jingdu)
            {
                b1=bm(n);
                b2=bd(n);
                b3=bm1(n);
                b4=bd1(n);
                b5=bm2(n);
                b6=bd2(n);
                b_total=my_count[1]*b1+my_count[2]*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                {
                    mark=1;
                    U1=Um(b1);
                    U2=Ud(b2);
                    U3=Um1(b3);
                    U4=Ud1(b4);
                    U5=Um2(b5);
                    U6=Ud2(b6);
                    Uz=my_count[1]*U1+my_count[2]*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                    if(Uz>temp)
                    {
                        temp=Uz;
                        returnband[0]=b1;
                        returnband[1]=b2;
                        returnband[2]=b3;
                        returnband[3]=b4;
                        returnband[4]=b5;
                        returnband[5]=b6;
                    }
                }
                else
                {
                    // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                }

            }
            if(mark==1)
            {
                Umax=temp;
                returnband[6]=mark;
                //cout<<"接入二级数据业务业务成功!"<<endl;
                //cout<<"Umax="<<Umax<<endl;
                //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                //cout<<"b_media="<<b_media<<endl;
                //cout<<"b_data="<<b_data<<endl;
                //cout<<"b_media1="<<b_media1<<endl;
                //cout<<"b_data1="<<b_data1<<endl;
                //cout<<"b_media2="<<b_media2<<endl;
                //cout<<"b_data2="<<b_data2<<endl;
                Bz=my_count[0]*BV+my_count[1]*b_media+my_count[2]*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                //cout<<"Bz="<<Bz<<endl;
            }
            else
            {
                RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                temp=0;
                mark=0;
                returnband[6]=mark;
                for(del=1; del<=my_count[2]; del++)
                {
                    for(n=jingdu; n<mk; n=n+jingdu)
                    {
                        b1=bm(n);
                        b2=bd(n);
                        b3=bm1(n);
                        b4=bd1(n);
                        b5=bm2(n);
                        b6=bd2(n);
                        b_total=my_count[1]*b1+(my_count[2]-del)*b2+my_count[5]*b3+my_count[6]*b4+my_count[9]*b5+my_count[10]*b6;
                        if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b2>=BDmin&&b2<=BDmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                        {
                            mark=1;
                            U1=Um(b1);
                            U2=Ud(b2);
                            U3=Um1(b3);
                            U4=Ud1(b4);
                            U5=Um2(b5);
                            U6=Ud2(b6);
                            Uz=my_count[1]*U1+(my_count[2]-del)*U2+my_count[0]*Uv+my_count[5]*U3+my_count[6]*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                            if(Uz>temp)
                            {
                                temp=Uz;
                                returnband[0]=b1;
                                returnband[1]=b2;
                                returnband[2]=b3;
                                returnband[3]=b4;
                                returnband[4]=b5;
                                returnband[5]=b6;
                            }
                        }
                        else
                        {
                            // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                        }

                    }
                    if(mark==1) break;

                }
                if(mark==1)
                {
                    Umax=temp;
                    returnband[6]=mark;
                    returnband[7]=2;
                    returnband[8]=del;
                    //cout<<"接入业务二级数据业务成功!"<<endl;
                    //cout<<"普通数据业务被踢出个数="<<del<<endl;
                    //cout<<"Umax="<<Umax<<endl;
                    //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                    //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                    //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                    //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                    //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                    //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                    //cout<<"b_media="<<b_media<<endl;
                    //cout<<"b_data="<<b_data<<endl;
                    //cout<<"b_media1="<<b_media1<<endl;
                    //cout<<"b_data1="<<b_data1<<endl;
                    //cout<<"b_media2="<<b_media2<<endl;
                    //cout<<"b_data2="<<b_data2<<endl;
                    Bz=my_count[0]*BV+my_count[1]*b_media+(my_count[2]-del)*b_data+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+my_count[6]*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                    //cout<<"Bz="<<Bz<<endl;
                    my_count[2]=my_count[2]-del;
                }
                else
                {
                    returnband[9]=2;
                    returnband[10]=my_count[2];
                    my_count[2]=0;
                    RB=LBK-my_count[0]*BV-my_count[3]*BV-my_count[4]*BV-my_count[7]*BV-my_count[8]*BV-my_count[11]*BV;
                    temp=0;
                    mark=0;
                    returnband[6]=mark;
                    for(del=1; del<=my_count[6]; del++)
                    {
                        for(n=jingdu; n<mk; n=n+jingdu)
                        {
                            b1=bm(n);
                            b2=0;
                            b3=bm1(n);
                            b4=bd1(n);
                            b5=bm2(n);
                            b6=bd2(n);
                            b_total=my_count[1]*b1+my_count[5]*b3+(my_count[6]-del)*b4+my_count[9]*b5+my_count[10]*b6;
                            if(b_total<=RB&&b1>=BMmin&&b1<=BMmax&&b3>=BMmin&&b3<=BMmax&&b5>=BMmin&&b5<=BMmax&&b4>=BDmin&&b4<=BDmax&&b6>=BDmin&&b6<=BDmax)
                            {
                                mark=1;
                                U1=Um(b1);
                                //U2=Ud(b2);
                                U3=Um1(b3);
                                U4=Ud1(b4);
                                U5=Um2(b5);
                                U6=Ud2(b6);
                                Uz=my_count[1]*U1+my_count[0]*Uv+my_count[5]*U3+(my_count[6]-del)*U4+my_count[4]*Uv1+my_count[9]*U5+my_count[10]*U6+my_count[8]*Uv2+my_count[3]*Uv+my_count[7]*Uv1+my_count[11]*Uv2;
                                if(Uz>temp)
                                {
                                    temp=Uz;
                                    returnband[0]=b1;
                                    returnband[1]=b2;
                                    returnband[2]=b3;
                                    returnband[3]=b4;
                                    returnband[4]=b5;
                                    returnband[5]=b6;
                                }
                            }
                            else
                            {
                                // cout<<"error£¬ÊýŸÝ²»·ûºÏ£¡"<<endl;
                            }

                        }
                        if(mark==1) break;

                    }
                    if(mark==1)
                    {
                        Umax=temp;
                        returnband[6]=mark;
                        returnband[7]=6;
                        returnband[8]=del;
                        //cout<<"接入业务二级数据业务成功!"<<endl;
                        //cout<<"一级数据业务被踢出个数="<<del<<endl;
                        //cout<<"Umax="<<Umax<<endl;
                        //cout<<"U_media="<<Um(b_media)*my_count[1]<<endl;
                        //cout<<"U_data="<<Ud(b_data)*my_count[2]<<endl;
                        //cout<<"U_media1="<<Um1(b_media1)*my_count[5]<<endl;
                        //cout<<"U_data1="<<Ud1(b_data1)*my_count[6]<<endl;
                        //cout<<"U_media2="<<Um2(b_media2)*my_count[9]<<endl;
                        //cout<<"U_data2="<<Ud2(b_data2)*my_count[10]<<endl;
                        //cout<<"b_media="<<b_media<<endl;
                        //cout<<"b_data="<<b_data<<endl;
                        //cout<<"b_media1="<<b_media1<<endl;
                        //cout<<"b_data1="<<b_data1<<endl;
                        //cout<<"b_media2="<<b_media2<<endl;
                        //cout<<"b_data2="<<b_data2<<endl;
                        Bz=my_count[0]*BV+my_count[1]*b_media+my_count[3]*BV+my_count[4]*BV+my_count[5]*b_media1+(my_count[6]-del)*b_data1+my_count[7]*BV+my_count[8]*BV+my_count[9]*b_media2+my_count[10]*b_data2+my_count[11]*BV;
                        //cout<<"Bz="<<Bz<<endl;
                        my_count[6]=my_count[6]-del;
                    }
                    else
                    {
                        my_count[10]=my_count[10]-1;
                        returnband[6]=0;
                        //cout<<"接入二级数据业务失败！当前个数:"<<my_count[10]<<endl;
                    }
                }
            }
        }
        break;
    }//case10

    case 11:
    {
        my_count[11]++;
        if(Lb>=BV)
        {
            Lb=Lb-BV;
            returnband[0]=128;
            returnband[1]=128;
            returnband[2]=128;
            returnband[3]=128;
            returnband[4]=128;
            returnband[5]=128;
            returnband[6]=1;
            //cout<<"**********二级切换语音业务个数为"<<my_count[11]<<endl;
        }
        else if(Lb>=0&&Lb<BV)
        {
            Umaxjs1(11);
        }
    }//case11

    }  //switch

}
/*int main()
{
	// int my_count[12]={0},m,Uv=3,Uv1=6,Uv2=9,mark=0,del=0;
    // float Umax=0,Lb=66000,temp=0,RB,n,b1,b2,b3,b4,b5,b6,b_total,U1,U2,U3,U4,U5,U6,Uz,b_media,b_data,b_media1,b_data1,b_media2,b_data2,Bz;
	 int *p=new int[size_total];
	  p=asrand();
	 // system("pause");
	 int *p1=new int[size_total];
	 for(int m=0;m<size_total;m++)
	 {
		 p1[m]=p[m];
	         switchcasein(p1[m]);
         }//for
         for(int m=0;m<200;m++)
	 {
		 p1[m]=p[m];
	         switchcaseout(p1[m]);
         }
	  cout<<"my_count0:"<<my_count[0]<<endl;
	  cout<<"my_count1:"<<my_count[1]<<endl;
	  cout<<"my_count2:"<<my_count[2]<<endl;
	  cout<<"my_count3:"<<my_count[3]<<endl;
	  cout<<"my_count4:"<<my_count[4]<<endl;
	  cout<<"my_count5:"<<my_count[5]<<endl;
	  cout<<"my_count6:"<<my_count[6]<<endl;
	  cout<<"my_count7:"<<my_count[7]<<endl;
	  cout<<"my_count8:"<<my_count[8]<<endl;
	  cout<<"my_count9:"<<my_count[9]<<endl;
	  cout<<"my_count10:"<<my_count[10]<<endl;
	  cout<<"my_count11:"<<my_count[11]<<endl;
	     char k12;
             cin>>k12;
return 0;
}*/
