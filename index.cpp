#include "opencv2/objd mgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void detectAndDraw(Mat& img, CascadeClassifier& cascade, double scale){
    vector<Rect> faces;    
    Mat gray;
    cvtColor(img,gray,COLOR_BGR2GRAY);


cascade.detectMultiScale(smallImg, faces, 1.1, 2,0|CASCADE_SCALE_IMAGE,Size(30,30));

for ( size_t i = 0; i < faces.size(); i++ )
{
Rect r = faces[i];
Scalar color = Scalar(255, 0, 0);
rectangle( img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)), cvPoint(cvRound((r.x +
r.width-1)*scale), cvRound((r.y + r.height-1)*scale)), color, 3, 8, 0);
}

imshow( "Face Detection", img );

int main()
{
// Load the cascade classifier
cascade.load( "../../haarcascade_frontalcatface.xml" ) ;
double scale=1;
frame = imread('lenna.jpg', CV_LOAD_IMAGE_COLOR);
detectAndDraw( frame, cascade, scale );
return 0;
}

//     double aspect_ratio = (double)r.width/r.height;
//     if(0.75<aspect_ratio && aspect_ratio<1.3)
//     {
//         center.x = cvRound((r.x + r.width*0.5)*scale);
//         center.y = cvRound((r.y + r.height*0.5)*scale);
//         radius = cvRound((r.width + r.height)*0.25*scale);
//         circle(img, center, radius, color,3,8,0);

//     }
// else
// rectangle(img, cvPoint(cvRound(r.x*scale), cvRound(r.y*scale)),cvPoint(cvRound(r.x + r.width -1)*scale),cvRound((r.y + r.height -1)*scale), color,3,8,0);
// if(nestedCascade.empty())
// continue;
// smallImagROI = smallImg(r);
// nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1,2
//                                0| CASCADE_SCALE_IMAGE, Size(30,30));

// for(size_t j = 0; j<nestedObjects.size();j++){
//     Rect nr = nestedObjects[j];
//     center.x = cvRound((r.x + nr.x+ nr.width*0.5)*scale);
//     center.x = cvRound((r.y +nr.x+ nr.height*0.5)*scale);
//      radius = cvRound((nr.width + nr.height)*0.25*scale);
//      circle(img, center, radius, color,3,8,0);

// }

// }
// imshow("Face Detection",img);
// }
