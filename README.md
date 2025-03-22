# Overview

Set of useful functions and classes that can be used to simplify work for PHENIX collaborators.

This repository currently contains only the code that can simplify drawing PHENIX preliminary logo onto the ROOT TPad.

# Requirements

- GNU GCC++17 or newer.
- [ROOT](https://root.cern/) V.6.00 or newer.

If [ROOT6](https://root.cern/) was not installed with a package manager on your system, you also need to set path to the directory in which root was installed ($ROOT_PATH) in your profile (.bashrc, .zshrc, or other) or configure the paths in CMakeLists.txt.

# Installing

Run in your working directory to copy the repository

```sh
git clone https://github.com/Sergeyir/PHENIXTools --depth=1
```

First run in the downloaded directory to generate Makefile

```sh
cmake .
```

Then run to compile the libraries and executable examples

```sh 
make
```

# Documentation

You can view the detailed documentation at https://sergeyir.github.io/documentation/ROOTTools/. (see Namespaces / Namespaces List / PHENIXTools). Since this repository is not designed to be used on its own and is intended to be used as a set of libraries, every class, method, and variable are all in the PHENIXTools namespace scope.

If the link is inaccessible, you can generate the documentation yourself with Doxygen. To do this run while in the root of the repository

```sh
doxygen
```

To view the generated html file open html/index.html with any browser or simply run to automaticaly open it on linux

```sh
xdg-open html/index.html
```

# Usage

See [examples](https://sergeyir.github.io/documentation/PHENIXTools/examples.html) on how to use libraries from this project.
