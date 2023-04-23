/*
Muhammad Ali Ahson
21i - 2535
Section - C
Assignment 01 Data Structures */









#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <cmath>
#include<cstdlib>
#include <iostream>

using namespace cv;
using namespace std;

int** task1() {
    // to read image
    Mat im = imread("F:\\Assignment 3\\Segmented Outputs\\mIMD004.bmp", IMREAD_GRAYSCALE);
    // To find the rows and ciols of the images
     int  rows = im.rows;
     int  cols = im.cols;

    cout << "rows     " << rows<<endl;
    cout << "cols     "<< cols<<endl;

    // Making 2D Dynamic Array
    int **arr=new int*[rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    // Assigning Values
   for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = im.at<uchar>(i, j);
        }
    }

   int c = 1; // Label to assign  
   int min = 0; // To find the min value in the surrounding
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols-1; j++) {
             
            if ( arr[i][j] == 255 && (i !=0 && j !=0  )) {
                if ((arr[i][j - 1] == 0) && (arr[i - 1][j - 1] == 0) && ( arr[i - 1][j] == 0) && (arr[i - 1][j + 1] == 0)) {
                    arr[i][j] = c; // Assigning new label
                    c++;
                }
                else  if ((arr[i][j - 1] != 0) || (arr[i - 1][j - 1] != 0) || (arr[i - 1][j] != 0) || (arr[i - 1][j + 1] != 0))
                    {
                    // Finding non-zero min value

                    if ((arr[i][j - 1] != 0)) {
                        min = arr[i][j - 1];
                        if ((min > arr[i - 1][j - 1]) && (arr[i - 1][j - 1] != 0)) {
                            min = arr[i - 1][j - 1];
                        }
                        if ((min > arr[i - 1][j]) && (arr[i - 1][j] != 0)) {
                            min = arr[i - 1][j];
                        }
                        if ((min > arr[i - 1][j + 1]) && (arr[i - 1][j + 1] != 0)) {
                            min = arr[i - 1][j + 1];
                        }
                    }
                         else if ((arr[i - 1][j - 1] != 0)) {
                        // Finding non-zero min value

                             min = arr[i - 1][j - 1];
                             if ((min > arr[i][j - 1]) && (arr[i][j - 1] != 0)) {
                                 min = arr[i][j - 1];
                             }
                             if ((min > arr[i - 1][j]) && (arr[i - 1][j] != 0)) {
                                 min = arr[i - 1][j];
                             }
                             if ((min > arr[i - 1][j + 1]) && (arr[i - 1][j + 1] != 0)) {
                                 min = arr[i - 1][j + 1];
                             }
                         }
                         else if ((arr[i - 1][j] != 0)) {
                        // Finding non-zero min value

                             min = arr[i - 1][j];
                             if ((min > arr[i][j - 1]) && (arr[i][j - 1] != 0)) {
                                 min = arr[i][j - 1];
                             }
                             if ((min > arr[i - 1][j - 1]) && (arr[i - 1][j - 1] != 0)) {
                                 min = arr[i - 1][j - 1];
                             }
                             if ((min > arr[i - 1][j + 1]) && (arr[i - 1][j + 1] != 0)) {
                                 min = arr[i - 1][j + 1];
                             }
                         }
                         else if ((arr[i - 1][j + 1] != 0)) {
                        // Finding non-zero min value

                             min = arr[i - 1][j + 1];
                             if ((min > arr[i][j - 1]) && (arr[i][j - 1] != 0)) {
                                 min = arr[i][j - 1];
                             }
                             if ((min > arr[i - 1][j - 1]) && (arr[i - 1][j - 1] != 0)) {
                                 min = arr[i - 1][j - 1];
                             }
                             if ((min > arr[i - 1][j]) && (arr[i - 1][j] != 0)) {
                                 min = arr[i - 1][j];
                             }
                         }

                    arr[i][j] = min;
                    if (arr[i ][j - 1] != 0) {
                        arr[i][j - 1] = min;
                    }
                    if (arr[i - 1][j - 1] != 0) {
                        arr[i - 1][j - 1] = min;
                    }
                    if (arr[i - 1][j] != 0) {
                        arr[i - 1][j] = min;
                    }
                    if (arr[i - 1][j + 1] != 0) {
                        arr[i - 1][j + 1] = min;
                    }
  
                }
               
            }
       }  
    }
    // Code to find the most occuring value(Label)
    int count=0;
     int *ptr=new int [c];
    int* ptr2 = new int[c];
    for (int i = 0; i < c; i++) {
        ptr[i] = i+1;
    }
    int yu = 1;
    int * count_1 = new int [c];
    for (int k = 0; k < c; k++) {
        yu = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (ptr[k] == arr[i][j]) {
                    count_1[k] = yu;
                    yu++;
                }
            }
        }
    }

    // copying array
    for (int i = 0; i < c; i++) {
        ptr2[i] = ptr[i];
    }


    int index = 0;
    for (int i = 1; i < c; ++i) {

        // Change < to > if you want to find the smallest element
        if (count_1[0] < count_1[i]) {
            count_1[0] = count_1[i];
            index = i;
        }
    }
    cout << endl;
    cout <<"Value of maximum ocurence    " << ptr2[index]<<endl;

    //Assigning most Occured value 255 the white pixel
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == ptr2[index]) {
                arr[i][j] = 255;
                count++;
             }
            else {
                arr[i][j] = 0;
               }
        }
    
    }

   // Assigning the value to image pixels after the implemention of collective Labelling
    Mat other= imread("F:\\Assignment 3\\Segmented Outputs\\mIMD004.bmp", IMREAD_GRAYSCALE);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          other.at<uchar>(i, j)  = arr[i][j];
        }
    }

    // To show the Image
    
    imshow("title", other);
    waitKey(0);

    // Assigniing the white pixels back to 1 so it can be use for task 3

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 255) {
                arr[i][j] = 1;
                count++;
            }
            else {
                arr[i][j] = 0;
            }


        }

    }


    return arr;
}


int** task2() {
    int rows = 0, cols = 0;
    // to read image
    Mat task2 = imread("F:\\Assignment 3\\Original Images\\IMD004.bmp", IMREAD_GRAYSCALE);
    rows = task2.rows;
    cols = task2.cols;


    // Assiging the random values
    srand(1000);
    int cluster1 = rand() % 255;
    int cluster2 = rand() % 256;
    cluster2--;
  
    // Dynamic 2D array implementation

    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }


    // Assigning pixel values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = task2.at<uchar>(i, j);
        }
    }


    int rev = 0;
    int k1 = 0, k2 = 0;// cluster 1 mn 1 dalo aur cluster 2 mn 2 dalo
    int c1 = 0, c2 = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rev = arr[i][j];

            // k1 and k2 are the eclidion distance of custer 1 and cluster 2  respectively
            k1 = sqrt((rev - cluster1) * (rev - cluster1));
            k2 = sqrt((rev - cluster2) * (rev - cluster2));
            if (k1 < k2) {
                arr[i][j] = 1;
                c1 += rev;
                count1++;
            }
            else {
                arr[i][j] = 2;
                c2 += rev;
                count2++;
            }

        }

    // Assigning it after calculating the averages
        cluster1 = c1 / count1;
        cluster2 = c2 / count2;
    }


    // Assigning the max label equal to white pixels 

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // comparing both
                if (arr[i][j] == 2) {
                    arr[i][j] = 255;
                }
                else {
                    arr[i][j] = 0;
                }
            
            
        }
    }

    Mat othertask2 = imread("F:\\Assignment 3\\Original Images\\IMD004.bmp", IMREAD_GRAYSCALE);//IMREAD_COLOR

    // Assigning values to the image

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            othertask2.at<uchar>(i, j) = arr[i][j];
        }
    }

    // To display the image

  /* imshow("t", othertask2);
    waitKey(0);*/



    // Converting the white pixels to 1 so it can be use for the task 3
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 255) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    return arr;

}
int task3() {
    // to read image
    Mat im = imread("F:\\Assignment 3\\Ground Truths\\IMD004_lesion.bmp", IMREAD_GRAYSCALE);

    // for getting rows and cols of image
    const int  rows = im.rows;
    const int  cols = im.cols;

    cout << "rows     " << rows << endl;
    cout << "cols     " << cols << endl;


    int** arr = new int* [rows];

    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    int Tp = 0,Fp=0,Fn=0;
    arr = task1();// getting the address of 2d array form task 1




    // caluculating the True Positive, False Positive & False Negative

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((im.at<uchar>(i, j) == 255) && (arr[i][j] == 1)) {
                Tp++;
             }
            else if ((im.at<uchar>(i, j) == 0) && (arr[i][j] == 1)) {
                Fp++;
            }
            else if ((im.at<uchar>(i, j) == 255) && (arr[i][j] == 0)) {
                Fn++;
            }
        }
    }


    // display the values
    cout << "False Negative              " << Fn << endl;
    cout << "False Positive              " << Fp << endl;
    cout << "True Positive               " << Tp << endl<<endl;

    // Calculating the Dice Cofficient

    float dice = 0;
   dice = (2 * Tp) ;
    dice = dice / (Fn + (2 * Tp) + Fp);
    cout << "Dice Cofficient of task 1   " << dice << endl;

    arr = task2(); // getting the address of 2d array form task 2

    Tp = 0, Fp = 0, Fn = 0;

    // caluculating the True Positive, False Positive & False Negative from task 2


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if ((im.at<uchar>(i, j) == 255) && (arr[i][j] == 1)) {
                Tp++;
            }
            else if ((im.at<uchar>(i, j) == 0) && (arr[i][j] == 1)) {
                Fp++;
            }
            else if ((im.at<uchar>(i, j) == 255) && (arr[i][j] == 0)) {
                Fn++;
            }
        }
    }

    // display the values
    cout << "False Negative              " << Fn << endl;
    cout << "False Positive              " << Fp << endl;
    cout << "True Positive               " << Tp << endl<<endl;

    // Calculating the Dice Cofficient
     dice = 0;
    dice = (2 * Tp);
    dice = dice / (Fn + (2 * Tp) + Fp);
    cout << "Dice Cofficient of task 2   " << dice << endl;


    return 0;
}
class node {
public:
    int sc;
    int ec;
    int row;
    node* next;
    node() {
        row = 0;
        sc = 0;
        ec = 0;
        next = NULL;
    }
    node(int  v, int v1, int row) {
        this->row = row;
        sc = v;
        ec = v1;
        next = NULL;
    }

};
class linklist {
public:
    node* head;
    linklist() {
        head = NULL;
    }
    void insert(int v, int v1, int row) {

        node* n = new node(v, v1, row);
        if (head == NULL) {
            head = n;
        }

        else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }







    void display() {
        node* temp = head;
        while (temp->next != NULL) { // to run till end
          
            if (temp->sc != temp->ec) {
              
                if (temp->row == temp->next->row) {
                    //  if the row is same
                    cout  << "    " << temp->sc << "  " << "   " << temp->ec ;
                    temp = temp->next;

                }
                else if(temp->row != temp->next->row) {
                   
                    cout  << "    " << temp->sc << "  " << "    " << temp->ec ;
                  
                    cout << "  -1" << endl; 
                    cout << endl;
                    temp = temp->next;
                }
            }
            else {
                // the row dosen't have any white pixels
                  cout << "  -1" << endl;
         temp = temp->next;
            }
        }
    }

    void task4() {

        // to read image
        Mat im = imread("F:\\Assignment 3\\Segmented Outputs\\mIMD020.bmp", IMREAD_GRAYSCALE);


        // for rows and cols
        const int  rows = im.rows;
        const int  cols = im.cols;

        cout << "rows     " << rows << endl;
        cout << "cols     " << cols << endl;


        int val = 0, r = 0, sv = 0, ev = 0;
        int check = 0, counter = 0;
        bool flag;


        for (int i = 0; i < rows; i++) {
            flag = true;
            for (int j = 0; j < cols; j++) {
             

                if (im.at<uchar>(i, j) == 255) {
                    check = j;
                    sv = j;
                    while ( im.at<uchar>(i, check + 1) == 255)
                    {

                        check++; // to check the consective values indexs

                    }


                    r = i;
                  
                    ev = check;
                     insert(sv, ev, r);// inseertion of the stating and the ending points of the white pixels
                    j = check;
                     flag = false;
                  
                }
            }
             if (flag) {
                insert(0, 0, i); // insetion if the respective rows doesn't have any white pixel values
            }
          


        }
        // to display the values from the link list
       display();
    }


};

       









int main()
{
 /*   With respect, It is stated that if you want to run task 3 
        then please commnet the imshow function in the task 1 and 2. thank you!*/

   /* Muhammad Ali Ahson
        21i-2535
        Section- C
        Assignment 01 Data Structures*/

    linklist l;
  //task1();
   //task2(); 
    task3();
  //  l.task4();

}



