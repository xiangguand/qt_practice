# QT5 example

clone the qt5 source code  
initialize hte sub-module
```
perl init-repository
```

```
mkdir qt5-build
cd qt5-build
```

```
..\.\configure -developer-build -opensource -nomake examples -nomake tests -platform win32-g++ -no-opengl -skip qtconnectivity -skip qt3d -skip qtcanvas3d -skip qtdatavis3d -opensource
```

```
mingw32-make -j4
```


