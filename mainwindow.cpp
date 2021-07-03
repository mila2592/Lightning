#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib> // для функций rand() и srand()
#include <iostream>




#include <vtkActor.h>
#include <vtkCellArray.h>
#include <vtkCellData.h>
#include <vtkDoubleArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPolyLine.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>

#include <vtkSphereSource.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkNamedColors.h>
#include <vtkProperty.h>



#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkLight.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>

#include <array>

Node* create_first_el();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ////////////
    int N=20;

    node=new Node[N];

    int k=10;
    srand(4541); // устанавливаем стартовое значение - 4 541

    for(int i=0;i<N;i++)// сначала цикл для отрисовки ребер
    {
        Node n;

        node[i]= n;
        node[i].set_coords(rand()%k ,rand()%k ,rand()%k );
        if(i>0)
        {
            node[i-1].connected.insert(&node[i]);
            //            glVertex3f(node[i-1].x,node[i-1].y,node[i-1].z);
            //            glVertex3f(node[i].x,node[i].y,node[i].z);
        }


        //        std::cout << node[i].x<<" "<<node[i].y<<" "<<node[i].z<<" "<< "\n";
    }

    //nodes.push_back(create_first_el());


    //  vtkNew<vtkNamedColors> colors;
    vtkNamedColors *colors = vtkNamedColors::New();


    //  vtkNew<vtkCylinderSource> cylinder;
    //  vtkCylinderSource *cylinder = vtkCylinderSource::New();

    // Create five points.
    double origin[3] = {0.0, 0.0, 0.0};
    double p0[3] = {1.0, 0.0, 0.0};
    double p1[3] = {0.0, 1.0, 0.0};
    double p2[3] = {0.0, 1.0, 2.0};
    double p3[3] = {1.0, 2.0, 3.0};

    // Create a vtkPoints object and store the points in it
    //  vtkNew<vtkPoints> points;
    vtkPoints *points = vtkPoints::New();




    //    points->InsertNextPoint(origin);
    //    points->InsertNextPoint(p0);
    //    points->InsertNextPoint(p1);
    //    points->InsertNextPoint(p2);
    //    points->InsertNextPoint(p3);

    for(int i=0;i<N;i++)
    {
        double p[3] = {node[i].x, node[i].y, node[i].z};
        points->InsertNextPoint(p);

    }


    //  vtkNew<vtkPolyLine> polyLine;
    vtkPolyLine *polyLine = vtkPolyLine::New();




    polyLine->GetPointIds()->SetNumberOfIds(N);
    for (unsigned int i = 0; i < N; i++)
    {
        polyLine->GetPointIds()->SetId(i, i);
    }

    // Create a cell array to store the lines in and add the lines to it
    //  vtkNew<vtkCellArray> cells;
    vtkCellArray *cells = vtkCellArray::New();



    cells->InsertNextCell(polyLine);

    // Create a polydata to store everything in
    //  vtkNew<vtkPolyData> polyData;
    vtkPolyData *polyData = vtkPolyData::New();



    // Add the points to the dataset
    polyData->SetPoints(points);

    // Add the lines to the dataset
    polyData->SetLines(cells);
    ///////////////////////////

    //    // Create a sphere
    //    //  vtkNew<vtkSphereSource> sphereSource;
    //    vtkSphereSource *sphereSource = vtkSphereSource::New();

    //    sphereSource->SetCenter(node[0].x, node[0].y, node[0].z);
    //    sphereSource->SetRadius(0.1);
    //    // Make the surface smooth.
    //    sphereSource->SetPhiResolution(30);
    //    sphereSource->SetThetaResolution(30);
    ///////////////////////


    // Setup actor and mapper
    //  vtkNew<vtkPolyDataMapper> mapper;
    vtkPolyDataMapper *mapper = vtkPolyDataMapper::New();


    //    mapper->SetInputData(polyData);
    //    mapper->SetInputConnection(sphereSource->GetOutputPort());
    mapper->SetInputData(polyData);

    //  vtkNew<vtkActor> actor;
    vtkActor *actor = vtkActor::New();




    actor->SetMapper(mapper);
    //    actor->GetProperty()->SetColor(colors->GetColor3d("Tomato").GetData());
    actor->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());


    ///////////////////////////////////


    //    std::vector <vtkActor> node_actors;
    // QVector<vtkActor> node_actors;


    ///////////////////////////

    // Create a sphere
    //  vtkNew<vtkSphereSource> sphereSource;
    vtkSphereSource *sphereSource = vtkSphereSource::New();

    sphereSource->SetCenter(node[0].x, node[0].y, node[0].z);
    sphereSource->SetRadius(0.1);
    // Make the surface smooth.
    sphereSource->SetPhiResolution(30);
    sphereSource->SetThetaResolution(30);
    /////////////////////


    // Setup actor and mapper for sphere
    //  vtkNew<vtkPolyDataMapper> mapper;
    vtkPolyDataMapper *mapper2 = vtkPolyDataMapper::New();


    mapper2->SetInputConnection(sphereSource->GetOutputPort());


    //  vtkNew<vtkActor> actor;
    vtkActor *actor2 = vtkActor::New();




    actor2->SetMapper(mapper2);
    actor2->GetProperty()->SetColor(colors->GetColor3d("Tomato").GetData());
    //    actor2->GetProperty()->SetColor(colors->GetColor3d("Cornsilk").GetData());

    /////////////////////////////////////

    /////////////////////////////////////////////////////
    //begin spheres
    /////////////////////////////////////////////////////


    // vtkNew<vtkNamedColors> colors;
    //   vtkNamedColors *colors = vtkNamedColors::New();


    // Set the background color.
    std::array<unsigned char, 4> bkg{{26, 51, 102, 255}};
    colors->SetColor("bkg", bkg.data());

    // The following lines create a sphere represented by polygons.
    //
    //  vtkNew<vtkSphereSource> sphere;
    vtkSphereSource *sphere = vtkSphereSource::New();


    sphere->SetThetaResolution(100);
    sphere->SetPhiResolution(50);
    sphere->SetRadius(0.3);

    // The mapper is responsible for pushing the geometry into the graphics
    // library. It may also do color mapping, if scalars or other attributes
    // are defined.
    //
    //  vtkNew<vtkPolyDataMapper> sphereMapper;
    vtkPolyDataMapper *sphereMapper = vtkPolyDataMapper::New();

    sphereMapper->SetInputConnection(sphere->GetOutputPort());

    // The actor is a grouping mechanism: besides the geometry (mapper), it
    // also has a property, transformation matrix, and/or texture map.
    // In this example we create eight different spheres (two rows of four
    // spheres) and set the diffuse lighting coefficients. A little ambient
    // is turned on so the sphere is not completely black on the back side.
    //
    // Since we are using the same sphere source and mapper for all eight spheres
    // we will use a std::array holding the actors.
    //
    // If you want/need to use std::vector, then you must use
    // std::vector<vtkSmartPointer<vtkActor>> spheres;
    // and then, in a loop, create the object using
    // spheres.push_back(vtkSmartPointer<vtkActor>::New());
    //
    // The reason:
    // vtkNew, in contrast to vtkSmartPointer, has no assignment operator
    // or copy constructor and owns one object for its whole lifetime.
    // Thus vtkNew does not satisfy the CopyAssignable and CopyConstructible
    // requirements needed for other std containers like std::vector or std::list.
    // std::array, on the other hand, is a container encapsulating fixed size
    // arrays so its elements do not need to be CopyAssignable and
    // CopyConstructible.
    //
    // So:
    //    std::array - vtkNew or vtkSmartPointer can be used.
    //    std::vector, std::list - only vtkSmartPointer can be used.
    //
    //     auto const numberOfSpheres = 8;
    auto  numberOfSpheres = N;
    //  std::array<vtkSmartPointer<vtkActor>, numberOfSpheres> spheres;

    //  std::array<vtkActor::New(), numberOfSpheres> spheres;

    std::vector< vtkSmartPointer<vtkActor> > spheres;


    for(int i=0;i<numberOfSpheres;i++)
    {
        vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
        spheres.push_back(actor);
    }

    auto ambient = 0.3;
    auto diffuse = 0.0;
    auto specular = 0.0;
    std::array<double, 3> position{{0, 0, 0}};
    for (auto i = 0; i < spheres.size(); ++i)
    {
        spheres[i]->SetMapper(sphereMapper);
        spheres[i]->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());
        spheres[i]->GetProperty()->SetAmbient(ambient);
        spheres[i]->GetProperty()->SetDiffuse(diffuse);
        spheres[i]->GetProperty()->SetSpecular(specular);
        //       spheres[i]->SetRadius(0.1);


        //       spheres[i]->AddPosition(position.data());
        position[0] =  node[i].x;
        position[1] = node[i].y;
        position[2] = node[i].z;

        spheres[i]->AddPosition(position.data());
        std::cout << diffuse << std::endl;
        //    diffuse += 0.125;
        position[0] += 1.25;
        //     position[1] += 1;
        position[2] += 0.3;
        if (i == 3)
        {
            position[0] = 0;
            position[1] = 1.25;
        }
    }

    //     // Create the graphics structure. The renderer renders into the
    //     // render window. The render window interactor captures mouse events
    //     // and will perform appropriate camera or actor manipulation
    //     // depending on the nature of the events.
    //     //
    //   //  vtkNew<vtkRenderer> ren;
    //     vtkRenderer *ren = vtkRenderer::New();

    //   //  vtkNew<vtkRenderWindow> renWin;
    //     vtkRenderWindow *renWin = vtkRenderWindow::New();

    //     renWin->AddRenderer(ren);

    //   //  vtkNew<vtkRenderWindowInteractor> iren;
    //     vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();

    //     iren->SetRenderWindow(renWin);

    //     // Add the actors to the renderer, set the background and size.
    //     //
    //     for (auto i = 0; i < numberOfSpheres; ++i)
    //     {
    //       ren->AddActor(spheres[i]);
    //     }

    //     ren->SetBackground(colors->GetColor3d("bkg").GetData());
    //     renWin->SetSize(640, 480);
    //     renWin->SetWindowName("DiffuseSpheres");

    //     // Set up the lighting.
    //     //
    //   //  vtkNew<vtkLight> light;
    //     vtkLight *light = vtkLight::New();

    //     light->SetFocalPoint(1.875, 0.6125, 0);
    //     light->SetPosition(0.875, 1.6125, 1);
    //     ren->AddLight(light);

    //     // We want to eliminate perspective effects on the apparent lighting.
    //     // Parallel camera projection will be used. To zoom in parallel projection
    //     // mode, the ParallelScale is set.
    //     //
    //     ren->GetActiveCamera()->SetFocalPoint(0, 0, 0);
    //     ren->GetActiveCamera()->SetPosition(0, 0, 1);
    //     ren->GetActiveCamera()->SetViewUp(0, 1, 0);
    //     ren->GetActiveCamera()->ParallelProjectionOn();
    //     ren->ResetCamera();
    //     ren->GetActiveCamera()->SetParallelScale(2.0);
    //     // This starts the event loop and invokes an initial render.
    //     //
    //     iren->Initialize();
    //     renWin->Render();
    //     iren->Start();

    /////////////////////////////////////////////////////
    //end spheres
    /////////////////////////////////////////////////////



    // Setup render window, renderer, and interactor
    //  vtkNew<vtkRenderer> renderer;
    vtkRenderer *renderer = vtkRenderer::New();



    //  vtkNew<vtkRenderWindow> renderWindow;
    vtkRenderWindow *renderWindow = vtkRenderWindow::New();





    renderWindow->SetWindowName("PolyLine + Sphere");
    renderWindow->AddRenderer(renderer);
    //  vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
    vtkRenderWindowInteractor *renderWindowInteractor = vtkRenderWindowInteractor::New();



    renderWindowInteractor->SetRenderWindow(renderWindow);
    renderer->AddActor(actor);
    renderer->AddActor(actor2);// sphere actor

    // Add the actors to the renderer, set the background and size.
    //
    for (auto i = 0; i < numberOfSpheres; ++i)
    {
        renderer->AddActor(spheres[i]);
    }



    renderer->SetBackground(colors->GetColor3d("DarkOliveGreen").GetData());

    renderWindow->Render();
    renderWindowInteractor->Start();

}

MainWindow::~MainWindow()
{
    delete ui;
}


Node* create_first_el()
{
    Node node0;

    node0.set_coords(0,0, 0);

    return &node0;
}
