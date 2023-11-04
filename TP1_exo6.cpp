#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Marque {
private:
    int code;
    string nom;

public:
    Marque(int c, const string &n) : code(c), nom(n) {}

    int getCode() { return code; }
    string getNom() { return nom; }

    void setCode(int c) { code = c; }
    void setNom(const string &n) { nom = n; }

    void affiche() {
        cout << "Code de la marque : " << code << endl;
        cout << "Nom de la marque : " << nom << endl;
    }
};

class Article {
private:
    static int reference_auto_increment;
    int reference;
    float prixHT;
    string marque;
    float tva;

public:
    Article(float p, const string &m, float t = 20) : reference(++reference_auto_increment), prixHT(p), marque(m), tva(t) {}

    int getReference() { return reference; }
    float getPrixHT() { return prixHT; }
    string getMarque() { return marque; }
    float getTVA() { return tva; }

    void setPrixHT(float p) { prixHT = p; }
    void setMarque(const string &m) { marque = m; }
    void setTVA(float t) { tva = t; }

    void saisie() {
        cout << "Prix HT : ";
        cin >> prixHT;
        cout << "Marque : ";
        cin >> marque;
        cout << "TVA : ";
        cin >> tva;
    }

    void affichage() {
        cout << "Référence : " << reference << endl;
        cout << "Prix HT : " << prixHT << endl;
        cout << "Marque : " << marque << endl;
        cout << "TVA : " << tva << endl;
    }

    bool comparer(Article a) {
        return prixHT > a.getPrixHT();
    }

    float calculPrixTTC() {
        return prixHT + (prixHT * tva / 100);
    }

    static Article maxPrix(Article a1, Article a2) {
        return (a1.getPrixHT() > a2.getPrixHT()) ? a1 : a2;
    }
};

int Article::reference_auto_increment = 0;

class Marche {
private:
    string nomMagasin;
    string adresse;
    int numeroRue;
    vector<Article> stock;

public:
    Marche(const string &nom, const string &adr, int rue) : nomMagasin(nom), adresse(adr), numeroRue(rue) {}

    string getNomMagasin() { return nomMagasin; }
    string getAdresse() { return adresse; }
    int getNumeroRue() { return numeroRue; }
    vector<Article> getStock() { return stock; }

    void setNomMagasin(const string &nom) { nomMagasin = nom; }
    void setAdresse(const string &adr) { adresse = adr; }
    void setNumeroRue(int rue) { numeroRue = rue; }
    void setStock(const vector<Article> &s) { stock = s; }

    void saisie() {
        cout << "Nom du magasin : ";
        cin >> nomMagasin;
        cout << "Adresse : ";
        cin >> adresse;
        cout << "Numéro de rue : ";
        cin >> numeroRue;
    }

    void affichage() {
        cout << "Nom du magasin : " << nomMagasin << endl;
        cout << "Adresse : " << adresse << endl;
        cout << "Numéro de rue : " << numeroRue << endl;
    }

    Article maxPrix() {
        if (stock.empty()) {
            cout << "Le stock est vide." << endl;
            return Article(0, "");
        }

        Article max = stock[0];
        for (size_t i = 1; i < stock.size(); i++) {
            if (stock[i].comparer(max)) {
                max = stock[i];
            }
        }
        return max;
    }

    float MoyPrix() {
        if (stock.empty()) {
            cout << "Le stock est vide." << endl;
            return 0.0;
        }

        float sum = 0.0;
        for (const Article &a : stock) {
            sum += a.getPrixHT();
        }
        return sum / stock.size();
    }

    void addArticle(Article a) {
        stock.push_back(a);
    }

    bool findArticleByRef(int ref) {
        for (const Article &a : stock) {
            if (a.getReference() == ref) {
                return true;
            }
        }
        return false;
    }

    void liquiderStock() {
        stock.clear();
    }

    bool isEmpty() {
        return stock.empty();
    }

    int nbrArticleAvecMemeMarque(const string &marque) {
        int count = 0;
        for (const Article &a : stock) {
            if (a.getMarque() == marque) {
                count++;
            }
        }
        return count;
    }

    void afficheArticle(const string &marque) {
        for (const Article &a : stock) {
            if (a.getMarque() == marque) {
                a.affichage();
                cout << endl;
            }
        }
    }
};

int main() {
    Marche hypermarche("SuperMart", "123 Main Street", 1);

    Article article1(10.0, "MarqueA", 15.0);
    Article article2(12.0, "MarqueB");
    Article article3(8.0, "MarqueA", 10.0);

    hypermarche.addArticle(article1);
    hypermarche.addArticle(article2);
    hypermarche.addArticle(article3);

    hypermarche.saisie();
    hypermarche.affichage();

    Article articleMaxPrix = hypermarche.maxPrix();
    cout << "L'article le plus cher est : " << articleMaxPrix.getReference() << endl;

    float moyennePrix = hypermarche.MoyPrix();
    cout << "La moyenne des prix dans le stock est : " << moyennePrix << endl;

    if (hypermarche.findArticleByRef(2)) {
        cout << "L'article avec la référence 2 existe dans le stock." << endl;
    } else {
        cout << "L'article avec la référence 2 n'existe pas dans le stock." << endl;
    }

    hypermarche.liquiderStock();
    if (hypermarche.isEmpty()) {
        cout << "Le stock est vide." << endl;
    }

    int nbrArticlesMarqueA = hypermarche.nbrArticleAvecMemeMarque("MarqueA");
    cout << "Nombre d'articles de
