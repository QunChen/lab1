//
// Created by think on 2016/3/5.
//
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include "pet.h"

using namespace std;

void populate(Pet*,int,string);

int countRecords(char* file_name){
    ifstream file(file_name);
    int count = 0;
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                count++;
            }
        }
    }else{
       cout<<"can not open"<<endl;
    }

    return count;
}

void loadRecords(char* file_name, Pet * pets,int num){
    ifstream file(file_name);
    int count = 0;
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                populate(pets,count,line);
                count++;
            }
        }
    }else{
        cout<<"can not open"<<endl;
    }

}

void printRecords(Pet* pets, int num){
    for(int i=0;i<num;i++){
        cout<<pets[i].status<<" "<<endl;
    }
}

void populate(Pet* pet,int count,string s){
    stringstream ss(s);
    string item;
    int column=0;
    int length,split;
    while(getline(ss,item,',')){
        switch (column){
            case 0:
                pet[count].status=item;
                break;
            case 1:
                pet[count].pet_type=item;
                break;
            case 2:
                pet[count].gender=item;
                break;
            case 3:
                pet[count].breeds=item;
                break;
            case 4:
                length=item.length();
                for(int i=0;i<length;i++){
                    if(isspace(item.at(i))){
                       split=i;
                    }
                }
                pet[count].age_of_year=item.substr(0,split);
                pet[count].age_of_month=item.substr(split+1,length);
                break;
            case 5:
                pet[count].colour=item;
                break;
            case 6:
                pet[count].chip_number=item;
                break;
            case 7:
                pet[count].location=item;
                break;
            case 8:
                pet[count].contact_phone_number=item;
                break;
        }
        column++;
    }
}

int main(){
    cout<<"file name:"<<endl;
    char file_name[128];
    cin>>file_name;
   int num=countRecords(file_name);
   Pet* pets=new Pet[num];
    loadRecords(file_name,pets,num);
    printRecords(pets,num);
    delete pets;
}