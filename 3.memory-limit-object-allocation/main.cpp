#include <iostream>
#include <string>

using namespace std;


class Galaxy{
private:
    string name;
    int stars;
    char data[1024*1024];

public:
    Galaxy(const string& name, int stars){
        this->name = name;
        this->stars = stars;

        for(int i = 0; i < sizeof(data); i++){
            data[i] = 'X';
        }
    }

    void showInfo() const{
        cout << "Galaxy: " << name << ", Stars: " << stars << endl;
    }

};


int main()
{

    const int MAX_MB = 200;
    const int MAX_GALAXIES = MAX_MB;
    Galaxy* galaxies[MAX_GALAXIES];
    int count = 0;

    for(int i = 0; i < MAX_GALAXIES; i++){
        try{
            galaxies[i] = new Galaxy("Andromeda_" + to_string(i), i * 1000);
            count ++;
        }catch (bad_alloc& e){
            cout << "Memory allocation failed at Galaxy #" << i << endl;
            break;
        }
    }

    cout << "\nTotal galaxies created before reaching ~200MB: " << count << endl;

    for(int i = 0; i < count; i++){
        delete galaxies[i];
    }

    return 0;
}
