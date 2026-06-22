#include "dna.h"
#include "aminokwasy.h"

string dna_mrna(string dna)
{
    string mrna = "";

    for (int i = 0; i < dna.length(); i++)
    {
        if (dna[i] == 'A')
            mrna += 'U';
        else if (dna[i] == 'T')
            mrna += 'A';
        else if (dna[i] == 'G')
            mrna += 'C';
        else if (dna[i] == 'C')
            mrna += 'G';
    }

    return mrna;
}

int find_start(string mrna)
{
    for (int i = 0; i < mrna.length() - 2; i++)
    {
        if (mrna.substr(i, 3) == "AUG")
            return i;
    }

    return -1;
}

string kodon_na_aminokwas(string kodon)
{
    for (int i = 0; i < N; i++)
    {
        if (kodony[i] == kodon)
            return aminokwasy[i];
    }

    return "Nieznany";
}
#include "aminokwasy.h"

string kodony[N] =
{
    "UUU","UUC","UUA","UUG",
    "UCU","UCC","UCA","UCG",
     "UAU","UAC","UAA","UAG",
    "UGU","UGC","UGA","UGG",

    "CUU","CUC","CUA","CUG",
    "CCU","CCC","CCA","CCG",
    "CAU","CAC","CAA","CAG",
    "CGU","CGC","CGA","CGG",

    "AUU","AUC","AUA","AUG",
    "ACU","ACC","ACA","ACG",
    "AAU","AAC","AAA","AAG",
    "AGU","AGC","AGA","AGG",

    "GUU","GUC","GUA","GUG",
    "GCU","GCC","GCA","GCG",
    "GAU","GAC","GAA","GAG",
    "GGU","GGC","GGA","GGG"
};

string aminokwasy[N] =
{
    "Fenyloalanina","Fenyloalanina","Leucyna","Leucyna",
    "Seryna","Seryna","Seryna","Seryna",
    "Tyrozyna","Tyrozyna","STOP","STOP",
    "Cysteina","Cysteina","STOP","Tryptofan",

    "Leucyna","Leucyna","Leucyna","Leucyna",
    "Prolina","Prolina","Prolina","Prolina",
    "Histydyna","Histydyna","Glutamina","Glutamina",
    "Arginina","Arginina","Arginina","Arginina",

    "Izoleucyna","Izoleucyna","Izoleucyna","Metionina",
    "Treonina","Treonina","Treonina","Treonina",
    "Asparagina","Asparagina","Lizyna","Lizyna",
    "Seryna","Seryna","Arginina","Arginina",

    "Walina","Walina","Walina","Walina",
    "Alanina","Alanina","Alanina","Alanina",
    "Kwas asparaginowy","Kwas asparaginowy","Kwas glutaminowy","Kwas glutaminowy",
    "Glicyna","Glicyna","Glicyna","Glicyna"
};