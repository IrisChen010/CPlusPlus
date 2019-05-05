#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

const double PI = 3.14159265359;
const string CUBES_FILE = "CUBES.DAT";
const string SPHERES_FILE = "SPHERES.DAT";
const string CONES_FILE = "CONES.DAT";
const string CYLINDERS_FILE = "CYLINDERS.DAT";
const string RECTANGULARS_FILE = "RECTANGULARS.DAT";
const string FRUSTUMS_FILE = "FRUSTUMS.DAT";
const string UNKNOWN_FILE = "UNKNOWNS.DAT";

//return volume calculation of a cube
double findVolume1(double side);
//return volume calculation of a cone
double findVolume1(double radius, double height);
//return volume calculation of a rectangular tank
double findVolume1(double length, double width, double height);

//return volume calculation of a sphere
double findVolume2(double radius);
//return volume calculation of a cylinder
double findVolume2(double radius, double height);
//return volume calculation of a conical frustum
double findVolume2(double length, double width, double height);

// randomly generate data file accordingly to the solid (1-cube, 2-sphere, 3-cone, 4-cylinder, 5-frustum, and 6-rectangular)
void CreateDataFile(int type);

// display calculated volumes and computed average volume of the type of solids
// 1-cube, 2-sphere, 3-cone, 4-cylinder, 5-frustum, and 6-rectangular
void DisplayVolumesAndAverageOfSolid(int type, double& AvgVolumeOfSolid);

void DipplayLargestAvgVolume(double avgVolumeOfCube, double avgVolumeOfSphere,
        double avgVolumeOfCone, double avgVolumeOfCylinder,
        double avgVolumeOfFrustum, double avgVolumeOfRectanglular);

void DisplaySmallestAvgVolume(double avgVolumeOfCube, double avgVolumeOfSphere,
        double avgVolumeOfCone, double avgVolumeOfCylinder,
        double avgVolumeOfFrustum, double avgVolumeOfRectanglular);

int main()

{
    double AvgVolumeOfSolid = 0.0;
    double avgVolumeOfCube = 0.0;
    double avgVolumeOfSphere = 0.0;
    double avgVolumeOfCone = 0.0;
    double avgVolumeOfCylinder = 0.0;
    double avgVolumeOfFrustum = 0.0;
    double avgVolumeOfRectanglular = 0.0;

    do {
        cout << "\n\t by Antonio Rodriguez\n"
                "\t=========================================================================\n"
                "\t  1. Create DATA file for cubes\n"
                "\t  2. Display the volume of cubes and the average volume\n"
                "\t  3. Create DATA file for spheres\n"
             	"\t  4. Display the volume of spheres and the average volume\n"
              	"\t  5. Create DATA file for cones\n"
              	"\t  6. Display the volume of cones and the average volume\n"
         		"\t  7. Create DATA file for cylinders\n"
         		"\t  8. Display the volume of cylinders and the average volume\n"
         		"\t  9. Create DATA file for conical frustums\n"
         		"\t  10. Display the volume of conical frustums and the average volume\n"
         		"\t  11. Create DATA file for rectangular tanks\n"
          		"\t  12. Display the volume rectangular tanks and the average volume\n"
         		"\t  13. Display the largest average volume of these 3-D solids\n"
         		"\t  14.Display the smallest average volume of these 3-D solids\n"
         		"\t   0. Exit"
         		"\t==========================================================================\n";

        char option[80];
        cin >> option;

        switch (atoi(option)) {
        case 1:
            CreateDataFile(1);
            break;
        case 2:
            DisplayVolumesAndAverageOfSolid(1, AvgVolumeOfSolid);
            avgVolumeOfCube = AvgVolumeOfSolid;
            break;
        case 3:
            CreateDataFile(2);
            break;
        case 4:
            DisplayVolumesAndAverageOfSolid(2, AvgVolumeOfSolid);
            avgVolumeOfSphere = AvgVolumeOfSolid;
            break;
        case 5:
            CreateDataFile(3);
            break;
        case 6:
            DisplayVolumesAndAverageOfSolid(3, AvgVolumeOfSolid);
            avgVolumeOfCone = AvgVolumeOfSolid;
            break;
        case 7:
            CreateDataFile(4);
            break;
        case 8:
            DisplayVolumesAndAverageOfSolid(4, AvgVolumeOfSolid);
            avgVolumeOfCylinder = AvgVolumeOfSolid;
            break;
        case 9:
            CreateDataFile(5);
            break;
        case 10:
            DisplayVolumesAndAverageOfSolid(5, AvgVolumeOfSolid);
            avgVolumeOfFrustum = AvgVolumeOfSolid;
            break;
        case 11:
            CreateDataFile(6);
            break;
        case 12:
            DisplayVolumesAndAverageOfSolid(6, AvgVolumeOfSolid);
            avgVolumeOfRectanglular = AvgVolumeOfSolid;
            break;
        case 13:
            DipplayLargestAvgVolume(avgVolumeOfCube, avgVolumeOfSphere,
                    avgVolumeOfCone, avgVolumeOfCylinder, avgVolumeOfFrustum,
                    avgVolumeOfRectanglular);
            break;
        case 14:
            DisplaySmallestAvgVolume(avgVolumeOfCube, avgVolumeOfSphere,
                    avgVolumeOfCone, avgVolumeOfCylinder, avgVolumeOfFrustum,
                    avgVolumeOfRectanglular);
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    } while (true);

    return 0;
}

double findVolume1(double side)
{
    double volume;
    return volume = side * side * side;
}

double findVolume1(double radius, double height)
{
    double volume;
    return volume = (1.0 / 3.0) * PI * radius * radius * height;
}

double findVolume1(double length, double width, double height)
{
    double volume;
    return volume = length * width * height;
}

double findVolume2(double radius)
{
    double volume;
    return volume = (4.0 / 3.0) * PI * radius * radius * radius;
}

double findVolume2(double radius, double height)
{
    double volume;
    return volume = PI * radius * radius * height;
}

double findVolume2(double length, double width, double height)
{
    double volume;
    return volume = (1.0 / 3.0) * PI * height; // Completion of this formula is pending
}

void CreateDataFile(int type) {
    ofstream outFile;
    srand((unsigned) time(NULL));

    switch (type) {
    case 1: {
        outFile.open(CUBES_FILE);

        int cubes = (rand() % (19)) + 2; // create an integer beteween (2,21]
        for (int i = 1; i < cubes; i++) {

            double number1 = 5 * (rand() / double(RAND_MAX));
            outFile << i << "   " << number1 << endl;
        }
        outFile.close();
    }
        break;
    case 2: {
        outFile.open(SPHERES_FILE);

        int spheres = (rand() % (19)) + 2;
        for (int i = 1; i < spheres; i++) {

            double number2 = 5 * (rand() / double(RAND_MAX));
            outFile << i << "   " << number2 << endl;

        }
        outFile.close();
    }
        break;
    case 3: {
        outFile.open(CONES_FILE);

        int cones = (rand() % (19)) + 2;
        for (int i = 1; i < cones; i++) {

            double number31 = 5 * (rand() / double(RAND_MAX));
            double number32 = 5 * (rand() / double(RAND_MAX));
            outFile << i << "   " << number31 << "   " << number32 << endl;

        }
        outFile.close();
    }
        break;
    case 4: {
        outFile.open(CYLINDERS_FILE);

        int cylinders = (rand() % (19)) + 2;
        for (int i = 0; i < cylinders; i++) {

            double number41 = 5 * (rand() / double(RAND_MAX));
            double number42 = 5 * (rand() / double(RAND_MAX));
            outFile << i << "   " << number41 << "   " << number42 << endl;

        }
        outFile.close();
    }
        break;
    case 5: {
        outFile.open(FRUSTUMS_FILE);

        int frustums = (rand() % (19)) + 2;
        for (int i = 0; i < frustums; i++) {

            double number51 = 5 * (rand() / double(RAND_MAX));
            double number52 = 5 * (rand() / double(RAND_MAX));
            double number53 = 5 * (rand() / double(RAND_MAX));
            outFile << i << "   " << number51 << "   " << number52 << "   "
                    << number53 << endl;

        }
        outFile.close();
    }
        break;
    case 6: {
        outFile.open(RECTANGULARS_FILE);

        int rectangulars = (rand() % (19)) + 2;
        for (int i = 0; i < rectangulars; i++) {
            double number61 = 5 * (rand() / double(RAND_MAX));
            double number62 = 5 * (rand() / double(RAND_MAX));
            double number63 = 5 * (rand() / double(RAND_MAX));
            outFile << i << "   " << number61 << "   " << number62 << "   "
                    << number63 << endl;

        }
        outFile.close();
    }
        break;
    default:
        break;
    }

}

void DisplayVolumesAndAverageOfSolid(int type, double& AvgVolumeOfSolid) {
    AvgVolumeOfSolid = 0;
    switch (type) {
    case 1: {
        ifstream ifs(CUBES_FILE);
        string str;
        int count = 0;
        double parameter1;
        double volume;
        double sum = 0;

        while (ifs >> str) {
            ifs >> str;
            parameter1 = stod(str);

            volume = findVolume1(parameter1);
            cout << "The volume of cube is: " << volume << endl;
            sum += volume;
            count++;
        }
        AvgVolumeOfSolid = sum / count;
        cout << "The average volume of cube is: " << AvgVolumeOfSolid << endl;
        ifs.close();
    }
        break;
    case 2: {
        ifstream ifs(SPHERES_FILE);
        string str;
        int count = 0;
        double parameter1;
        double volume;
        double sum = 0;

        while (ifs >> str) {
            ifs >> str;
            parameter1 = stod(str);

            volume = findVolume2(parameter1);
            cout << "The volume of sphere is: " << volume << endl;
            sum += volume;
            count++;
        }
        AvgVolumeOfSolid = sum / count;
        cout << "The average volume of sphere is: " << AvgVolumeOfSolid << endl;
        ifs.close();
    }
        break;
    case 3: {
        ifstream ifs(CONES_FILE);
        string str;
        int count = 0;
        double parameter1;
        double parameter2;
        double volume;
        double sum = 0;

        while (ifs >> str) {
            ifs >> str;
            parameter1 = stod(str);

            ifs >> str;
            parameter2 = stod(str);

            volume = findVolume1(parameter1, parameter2);
            cout << "The volume of cone is: " << volume << endl;
            sum += volume;
            count++;
        }
        AvgVolumeOfSolid = sum / count;
        cout << "The average volume of cone is: " << AvgVolumeOfSolid << endl;
        ifs.close();
    }
        break;
    case 4: {
        ifstream ifs(CYLINDERS_FILE);
        string str;
        int count = 0;
        double parameter1;
        double parameter2;
        double volume;
        double sum = 0;

        while (ifs >> str) {
            ifs >> str;
            parameter1 = stod(str);

            ifs >> str;
            parameter2 = stod(str);

            volume = findVolume2(parameter1, parameter2);
            cout << "The volume of cylinder is: " << volume << endl;
            sum += volume;
            count++;
        }
        AvgVolumeOfSolid = sum / count;
        cout << "The average volume of cylinder is: " << AvgVolumeOfSolid
                << endl;
        ifs.close();
    }
        break;
    case 5: {
        ifstream ifs(FRUSTUMS_FILE);
        string str;
        int count = 0;
        double parameter1;
        double parameter2;
        double parameter3;
        double volume;
        double sum = 0;

        while (ifs >> str) {
            ifs >> str;
            parameter1 = stod(str);

            ifs >> str;
            parameter2 = stod(str);

            ifs >> str;
            parameter3 = stod(str);
            volume = findVolume2(parameter1, parameter2, parameter3);
            cout << "The volume of frustum is: " << volume << endl;
            sum += volume;
            count++;
        }
        AvgVolumeOfSolid = sum / count;
        cout << "The average volume of frustum is: " << AvgVolumeOfSolid
                << endl;
        ifs.close();
    }
        break;
    case 6: {
        ifstream ifs(RECTANGULARS_FILE);
        string str;
        int count = 0;
        double parameter1;
        double parameter2;
        double parameter3;
        double volume;
        double sum = 0;

        while (ifs >> str) { 
            ifs >> str;
            parameter1 = stod(str);

            ifs >> str;
            parameter2 = stod(str);

            ifs >> str;
            parameter3 = stod(str);
            volume = findVolume1(parameter1, parameter2, parameter3);
            cout << "The volume of rectange is: " << volume << endl;
            sum += volume;
            count++;
        }
        AvgVolumeOfSolid = sum / count;
        cout << "The average volume of rectange is: " << AvgVolumeOfSolid
                << endl;
        ifs.close();
    }
        break;
    default:
        break;
    }
}

void DipplayLargestAvgVolume(double avgVolumeOfCube, double avgVolumeOfSphere,
        double avgVolumeOfCone, double avgVolumeOfCylinder,
        double avgVolumeOfFrustum, double avgVolumeOfRectanglular) {
    double LargestAvgVolume = avgVolumeOfCube;
    if (avgVolumeOfSphere > LargestAvgVolume)
        LargestAvgVolume = avgVolumeOfSphere;
    if (avgVolumeOfCone > LargestAvgVolume)
        LargestAvgVolume = avgVolumeOfCone;
    if (avgVolumeOfCylinder > LargestAvgVolume)
        LargestAvgVolume = avgVolumeOfCylinder;
    if (avgVolumeOfFrustum > LargestAvgVolume)
        LargestAvgVolume = avgVolumeOfFrustum;
    if (avgVolumeOfRectanglular > LargestAvgVolume)
        LargestAvgVolume = avgVolumeOfRectanglular;
    cout << "The largest average volume is: " << LargestAvgVolume << endl;
}

void DisplaySmallestAvgVolume(double avgVolumeOfCube, double avgVolumeOfSphere,
        double avgVolumeOfCone, double avgVolumeOfCylinder,
        double avgVolumeOfFrustum, double avgVolumeOfRectanglular) {
    double SmallestAvgVolume = avgVolumeOfCube;
    if (avgVolumeOfSphere < SmallestAvgVolume)
        SmallestAvgVolume = avgVolumeOfSphere;
    if (avgVolumeOfCone < SmallestAvgVolume)
        SmallestAvgVolume = avgVolumeOfCone;
    if (avgVolumeOfCylinder < SmallestAvgVolume)
        SmallestAvgVolume = avgVolumeOfCylinder;
    if (avgVolumeOfFrustum < SmallestAvgVolume)
        SmallestAvgVolume = avgVolumeOfFrustum;
    if (avgVolumeOfRectanglular < SmallestAvgVolume)
        SmallestAvgVolume = avgVolumeOfRectanglular;
    cout << "The smallest average volume is: " << SmallestAvgVolume << endl;
}
