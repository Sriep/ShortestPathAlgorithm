TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dijkstra.cpp \
    graph.cpp \
    bellmanford.cpp \
    floydwarshall.cpp

HEADERS += \
    dijkstra.h \
    graph.h \
    bellmanford.h \
    floydwarshall.h
