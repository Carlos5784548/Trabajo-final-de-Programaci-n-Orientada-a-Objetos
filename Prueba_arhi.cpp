#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
struct Usuario{
	char nombre[80];
	char contra[20];
	bool rol;
};
int main(int argc, char *argv[]) {
	vector<Usuario>m;
	Usuario a;
	ifstream archi ("Credenciales.dat",ios::binary|ios::ate);
	int total=archi.tellg()/sizeof(Usuario);
	archi.seekg(0);
	for(int i=0;i<total;i++) { 
	archi.read(reinterpret_cast<char*>(&a), sizeof(Usuario));
	m.push_back(a);
	}
	for(int i=0;i<m.size();i++) { 
		cout<<"NOMBRE:"<<m[i].nombre<<endl;
		cout<<"CONTRASEÑA:"<<m[i].contra<<endl;
		if(m[i].rol){
			cout<<"ES ADMIN"<<endl;
			
		}else{
			cout<<"NO ES ADMIN"<<endl;
		}
	}
	
	return 0;
}

