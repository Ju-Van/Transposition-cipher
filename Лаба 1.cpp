#include <string>
#include <iostream>
#include <fstream>
using namespace std;
void permutationcode(string& text, string& const key)
{
    int col = key.size();
    int row = (text.size() % col) ? ((text.size() / col) + 1) : (text.size() / col);
    
    int** arrtext = new int*[row];
    for (int i = 0; i < row; ++i)
        arrtext[i] = new int[col];
 
    //inizialization array {0}
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            arrtext[i][j] = 0;
 
    //fill array {text[i]}
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            arrtext[i][j] = text[(i*col)+j];
        
 
    int index = 0;
    //permutation
    for (int i = 0; i < 256; ++i)
        for (int j = 0; j < col; ++j)
            if (key[j] == i)
                for (int k = 0; k < row; ++k, ++index)
                {
                    text[index] = arrtext[k][j];
                }
    for (int i = 0; i < row; ++i)
      delete[] arrtext[i];
      delete[] arrtext; 
}
 
 
void permutationdecode(string& text, const string& const key)
{
    int col = key.size();
    int row = (text.size() % col) ? ((text.size() / col) + 1) : (text.size() / col);
 
    int** arrtext = new int*[row];
    for (int i = 0; i < row; ++i)
        arrtext[i] = new int[col];
 
    //inizialization array {0}
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            arrtext[i][j] = 0;
 
    //fill array {text[i]}
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
                arrtext[i][j] = text[(j*row)+i];
    
    int index = 0;
    //decode
    for (int i = 0; i < row; ++i){
        for (int k = 0; k < 256; ++k){
            for (int j = 0; j < col; ++j){
                if (key[j] == k)
                {
                    text[index] = arrtext[i][j];
                    ++index;
                }
            }
        }
    }
 
    for (int i = 0; i < row; ++i)
      delete[] arrtext[i];
      delete[] arrtext; 
}
 
 
 
int main(int argc, char* argv[])
{
    ofstream mem;
    mem.open("mem.txt");
    string text("ABCDEFGHIJKN");
    string key("1234");
    int a=0;
    int siz1 = text.size();
    int siz2 = text.size() / key.size();
    int siz3 = key.size();
    cout << "Text before: " << endl;
    mem << "Text before: " << endl;
    do
    {
        cout << text[a] <<" ";
        mem << text[a] << " ";
        a++;
        if (a % siz3 == 0)
        {
            cout << endl;
            mem << endl;
        }
    } while (a <= siz1);
    a = 0;
    cout << endl;
    permutationcode(text,key);
    cout << "Coded text:  " << endl;
    mem << "Coded text:  " << endl;
    do
    {
        cout << text[a] << " ";
        mem << text[a] << " ";
        a++;
        if (a % siz2 == 0)
        {
            cout << endl;
            mem << endl;
        }
    } while (a <= siz1);
    a = 0;
    cout << endl;
    permutationdecode(text,key);
    cout << "Decoded text: " << endl;
    mem << "Decoded text: " << endl;
    do
    {
        cout << text[a] << " ";
        mem << text[a] << " ";
        a++;
        if (a % siz3 == 0)
        {
            cout << endl;
            mem << endl;
        }
    } while (a <= siz1);
    return 0;
}