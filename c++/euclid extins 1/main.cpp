 #include <iostream>
     #include <cstdlib>
     #define TESTS 1000
     using namespace std;

     int main() {
        // system("g++ -o gen gen.cpp");//compile the files, the executable file will be named gen
        // system("g++ -o brute brute.cpp");
        // system("g++ -o ok ok.cpp");
        for(int i=0; i<TESTS; ++i) {
          //  system("gen > input");//redirects the stdout of the program gen to the file named input
           // system("brute < input > bout");//redirects the file input to stdin and stdout to bout
           // system("ok <input > oout");
          //  if(system("diff -q bout oout")) {
           //     cout<<"Outputs differ";
            //    return 0;
          //  }
        }
        if(system("diff -q bout oout")) ;
        return 0;
    }
