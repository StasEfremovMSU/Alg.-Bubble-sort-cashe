#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <fstream>

#define NUM 30000

using namespace std;
int count = 0; int stop = 0; int step = 5000;
int a_old[NUM];
int rr= 0;

int main()
{
    ofstream fout("cppstudio.txt");
    //cin >> size;
    int count = 0;
    int *a = new int[NUM];
    int *base = new int [NUM]; // Исходный массив
    srand (time (NULL));
    cout << " start massiv base" << endl;

    for (int i = 0; i < NUM; i++)
    {
        base [i] = a[i] =  rand()%9;
    }
    cout << endl;
    ///cout.precision(5);

    do
    {

        stop =0;
        for (int i = 0; i < NUM; i++) a[i] = base[i];

        LARGE_INTEGER timerFrequency, timerStart, timerStop;
        QueryPerformanceFrequency(&timerFrequency);
        QueryPerformanceCounter(&timerStart);



    int j = 0; int te =0; bool tt = 0;
    bool k = 0;
    do{
            if (j == 0) {
                    k = 0; te=0;
                }
            //cout << " j start =" << j<< endl;;
            if ( j == NUM) {
                k = 1; te=0;
                //cout << "return";
            }
            tt=0;
            switch (k) {


        case 0:
            if (a[j] > a[j+1]) {
                count+=2;
                swap (a[j], a [j+1]);
                tt = 1; te=0;
            }
            else {j++; te++; tt=0; }
            break;
        case 1:
            if (a[j] < a[j-1]) {
                count +=2;
                swap (a[j], a [j-1]);
                tt = 0; te = 0;
            }
            else {j--;te++; tt=1; }
            break;
            }
            k = tt;



    } while (te!=(NUM-1));

        QueryPerformanceCounter(&timerStop);
        double const t( static_cast<double>( timerStop.QuadPart -
        timerStart.QuadPart ) / timerFrequency.QuadPart );

        cout << "Time is " << t << " seconds." << endl;
        fout << t << endl;
       // ofstream t("t.txt");

        ///cout << " Time " << ( timeGetTime()- cl ) << endl;
        ///cout << " Number of operation = " << count<< endl ;

    for (int y = 0; y < step; y++) {
    for (int i = 0; i < (NUM - 1) ; i++ )
    {
        if (base[i] > base[i+1])
        {
            swap (base[i], base[i+1]); stop = 1;
        }
    }
    }

   /// ofsream rr (n.txt);
    rr+=step;
    /// cout << " end a " << endl;
    /// for (int i = 0; i < size; i++)  cout << a[i] << "";
    ///cout << endl <<" base " << endl;
    /// for (int i = 0; i < size; i++)  cout << base[i] << "";
    ///cout << endl<< endl;
    //y++;

    } while (stop);

    fout.close();

    return 0;
}
