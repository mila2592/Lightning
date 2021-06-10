#ifndef NODE_H
#define NODE_H
#include <set>

struct Link;

class Node
{
public:
    //private:




    double q;
    double phi,phi_old, phi_ext;
    double x,y,z; // координаты вершины
    int num;
    std::set <Node*> connected;
    std::set <Link*> links;

    std::set <Node*> cover;
    std::set <Link*> cover_links;


public:
    Node();
    void set_coords(int x,int y, int z);
    void calc_I();
    void calc_phi();


    friend bool operator== (const Node &n1, const Node &n2);
    friend bool operator!= (const Node &n1, const Node &n2);
};

struct Link
{
public:

    Node *n1,*n2;
    double I;
    double T;
    double G;


};
#endif // NODE_H
