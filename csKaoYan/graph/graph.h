#ifndef GRAPH_H
#define GRAPH_H

#include<mai.h>
#include<assert.h>
using namespace std;

#define MaxVertexNum 100

using VertexType = string;
using EdgeType = int;

typedef enum GraphType{
    UDG,DG,UDN,DN
}GraphType;

//邻接矩阵
using weight = int;

struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum,arcnum;
    GraphType type;
}MGraph,*graph;

//邻接表
struct ArcNode{
    int adjvex;
    ArcNode *next;
    weight w;
};
struct VNode{
    VertexType data;
    ArcNode *first;
};

struct GraphRepr{
    VNode *node;
    int vexnum,arcnum;
};
#endif

