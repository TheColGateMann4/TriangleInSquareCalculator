#include <iostream>
#include <random> // std::_Pi

float MirrorNumber(float number, int numberAlpha)
{
    float mirroredNumber = numberAlpha - number;
   // std::cout << "mirroredNumber = numberAlpha - number:   " << mirroredNumber << " = " << numberAlpha << " - " << number << '\n';
    mirroredNumber = std::abs(mirroredNumber);
    return mirroredNumber;
}

float GetSeparatedAngle(float Angle)
{
    //std::cout << "Angle Before: " << Angle << '\n';
    Angle = (((Angle / 90) - std::floor(Angle / 90)) * 90);
   // std::cout << "Angle After: " << Angle << '\n';

    if (Angle > 45)
        Angle = MirrorNumber(Angle, 45);

    std::cout << "Angle After Mirroring: " << Angle << '\n';

    return Angle;
}

float TrueDistance(float Angle, float Distance)
{
    float a, b, c;
    float alpha, beta, gamma;
    float radAlpha, radBeta, radGamma;

    alpha = 90;
    beta = GetSeparatedAngle(Angle);
    radAlpha = alpha / (180.0 / std::_Pi);
    radBeta = beta / (180.0 / std::_Pi);
    radGamma = gamma = radAlpha - radBeta;

    //std::cout << "Gamma Before: " << gamma << '\n';
    radGamma = gamma = std::abs(gamma);

    gamma = gamma * (180.0 / std::_Pi);
    //std::cout << "Gamma after: " << gamma << '\n';

    c = Distance;
    b = c * sin(radAlpha) / sin(radGamma);
    a = c * sin(radBeta) / sin(radGamma);

    b = std::abs(b);
    a = std::abs(a);

    std::cout << '\n' 
        << "Alpha: " << alpha << " = " << radAlpha << " rad" << '\n'
        << "Beta: " << beta << " = " << radBeta << " rad" << '\n'
        << "Gamma: " << gamma << " = " << radGamma << " rad" << '\n';

    // std::cout << "a = c * sin(alpha) (alpha) / sin(gamma) (gamma):  " << a << " = " << c << " * " << sin(radAlpha) << " (" << alpha << ") / " << sin(radGamma) << " (" << gamma << ")" << '\n';
    // std::cout << "b = c * sin(beta) (beta) / sin(gamma) (gamma):  " << b << " = " << c << " * " << sin(radBeta) << " (" << beta << ") / " << sin(radGamma) << " (" << gamma << ")" << '\n';
    
    std::cout << '\n'
        << "a = " << a << '\n'
        << "b = " << b << '\n'
        << "c = " << c << '\n';

    return b;
}

/*
    project 100% original


    this picture perfectly describes how to program works:
    https://imgur.com/a/dLIyiJ3

    for clarity, in program first we pass "x", then we pass "alpha", the
    naming in the picture is not directly how program works under the hood
    its only to understand what program calculates
*/

int main()
{
    float angle, distance;

    std::cout << "How much should it move... ";
    std::cin >> distance;
    std::cout << "Angle where it should move... ";
    std::cin >> angle;

    std::cout << '\n' << "Distance From Given Angle: " << TrueDistance(angle, distance);

    while (true) {  }
}
