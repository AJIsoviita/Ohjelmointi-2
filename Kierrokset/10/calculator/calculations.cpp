// Note that there is no need for "using namespace std",
// since no C++ standard libraries are used.

double addition(double left, double right) {
    return left + right;
}


double subtraction(double left, double right) {
    return left - right;
}


double multiplication(double left, double right) {
    return left * right;
}


double division(double left, double right) {
    return left / right;
}


double exponent(double left, double right) {
    int i = 0;
    int result = 0;
    if(left == 1 and right == 1)
        result = 1;
    else if(left == 0)
        result = 0;
    else if(right == 0)
        result = 1;
    else
    {
        while(i <= right)
        {
            result += left;
            i++;
        }
    }

    return result;
}
