/**
* 分数的四则运算
* 结果注意化简
**/


/**
* 分数的加法
* 公式：result = (f1.up * f2.down + f2.up * f1.down) / (f1.down * f2.down)
**/
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down + f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

/**
* 分数的减法
* 公式：result = (f1.up * f2.down - f2.up * f1.down) / (f1.down * f2.down)
**/
Fraction minu(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down - f2.up * f1.down;
    result.down = f1.down * f2.down;
    return reduction(result);
}

/**
* 分数的乘法
* 公式：result = (f1.up * f2.up) / (f1.down * f2.down)
**/
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.up;
    result.down = f1.down * f2.down;
    return reduction(result);
}

/**
* 分数的除法
* 公式：result = (f1.up * f2.down) / (f1.down * f2.up)
**/
Fraction add(Fraction f1, Fraction f2) {
    Fraction result;
    result.up = f1.up * f2.down;
    result.down = f1.down * f2.up;
    return reduction(result);
}
