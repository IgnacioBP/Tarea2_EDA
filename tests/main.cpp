#include "lLists/stack.hpp"
#include <iostream>
#include <fstream>
#include <string.h>


using namespace eda;

using namespace std;

int main(){
  fstream entry;   //To the input file
  //ofstream out;  //To the output file

  entry.open("../data.html");//This line open the file, we have to change it later to  recieva a name of a file

  //Confirm if the file opens correctly
  if (entry.fail()){
    cerr<<"Error al abrir el archivo";
    exit(1);
  }


  string line;        // variable that recibe a line of text
  char leter;
  string word;
  bool flag=false;

  while (!entry.eof()){
    getline(entry,line);
    //cout<<line<<endl;
    for(int i=0;i<line.size();i++){
      //cout<<line[i]<<endl;
      leter=line[i];
      if(leter == '<'&& flag == false){
        //cout<<"Comienzo detectado"<<endl;
        word += leter;
        flag=true;
      }
      else if(leter=='>'&& flag == true){
        //cout<<"Termino detectado"<<endl;
        word += leter;
        cout<<word<<endl;
        word.erase(word.begin(),word.end());
        flag==false;
      }
      else if(leter!='>'&& leter!='<'&&flag==true){
        word += leter;
      }
      else{
        continue;
      }
    }
  }

  entry.close();



}

/*
LISTA DE COSAS POR HACER:

-Modificar struct para que reciba char o string
-definir constantes /,<,>
-comparar char para identificar alguna de las consts(sujeto a cambios)

HAblar con la Andi:
-forma de abordar el problema
-numero de stacks a usar
-cantidad de atributos de cada stack

*/