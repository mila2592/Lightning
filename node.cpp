#include "model-node.h"
#include <iostream>
#include <random>

Node::Node()//constructor
{

}

void Node::set_coords(int x,int y, int z)
{
    this->x=x;
    this->y=y;
    this->z=z;

}

bool operator== (const Node &n1, const Node &n2)
{
    return (n1.x == n2.x &&
            n1.y == n2.y && n1.z == n2.z&& n1.phi== n2.phi && n1.q == n2.q);
}

bool operator!= (const Node &n1, const Node &n2)
{
    return !(n1== n2);
}

void Node::calc_I()
{

    std::set<Link*>::iterator it; //создание итератора

    for(it = links.begin(); it != links.end(); it++)
    {
        (*it)->I=(*it)->n1->phi-(*it)->n2->phi;
        // Вывод всех элементов
        std::cout <<"I= "<< ((*it)->I) <<std::endl; // множества

    }
}


void Node::calc_phi()
{

    std::set<Node*>::iterator it; //создание итератора
    double Q=0;

    for(it = connected.begin(); it != connected.end(); it++)
    {

        Q+=(*it)->q;
        // Вывод всех элементов


    }
    std::cout <<"I_sum= "<< Q <<std::endl; // множества

    phi_old=phi;
    this->phi=Q+this->q+phi_ext;

}
