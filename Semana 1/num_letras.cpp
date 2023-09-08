#include <string>
#include <iostream>

using namespace std;

string unidades[] = {"cero", "uno", "dos", "tres", "cuatro", "cinco",
                     "seis", "siete", "ocho", "nueve", "diez"};

string especiales[] = {"once", "doce", "trece", "catorce", "quince",
                       "dieciséis", "diecisiete", "dieciocho", "diecinueve"};

string decenas[] = {"veinte", "treinta", "cuarenta", "cincuenta", "sesenta",
                    "setenta", "ochenta", "noventa"};

string centenas[] = {"cien", "doscientos", "trescientos", "cuatrocientos", "quinientos",
                     "seiscientos", "setecientos", "ochocientos", "novecientos"};

string miles[] = {"mil"};

string convertirNumero(int num)
{
    if (num >= 0 && num <= 10)
        return unidades[num];
    else if (num < 20)
        return especiales[num - 11];
    else if (num < 100)
    {
        int unid = num % 10;
        int dec = num / 10;
        if (unid == 0)
            return decenas[dec - 2];
        else
            return decenas[dec - 2] + " y " + unidades[unid];
    }
    else if (num < 1000)
    {
        int cent = num / 100;
        int resto = num % 100;
        if (resto == 0)
            return centenas[cent - 1];
        else
            return centenas[cent - 1] + " " + convertirNumero(resto);
    }
    else if (num < 1000000)
    {
        int mil = num / 1000;
        int resto = num % 1000;
        if (mil == 1 && resto == 0)
            return miles[0];
        else if (mil == 1)
            return miles[0] + " " + convertirNumero(resto);
        else if (resto == 0)
            return convertirNumero(mil) + " " + miles[0];
        else
            return convertirNumero(mil) + " " + miles[0] + " " + convertirNumero(resto);
    }
    else
        return "Número fuera de rango";
}

int main()
{
    cout << "Ingrese un numero entre 0-1000000: ";
    int num;
    cin >> num;

    cout << convertirNumero(num) << endl;
    return 0;
}
