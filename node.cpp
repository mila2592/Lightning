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


void ort_Gramm_Shmidt(double **f,int n)
{
    double g[n][n],mod=0,pr=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            std::cout<<"f["<<i<<"]["<<j<<"]= "<<f[i][j]<<std::endl;

        }

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {

            g[i][j]=f[i][j];
        }

    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            std::cout<<"g["<<i<<"]["<<j<<"]= "<<g[i][j]<<std::endl;

    std::cout<<std::endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {

            mod=0;
            pr=0;

            for(int k=0;k<n;k++)
            {
                for(int s=0;s<n;s++)
                {
                    mod+=g[j][s]*g[j][s];
                    pr+=f[i][s]*g[j][s];
                }

                g[i][k]-=g[j][k]*pr/mod;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        mod=0;
        for(int j=0;j<n;j++)
        {
            mod+=g[i][j]*g[i][j];
        }
        mod=sqrt(mod);

        for(int k=0;k<n;k++)
        {
            g[i][k]/=mod;
        }
    }

    pr=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            std::cout<<"g["<<i<<"]["<<j<<"]= "<<g[i][j]<<std::endl;
            f[i][j]=g[i][j];
            //            qDebug()<<"g["<<i<<"]["<<j<<"]= "<<g[i][j];
        }


    for(int k=0;k<n;k++)
    {
        pr+=g[0][k]*g[1][k];
    }


    std::cout<<"pr01= "<<pr<<std::endl;

    pr=0;

    for(int k=0;k<n;k++)
    {
        pr+=g[0][k]*g[2][k];
    }
    std::cout<<"pr02= "<<pr<<std::endl;

    pr=0;

    for(int k=0;k<n;k++)
    {
        pr+=g[1][k]*g[2][k];
    }
    std::cout<<"pr12= "<<pr<<std::endl;

}
