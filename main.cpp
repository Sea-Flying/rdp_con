#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
	string param(argv[1]);
	size_t p0 = param.find(":",0);
	size_t p1 = param.find("-",p0+1);
	size_t p2 = param.find("-",p1+1);
	size_t len1 = p1 - p0 - 1;
	size_t len2 = p2 - p1 - 1;
	size_t len3 = param.size() - 1 - len2 -1;
	string server = param.substr(p0+1,len1);
	string user = param.substr(p1+1,len2);
	string pass = param.substr(p2+1,len3);
//	cout<<p1<<" "<<p2<<endl;
//	cout<<server<<endl<<user<<endl<<pass<<endl;
	string cmd1 = "cmdkey /add:TERMSRV/"+server+" /user:"+user+" /pass:"+pass;
	string cmd2 = "mstsc /v:"+server;
	string cmd3 = "cmdkey /delete:TERMSRV/"+server;
	cout<<cmd1<<endl<<cmd2<<endl<<cmd3<<endl;
	system(cmd1.c_str());
	system(cmd2.c_str());
	//system(cmd3.c_str());
	return 0;
}
