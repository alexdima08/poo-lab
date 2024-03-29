#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

ifstream f("animale.txt");
ifstream f1("client.in");
ifstream f2("accesorii.in");
ifstream f3("hrana.in");
ofstream g("animale.out");
ofstream g1("client.out");
ofstream g2("accesorii.out");
ofstream g3("hrana.out");
int poz,poz2;

class Animale
{
private:
    char tip_animal[30];
    char *rasa_animal;
    bool vaccinat;
    float greutate;
    const int ID_Animal;
    float pret;
    char gen;
    static int nr_animale;
    int varsta;
    float *gr = new float[30];
public:
    void setTipAnimal(char tip_animal[30])
    {
        //this->tip_animal = tip_animal;
        strcpy(this->tip_animal,tip_animal);
    }
    char *getTipAnimal()
    {
        return this->tip_animal;
    }
    void setRasaAnimal(char* rasa_animal)
    {
        if(this->rasa_animal!=nullptr)
            delete[] this->rasa_animal;

        this->rasa_animal = new char[strlen(rasa_animal)+1];
        strcpy(this->rasa_animal,rasa_animal);
    }
    char* getRasaAnimal()
    {
        return this->rasa_animal;
    }
    void setGen(char gen)
    {
        this->gen = gen;
    }
    char getGen()
    {
        return this->gen;
    }
    void setGretutate(float greutate)
    {
        this->greutate = greutate;
    }
    float getGreutate()
    {
        return this->greutate;
    }
    const int getIdAnimal()
    {
        return this->ID_Animal;
    }
    void setPret(float pret)
    {
        this->pret = pret;
    }
    float getPret()
    {
        return this->pret;
    }
    void setVaccinat(bool vaccinat)
    {
        this->vaccinat = vaccinat;
    }
    bool getVaccinat()
    {
        return this->vaccinat;
    }
    void setVarsta(int varsta)
    {
        this->varsta = varsta;
    }
    int getVarsta()
    {
        return this->varsta;
    }
    float *getGr()
    {
        return gr;
    }
    Animale():ID_Animal(0000)
    {
        strcpy(this->tip_animal,"Anonim");
        this->rasa_animal = new char[strlen("Anonima")+1];
        strcpy(this->rasa_animal,"Anonima");
        this->greutate = 0;
        this->pret = 0;
        this->varsta = 0;
        this->nr_animale++;
    }
    Animale(int id,char tip_animal[30],char *rasa_animal):ID_Animal(id)
    {
        strcpy(this->tip_animal,tip_animal);
        this->rasa_animal = new char[strlen(rasa_animal)+1];
        strcpy(this->rasa_animal,rasa_animal);
        this->greutate = 0;
        this->pret = 0;
        this->varsta = 0;
        this->nr_animale++;
    }
    Animale(int id,char tip_animal[30],char *rasa_animal,float greutate,float pret,bool vaccinat,int varsta,char gen):ID_Animal(id)
    {
        strcpy(this->tip_animal,tip_animal);
        this->rasa_animal = new char[strlen(rasa_animal)+1];
        strcpy(this->rasa_animal,rasa_animal);
        this->greutate = greutate;
        this->pret = pret;
        this->vaccinat = vaccinat;
        this->varsta = varsta;
        this->gen = gen;
        this->nr_animale++;
    }
    Animale(const Animale &obj):ID_Animal(obj.ID_Animal)
    {
        strcpy(this->tip_animal,obj.tip_animal);
        this->rasa_animal = new char[strlen(obj.rasa_animal)+1];
        strcpy(this->rasa_animal,obj.rasa_animal);
        this->greutate = obj.greutate;
        this->pret = obj.pret;
        this->vaccinat = obj.vaccinat;
        this->varsta = obj.varsta;
        this->gen = obj.gen;
    }
    Animale &operator=(const Animale &obj)
    {
        if( this != &obj)
        {
            strcpy(this->tip_animal,obj.tip_animal);
            if(this->rasa_animal!=nullptr)
                delete[] this->rasa_animal;
            this->rasa_animal = new char[strlen(obj.rasa_animal)+1];
            strcpy(this->rasa_animal,obj.rasa_animal);
            this->greutate = obj.greutate;
            this->pret = obj.pret;
            this->vaccinat = obj.vaccinat;
            this->varsta = obj.varsta;
            this->gen = obj.gen;
        }
        return *this;
    }
    Animale operator++();
    Animale operator++(int);
    Animale operator+(float);
    Animale operator-(float);
    bool operator ==(Animale&);
    bool operator <(Animale&);
//    istream &operator>>( istream  &input, Animale &D )
//    {
//        input >> D.rasa_animal >> D.tip_animal;
//        return input;
//    }
    friend istream &operator>>(istream &input,Animale &obj)
    {
        char copie[30];
        cout <<"introduceti tipul de animal: ";
        input >> obj.tip_animal;
        cout <<"introduceti rasa animalului: ";
        input >>copie;
        if(obj.rasa_animal!=nullptr)
            delete[] obj.rasa_animal;
        obj.rasa_animal = new char[strlen(copie)+1];
        strcpy(obj.rasa_animal,copie);
        cout<<"introduceti greutatea animalului: ";
        input>> obj.greutate;
        cout<<"introduceti pretul animalului: ";
        input>> obj.pret;
        cout<<"spuneti daca animalul este vaccinat sau nu este vaccinat(1 daca este vaccinat, 0 daca nu este vaccinat): ";
        input>>obj.vaccinat;
        cout<<"introduceti varsta animalului: ";
        input>> obj.varsta;
        try
        {
            if(obj.varsta < 0)
                throw 'f';
        }
        catch(char x)
        {
            while(obj.varsta < 0)
            {
                cout<<"Eroare, animalul nu poate avea varsta negativa. Introduceti inca o data varsta animalului: ";
                input>>obj.varsta;
            }
        }
        cout<<"introduceti genul animalului(F sau M): ";
        input>>obj.gen;
        obj.gen = toupper(obj.gen);
        try
        {
            if (obj.gen!='F' && obj.gen != 'M')
                throw 1;

        }
        catch(int x)
        {

            while(obj.gen!='F' && obj.gen != 'M')
            {
                cout<<"Eroare, nu ati introdus corect. Introduceti inca o data va rog, F sau M: ";
                input>>obj.gen;
                obj.gen = toupper(obj.gen);
            }
        }
        nr_animale++;
        return input;

    }
    friend ifstream &operator>>(ifstream &input,Animale &obj)
    {
        char copie[30];
        input >> obj.tip_animal;
        input >>copie;
        if(obj.rasa_animal!=nullptr)
            delete[] obj.rasa_animal;
        obj.rasa_animal = new char[strlen(copie)+1];
        strcpy(obj.rasa_animal,copie);
        input>> obj.greutate;
        input>> obj.pret;
        input>>obj.vaccinat;
        input>> obj.varsta;
        input>>obj.gen;
        obj.gen = toupper(obj.gen);
        nr_animale++;
        return input;

    }
    friend ostream& operator<<(ostream &output, const Animale &obj)
    {
        if (obj.vaccinat == 1)
            output<<"Animalul este "<<obj.tip_animal<<", este de rasa "<<obj.rasa_animal<<", este de genul "<<obj.gen<<", cantareste "<<obj.greutate<<" kg , costa "<<obj.pret<<" lei, are varsta de "<<obj.varsta<<" ani si este vaccinat."<<endl;
        else
            output<<"Animalul este "<<obj.tip_animal<<", este de rasa "<<obj.rasa_animal<<", este de genul "<<obj.gen<<", cantareste "<<obj.greutate<<" kg , costa "<<obj.pret<<"lei , are varsta de "<<obj.varsta<<" ani si nu este vaccinat."<<endl;
        return output;
    }
    friend ofstream& operator<<(ofstream &output, const Animale &obj)
    {
        if (obj.vaccinat == 1)
            output<<"Animalul este "<<obj.tip_animal<<", este de rasa "<<obj.rasa_animal<<", este de genul "<<obj.gen<<", cantareste "<<obj.greutate<<" kg , costa "<<obj.pret<<" lei, are varsta de "<<obj.varsta<<" ani si este vaccinat."<<endl;
        else
            output<<"Animalul este "<<obj.tip_animal<<", este de rasa "<<obj.rasa_animal<<", este de genul "<<obj.gen<<", cantareste "<<obj.greutate<<" kg , costa "<<obj.pret<<"lei , are varsta de "<<obj.varsta<<" ani si nu este vaccinat."<<endl;
        return output;
    }
    void functionalitate_animal()
    {
        cout<<"buna ziua, as dori: "<<endl;
        int ok = 0,ok2,nr=0;
        float sum = 0;
        while(ok != 1)
        {
            Animale a;
            cin>>a;
            if(a.getVaccinat()== 1)
                cout<<"1 "<<a.getTipAnimal()<<", de rasa "<<a.getRasaAnimal()<<", de genul "<<a.getGen()<<", de greutate "<<a.getGreutate()<<" ,cu varsta de "<<a.getVarsta()<<" ani, vaccinat."<<endl;
            else
                cout<<"1 "<<a.getTipAnimal()<<", de rasa "<<a.getRasaAnimal()<<", de genul "<<a.getGen()<<", de greutate "<<a.getGreutate()<<" ,cu varsta de "<<a.getVarsta()<<" ani, nevaccinat."<<endl;
            sum = sum +a.getPret();
            nr++;
            cout<<"am notat,ati mai dori si altceva?daca da,apasati 1,daca nu apasati 0;"<<endl;
            cin>>ok2;
            if(ok2 == 0)
                ok = 1;
            else
                ok = 0;
        }
        cout<<"Ati cumparat un total de "<<nr<<" animale, care costa "<<sum<<" lei!";
    }
    void add_animal(Animale obj)
    {
        gr[poz++]=obj.getGreutate();
    }
    char operator [](int index)
    {
        if((index < strlen(tip_animal)) && index > 0)
            return tip_animal[index];
        else
        {
            cout<<"index invalid";
            return -1;
        }
    }
    explicit operator int()
    {
        return (int)pret;
    }


    ~Animale()
    {
        if (this->rasa_animal != nullptr)
            delete [] this->rasa_animal;
        if (this->gr != nullptr)
            delete [] this->gr;
    }
};

int Animale::nr_animale=0;
Animale Animale :: operator ++()
{
    this->pret++;
    return *this;
}
Animale Animale :: operator ++(int)
{
    this->pret++;
    return *this;
}
Animale Animale :: operator -(float x)
{
    this->pret -= x;
    return *this;
}
Animale Animale :: operator +(float x)
{
    this->pret += x;
    return *this;
}
bool Animale :: operator ==(Animale &obj)
{
    return this->pret == obj.pret;
}
bool Animale :: operator <(Animale &obj)
{
    return this->pret < obj.pret;
}

class Client
{
private:
    char *nume;
    char prenume[30];
    char initiala_tata;
    float greutate_client;
    float* resurse = new float[30];
    bool conditie;
    int varsta_client;
    static int nr_clienti;
    const int nr_telefon;
public:

    void setNume(char *nume)
    {
        if (this->nume != nullptr)
            delete[] this->nume;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    char *getNume()
    {
        return this->nume;
    }
    void setPrenume(char prenume[30])
    {
        strcpy(this->prenume,prenume);
    }
    char *getPrenume()
    {
        return this->prenume;
    }
    void setInitialaTata(char initiala_tata)
    {
        this->initiala_tata = initiala_tata;
    }
    char getInitialaTata()
    {
        return this->initiala_tata;
    }
    void setGreutateClient(float greutate_client)
    {
        this->greutate_client = greutate_client;
    }
    float getGreutateClient()
    {
        return this->greutate_client;
    }
    void setConditie(bool conditie)
    {
        this->conditie = conditie;
    }
    bool getConditie()
    {
        return this->conditie;
    }
    void setVarstaClient(int varsta_client)
    {
        this->varsta_client = varsta_client;
    }
    int getVarstaClient()
    {
        return this->varsta_client;
    }
    float *getResurse()
    {
        return resurse;
    }
    Client () : nr_telefon(0000000000)
    {
        this->nume = new char[strlen("Anonim")+1];
        strcpy(this->nume,"Anonim");
        strcpy(this->prenume,"Anonim");
        this->initiala_tata = '0';
        this->greutate_client = 0;
        this->varsta_client = 0;
        this->nr_clienti++;
    }
    Client(int id,char *nume,char prenume[30],char initiala_tata):nr_telefon(id)
    {
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->prenume,prenume);
        this->initiala_tata = initiala_tata;
        this->greutate_client = 0;
        this->varsta_client = 0;
        this->nr_clienti++;
    }
    Client (int id,char *nume,char prenume[30],char initiala_tata,float greutate_client,int varsta_client):nr_telefon(id)
    {
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        strcpy(this->prenume,prenume);
        this->initiala_tata = initiala_tata;
        this->greutate_client = greutate_client;
        this->varsta_client = varsta_client;
        this->nr_clienti++;
    }
    Client (const Client &obj):nr_telefon(obj.nr_telefon)
    {
        this->nume = new char[strlen(obj.nume)+1];
        strcpy(this->nume,obj.nume);
        strcpy(this->prenume,obj.prenume);
        this->initiala_tata = obj.initiala_tata;
        this->greutate_client = obj.greutate_client;
        this->varsta_client = obj.varsta_client;
    }
    Client &operator=(const Client &obj)
    {
        if(this != &obj)
        {
            this->nume = new char[strlen(obj.nume)+1];
            strcpy(this->nume,obj.nume);
            strcpy(this->prenume,obj.prenume);
            this->initiala_tata = obj.initiala_tata;
            this->greutate_client = obj.greutate_client;
            this->varsta_client = obj.varsta_client;
        }
        return *this;
    }
    Client operator++();
    Client operator++(int);
    Client operator+(float);
    Client operator-(float);
    bool operator ==(Client&);
    bool operator >(Client&);


    char operator [](int index)
    {
        if((index < strlen(prenume)) && index > 0)
            return prenume[index];
        else
        {
            cout<<"index invalid";
            return -1;
        }
    }
    explicit operator int()
    {
        return (int)greutate_client;
    }

    friend istream &operator>>(istream &input,Client &obj)
    {
        char copie[30];
        cout <<"introduceti numele clientului: ";
        input >> copie;
        if(obj.nume!=nullptr)
            delete[] obj.nume;
        obj.nume = new char[strlen(copie)+1];
        strcpy(obj.nume,copie);
        cout <<"introduceti initiala tatalui: ";
        input >>obj.initiala_tata;
        obj.initiala_tata = toupper(obj.initiala_tata);
        cout<<"introduceti prenumele clientului: ";
        input>> obj.prenume;
        cout<<"introduceti greutate clientului: ";
        input>> obj.greutate_client;
        cout<<"introduceti varsta clientului: ";
        input>>obj.varsta_client;
        nr_clienti++;
        return input;
    }
    friend ifstream &operator>>(ifstream &input,Client &obj)
    {
        char copie[30];
        input >> copie;
        if(obj.nume!=nullptr)
            delete[] obj.nume;
        obj.nume = new char[strlen(copie)+1];
        strcpy(obj.nume,copie);
        input >>obj.initiala_tata;
        obj.initiala_tata = toupper(obj.initiala_tata);
        input>> obj.prenume;
        input>> obj.greutate_client;
        input>>obj.varsta_client;
        nr_clienti++;
        return input;
    }
    friend ostream &operator<<(ostream &output, Client &obj )
    {
        output<<"Clientul "<<obj.nume<<" "<<obj.initiala_tata<<". "<<obj.prenume<<", de greutate "<<obj.greutate_client<<" si varsta de "<<obj.varsta_client<<" de ani,";
        if(obj.varsta_client < 18)
            obj.conditie = 0;
        else
            obj.conditie = 1;
        if(obj.conditie == 1)
            output<<" poate cumpara animal deoarece este major."<<endl;
        else
            output<<" nu poate cumpara animal deoarece nu este major."<<endl;
        return output;
    }
    friend ofstream &operator<<(ofstream &output, Client &obj )
    {
        output<<"Clientul "<<obj.nume<<" "<<obj.initiala_tata<<". "<<obj.prenume<<", de greutate "<<obj.greutate_client<<" si varsta de "<<obj.varsta_client<<" de ani,";
        if(obj.varsta_client < 18)
            obj.conditie = 0;
        else
            obj.conditie = 1;
        if(obj.conditie == 1)
            output<<" poate cumpara animal deoarece este major."<<endl;
        else
            output<<" nu poate cumpara animal deoarece nu este major."<<endl;
        return output;
    }
    void add_suma_bani()
    {
        float suma_bani;
        cout<<"adaugati o suma de bani in pe un card: ";
        cin>>suma_bani;

        resurse[poz2++] = suma_bani;
    }
    void functionalitate_client()
    {
        float suma;
        float saptamana[7];
        cout<<"Clientul "<<nume<<" "<<initiala_tata<<". "<<prenume<<" va primi un cupon de reducere de la magazin in functie de achizitiile sale in saptamana curenta"<<endl;
        for (int i = 0; i < 7; i++)
        {
            cout<<"In ziua "<<i+1<<" Clientul "<<nume<<" "<<initiala_tata<<". "<<prenume<<" a cheluit suma de lei egala cu: ";
            cin>>saptamana[i];
            suma += saptamana[i];
        }
        cout<<"La inceputul saptamanii urmatoare, clientul "<<nume<<" "<<initiala_tata<<". "<<prenume<<" va primi un cupon in valoare de "<<int(suma/7)<<" lei";
    }
    ~Client()
    {
        if(this->nume != nullptr)
            delete [] this->nume;
        if (this->resurse != nullptr)
            delete [] this->resurse;
    }
};

int Client :: nr_clienti = 0;

Client Client :: operator ++()
{
    this->greutate_client++;
    return *this;
}
Client Client :: operator ++(int)
{
    this->greutate_client++;
    return *this;
}
Client Client :: operator -(float x)
{
    this->greutate_client -= x;
    return *this;
}
Client Client :: operator +(float x)
{
    this->greutate_client += x;
    return *this;
}
bool Client :: operator ==(Client &obj)
{
    if( strcmp(this->nume,obj.nume) ==0 && strcmp(this->prenume,obj.prenume)== 0)
        return 1;
    return 0;
}
bool Client :: operator >(Client &obj)
{
    return this->greutate_client > obj.greutate_client;
}

class Accesorii
{
private:
    char nume_accesoriu[50];
    char culoare[30];
    float pret_accesoriu;
    char marime;
    int cod_accesoriu;
public:
    void setNumeAccesoriu(char nume_accesoriu[50])
    {
        strcpy(this->nume_accesoriu,nume_accesoriu);
    }
    char* getNumeAccesoriu()
    {
        return this->nume_accesoriu;
    }
    void setCuloare(char culoare[50])
    {
        strcpy(this->culoare,culoare);
    }
    char* getCuloare()
    {
        return this->culoare;
    }
    void setPretAccesoriu(float pret_accesoriu)
    {
        this->pret_accesoriu = pret_accesoriu;
    }
    float getPretAccesoriu()
    {
        return this->pret_accesoriu;
    }
    void setMarime(char marime)
    {
        this->marime = marime;
    }
    char getMarime()
    {
        return this->marime;
    }
    void setCodAccesoriu(int cod_accesoriu)
    {
        this->cod_accesoriu = cod_accesoriu;
    }
    int getCodAccesoriu()
    {
        return this->cod_accesoriu;
    }
    Accesorii()
    {
        strcpy(this->nume_accesoriu,"Anonim");
        strcpy(this->culoare,"Anonima");
        this->pret_accesoriu = 0;
        this->marime = 'A';
        this->cod_accesoriu = 10000;
    }
    Accesorii(char nume_accesoriu[50],float pret_accesoriu)
    {
        strcpy(this->nume_accesoriu,nume_accesoriu);
        strcpy(this->culoare,"Anonima");
        this->pret_accesoriu = pret_accesoriu;
        this->marime = 0;
        this->cod_accesoriu = 10000;
    }
    Accesorii(char nume_accesoriu[50],char culoare[30],float pret_accesoriu,char marime,int cod_accesoriu)
    {
        strcpy(this->nume_accesoriu,nume_accesoriu);
        strcpy(this->culoare,culoare);
        this->pret_accesoriu = pret_accesoriu;
        this->marime = marime;
        this->cod_accesoriu = cod_accesoriu;
    }
    Accesori(const Accesorii &obj)
    {
        strcpy(this->nume_accesoriu,obj.nume_accesoriu);
        strcpy(this->culoare,obj.culoare);
        this->pret_accesoriu = obj.pret_accesoriu;
        this->marime = obj.marime;
        this->cod_accesoriu = obj.cod_accesoriu;
    }
    Accesorii &operator=(const Accesorii &obj)
    {
        if(this != &obj)
        {
            strcpy(this->nume_accesoriu,obj.nume_accesoriu);
            strcpy(this->culoare,obj.culoare);
            this->pret_accesoriu = obj.pret_accesoriu;
            this->marime = obj.marime;
            this->cod_accesoriu = obj.cod_accesoriu;
        }
        return *this;
    }
    friend istream &operator>>(istream &input,Accesorii &obj)
    {
        cout<<"introduceti numele accesoriului: ";
        input>>obj.nume_accesoriu;
        cout<<"introduceti culoarea accesoriului: ";
        input>>obj.culoare;
        cout<<"introduceti pretul accesoriului: ";
        input>>obj.pret_accesoriu;
        cout<<"introduceti marimea accesoriului(S, M, L): ";
        input>>obj.marime;
        obj.marime = toupper(obj.marime);
        while(obj.marime !='S' && obj.marime !='M' && obj.marime !='L')
        {
            cout<<"introduceti inca o data va rog, S, M sau L : ";
            input>>obj.marime;
            obj.marime = toupper(obj.marime);
        }
        cout<<"introduceti codul accesoriului: ";
        input>>obj.cod_accesoriu;
        return input;
    }
    friend ifstream &operator>>(ifstream &input,Accesorii &obj)
    {
        input>>obj.nume_accesoriu;
        input>>obj.culoare;
        input>>obj.pret_accesoriu;
        input>>obj.marime;
        obj.marime = toupper(obj.marime);
        input>>obj.cod_accesoriu;
        return input;
    }
    friend ostream &operator<<(ostream &out,Accesorii &obj)
    {
        out<<"Avem accesoriul "<<obj.nume_accesoriu<<" de culoare "<<obj.culoare<<" care costa "<<obj.pret_accesoriu<<" lei, de marime "<<obj.marime<<" si are codul "<<obj.cod_accesoriu<<endl;
        return out;
    }
    friend ofstream &operator<<(ofstream &out,Accesorii &obj)
    {
        out<<"Avem accesoriul "<<obj.nume_accesoriu<<" de culoare "<<obj.culoare<<" care costa "<<obj.pret_accesoriu<<" lei, de marime "<<obj.marime<<" si are codul "<<obj.cod_accesoriu<<endl;
        return out;
    }
    ~Accesorii()
    {

    }
    void functionalitate_accesorii()
    {
        int nr,suma=0,target;
        cout<<"Va rog introduceti numarul de zile: ";
        cin>>nr;
        cout<<"Va rog introduceti un target: ";
        cin>>target;
        cout<<"In acest interval de "<<nr<<" zile, avem un target de: "<<target<<" vanzari"<<endl;
        int *nr_accesorii = new int[nr];
        for (int i = 0; i < nr; i++)
        {
            cout<<"In ziua "<<i+1<<" s-au vandut un nr de ";
            cin>>nr_accesorii[i];
            suma += nr_accesorii[i];
        }
        for(int i = 1; i < nr; i++)
        {
            if(nr_accesorii[i] == nr_accesorii[i-1])
                cout<<"in ziua "<<i+1<<",s-au vandut la fel de multe accesorii ca in ziua anterioara"<<endl;
            else if(nr_accesorii[i] > nr_accesorii[i-1])
                cout<<"in ziua "<<i+1<<", se observa o crestere de "<<nr_accesorii[i]-nr_accesorii[i-1]<<" in vanzari"<<endl;
            else
                cout<<"in ziua "<<i+1<<", se observa o descrestere de "<<nr_accesorii[i-1]-nr_accesorii[i]<<" in vanzari"<<endl;

        }
        if(suma == target)
            cout<<"Am reusit sa atingem targetul! :D ";
        if(suma < target)
            cout<<"Din pacate, nu am reusit sa atingem targetul, ne mai trebuiau "<<target-suma<<" vanzari";
        if(suma > target)
            cout<<"Super! Am reusit sa facem cu "<<suma-target<<" vanzari mai mult decat ne am propus";
    }

};

class Hrana //abstracta
{
private:
    char tip_hrana[30];
    char denumire_hrana[30];
    float pret_hrana;
    float cantitate;
public:
    void setTipHrana(char tip_hrana[30])
    {
        strcpy(this->tip_hrana,tip_hrana);
    }
    char* getTipHrana()
    {
        return this->tip_hrana;
    }
    void setDenumireHrana(char denumire_hrana[30])
    {
        strcpy(this->denumire_hrana,denumire_hrana);
    }
    char* getDenumireHrana()
    {
        return this->denumire_hrana;
    }
    void setPretHrana(float pret_hrana)
    {
        this->pret_hrana = pret_hrana;
    }
    float getPretHrana()
    {
        return this->pret_hrana;
    }
    void setCantitate(float cantitate)
    {
        this->cantitate = cantitate;
    }
    float getCantitate()
    {
        return this->cantitate;
    }
    Hrana()
    {
        strcpy(tip_hrana,"Anonim");
        strcpy(denumire_hrana,"Anonim");
        pret_hrana = 0;
        cantitate = 0;
    }
    Hrana(char tip_hrana[30],char denumire_hrana[30],float pret_hrana,float cantitate)
    {
        strcpy(this->tip_hrana,tip_hrana);
        strcpy(this->denumire_hrana,denumire_hrana);
        this->pret_hrana = pret_hrana;
        this->cantitate = cantitate;
    }
    Hrana(const Hrana &obj)
    {
        strcpy(this->tip_hrana,obj.tip_hrana);
        strcpy(this->denumire_hrana,obj.denumire_hrana);
        pret_hrana = obj.pret_hrana;
        cantitate = obj.cantitate;
    }
    Hrana &operator=(const Hrana &obj)
    {
        if(this != &obj)
        {
            strcpy(this->tip_hrana,obj.tip_hrana);
            strcpy(this->denumire_hrana,obj.denumire_hrana);
            pret_hrana = obj.pret_hrana;
            cantitate = obj.cantitate;
        }
        return *this;
    }
    friend istream &operator>>(istream &input,Hrana &obj)
    {
        cout<<"introduceti tipul hranei(tipul de animal): ";
        input>>obj.tip_hrana;
        cout<<"introduceti denumirea hranei: ";
        input>>obj.denumire_hrana;
        cout<<"introduceti pretul hranei: ";
        input>>obj.pret_hrana;
        cout<<"introduceti cantitatea hranii: ";
        input>>obj.cantitate;
        return input;
    }
    friend ifstream &operator>>(ifstream &input,Hrana &obj)
    {
        input>>obj.tip_hrana;
        input>>obj.denumire_hrana;
        input>>obj.pret_hrana;
        input>>obj.cantitate;
        return input;
    }
    friend ostream &operator<<(ostream &out,Hrana &obj)
    {
        out<<"Hrana este pentru "<<obj.tip_hrana<<" , se numeste "<<obj.denumire_hrana<<" , cantareste "<<obj.cantitate<<" kg. "<<endl;
        return out;
    }
    friend ofstream &operator<<(ofstream &out,Hrana &obj)
    {
        out<<"Hrana este pentru "<<obj.tip_hrana<<" , se numeste "<<obj.denumire_hrana<<" , cantareste "<<obj.cantitate<<" kg. "<<endl;
        return out;
    }
    //virtual float calculeaza_pret_hrana()=0;
    virtual float calculeaza_pret_hrana()
    {
        return getPretHrana();
    }
    void funtionalitate_hrana(Animale &obj)
    {
        if(strcmp(tip_hrana,obj.getTipAnimal())==0)
        {
            float portie;
            int nr_portii = 0;
            if(obj.getGreutate() > 0 && obj.getGreutate() <=10)
                portie = 0.3;
            if(obj.getGreutate()>10 && obj.getGreutate() <=25)
                portie = 0.5;
            if(obj.getGreutate() > 25)
                portie = 1.5;
            nr_portii = int(cantitate / portie);
            cout<<"Animalul "<<obj.getTipAnimal()<<","<<obj.getRasaAnimal() <<" va putea avea parte de maxim "<<nr_portii<<" portii din hrana pe care doriti sa o cumparati";
        }
        else
        {
            cout<<"nu se poate calcula nr de portii deoarece hrana aleasa nu este pentru animalul "<<obj.getTipAnimal()<<", "<<obj.getRasaAnimal();
        }
    }

    ~Hrana()
    {

    }
};
class Hrana_bio : public Hrana
{
private:
    int durata_valabilitatii;
public:
    Hrana_bio()
    {
        durata_valabilitatii = 0;
    }
    friend istream& operator >>(istream& in, Hrana_bio& obj)
    {

        in>>(Hrana&)obj;
        cout<<"Introduceti durata valabilitatii: ";
        in>>obj.durata_valabilitatii;
        return in;
    }
    friend ostream& operator<<(ostream& out,const Hrana_bio& obj)
    {
        out<<(Hrana&)obj;
        out<<"De asemenea, puteti sa o folositi timp de "<<obj.durata_valabilitatii<<" zile.";
        return out;
    }
    float calculeaza_pret_hrana()
    {
        return (getPretHrana() + getPretHrana()/5);
    }
};

class Calcul
{
public:
    virtual float calc_pret()=0;
};

class Album : public Animale,public Calcul
{
private:
    //Animale v[50];
    vector<Animale> v;
    int nr;
public:
    Album()
    {
        nr = 0;
        //memset(v,0,nr); ///imi pune 0 uri pe pozitiile din v,incepand de la nr
    }
    /*void adaugare_animal(Animale &obj)  /// adaugare de animal la sfarsit
    {
        v[nr] = new Animale();
        v[nr] = &obj;
        nr++;
    }*/
    void adaugare_animal()  /// adaugare de animal la sfarsit
    {
        //v[nr++] = obj;
        Animale x;
        cin>>x;
        v.push_back(x);
    }
    void stergere_animal(int k)
    {
        v.erase(v.begin() + k);
    }
    Animale operator [](int index)
    {
        if(index < nr && index >= 0)
            return v.at(index);
    }
    friend istream& operator >>(istream& in,Album &obj)
    {
        cout<<"introduceti numarul de animale din album: ";
        in>>obj.nr;
        for(int i = 0; i < obj.nr ; i++)
        {
            Animale x;
            in>>x;
            obj.v.push_back(x);
            cout<<endl;
        }
        return in;
    }
    friend ostream& operator <<(ostream& out,Album &obj)
    {
        out<<"albumul contine urmatoarele animale: "<<endl;
        int k=1;
        for(auto i = obj.v.begin() ; i < obj.v.end() ; i++)
        {
            out<<k<<") "<<*i<<endl;
            k++;
        }
        return out;
    }
    float calc_pret()
    {
        float s = 0;
        for(auto i = v.begin() ; i != v.end() ; i++)
        {
            s = s + (*i).getPret();
        }
        return s;
    }
    int dimensiune()
    {
        return v.capacity();
    }
    ~Album()
    {
    }
};
void meniu ()
{
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"|Buna ziua, bine ati venit la Petshop-ul lui Alexandru Dima|"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<endl;
    cout<<" Alegeti una din urmatoarele comenzi:"<<endl;
    cout<<" 1. Animale"<<endl;
    cout<<" 2. Client"<<endl;
    cout<<" 3. Accesorii"<<endl;
    cout<<" 4. Hrana"<<endl;
    cout<<" 5. Album"<<endl;
    cout<<" 0. Iesire"<<endl;
}
void meniu_animale ()
{
    cout<<" Alegeti una din urmatoarele comenzi:"<<endl;
    cout<<" 1. Doriti sa cumparati niste animale? Spuneti-ne ce ati dori. "<<endl;
    cout<<" 2. Va prezentam o lista de animale creata special pentru dumneavoasta "<<endl;
    cout<<" 3. Doriti sa creati un wishlist?"<<endl;
    cout<<" 0. Inapoi"<<endl;
}
void meniu_client ()
{
    cout<<" Alegeti una din urmatoarele comenzi:"<<endl;
    cout<<" 1. Doriti sa va adaugam in lista noastra de contacte? "<<endl;
    cout<<" 2. Aici se vede lista cu toti clientii "<<endl;
    cout<<" 3. Saptamana asta avem o oferta limitata la magazin, va invitam sa participati. "<<endl;
    cout<<" 0. Inapoi"<<endl;
}
void meniu_accesorii ()
{
    cout<<" Alegeti una din urmatoarele comenzi:"<<endl;
    cout<<" 1. Aici se poate observa ultima noastra vanzare de accesorii. "<<endl;
    cout<<" 0. Inapoi"<<endl;
}
void meniu_hrana ()
{
    cout<<" Alegeti una din urmatoarele comenzi:"<<endl;
    cout<<" 1. Doriti sa cumparati mancare pentru animale? (cele adaugate in wishlist) "<<endl;
    cout<<" 0. Inapoi"<<endl;
}
void meniu_album ()
{
    cout<<" Alegeti una din urmatoarele comenzi:"<<endl;
    cout<<" 1. Creati un album de animale "<<endl;
    cout<<" 2. Afisati albumul in starea curenta "<<endl;
    cout<<" 3. Adaugati un animal intr-un album deja existent"<<endl;
    cout<<" 4. Stergeti un animal dintr-un album deja existent"<<endl;
    cout<<" 5. Afisati pretul animalelor din album"<<endl;
    cout<<" 0. Inapoi"<<endl;
}
int main()
{

    //int n;

    //f1>>n;
    //f2>>n;
    //f3>>n;
    //for(int i=0;i<n;i++)
    //{
        //Animale x;
        //f>>x;
        //g<<x;
        //Client x;
        //f1>>x;
        //g1<<x;
        //Accesorii x;
        //f2>>x;
        //g2<<x;
        //Hrana x;
        //f3>>x;
        //g3<<x;
    //}

    int n;
    list<Client> l;
    vector<Animale> a;
    do
    {
        meniu();
        cin>>n;
        system("cls");
        switch(n)
        {
        case 1:
        {
            int x;
            do
            {
                meniu_animale();
                cin>>x;
                switch(x)
                {
                case 1:
                {
                    Animale x;
                    x.functionalitate_animal();
                    cout<<endl;
                    break;
                }
                case 2:
                {
                    int n;
                    list <Animale> v;
                    f>>n;
                    for(int i=0; i<n; i++)
                    {
                        Animale x;
                        f>>x;
                        v.push_back(x);
                    }
                    for(auto i = v.begin(); i != v.end(); i++)
                        cout<< *i<<endl;
                    break;
                }
                case 3:
                {
                    int ok = 0,ok2;
                    while(ok != 1)
                    {
                        Animale x;
                        cin>>x;
                        a.push_back(x);
                        cout<<"Doriti sa mai adaugati un animal in wishlist?(1 da, 0 nu)"<<endl;
                        cin>>ok2;
                        if(ok2 == 0)
                            ok = 1;
                        else
                            ok = 0;
                    }
                    break;
                }
                }
            }while(x);
            system("cls");
            break;
        }
        case 2:
            {
                int x;
                do
                {
                    meniu_client();
                    cin>>x;
                    switch(x)
                    {
                    case 1:
                    {
                        Client x;
                        cin>>x;
                        l.push_back(x);
                        break;
                    }
                    case 2:
                    {
                        for(auto i = l.begin(); i != l.end(); i++)
                            cout<<*i<<endl;
                        break;
                    }
                    case 3:
                    {
                        Client x;
                        cin>>x;
                        x.functionalitate_client();
                        cout<<endl;
                        break;
                    }
                    }

                }
                while(x);
                system("cls");
                break;
            }
        case 3:
            {
                int x;
                do
                {
                    meniu_accesorii();
                    cin>>x;
                    switch(x)
                    {
                    case 1:
                    {
                        Accesorii x;
                        x.functionalitate_accesorii();
                        cout<<endl;
                    }
                    }
                }
                while(x);
                system("cls");
                break;
            }
        case 4:
            {
                int x;
                do
                {
                    meniu_hrana();
                    cin>>x;
                    switch(x)
                    {
                    case 1:
                    {
                        if(a.capacity() == 0)
                        {
                            cout<<"mai intai completati wishlist-ul si dupa reveniti"<<endl;
                            break;
                        }
                        Hrana x;
                        cin>>x;
                        for(auto i = a.begin();i != a.end();i++)
                            {
                                x.funtionalitate_hrana(*i);
                                cout<<endl;
                            }
                        break;
                    }
                    }

                }
                while(x);
                system("cls");
                break;
            }
        case 5:
        {
            int x;
            Album a;
            do
            {
                meniu_album();
                cin>>x;
                switch(x)
                {
                    case 1:
                    {
                        cin>>a;
                        break;
                    }
                    case 2:
                    {
                        cout<<a;
                        break;
                    }
                    case 3:
                    {
                        a.adaugare_animal();
                        break;
                    }
                    case 4:
                    {
                        if(a.dimensiune() == 0)
                            {
                                cout<<"albumul este gol"<<endl;
                                break;
                            }
                        int nr;
                        cout<<"introduceti pozitia din album pe care doriti sa o stergeti: ";
                        cin>>nr;
                        if(nr > a.dimensiune())
                            cout<<"pozitia nu exista in album"<<endl;
                        else
                            a.stergere_animal(nr-1);
                        break;
                    }
                    case 5:
                    {
                        cout<<"Pretul total este de "<<a.calc_pret() <<" de lei"<<endl;
                        break;
                    }

                }
            }while(x);
            system("cls");
            break;
        }
        }
        }while(n);
        cout<<"Va urez o zi buna!";


        ///Clasa animale

//    Animale a(121213,"caine","Husky",40.44,50.55,1,3,'F'); //constructor cu parametri
//    Animale b(1233,"pisica","birmaneza",30.33,52.22,1,3,'m');
//
//    a.add_animal(a); //utilizare pt float*
//    a.add_animal(b);
//    for(int i = 0;i < poz;i++)
//        cout<<a.getGr()[i]<<" ";
//
//    a.functionalitate_animal();
//    cout<<a[2]<<endl; // operatorul [],afiseaza litera x din tip_animal;
//    a++; // post +
//    ++a; // pre +
//    b = a; // operatorul =
//    a = a + 12;  //operatorul +
//    a = a - 13;  //operatorul -
//    if(b==a)  //operatorul ==
//        cout<<"da";
//    else
//        cout<<"nu";
//    if(b<a)  //operatorul <
//        cout<<"da";
//    else
//        cout<<"nu";
//    //se compara preturile animalelor la == si la <
//    cout<<(int)a; //castare explicita de la float la int ,pretul animalului

        ///Clasa Client

//    Client b(123456,"Dima","Alexandru",'F',86.2,20);
//    Client d(122,"Dima","Radu",'F',48.5,12);
//    Client c;
//    c = b; //operatorul =
//    cout<<b[2]<<endl; // operatorul []
//    b++; // post +
//    ++b; // pre +
//    b = b + 12;  //operatorul +
//    b = b - 13;  //operatorul -
//    if(b==d)  //operatorul ==
//        cout<<"da";
//    else
//        cout<<"nu";
//    if(b>d)  //operatorul <
//        cout<<"da";
//    else
//        cout<<"nu";
//    b.functionalitate_client();
//    b.add_suma_bani();//utilizare pt float*
//    b.add_suma_bani();
//    b.add_suma_bani();
//    for(int i = 0;i < poz2;i++)
//        cout<<b.getResurse()[i]<<" ";



        ///Clasa accesorii
//    Accesorii a("zgarda","neagra",30.33,'M',1234);
//    Accesorii b;
//    cin>>b;
//    b = a;
//    cout<< b;
//    b.functionalitate_accesorii();
//    return 0;


        ///Clasa hrana
//    Hrana ab("caine","Pedigree",145.55,100);
//    Hrana bc;
//    cin>>bc;
//    bc = ab; //operator =
//    cout<<bc<<endl;
//    cout<<bc.calculeaza_pret_hrana()<<endl;
//    cout<<ab;
//    ab.funtionalitate_hrana(a);
        ///Clasa hrana_valabilitate

//    Hrana_bio a;
//    cin>>a;
//    cout<<a.calculeaza_pret_hrana()<<endl;
//    cout<<a;


}
