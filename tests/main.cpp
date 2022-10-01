#include "lLists/stack.hpp"
#include <iostream>
#include <fstream>
#include <string>


using namespace eda;

using namespace std;


int main(){
  fstream entry;   //To the input file
  ofstream out;    //To the output file

  entry.open("../data.html");//This line open the file, we have to change it later to  recieva a name of a file
  out.open("../salida.log");

  //Confirm if the file opens correctly
  if (entry.fail()){
    cerr<<"Error al abrir el archivo";
    exit(1);
  }

  

  


  string line;        // variable that recibe a line of text
  char leter;         // variable that recibe char by char in the line
  
  string word;        // save the tag <expresion>

  bool flag=false;    // indicate strart or end of a tag
  bool signal=false;  //indicate that the tag is an ending 
  bool error=false;
  int  count=0;
  Stack tags;


  while (!entry.eof() && !error){
    getline(entry,line);
    count++;
    //cout<<line<<endl;
    for(int i=0;i<line.size();i++){
      
      leter=line[i];
      
      if(leter == '<'&& flag == false){                      //Tag strart(LISTO)
        word += leter;
        flag=true;
      }
      
      else if(leter=='>'&& flag == true){                   //Tag end(NO LISTO)
        word += leter;
        //cout<<word<<endl;
        if (signal==true){                                  //Check if word is equal to the top data of the stack (SIGNAL ON)
          string buffer=(tags.top())->getData();
          if (buffer==word){                                //If equal   
            tags.pop();
            out<<"tag "<<buffer<<" cerrado con exito"<<endl;
            signal=false;
          }
          else{                                             //If diferent
            cout<<"ERROR en linea "<<count<< " : se ha recibido "<<word<<" se esperaba "<<buffer<<endl;
            out<<"ERROR en linea "<<count<< " : se ha recibido "<<word<<" se esperaba "<<buffer<<endl;
            error=true;
          }
        }
        else{                                                //Push the word in the stack (SIGNAL OFF)
          tags.push(word);
        }
        word.erase(word.begin(),word.end());
        flag=false;
      }

      else if(leter=='/'&& flag == true){                   //slash and revision condition(LISTO)
        signal=true;
      }

      else if(leter!='>'&& leter!='<'&&flag==true){
        word += leter;
      }
      else{
        continue;
      }
    }
  }

  if (!error){
    out<<"0 errores detectados"<<endl;
  }
  entry.close();
  out.close();


}


/*
int main(){
  Stack dato;
  dato.push("hola");
  dato.push("palabra");
  dato.push("cosa");
  
  while(!dato.isEmpty()){
    cout<<(dato.top())->getData()<<endl;
    if((dato.top())->getData()=="hola"){
      cout<<"Adios"<<endl;
    }
    dato.pop();
  }

}

LISTA DE COSAS POR HACER:

-Modificar struct para que reciba char o string
-definir constantes /,<,>
-comparar char para identificar alguna de las consts(sujeto a cambios)

HAblar con la Andi:
-forma de abordar el problema
-numero de stacks a usar
-cantidad de atributos de cada stack

*/