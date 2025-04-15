#include <iostream>

using namespace std;

class Poste{
private:
    int height;
    float diameter;

public:
    Poste(){
        height = 0;
        diameter = 0.0;
    }

    Poste(int h, float d){
        height = h;
        diameter = d;
    }

    int getHeight() const {return height;}
    float getDiameter() const {return diameter;}

    void show() const{
        cout << "Height: " << height << " meteres, Diameter: " << diameter << " centimeters" << endl;
    }

};

void showPoste(Poste postes[], int quantity){
    for(int i = 0; i < quantity; i++){
        cout << "Poste " << i+1<<": ";
        postes[i].show();
    }
}

void bubbleSort(Poste postes[], int quantity){
    for(int i = 0; i < quantity - 1; i++){
        for(int j = 0; j < quantity - 1;j++){
            if(postes[j].getHeight() > postes[j+1].getHeight()){
                Poste temp = postes[j];
                postes[j] = postes[j+1];
                postes[j+1]=temp;
            }
        }
    }
}

int main(){
    const int postes_quantity = 3;
    Poste postes[postes_quantity];

    postes[0] = Poste(10, 30.5);
    postes[1] = Poste(7, 25.0);
    postes[2] = Poste(12, 35.0);

    cout << "Before sort:\n";
    showPoste(postes, postes_quantity);

    bubbleSort(postes, postes_quantity);

    cout << "\nAfter sort:\n";
    showPoste(postes, postes_quantity);

    return 0;
}

