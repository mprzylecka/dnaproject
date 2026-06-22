#include <iostream>
#include <fstream>
#include <string>

#include "dna.h"
#include "aminokwasy.h"

using namespace std;

int main()
{
    ifstream plik_txt("/Users/majaprzylecka/Desktop/programowanie/untitled1/seq.txt");

    if (!plik_txt.is_open())
    {
        cout << "Nie można otworzyć pliku!" << endl;
        return 1;
    }

    string dna;
    string linia;

    while (getline(plik_txt, linia))
    {
        dna += linia;
    }

    plik_txt.close();

    cout << "DNA: " << dna << endl;

    string mrna = dna_mrna(dna);

    cout << "mRNA: " << mrna << endl;

    int start = find_start(mrna);

    if (start == -1)
    {
        cout << "Nie znaleziono START (AUG)" << endl;
        return 0;
    }

    cout << "START znaleziony na pozycji: " << start << endl;

    cout << "\nKodony:\n";

    string znalezione[1000];
    int liczba_aminokwasow = 0;

    cout << "\nAminokwasy:\n";

    for (int i = start; i < mrna.length() - 2; i += 3)
    {
        string kodon = mrna.substr(i, 3);

        string aminokwas = kodon_na_aminokwas(kodon);

        if (aminokwas == "STOP")
        {
            cout << "STOP\n";
            break;
        }

        cout << kodon << " -> " << aminokwas << endl;

        znalezione[liczba_aminokwasow] = aminokwas;
        liczba_aminokwasow++;
    }
    cout << "\nLiczba znalezionych aminokwasow: "
     << liczba_aminokwasow << endl;
    cout << "\nStatystyka aminokwasow:\n";

    for (int i = 0; i < liczba_aminokwasow; i++)
    {
        bool juz_liczony = false;

        for (int j = 0; j < i; j++)
        {
            if (znalezione[i] == znalezione[j])
            {
                juz_liczony = true;
                break;
            }
        }

        if (!juz_liczony)
        {
            int licznik = 0;

            for (int j = 0; j < liczba_aminokwasow; j++)
            {
                if (znalezione[i] == znalezione[j])
                {
                    licznik++;
                }
            }

            cout << znalezione[i]
                 << " : "
                 << licznik
                 << endl;
        }
    }

    return 0;
}