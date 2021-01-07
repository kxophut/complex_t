#ifndef COMPLEX_T_H
#define COMPLEX_T_H

#include<iostream>

class complex_t {
private:
    double re, im;
public:
    complex_t(){
        re=0;
        im=0;
    }

    complex_t(double x,double y){
        re=x;
        im=y;
    }

    ~complex_t()=default;

    friend complex_t operator +(const complex_t& x, const complex_t& y) {
        complex_t t;
        t.re = x.re + y.re;
        t.im = x.im + y.im;
        return t;
    }//Оператор сложения комплексных чисел

    friend void operator +=(complex_t& x, const complex_t& y) {
        x.re = x.re + y.re;
        x.im = x.im + y.im;
    }//оператор сложения комплексных чисел c присвоением

    friend void operator -=(complex_t& x, const complex_t& y) {
        x.re = x.re - y.re;
        x.im = x.im - y.im;
    }//оператор вычитания комплексных чисел с присвоением

    friend complex_t operator -(const complex_t& x, const complex_t& y) {
        complex_t t;
        t.re = x.re - y.re;
        t.im = x.im - y.im;
        return t;
    }//оператор вычитания комплексных чисел

    friend complex_t operator -(const complex_t& x){
        complex_t t;
        t.re=-x.re;
        t.im=-x.im;
        return t;
    }//унарный минус

    friend complex_t operator --(const complex_t& x){
        complex_t t;
        t.re=x.re;
        t.im=-x.im;
        return t;
    }//Комплексно-сопряженное

    friend complex_t operator +(const complex_t& x){ return x; }//Унарный плюс (ничего не меняет)

    friend complex_t operator *(const complex_t& x, const complex_t &y) {
        complex_t t;
        t.re = x.re * y.re - x.im * y.im;
        t.im = x.im * y.re + y.re * x.im;
        return t;
    }//Оператор умножения комплексных чисел

    friend complex_t operator *(const double& y, const complex_t& x) {
        complex_t t;
        t.re = x.re * y;
        t.im = x.im * y;
        return t;
    }//Оператор умножения действительного числа на комплексное

    friend complex_t operator *(const complex_t& x, const double& y) {
        complex_t t;
        t.re = x.re * y;
        t.im = x.im * y;
        return t;
    }//Оператор умножения комплексного числа на действительное

    friend complex_t operator /(const complex_t &x, const complex_t &y) {
        complex_t t;
        t.re = (x.re * y.re + x.im * y.im) / (y.re * y.re + y.im * y.im);
        t.im = (x.im * y.re - x.re * y.im) / (y.re * y.re + y.im * y.im);
        return t;
    }//Оператор деления комплексных чисел

    double GetRe(){
        return re;
    }//Берем действительную часть (без мнимой единицы i)

    double GetIm(){
        return im;
    }//Берем мнимую часть(с мнимой единицей i)

    void SetRe(double re_){re=re_;}//Устанавливаем действительную часть

    void SetIm(double im_){im=im_;}//Устанавливаем мнимую часть

    friend std::ostream& operator <<(std::ostream &out, const complex_t &complex){
        out<<"("<<complex.re<<","<<complex.im<<")";
        return out;
    }//Вывод комплексного числа
};

#endif
