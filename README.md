<div align="center">
  <a align="center" href="https://www.youtube.com/watch?v=FWizpd-n7W4">
    <img src="https://img.youtube.com/vi/FWizpd-n7W4/mqdefault.jpg" width=30%>
  </a>
  <h1>Structured bindings examples</h1>
  <p>
    Git repo for the video <a href="https://www.youtube.com/watch?v=FWizpd-n7W4">C++ Structured Bindings: How, Why, and Why not</a>.
    <br>
    <sub>By <a href="https://www.youtube.com/@ElisePlusPlus">Elise++</a></sub><br><br>
    <a href="/../../actions/workflows/cmake.yml">
      <img src="/../../actions/workflows/cmake.yml/badge.svg">
    </a>
    <a href="LICENSE">
      <img src="https://img.shields.io/badge/License-MIT-yellow.svg">
    </a>
  </p>
</div>

***

## Introduction
This repo contains all the code files shown in the video [C++ Structured Bindings: How, Why, and Why not](https://www.youtube.com/watch?v=FWizpd-n7W4). It shows how structured bindings can make code shorter and more readable. It also covers some common pitfalls and when you'd want to avoid using them.

## Building and testing
### Manually
Build the project using cmake and a compiler with C++ 20 abilities. Most modern compilers should work. Making the file will result in the unit tests getting executed automatically.

```shell
git clone https://github.com/EliseBriers/cpp-structured-bindings
cd cpp-structured-bindings
mkdir build
cd build
cmake ..
cmake --build .
```

### Visual Studio (Windows)
The easiest way to build and run the project on windows is opening it in a recent version of Vidual Studio. This project has been tested using Visual Studio 2022.
