// 編譯指令
/*
g++ -O3 -Wall -shared -std=c++14 -fPIC `python3 -m pybind11 --includes` gemini.cpp -o gemini`python3-config --extension-suffix` `python3-config --ldflags`
*/

#include <pybind11/pybind11.h>
#include <iostream>

using namespace std;
namespace py = pybind11;

int add(int i, int j) {
  int a = 0;

  for (int k = 0; k < 500000; k = k + 1) {
    a = i + j;
  }
  return a;
}

void talk(void) {
  cout << "Hello plugin with pybind11!" << endl;
  return;
}


PYBIND11_MODULE(gemini, m) {
  /* 
    gemini: module name for python 呼叫用
    m: module instance name

    func:
      add(int, int) -> int
      talk() -> None
  */
  m.doc() = "pybind11 example plugin";       // module doc string
  m.def("add",                               // function name for python
        &add,                                // function pointer for cpp
        "A function which adds two numbers"  // function doc string
       );
  m.def("talk", &talk, "A function which talks");
}