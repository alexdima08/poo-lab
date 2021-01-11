///Dima Alexandru 212
///gnu gcc  compiler
///Szmeteanca Gabriel Eduard
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vaccin
{
protected:
    float pret;
    float temperatura_depozitare;
    vector<string> substante;
    int dim;
public:
    Vaccin()
    {
        pret = 0;
        temperatura_depozitare = 0;
        dim = 1;
        for(int i = 0;i < dim; i++)
            substante.push_back("anonima");
    }
    void stergere(int k)
    {
        substante.erase(substante.begin() + k);
    }
    friend istream &operator>>(istream &in,Vaccin &obj)
    {
        obj.stergere(0);
        string subst;
        cout<<"pret: ";
        in>>obj.pret;
        cout<<"temperatura depozitare: ";
        in>>obj.temperatura_depozitare;
        cout<<"nr substante folosite: ";
        in>>obj.dim;
        cout<<"subtantele folosite sunt: ";
        for(int i=0; i<obj.dim; i++)
        {
            in>>subst;
            obj.substante.push_back(subst);
        }
        return in;
    }
    friend ostream &operator <<(ostream &out,Vaccin &obj)
    {
        ///o sa afisez pretul,temperatura de depozitare,si substantele folosite in ordinea asta
        out<<"pretul este "<<obj.pret<<"\ntemperatura de depozitare este "<<obj.temperatura_depozitare<<endl;
        out<<"iar lista de substante este: ";
        for(auto i = obj.substante.begin(); i!= obj.substante.end();i++)
            out<<(*i)<<" ";
        return out;
    }
    virtual void schema_vaccinare(){};
    ~Vaccin()
    {

    }
};
class VaccinAntigripal: public Vaccin
{
protected:

    string tulpina;
    bool conditie;


public:
    VaccinAntigripal()
    {

        tulpina = "anonima";
        conditie = 0;
    }
    friend istream &operator>>(istream &in,VaccinAntigripal &obj)
    {

        in>>(Vaccin&) obj;
        cout<<"tulpina: ";
        in>>obj.tulpina;
        cout<<"respecta recomandarile OSM?(Da = 1,Nu = 0) ";
        in>>obj.conditie;
        return in;
    }
    friend ostream &operator <<(ostream &out,VaccinAntigripal &obj)
    {
        out<<(Vaccin&) obj<<endl;
        if(obj.conditie == 0)
            out<<"tulpina este "<<obj.tulpina<<" si nu respecta recomandarile OSM";
        else
            out<<"tulpina este "<<obj.tulpina<<" si respecta recomandarile OSM";
        return out;
    }
    void schema_vaccinare()
    {
        cout<<"vaccinul Antigripal se administreaza la adulti o doza de 0.5 ml, iar la copii si adolescenti o daza de 0.3 ml, repetandu-se din 2 in 2 ani.";
    }
    ~VaccinAntigripal()
    {

    }
};

class VaccinAntihepatic : public Vaccin
{
protected:
    char tip_hepatita;
    string mod_vaccinare;
public:
    VaccinAntihepatic()
    {
        tip_hepatita = 'A';
        mod_vaccinare = "anonim";


    }
    friend istream &operator>>(istream &in,VaccinAntihepatic &obj)
    {
        in>>(Vaccin&) obj;
        cout<<"tipul hepatitei: ";
        in>>obj.tip_hepatita;
        cout<<" modul de vaccinare: ";
        in>>obj.mod_vaccinare;
        return in;
    }
    friend ostream &operator <<(ostream &out,VaccinAntihepatic &obj)
    {
        out<<(Vaccin&) obj<<endl;
        out<<"este pentru tipul de hepatita "<<obj.tip_hepatita<<endl<<"modul de vaccinare este "<<obj.mod_vaccinare;
        return out;
    }
    void schema_vaccinare()
    {
        if(tip_hepatita== 'A' || tip_hepatita == 'B')
            cout<<"vaccinul de antiheptatita A si B, la copii cu varsta mai mica de 1 an se administreaza 2 injectari la un interval de o luna, a treia injectare dupa 6 luni de la prima administrare, la adulti  conform schemei de imunizare recomandata de medic.";
        if(tip_hepatita== 'C')
            cout<<"vaccinul de antihepatita c doar la recomandarea medicului";
    }
    ~VaccinAntihepatic()
    {

    }
};

class VaccinAntiSarsCov2 : public Vaccin
{
protected:
    vector<string> reactii_adverse;
    float rata_eficienta;
    vector<string> medicamente;
    int dim1;
    int dim2;

public:
    VaccinAntiSarsCov2()
    {
        rata_eficienta = 0;
        dim1 = 1;
        dim2 = 1;
        for(int i = 0;i < dim1; i++)
            reactii_adverse.push_back("anonima");
        for(int i = 0;i < dim2; i++)
            medicamente.push_back("anonim");
    }
    void stergere1(int k)
    {
        reactii_adverse.erase(reactii_adverse.begin() + k);
    }
    void stergere2(int k)
    {
        medicamente.erase(medicamente.begin() + k);
    }
    friend istream &operator>>(istream &in,VaccinAntiSarsCov2 &obj)
    {
        string cuv;
        obj.stergere1(0);
        obj.stergere2(0);

        in>>(Vaccin&) obj;
        cout<<"nr de reactii adverse: ";
        in>>obj.dim1;
        cout<<"reactiile adverse sunt: ";
        for(int i=0; i<obj.dim1; i++)
        {
            in>>cuv;
            obj.reactii_adverse.push_back(cuv);
        }
        cout<<"nr de medicamente: ";
        in>>obj.dim2;
        cout<<"medicamentele sunt: ";
        for(int i=0; i<obj.dim2; i++)
        {
            in>>cuv;
            obj.medicamente.push_back(cuv);
        }
        cout<<"rata eficienta medicament: ";
        in>>obj.rata_eficienta;
        return in;

    }
    friend ostream &operator<<(ostream &out,VaccinAntiSarsCov2 &obj)
    {
        out<<(Vaccin&) obj<<endl;
        out<<"lista de reactii adverse este: ";
        for(auto i = obj.reactii_adverse.begin(); i!= obj.reactii_adverse.end();i++)
            out<<(*i)<<" ";
        out<<endl;
        out<<"lista de medicamente este: ";
        for(auto i = obj.medicamente.begin(); i!= obj.medicamente.end();i++)
            out<<(*i)<<" ";
        out<<endl;
        out<<"rata eficientei este "<<obj.rata_eficienta<<" %.";
        return out;

    }
    void schema_vaccinare()
    {
        cout<<"vaccinul Sars-cov2 se administreaza persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 de zile.";
    }
    ~VaccinAntiSarsCov2()
    {

    }
};
class Comanda
{
protected:
    static int id;
    string data;
    string nume_client;
    string vaccin_cerut;
    int nr_vaccinuri;
public:
    Comanda()
    {
        data = "0.0.2021";
        nume_client = "anonim";
        vaccin_cerut = "anonim";
        nr_vaccinuri = 0;
        id++;
    }
    Comanda(string data,string nume_client,string vaccin_cerut,int nr_vaccinuri)
    {
        this->data = data;
        this->nume_client = nume_client;
        this->vaccin_cerut = vaccin_cerut;
        this->nr_vaccinuri = nr_vaccinuri;
        id++;
    }
    friend ostream &operator <<(ostream &out,Comanda &obj)
    {
        out<<"data comenzii: "<<obj.data<<endl;
        out<<"numele clientului: "<<obj.nume_client<<endl;
        out<<"vaccinul cerut: "<<obj.vaccin_cerut<<endl;
        out<<"nr de vaccinuri cerute este: "<<obj.nr_vaccinuri<<endl;
        return out;
    }
    ~Comanda()
    {

    }

};
int Comanda :: id = 0;
int main()
{
    VaccinAntigripal a;
    VaccinAntihepatic b;
    VaccinAntiSarsCov2 c;
    cin>>a;
    cout<<a;
    cin>>b;
    cout<<b;
    cin>>c;
    cout<<c;
    Vaccin* list[3];
    list[0]=new VaccinAntigripal();
    list[1]=new VaccinAntihepatic ();
    list[2]=new VaccinAntiSarsCov2();
    for(int i=0; i<3; i++)
        {
            list[i]-> schema_vaccinare();
            cout<<endl;
        }


    Comanda com1("20-12-2020", "SpitalX", "AntiSarsCov2",20);
    cout<<com1;
    return 0;
}

