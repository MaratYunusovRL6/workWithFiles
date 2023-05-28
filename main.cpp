#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int main() {
    FILE *res=fopen("War and Peace.txt","r");
    FILE *def=fopen("red1.txt","w");
    vector <char*> v;
    vector <char*> pv;
    v.push_back("check");
    char* data=new char[30];
    char buf;
    int k=0;
    int ok=0;
    int r=0;
    int y=0;
    while((fscanf(res,"%c",&buf)!=EOF)){
        if(isalpha(buf)){
            buf=tolower(buf);
            data[k]=buf;
            k++;
            ok=1;
        }
        else{
            if(ok==1){
                for(int i=0;i<size(v);i++) {
                    if (strcmp(v[i], data) == 0) {
                        r = 1;
                        break;
                    }
                    else{
                        for(int j=0;j<size(pv);j++){
                            if(strcmp(pv[j],data)==0){
                                y=1;
                                break;
                            }
                        }
                    }
                }
                if(r==0){
                    v.push_back(data);
                }
                if(y==0 && r==1){
                    fprintf(def,"%s/",data);
                    pv.push_back(data);
                }
            }
            y=0;
            r=0;
            k=0;
            ok=0;
            data=new char[30];
        }

    }
    fclose(res);
    fclose(def);
    return 0;
}
