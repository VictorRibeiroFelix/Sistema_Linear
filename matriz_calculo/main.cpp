#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, d;
    int a2, b2, c2, d2;
    int a3, b3, c3, d3;

    cout << "\nEnsira o valor A: ";
    cin >> a;
    cout << "\nEnsira o valor B: ";
    cin >> b;
    cout << "\nEnsira o valor C: ";
    cin >> c;
    cout << "\nEnsira o valor D: ";
    cin >> d;
    cout << "\nEnsira o valor A2: ";
    cin >> a2;
    cout << "\nEnsira o valor B2: ";
    cin >> b2;
    cout << "\nEnsira o valor C2: ";
    cin >> c2;
    cout << "\nEnsira o valor D2: ";
    cin >> d2;
    cout << "\nEnsira o valor A3: ";
    cin >> a3;
    cout << "\nEnsira o valor B3: ";
    cin >> b3;
    cout << "\nEnsira o valor C3: ";
    cin >> c3;
    cout << "\nEnsira o valor D3: ";
    cin >> d3;

    cout << endl;

    cout <<"\n" << a <<"x + " << b <<"y + " << c <<"z = "<< d;
    cout <<"\n" << a2 <<"x + " << b2 <<"y + " << c2 <<"z = "<< d2;
    cout <<"\n" << a3 <<"x + " << b3 <<"y + " << c3 <<"z = "<< d3;

    cout << endl;

    float B = 0, B2 = 0, B3 = 0;
    cout << "\n\nVerificacao de convergencia";

    B = fabs(((b + c) / static_cast<float>(a)));
    B2 = fabs((((a2 * B) + c2) / static_cast<float>(b2)));
    B3 = fabs((((a3 * B) + (b3 * B2)) / static_cast<float>(c3)));

    cout << "\nB1: " << B;
    cout << "\nB2: " << B2;
    cout << "\nB3: " << B3;

    cout << endl;

    if (B > B2 && B > B3) {
        if (B < 1) {
            cout << "\nB1 = " << B << " < 1" << " Converge" << endl;
        } else cout << "B1 nao converge";
    } else if (B2 > B3 && B2 > B) {
        if (B2 < 1) {
            cout << "\nB2 = " << B2 << " < 1" << " Converge" << endl;
        } else cout << "B2 nao converge";
    } else if (B3 > B2 && B3 > B) {
        if (B3 < 1) {
            cout << "\nB3 = " << B3 << " < 1" << " Converge" << endl;
        } else cout << "B3 nao converge";
    }

    float E = 0.05, auxX = 0.00, auxY = 0.00, auxZ = 0.00, rX = 0.00, rY = 0.00, rZ = 0.00, Er = 1.00;
    float X = 0.00, Y = 0.00, Z = 0.00;

    cout <<"\n\nSolucao inicial";

    X = (d / static_cast<float>(a));
    Y = (d2 / static_cast<float>(b2));
    Z = (d3 / static_cast<float>(c3));

    cout << "\nX " << X;
    cout << "\nY " << Y;
    cout << "\nZ " << Z;

    cout << endl;

    int i = 0;
    while (Er > E && B != 1 || B2 != 1 || B3 != 1) {
        auxX = X;
        auxY = Y;
        auxZ = Z;

        cout << "\n\nK =" << i << " : " << (i + 1) << " Iteracao" << endl;

        X = (1 / static_cast<float>(a)) * (d - (b * Y) - (c * Z));
        Y = (1 / static_cast<float>(b2)) * (d2 - (a2 * X) - (c2 * Z));
        Z = (1 / static_cast<float>(c3)) * (d3 - (a3 * X) - (b3 * Y));

        cout << "\nX" << (i + 1) << " = " << " (1/a) * (d - (b*Y) - (c*Z)) = " << X;
        cout << "\nY" << (i + 1) << " = " << " (1/b2) * (d2 - (a2*X) - (c2*Z)) = " << Y;
        cout << "\nZ" << (i + 1) << " = " << " (1/c3) * (d3 - (a3*X) - (b3*Y)) = " << Z;

        cout << endl;

        cout << "\nX " << X;
        cout << "\nY " << Y;
        cout << "\nZ " << Z;

        cout << endl;

        rX = fabs(X - auxX);
        rY = fabs(Y - auxY);
        rZ = fabs(Z - auxZ);

        cout << endl;

        cout << "\n|" << X << " - " << auxX << "| = " << rX;
        cout << "\n|" << Y << " - " << auxY << "| = " << rY;
        cout << "\n|" << Z << " - " << auxZ << "| = " << rZ;

        cout << endl;
        cout << endl;

        if (rX > rY && rX > rZ) {
            if (X > Y && X > Z) {
                Er = fabs((rX / X));
                cout << "||x" << (i + 1) << " - " << "x" << (i) << "||" << " / " << "x" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            } else if (Y > X && Y > Z) {
                Er = fabs((rY / Y));
                cout << "||x" << (i + 1) << " - " << "x" << (i) << "||" << " / " << "y" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            } else if (Z > X && Z > Y) {
                Er = fabs((rZ / Z));
                cout << "||x" << (i + 1) << " - " << "x" << (i) << "||" << " / " << "z" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            }
            cout << endl;
        } else if (rY > rZ && rY > rX) {
            if (X > Y && X > Z) {
                Er = fabs((rX / X));
                cout << "||y" << (i + 1) << " - " << "y" << (i) << "||" << " / " << "x" << (i + 1) << " = " << Er;
                cout << endl;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            } else if (Y > X && Y > Z) {
                Er = fabs((rY / Y));
                cout << "||y" << (i + 1) << " - " << "y" << (i) << "||" << " / " << "y" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            } else if (Z > X && Z > Y) {
                Er = fabs((rZ / Z));
                cout << "||y" << (i + 1) << " - " << "y" << (i) << "||" << " / " << "z" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            }
            cout << endl;
        } else if (rZ > rX && rZ > rY) {
            if (X > Y && X > Z) {
                Er = fabs((rX / X));
                cout << "||z" << (i + 1) << " - " << "z" << (i) << "||" << " / " << "x" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            } else if (Y > X && Y > Z) {
                Er = fabs((rY / Y));
                cout << "||z" << (i + 1) << " - " << "z" << (i) << "||" << " / " << "y" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            } else if (Z > X && Z > Y) {
                Er = fabs((rZ / Z));
                cout << "||z" << (i + 1) << " - " << "z" << (i) << "||" << " / " << "z" << (i + 1) << " = " << Er;
                cout << endl;
                if (Er <= E) {
                    cout << Er << " <= " << E << endl;
                    cout << "\nX " << X;
                    cout << "\nY " << Y;
                    cout << "\nZ " << Z;
                }
                cout << endl;
            }
        }

            i++;
    }

    cout << "\n\nSolucao final apos " << i << " Iteracoes:";
    cout << "\nX = " << X;
    cout << "\nY = " << Y;
    cout << "\nZ = " << Z;
    cout << endl;

    return 0;
}
